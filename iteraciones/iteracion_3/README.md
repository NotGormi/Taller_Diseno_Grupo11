# Iteración 3 - Versión Final

## Información General

**Fecha:** [24/06/2025]  
**Versión:** v3.0  
**Estado:** Prototipo de alta resolución - Versión final  
**Avance asociado:** Avance #3

---

## Descripción

Versión final del prototipo, incorporando todas las mejoras y refinamientos basados en feedback de v2 y testing extensivo con usuarios. Sistema robusto, probado y listo para piloto en contexto real.

**Objetivos alcanzados:**
- Prototipo completamente funcional y robusto
- Encapsulado finalizado con todos los componentes
- Métricas de impacto ODS cuantificadas
- Sistema instalable en contexto urbano real

---

## Cambios Respecto a v2

### Hardware
**Mejoras implementadas:**
1. [Mejora 1] Uso de pernos y tornillos
   - Razón: Los componentes no se ubicaban en una posición firme
   - Impacto: Los componentes no se mueven adentro del encapsulado por lo que se protegen fisicamente

2. [Mejora 2] Divición entre cara posterior e inferior
   - Razón: Permite una mejor mantención de componentes internos y facilidad de manipular
   - Impacto: Hay un menor riesgo a que los componentes se dañen al momento de querer hacer una mantención

**Cambios finales:**
- Mediciones coerentes al contexto
- Menor consumo electrico del microprocesador

### Software
**Nuevas funcionalidades:**
- Base de datos
- Mediciones certeras

**Optimizaciones finales:**
- [Optimización de código]
- [Mejora de eficiencia]

**Manejo de errores:**
- Implementado manejo robusto de casos extremos
- Mensajes de error informativos
- Recuperación automática ante fallas menores

### Diseño Mecánico
**Encapsulado finalizado:**
- Diseño optimizado para impresión 3D
- Todos los componentes integrados
- Sistema de montaje robusto
- Accesibilidad para mantenimiento

---

## Fotos del Prototipo Final

Incluir en esta carpeta:
- `v3_prototipo_final_frontal.jpg`
- `v3_prototipo_final_posterior.jpg`
- `v3_interior_componentes.jpg`
- `v3_instalado_contexto.jpg`
- `v3_detalle_sensores.jpg`
- `v3_testing_usuarios.jpg` (múltiples)

---

## Resultados Finales

### Funcionalidad Completa
✅ [Todas las funciones planificadas]  
✅ Sistema opera sin intervención manual  
✅ Conectividad estable  
✅ Interfaz de usuario funcional  
✅ Manejo robusto de errores  

### Validación de Impacto ODS

**ODS Seleccionado:** [3 Salud y Bienestar]

**Métricas de impacto:**

1. Alumnos con conciencia climatica
   - Baseline (sin prototipo): [10]
   - Con prototipo: [17]
   - Mejora: [70%]

2. Alumnos con protector solar
   - Baseline: [5]
   - Con prototipo: [8]
   - Mejora: [60%]

**Proyección de impacto:**
Si se despliega a escala [UAI]:
- [Menor malestar y enfermedad cutanias]
- [Alumnos, profesores, y cuerpo medico]

---

## Comparación de las 3 Iteraciones

| Aspecto | v1 | v2 | v3 | Mejora Total |
|---------|----|----|----| -------------|
| **Sensores** | 2/3 | 3/3 | 3/3 | ✅ 100% |
| **Tiempo respuesta (ms)** | 500 | 200 | 100 | ↓ 80% |
| **Consumo (mA)** | 250 | 180 | 120 | ↓ 52% |
| **Tasa errores (%)** | 15 | 5 | 1 | ↓ 93% |
| **Encapsulado** | ❌ | Prototipo | Finalizado | ✅ |
| **Usuarios testeados** | 0 | 2 | 5+ | ✅ |
| **Satisfacción (1-5)** | - | 3.8 | 4.5 | ↑ 18% |
| **Impacto ODS validado** | ❌ | Parcial | ✅ Completo | ✅ |

---

## Fortalezas del Prototipo Final

1. Encapsulado Firme
   - Evidencia: Las partes del encapsulado no se separan al movimiento forzado

2. Datos analiticos
   - Evidencia: La base de datos permite tomar decisiones por horarios

3. Consumo pertinente
   - Evidencia: El encapsulado permite tomar datos por minimo 2 días sin mantenimiento 

---

## Limitaciones Identificadas

1. Fragil a material particulado
   - Descripción: Horificios para cargar y encender el shield 
   - Impacto: El contorno interior es sensible amaterial externo
   - Posible solución futura: Mejor encapsulado

2. No existe una advertencia inmediata
   - Descripción: Sin revisar la base de datos o el servidor, no se permite tomar decisiones frente a la radiación UV
   - Impacto: Estudiantes y personal que esta ocupado en el exterior sin celular no puede ver la información
   - Posible solución futura: Luz led que se prenda desde cierta intensidad

---

## Aprendizajes del Proceso Completo

### Técnicos
1. Optimización de consumo energetico en IoT
2. Procesamiento de señales analógicas y de calibración

### De Diseño
1. Analisis de dimensiones fisicas y volumetricas
2. Diseño orientado a una funcionalidad fisica

### De Trabajo en Equipo
1. Desarrollo conjunto entre estaciones
2. Estandarización de documentos

### De Gestión de Proyecto
1. Gestión de restricciones y costos marginales
2. Planificación temporal 

---

## Trabajo Futuro Recomendado

### Mejoras a Corto Plazo
- [ ] Optimización de encapsulado
- [ ] Refinamiento del algoritmo

### Mejoras a Mediano Plazo
- [ ] Integración de alerta fisica
- [ ] Rediseño de hardware para otros contextos

### Escalabilidad
- [ ] Automatización de impresion y armado
- [ ] Codigo abierto transparente
- [ ] Alianza estrategica con comite estudiantil

---

## Archivos en esta Carpeta

- `v3_codigo_final.ino` - Código final documentado
- `v3_esquema_final.png` - Esquema definitivo del circuito
- `v3_modelo3d_final.f3d` - Diseño 3D completo en Fusion 360
- `v3_fotos/` - Fotografías del prototipo final
- `v3_testing_completo.pdf` - Reporte de testing con usuarios
- `v3_comparativa_versiones.xlsx` - Datos comparativos v1-v2-v3
