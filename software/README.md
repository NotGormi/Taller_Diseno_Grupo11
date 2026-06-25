# Software - Documentación

## Contenido
Esta carpeta contiene todo el código y documentación del software del proyecto.

### 📁 Carpetas

#### `src/`
Código fuente del proyecto (.ino para Arduino/ESP32)

#### `docs/`
Documentación técnica del software

---

## Stack Tecnológico

**Plataforma:** Arduino / ESP32  
**Lenguaje:** C/C++  
**IDE:** Arduino IDE 2.3.8  
**Librerías principales:**
- ESP8266WiFi.h - Versión 1.0
---

## Instalación y Configuración

### 1. Instalar Arduino IDE
[Instrucciones de instalación]

### 2. Configurar ESP8266
[Pasos de configuración]

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
