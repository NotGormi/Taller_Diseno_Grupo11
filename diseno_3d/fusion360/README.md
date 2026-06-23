# Archivos Fusion 360

## Archivos Requeridos

### `modelo_completo_v3.f3d`
Archivo principal con **historial de cambios completo**

**DEBE INCLUIR:**
-  Todos los componentes modelados
-  Ensamble completo funcional
-  Historial de diseño (timeline)
-  Materiales asignados
-  Constraints y relaciones

---

## Estructura del Modelo

### Componentes (Components)
```
Ensamble_Principal
├── Encapsulado_Lateral
├── Encapsulado_Inferior
├── Encapsulado_Superior
├── Soporte_Bateria
├── Bracket_Montaje
└── Tornilleria
```

### Uniones (Joints)
Documentar las juntas principales y sus restricciones

### Parámetros
Listar parámetros principales utilizados:
- `ancho_total = 146mm`
- `largo_total = 71mm`
- `alto_total = 139mm`
- `grosor_pared = 3mm`

---

## Instrucciones de Apertura

1. Abrir Fusion 360
2. File > Open > Seleccionar archivo `.f3d`
3. Verificar que todas las referencias están cargadas
4. Revisar timeline para ver historial

---

## Versiones

| Versión | Fecha | Cambios Principales |
|---------|-------|---------------------|
| v3.2 | [15/06] | Versión final para Avance #3 |
| v3.0 | [11/06] | Diseño final para avance #3 |
| v2.0 | [29/04] | Ajustes post Avance #2 |
| v1.0 | [27/04] | Primera versión funcional |

---
