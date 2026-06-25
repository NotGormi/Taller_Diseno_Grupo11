#include <ESP8266WiFi.h>

WiFiServer server(80);

float voltajeADC = 0.0;
int uvIndex = 0;
String riesgo = "";

String prepareHtmlPage()
{
  String htmlPage;
  htmlPage.reserve(1024);
  htmlPage = F("HTTP /1.1 200 OK \r\n"
  "Content-Type: text/html\r\n"
  "Connection: close\r\n"
  "Refresh: 5\r\n" // Refrescar la página cada 5 segundos
  "\r\n"
  "<!DOCTYPE HTML>"
  "<html>");
  htmlPage += handleRoot();
  htmlPage += F("</html>"
  "\r\n");
  return htmlPage;
}

const char* ssid = "SSID";
const char* password = "PASSWORD";

/*
 * ============================================================
 *  Sensor UV GUVA-S12SD + NodeMCU ESP8266
 *  
 *  Conexión de hardware:
 *    GUVA-S12SD  -->  NodeMCU ESP8266
 *    VCC         -->  3.3V
 *    GND         -->  GND
 *    OUT         -->  A0 (único pin analógico del ESP8266)
 *
 *  Nota: El ESP8266 tiene un ADC de 10 bits (0-1023) con
 *  voltaje de referencia de 1.0V en el pin A0.
 *  Se recomienda usar un divisor de voltaje si la salida
 *  del sensor supera 1.0V.
 * ============================================================
 */

// ── Pines ───────────────────────────────────────────────────
const int UV_PIN = A0;          // Pin analógico del ESP8266

// ── Constantes de calibración ───────────────────────────────
// Voltaje de referencia del ADC del ESP8266 = 1.0 V
// Si usas un divisor de voltaje ajusta VREF y el factor
const float VREF       = 1.0;   // Voltios
const int   ADC_BITS   = 1023;  // Resolución 10 bits

// Tabla de conversión mV -> Índice UV (basada en datasheet GUVA-S12SD)
// Índice UV 0-1: <= 50 mV
// Los umbrales están en milivolts (mV)
const float UV_INDEX_TABLE[][2] = {
  {50,   0},
  {227,  1},
  {318,  2},
  {408,  3},
  {503,  4},
  {606,  5},
  {696,  6},
  {795,  7},
  {881,  8},
  {976,  9},
  {1079, 10},
  {1170, 11}
};
const int TABLE_SIZE = sizeof(UV_INDEX_TABLE) / sizeof(UV_INDEX_TABLE[0]);

// ── Variables globales ───────────────────────────────────────
unsigned long previousMillis = 0;
const long    INTERVAL        = 15000;   // Lectura cada 15 segundos

// ── Prototipos ───────────────────────────────────────────────
float  leerVoltaje();
int    calcularUVIndex(float mV);
String clasificarUV(int index);
void   imprimirBarra(int index);

// ============================================================
// Lee el pin A0 y devuelve el voltaje en milivolts
// Promedia 10 muestras para estabilidad
// ============================================================
float leerVoltaje() {
  long suma = 0;
  for (int i = 0; i < 10; i++) {
    suma += analogRead(UV_PIN);
    delay(2);
  }
  float promedio = suma / 10.0;

  // Convertir a voltaje: (lectura / 1023) * VREF * 1000 para mV
  float mV = (promedio / ADC_BITS) * VREF * 1000.0;
  return mV;
}

// ============================================================
// Convierte milivolts al índice UV usando la tabla del datasheet
// ============================================================
int calcularUVIndex(float mV) {
  if (mV < UV_INDEX_TABLE[0][0]) return 0;

  for (int i = 0; i < TABLE_SIZE - 1; i++) {
    if (mV >= UV_INDEX_TABLE[i][0] && mV < UV_INDEX_TABLE[i + 1][0]) {
      return (int)UV_INDEX_TABLE[i][1];
    }
  }

  // Si supera el máximo de la tabla
  return 11;
}

// ============================================================
// Clasifica el nivel de riesgo según la OMS
// ============================================================
String clasificarUV(int index) {
  if (index <= 2)  return "Bajo       (0-2)   - Sin proteccion necesaria";
  if (index <= 5)  return "Moderado   (3-5)   - Usar protector solar";
  if (index <= 7)  return "Alto       (6-7)   - Proteccion recomendada";
  if (index <= 10) return "Muy alto   (8-10)  - Proteccion obligatoria";
  return             "Extremo    (11+)   - Evitar exposicion";
}

// ============================================================
// Imprime una barra de progreso visual en el monitor serie
// ============================================================
void imprimirBarra(int index) {
  int clamped = constrain(index, 0, 11);
  Serial.print("Nivel  [");
  for (int i = 0; i <= 11; i++) {
    Serial.print(i <= clamped ? "█" : "░");
  }
  Serial.print("] ");
  Serial.println(clamped);
}

String handleRoot() {
  voltajeADC = leerVoltaje();
  uvIndex = calcularUVIndex(voltajeADC);
  riesgo = clasificarUV(uvIndex);

  String html = "<body>";
  html += "<h1>Sensor UV</h1>";
  html += "<p>Voltaje ADC: " + String(voltajeADC) + " mV</p>";
  html += "<p>Indice UV: " + String(uvIndex) + "</p>";
  html += "<p>Riesgo: " + String(riesgo) + "</p>";
  html += "</body>";
  
  return html;
}

// ============================================================
void setup() {
  Serial.begin(115200);
  delay(10);

  // Iniciar conexión Wi-Fi
  Serial.println();
  Serial.print("Conectando a ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA); // Modo Estación
  WiFi.begin(ssid, password);

  // Esperar conexión
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi conectado");
  Serial.println("Dirección IP: ");
  Serial.println(WiFi.localIP()); // Muestra la IP asignada
  server.begin();
  Serial.println("Servidor web iniciado.");

  Serial.println();
  Serial.println("╔══════════════════════════════════════╗");
  Serial.println("║  Monitor UV - GUVA-S12SD + ESP8266   ║");
  Serial.println("╚══════════════════════════════════════╝");
  Serial.println();
  Serial.println("Iniciando sensor...");
  delay(500);
  Serial.println("Listo. Tomando lecturas cada 15 segundos.");
  Serial.println();
}

// ============================================================
void loop() {
  WiFiClient client = server.accept(); // Esperar a que el cliente (navegador web) se conecte

  if (client) {
    Serial.println("\n[Cliente conectado]");
    while (client.connected()){ // Leer linea por linea lo que el cliente (navegador web) está pidiendo (los protocolos HTTP)
      if (client.available()){
        String line = client.readStringUntil('\r');
        Serial.print(line);
        // Esperar al término del request del navegador, que esta marcado con una línea en blanco ("\r\n")
        if (line.length() == 1 && line[0] == '\n'){
          client.println(prepareHtmlPage());
          break;
        }
      }
    }

    while (client.available()) {
      client.read();
    }

    // Cerrar la conexión
    client.stop();
    Serial.println("[Cliente desconectado]");
  }

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= INTERVAL) {
    previousMillis = currentMillis;

    // 1. Promedio de 10 lecturas para reducir ruido
    voltajeADC = leerVoltaje();

    // 2. Calcular índice UV
    uvIndex = calcularUVIndex(voltajeADC);

    // 3. Clasificación de riesgo
    riesgo = clasificarUV(uvIndex);

    // 4. Mostrar resultados
    Serial.println("──────────────────────────────────────");
    Serial.print("Voltaje ADC : ");
    Serial.print(voltajeADC, 1);
    Serial.println(" mV");

    Serial.print("Índice UV   : ");
    Serial.println(uvIndex);

    Serial.print("Riesgo      : ");
    Serial.println(riesgo);

    imprimirBarra(uvIndex);
    Serial.println();

  }
}
