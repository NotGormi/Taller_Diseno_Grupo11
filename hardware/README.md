# Hardware - Documentación

## Contenido
Esta carpeta contiene toda la documentación técnica del hardware del proyecto.

### 📁 Carpetas

#### `esquemas/`
Diagramas de circuitos y esquemáticos del sistema

#### `bom/`
Bill of Materials (Lista de materiales)

#### `fotos/`
Fotografías de alta resolución del prototipo ensamblado

---

## Instrucciones de Ensamble

### Componentes Principales
1. [ESP 8266] - Traducir los datos analógicos del sensor y mandarlos a una base de datos
2. [GUVA-S12SD] - Sensor que detecta radiación UV
3. [Shield and Battery 18650] - Alimentación eléctrica al circuito

### Pasos de Ensamblaje
1. Soldar los cables de GND y 3V en el battery shield
2. Afirmar los componentes ESP 8266 y el Shield a la cara posterior del encapsulado con pernos y tuercas
3. Afirmar el piso a la cara delantera del encapsulado con pegamento para plastico
4. Afirmar la cara delantera y posterior con tornillos o pernos y tuercas
5. Afirmar el techo a las dos caras con tornillos
6. Afirmar los enganches laterales a la cara posterior con 2 tornillos en cada enganche
7. Afirmar el encapsulado a una superficie con la ayuda de los 2 tornillos delanteros de los enganches, y la ayuda de 4 tornillos del cuerpo principal si fueron utilizados en el paso 4

### Precauciones
- ⚠️ Al soldar los cables al battery shield procurar que los estaños para cada cable no entren en contacto
- ⚠️ Procurar lijar bien cualquier superficie que sea impresa con soportes por la impresión 3d

---

## Especificaciones Técnicas

**Alimentación:** [3.3V y 3000 mAh]  
**Consumo:** [0.264Watts/80mA]  
**Dimensiones:** [148 mm x 71 mm x 139 mm]  
**Peso:** [417 gramos]

---

## Troubleshooting

| Problema | Posible Causa | Solución |
|----------|---------------|----------|
| Circuito no funciona | Contacto de estaño genera corto-circuito | Limpiar estaño y soldar sin que genere contacto |
| El encapsulado no encajan | Soportes por impresión 3d que ocupan espacio | Lijar la impresión en todas las secciones que tengan contacto con parte |
