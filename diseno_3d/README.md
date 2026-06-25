# Diseño 3D - Documentación

## ⚠️ REQUISITO CRÍTICO

El modelo 3D debe incluir **TODOS** los componentes del prototipo:
- ✅ Encapsulado exterior completo
- ✅ Placa ESP32/Arduino (con dimensiones exactas)
- ✅ Todos los sensores en posición de instalación
- ✅ Todos los actuadores
- ✅ Batería / fuente de alimentación
- ✅ Cableado (routing aproximado)
- ✅ Sistema de montaje (brackets, tornillos)
- ✅ Orificios de ventilación (si aplica)

**NO ES ACEPTABLE:** Solo el encapsulado vacío sin componentes internos

---

## Carpetas

#### `fusion360/`
Archivos nativos de Fusion 360 (.f3d)

#### `renders/`
Imágenes renderizadas de alta calidad

#### `planos/`
Planos técnicos con cotas

---

## Especificaciones

**Software:** Autodesk Fusion 360  
**Unidades:** Milímetros (mm)  
**Escala:** 1:1 (dimensiones reales)

**Dimensiones externas:** [148 mm × 71 mm × 139 mm]  
**Peso estimado:** [400 gramos]  
**Material:** [PLA]

---

## Consideraciones de Diseño

### Funcionales
- [x] Acceso a puertos USB/alimentación
- [x] Ventilación adecuada
- [x] Protección de componentes
- [x] Fácil acceso para mantenimiento
- [ ] Resistencia a condiciones ambientales

### Fabricación
- [x] Imprimible sin soportes excesivos
- [x] Tolerancias de ensamble (+0.2mm)
- [x] Grosor de pared mínimo 2mm
- [x] Sin ángulos imposibles (overhangs <45°)

---

## Configuración de Impresión 3D (si fue utilizada)

**Impresora:** Impresora 3D DEC UAI 
**Material:** [PLA]  
**Calidad de capa:** 0.2mm  
**Relleno:** 15%  
**Soportes:** [Sí] - En cada agujero, partes donde se ubica el sensor 
**Temperatura nozzle:** [°C] 200
**Temperatura cama:** [°C]  50
**Velocidad:** [45 mm/s]

**Tiempo estimado de impresión:** [18 horas]  
**Peso de material:** [230 gramos]
