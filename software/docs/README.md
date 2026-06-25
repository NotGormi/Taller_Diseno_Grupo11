# Documentación de Software

## Contenido

### Documentación de Funciones

#### Funciones Principales

**leerVoltaje()**
- **Propósito:** Leer el voltaje capturado por el sensor ultravioleta
- **Parámetros:** Lectura análoga del voltaje del sensor GUVA-S12SD
- **Retorna:** float mV, corresponde al promedio de 10 lecturas de voltaje del sensor
- **Ejemplo de uso:**
```cpp
long suma = 0;
for (int i = 0; i < 10; i++) {
    suma += analogRead(UV_PIN);
    delay(2);
}
float promedio = suma / 10.0;

float mV = (promedio / ADC_BITS) * VREF * 1000.0;
return mV;
```

**calcularUVIndex()**
- **Propósito:** Calcular el índice UV según la clasificación en la tabla UV_INDEX_TABLE y el voltaje capturado por el sensor
- **Parámetros:** float mV, el voltaje capturado por el sensor
- **Retorna:** int index, Índice UV en números enteros
- **Ejemplo de uso:**
```cpp
if (mV < UV_INDEX_TABLE[0][0]) return 0;

for (int i = 0; i < TABLE_SIZE - 1; i++) {
    if (mV >= UV_INDEX_TABLE[i][0] && mV < UV_INDEX_TABLE[i + 1][0]) {
      return (int)UV_INDEX_TABLE[i][1];
    }
  }

  // Si supera el máximo de la tabla
  return 11;
```

**clasificarUV()**
- **Propósito:** Clasificar el índice UV según el cálculo del índice UV
- **Parámetros:** int index, el índice UV calculado en calcularUVIndex()
- **Retorna:** string, la clasificación del índice UV (Bajo, Moderado, Alto, Muy Alto o Extremo)
- **Ejemplo de uso:**
```cpp
if (index <= 2)  return "Bajo       (0-2)   - Sin proteccion necesaria";
if (index <= 5)  return "Moderado   (3-5)   - Usar protector solar";
if (index <= 7)  return "Alto       (6-7)   - Proteccion recomendada";
if (index <= 10) return "Muy alto   (8-10)  - Proteccion obligatoria";
return             "Extremo    (11+)   - Evitar exposicion";
```

**imprimirBarra()**
- **Propósito:** Imprime una barra de progreso virtual únicamente en el monitor serial
- **Parámetros:** int index, el índice UV clasificado anteriormente en clasificarUV()
- **Retorna:** void, interactúa directamente con el monitor serial
- **Ejemplo de uso:**
```cpp
int clamped = constrain(index, 0, 11);
Serial.print("Nivel  [");
for (int i = 0; i <= 11; i++) {
    Serial.print(i <= clamped ? "█" : "░");
}
Serial.print("] ");
Serial.println(clamped);
```

**prepareHtmlPage()**
- **Propósito:** Prepara la página web en donde se mostrarán los datos
- **Parámetros:** void, espera al término del request del navegador
- **Retorna:** string, el código fuente de la página web en HTML
- **Ejemplo de uso:**
```cpp
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
```

**handleRoot()**
- **Propósito:** Contenido de la página web
- **Parámetros:** void, espera a ser llamada dentro de la función prepareHtmlPage()
- **Retorna:** string, el cuerpo de la página web en HTML
- **Ejemplo de uso:**
```cpp
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
```
---

## Troubleshooting

### Problemas Comunes

**Problema 1: No conecta a WiFi**
- Causa probable: Variables ssid o password incorrectas.
- Solución: Actualizar el valor de las variables para permitir la conexión a WiFi.
