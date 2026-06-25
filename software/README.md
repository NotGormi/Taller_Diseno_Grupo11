# Software - Documentación

## Contenido
Esta carpeta contiene todo el código y documentación del software del proyecto.

### 📁 Carpetas

#### `src/`
Código fuente del proyecto (.ino para Arduino/ESP32)

#### `librerias/`
Librerías utilizadas en el proyecto

#### `docs/`
Documentación técnica del software

---

## Stack Tecnológico

**Plataforma:** Arduino / ESP32  
**Lenguaje:** C/C++  
**IDE:** Arduino IDE 2.3.8  
**Librerías principales:**
- ESP8266WiFi.h - Versión 1.0
- FirebaseClient.h - Versión 2.2.9
---

## Instalación y Configuración

### 1. Instalar Arduino IDE
1. Instalar Arduino IDE desde la página `https://docs.arduino.cc/software/ide/`

### 2. Configurar ESP8266
1. Descargar el driver universal CP210x desde la página `https://www.silabs.com/software-and-tools/usb-to-uart-bridge-vcp-drivers?tab=downloads`
2. Extraer el archivo zip en una carpeta destinada por el usuario (por ejemplo una carpeta en el escritorio llamada `Driver CP2102`)
3. En Arduino IDE, ir a `File > Preferences > Settings` y colocar en `Additional boards manager URLs:` colocar `https://arduino.esp8266.com/stable/package_esp8266com_index.json`

### 3. Cargar Código
1. Abrir `src/SensorUV_G11.ino`
2. Seleccionar placa y puerto
3. Compilar y subir

---

## Configuración de Parámetros

Editar las siguientes constantes en el código:

```cpp
// WiFi
const char* ssid "tu_red"
const char* password "tu_password"
```

---

### Módulos Principales
1. **Inicialización** - Setup del sistema
2. **Lectura de Sensores** - Captura de datos
3. **Procesamiento** - Análisis y decisiones
4. **Comunicación** - Envío de datos

---
