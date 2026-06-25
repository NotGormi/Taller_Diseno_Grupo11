# Código Fuente

## Archivos Principales

### `SensorUV_G11.ino`
Archivo principal del proyecto Arduino/ESP32

**Estructura:**
- Setup: Inicialización del sistema
- Loop: Ciclo principal de ejecución

---

## Nombres de Variables
- Variables: `voltajeADC`, `uvIndex`, `riesgo`, `mV`, `previousMillis`
- Constantes: `UV_PIN`, `VREF`, `ADC_BITS`, `UV_INDEX_TABLE`, `TABLE_SIZE`, `INTERVAL`
- Funciones: `leerVoltaje()`, `calcularUVIndex()`, `clasificarUV()`, `imprimirBarra()`, `prepareHtmlPage()`, `handleRoot()`

---

### Monitor Serial
- Baudrate: 115200
- Mensajes informativos con prefijos:
  - `[INFO]` - Información general
  - `[ERROR]` - Errores
  - `[DEBUG]` - Debug
