# Parcial domiciliario Sistemas de procesamiento de datos

## Parte 1: Contador de 0 a 99 con Display 7 Segmentos y Multiplexación

En este proyecto, diseñaremos un contador que mostrará números del 0 al 99 utilizando dos displays de 7 segmentos. Implementaremos la técnica de multiplexación para mostrar los dígitos en los displays. El contador comenzará en 0 y se podrá incrementar o disminuir su valor en una unidad con los botones.

### [Enlace al Código Completo en GitHub](Codigos/PARCIAL_1.ino)
### [Diagrama del circuito](Imagenes/Parcial - parte 1.jpg)

### Multiplexación
En este proyecto, la multiplexación se ha implementado con precisión para controlar los displays de 7 segmentos de manera eficiente. La técnica de multiplexación permite mostrar los dígitos de las unidades y decenas en los dos displays "UNIDAD" y "DECENA" alternativamente, a una velocidad lo suficientemente rápida para crear la ilusión de que ambos están encendidos al mismo tiempo. Este enfoque optimiza el uso de recursos y garantiza un funcionamiento suave y sin parpadeos.

La secuencia de multiplexación se ejecuta mediante la función `digitoEncendido()`, que alterna entre los dos displays de acuerdo con el valor de los dígitos a mostrar. La combinación de la rápida conmutación entre los displays y la configuración de los segmentos de 7 segmentos garantiza una visualización clara y coherente de los números a medida que el contador avanza.

La multiplexación es una técnica esencial en este proyecto, ya que permite mostrar los dígitos de manera efectiva en displays compartidos sin requerir una gran cantidad de pines y componentes adicionales.

## Autor
- Carbonaro Joaquin



## Parte 2: Modificación con Interruptor Deslizante y Números Primos

En esta parte del proyecto, se realizarán modificaciones al proyecto de la "Parte 1" para incorporar un interruptor deslizante y mostrar números primos en el rango de 0 a 99 además del contador. Además, se investigará un componente electrónico adicional, el "Motor de Aficionado", que podría mejorar el proyecto.

### [Enlace al Código Completo en GitHub](Codigos/PARCIAL_2_.ino)

### Diagrama del circuito
![Parcial - parte 2](https://github.com/JoaquinCarbonaro/Parcial-Domiciliario---Sistemas-de-Procesamiento-de-Datos/assets/138243106/05cfec5d-a41e-46d2-a83b-56bbadf042af)

### Modificaciones Realizadas

1. **Interruptor Deslizante**: Se ha sustituido uno de los botones por un interruptor deslizante de dos posiciones. Dependiendo de la posición del interruptor, el display mostrará o bien el contador (como en la "Parte 1") o los números primos en el rango de 0 a 99. Esto se ha logrado mediante una lógica de selección en el código que interpreta la posición del interruptor y actúa en consecuencia.

2. **Números Primos**: Se ha añadido una funcionalidad que permite mostrar los números primos en el rango de 0 a 99 cuando el interruptor está en la posición correspondiente. Esto implica una verificación de los números primos en el rango y su visualización en el display de 7 segmentos.

### Componente Electrónico Adicional: Motor de Aficionado

- **Descripción del Componente**: El "Motor de Aficionado" es un componente electrónico utilizado para generar movimiento en proyectos electrónicos. Este motor puede controlarse para girar en diferentes direcciones y velocidades.

- **Función en el Proyecto**: El motor de aficionado se ha agregado al proyecto para crear una representación física del contador. Cuando el contador se incrementa o decrementa, el motor gira en consecuencia, proporcionando una representación visual y atractiva del proceso de conteo.

- **Integración en el Proyecto**: La integración del motor de aficionado ha requerido la adición de circuitos de control y programación en el código. Se han utilizado pines específicos para controlar la velocidad y dirección del motor. Esto agrega una dimensión física al proyecto, mejorando la experiencia del usuario.

### Componente Electrónico Adicional: Sensor de Temperatura TMP36

- **Descripción del Componente**: El "Sensor de Temperatura TMP36" es un componente electrónico ampliamente utilizado para medir la temperatura ambiente. Proporciona una señal de voltaje analógica proporcional a la temperatura en grados Celsius.

- **Función en el Proyecto**: El sensor de temperatura TMP36 se ha incorporado al proyecto para medir la temperatura ambiente. Cuando la temperatura supera un umbral específico (definido como `umbralTemperatura` en el código), el motor de aficionado se activa para enfriar o ventilar el entorno. Esta adición mejora la eficiencia y utilidad del proyecto al automatizar la gestión de la temperatura.

- **Integración en el Proyecto**: El sensor de temperatura se conecta a un pin analógico (en este caso, `SENSOR_TEMPERATURA`). La lectura del sensor se convierte en grados Celsius y se compara con el `umbralTemperatura` para decidir si se debe activar o desactivar el motor de aficionado.

### Autor
- Carbonaro Joaquin



## Parte 3: Modificación según el Último Número de Documento

En esta parte del proyecto, se realizarán modificaciones al proyecto de la "Parte 2" para incorporar un componente adicional que afecta el funcionamiento del proyecto basado en el último número de tu número de documento (DNI o documento de identidad). Se explicará en detalle qué hace este nuevo componente y cómo se integra en el proyecto.

### [Enlace al Código Completo en GitHub](Codigos/PARCIAL_3.ino)

### Diagrama del circuito
![Parcial - parte 3](https://github.com/JoaquinCarbonaro/Parcial-Domiciliario---Sistemas-de-Procesamiento-de-Datos/assets/138243106/2c39fb05-f3ae-4ad0-83cc-0a2f1d1419f1)

### Modificaciones Realizadas

#### Componente Adicional: Fotoresistencia

- **Descripción del Componente**: La "Fotoresistencia" (también conocida como LDR o Light-Dependent Resistor) es un componente que cambia su resistencia eléctrica en función de la intensidad de la luz incidente. Su resistencia disminuye con la luz intensa y aumenta en la oscuridad.

- **Función en el Proyecto**: La fotoresistencia se ha incorporado al proyecto para controlar la visualización en el display en función de la luz ambiente. Dependiendo de la luminosidad detectada por la fotoresistencia, el display mostrará el contador o los números primos. La detección de luz ambiental agrega una dimensión adicional de automatización al proyecto.

- **Integración en el Proyecto**: La fotoresistencia se conecta a un pin analógico y se lee periódicamente para determinar la luminosidad. Cuando la luz ambiental supera un umbral específico, el proyecto mostrará el contador en el display. Si la luminosidad desciende por debajo de ese umbral, el proyecto mostrará los números primos. Esto se logra mediante una lógica en el código que verifica la lectura de la fotoresistencia y decide qué información mostrar en el display.

### Lógica detrás de la Modificación

La modificación basada en el último número del DNI se logra mediante la inclusión de la fotoresistencia. La fotoresistencia detecta la luz ambiental y determina si se debe mostrar el contador o los números primos. La lógica en el código toma la lectura de la fotoresistencia y compara con un umbral predefinido. Si la luz supera el umbral, se muestra el contador; si desciende por debajo del umbral, se muestran los números primos. Esto permite una adaptación dinámica del proyecto según las condiciones de iluminación.

### Instrucciones

- Asegúrate de seguir las instrucciones detalladas en el repositorio de GitHub para construir y ejecutar la versión final del proyecto con la modificación basada en el último número de tu DNI.
- Documenta las modificaciones realizadas en el código y cómo funcionan, especialmente en lo que respecta a la integración de la fotoresistencia y la lógica de control basada en la luz ambiental.

### Contribución

Si deseas contribuir o mejorar el proyecto, puedes hacerlo mediante solicitudes de extracción en el repositorio de GitHub.

### Autor
- Carbonaro Joaquin
