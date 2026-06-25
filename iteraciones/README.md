# Historial de Iteraciones

## Propósito

Esta carpeta documenta la evolución del prototipo a través de las diferentes versiones desarrolladas durante el curso.

**CRÍTICO:** Demostrar el proceso iterativo es un requisito para obtener puntaje completo en "Integración y Refinamiento" (2.5 puntos).

---

## Estructura de Carpetas

Cada iteración tiene su propia carpeta con documentación de esa versión:

```
iteraciones/
├── iteracion_1/    # Concepto inicial - Prototipo alpha
├── iteracion_2/    # Primera iteración - Avance #2
└── iteracion_3/    # Versión final - Avance #3
```

---

## Contenido de Cada Iteración

Cada carpeta debe incluir:

1. **README.md** - Descripción de la versión
2. **Fotos** - Imágenes del prototipo en ese estado
3. **Esquema** - Circuito de esa versión (si cambió)
4. **Código** - Versión del software (si cambió)
5. **Notas** - Problemas identificados y mejoras planificadas

---

## Tabla Comparativa de Iteraciones

| Aspecto | v1 | v2 | v3 |
|---------|----|----|----| 
| **Fecha** | 23/04/2026 | 21/05/2026 | 24/06/2026 |
| **Sensores** | GUVA-S12SD | GUVA-S12SD | GUVA-S12SD |
| **Actuadores** | ❌ | ❌ | ❌ |
| **Conectividad** | [tipo] | [tipo] | [tipo] |
| **Encapsulado** | Conceptual | Prototipo | Finalizado |
| **Testing** | Solo toma de datos | Servidor Locar | Base de datos |
| **Funcionalidad** | 40% | 75% | 100% |

---

## Evolución del Diseño

### Versión 1 (Iteración 1) - Concepto Inicial
**Fecha:** [23/04/2025]  
**Estado:** Prototipo alpha - Prueba de concepto

**Características:**
- Diseño conceptual de encapsulado y codigo inicial
- Problemas principales identificados: | Diseño sin mediciones | Diseño solo funcional | No hay orden de componentes | Codigo solo cumple con toma de datos |
- Aprendizajes clave: | Importancia de diseño y codigo ordenado y completo |

### Versión 2 (Iteración 2) - Primera Mejora
**Fecha:** [30/04/2025]  
**Estado:** Prototipo funcional mejorado

**Mejoras implementadas:**
- [Mejora 1] Diseño con medicioens y espacios para cada componente
- [Mejora 2] Codigo permite guardar datos

**Problemas pendientes:**
- [Problema 1] El diseño no cumple en contexto de situacion real
- [Problema 2] El codigo no permite ver información desde cualquier dispositivo

### Versión 3.0 (Iteración 3) - Versión Semi Completa
**Fecha:** [11/06/2025]  
**Estado:** Prototipo con diseño final

**Mejoras finales:**
- [Mejora 1] Diseño cumple con un proposito real
- [Mejora 2] Codigo permite visualizar datos desde un servidor

  **Problemas pendientes:**
- [Problema 1] El diseño no cumple con sistema de fijación

### Versión 3.2 (Iteración 4) - Versión FInal
**Fecha:** [21/06/2025]  
**Estado:** Prototipo final y robusto

**Mejoras finales:**
- [Mejora 1] Diseño puede ser fijado y mantenido en contexto de situación real

**Resultado:**
- Sistema robusto y probado
- Listo para piloto en terreno

---

## Justificación de Cambios

### Hardware
**De v1 a v2:**
- Cambio: Uso de shield y bateria para alimentar el microcontrolador
- Razón: En caso real, el microcontrolador no estara conectaddo a una computadora que pudiera enviara energia
- Impacto: Diseño mas portatil y general, que permite tomar mediciones desde lugares mas amplios

**De v2 a v3:**
- Cambio: Quitar el protoboard
- Razón: Habilidad de poder utilizar los pines del microcontrolador sin necesitar de un repetidor
- Impacto: Diseño con mas espacio y mas ligero lo que equivale a un menor costo de fabricación

### Software
**De v1 a v2:**
- El prototipo ermite lectura de datos en un servidor locar

**De v2 a v3:**
- El prototipo guarda datos en una base de datos

### Diseño 3D
**De v1 a v2:**
- Cambio de material utilizado y espació para componentes con mediciones

**De v2 a v3:**
- Cambio de caja a L y sistema de fijación

---

## Incorporación de Feedback

### Feedback del Avance #1 → Cambios en v2
1. El encapsulado es basico
2. El codigo no permite recopilar datos
   - Acción tomada: Aplicación de materiales en el diseño y guardado de datos por el codigo

### Feedback del Avance #2 → Cambios en v3
1. El encapsulado no puede ser fijado a una pared
2. El codigo no permite visualizar datos desde un sevidor
   - Acción tomada: Cambio de diseño desde una caja a una letra "L" invertida con ranuras a los costados para atornillar e inclusión de servidor para lectura de datos

### Feedback de Usuarios → Cambios en v3
1. El encapsulado no permite una ranura donde solo ilumine al sensor y no al resto de componentes
   - Acción tomada: Cambio de diseño del encapsulado superior hacia una tapa con una pequeña ranura solo para el sensor

---

## Métricas de Mejora

| Métrica | v1 | v2 | v3 | Mejora Total |
|---------|----|----|----| -------------|
| Tiempo respuesta (ms) | 500 | 200 | 100 | ↓80% |
| Consumo (mA) | 250 | 180 | 120 | ↓52% |
| Tasa de errores (%) | 15 | 5 | 1 | ↓93% |
| Toma de datos (1-5) | 3.0 | 3.8 | 4.5 | ↑50% |

---

## Lecciones Aprendidas

### Técnicas
- Modelaje 3D en Autodesk Fusion
- Escritura de codigo para microcontrolador ESP8266

### De Proceso
- Evaluación critica del proyecto al momento de buscar fallos en el diseño y codigo
- Asignar recursos a cada integrante para avanzar de forma eficaz y equitativa el proyecto

### De Trabajo en Equipo
- Comunicación: Poder dar opiniones y escuchar las demas al momento de querer mejorar el proyecto 
- Compromiso: Poder tomar conciencia e iniciativa al querer hacer el proyecto no solo por requerimiento
