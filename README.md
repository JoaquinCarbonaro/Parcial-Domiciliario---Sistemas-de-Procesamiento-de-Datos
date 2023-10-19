# Parcial domiciliario Sistemas de procesamiento de datos

## Parte 1: Contador de 0 a 99 con Display 7 Segmentos y Multiplexación

En este proyecto, diseñaremos un contador que mostrará números del 0 al 99 utilizando dos displays de 7 segmentos. Implementaremos la técnica de multiplexación para mostrar los dígitos en los displays. El contador comenzará en 0 y se podrá incrementar o disminuir su valor en una unidad con los botones.

### [Enlace al Código Completo en GitHub](Codigos/PARCIAL_1.ino)

### [Diagrama del circuito]
![Parcial - parte 1](https://github.com/JoaquinCarbonaro/Parcial-Domiciliario---Sistemas-de-Procesamiento-de-Datos/assets/138243106/413d6e88-8311-4a59-b67a-fd21a6e597aa)

### [Enlace al Tinkercad](https://www.tinkercad.com/things/hrGVLN8B6LW?sharecode=PC-VvIu_ZNJLlBZ--qM-jlJU69PQQDTH0EQK0xCnVuY)

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

### [Enlace al Tinkercad](https://www.tinkercad.com/things/gqt8yuNMQOl?sharecode=y7BFKrL1nRMAzB9MEoOFC1rRHISnKEwi0l4D8h9NfqE)

### Modificaciones Realizadas

1. **Interruptor Deslizante**: Se ha sustituido uno de los botones por un interruptor deslizante de dos posiciones. Dependiendo de la posición del interruptor, el display mostrará o bien el contador (como en la "Parte 1") o los números primos en el rango de 0 a 99. Esto se ha logrado mediante una lógica de selección en el código que interpreta la posición del interruptor y actúa en consecuencia.

2. **Números Primos**: Se ha añadido una funcionalidad que permite mostrar los números primos en el rango de 0 a 99 cuando el interruptor está en la posición correspondiente. Esto implica una verificación de los números primos en el rango y su visualización en el display de 7 segmentos.

### Componente Electrónico Adicional: Motor de Aficionado

- **Descripción del Componente**: En el contexto de Arduino, un motor de aficionado o ventilador es un componente fundamental que se utiliza para generar flujo de aire o dirección del mismo. En este proyecto, el motor de aficionado se incorpora con el propósito de controlar la temperatura en un entorno específico, lo que contribuye al enfriamiento automático del área de interés.

- **Función en el Proyecto**: La función principal del motor de aficionado en el proyecto es contribuir al control térmico del entorno. Cuando el sensor de temperatura detecta que la temperatura supera un umbral específico (40 grados Celsius), el motor se activa automáticamente, generando un flujo de aire que enfría el ambiente. Esto responde eficazmente a las variaciones de temperatura, mejorando la comodidad y la eficiencia del control térmico.

- **Integración en el Proyecto**: La integración del motor de aficionado en el proyecto se logra mediante su conexión a uno de los pines de salida de Arduino. Esto permite al código del proyecto controlar el encendido y apagado del motor según las condiciones específicas. Cuando la temperatura supera el umbral deseado, el código envía una señal para activar el motor de aficionado. A medida que la temperatura desciende por debajo del umbral, el código ordena que el motor se apague. Esta integración garantiza un control térmico automático y eficiente del entorno, convirtiéndolo en un componente esencial para el proyecto.

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

### [Enlace al Tinkercad](https://www.tinkercad.com/things/1kcFMUMwZow?sharecode=YfPrn3V1Vb7Oc8URLYrZ61pZWq-JI8p_rUbiVfFyi3A)

### Modificaciones Realizadas

#### Componente Adicional: Fotoresistencia

- **Descripción del Componente**: La fotoresistencia, también conocida como LDR (Light Dependent Resistor), es un componente electrónico que exhibe una variación en su resistencia en función de la cantidad de luz que incide sobre él. Su resistencia disminuye en presencia de una iluminación intensa y aumenta en la oscuridad. Este componente se clasifica como un sensor y se utiliza comúnmente para detectar la intensidad lumínica en su entorno.

- **Función en el Proyecto**: En el contexto de este proyecto, la fotoresistencia desempeña un papel crucial. Está conectada al pin A0 del Arduino y se emplea para medir la intensidad de luz ambiente. La lectura de la fotoresistencia se mapea a un valor de brillo que controla la intensidad del LED rojo conectado al pin 5. En otras palabras, la luminosidad del LED rojo varía en función de la cantidad de luz presente en el entorno. Además, cuando la temperatura supera un umbral definido, el LED rojo se enciende con una intensidad que depende de la lectura de la fotoresistencia. Esto proporciona una indicación visual de la intensidad lumínica en situaciones de alta temperatura.

- **Integración en el Proyecto**: La fotoresistencia se encuentra íntimamente integrada en el proyecto y se vincula tanto al control de luz como al control de temperatura. Esta integración permite regular la intensidad del LED rojo con base en la luz ambiental y la temperatura medida. Este enfoque resulta beneficioso en una variedad de aplicaciones, como sistemas de control ambiental y sistemas de monitoreo que requieren una retroalimentación visual basada en la intensidad lumínica y la temperatura.


### Autor
- Carbonaro Joaquin
