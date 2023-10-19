# Parcial domiciliario Sistemas de procesamiento de datos

## Parte 1: Contador de 0 a 99 con Display 7 Segmentos y Multiplexación

En este proyecto, diseñaremos un contador que mostrará números del 0 al 99 utilizando dos displays de 7 segmentos. Implementaremos la técnica de multiplexación para mostrar los dígitos en los displays. El contador comenzará en 0 y se podrá incrementar o disminuir su valor en una unidad con los botones.

### [Enlace al Código Completo en GitHub](enlace-a-tu-repositorio-con-el-codigo)

### Diagrama del circuito
![Parcial - parte 1](https://github.com/JoaquinCarbonaro/Parcial-Domiciliario---Sistemas-de-Procesamiento-de-Datos/assets/138243106/5b722cd4-4162-4fe8-aa45-89dd22b88ea7)

### Multiplexación
En este proyecto, la multiplexación se ha implementado con precisión para controlar los displays de 7 segmentos de manera eficiente. La técnica de multiplexación permite mostrar los dígitos de las unidades y decenas en los dos displays "UNIDAD" y "DECENA" alternativamente, a una velocidad lo suficientemente rápida para crear la ilusión de que ambos están encendidos al mismo tiempo. Este enfoque optimiza el uso de recursos y garantiza un funcionamiento suave y sin parpadeos.

La secuencia de multiplexación se ejecuta mediante la función `digitoEncendido()`, que alterna entre los dos displays de acuerdo con el valor de los dígitos a mostrar. La combinación de la rápida conmutación entre los displays y la configuración de los segmentos de 7 segmentos garantiza una visualización clara y coherente de los números a medida que el contador avanza.

La multiplexación es una técnica esencial en este proyecto, ya que permite mostrar los dígitos de manera efectiva en displays compartidos sin requerir una gran cantidad de pines y componentes adicionales.

## Autor
- Carbonaro Joaquin



## Parte 2: Modificación con Interruptor Deslizante y Números Primos

En esta parte del proyecto, se realizarán modificaciones al proyecto de la "Parte 1" para incorporar un interruptor deslizante y mostrar números primos en el rango de 0 a 99 además del contador. Además, se investigará un componente electrónico adicional, el "Motor de Aficionado", que podría mejorar el proyecto.

### [Enlace al Código Completo en GitHub](enlace-a-tu-repositorio-con-el-codigo)

### Diagrama del circuito
![Parcial - parte 2](https://github.com/JoaquinCarbonaro/Parcial-Domiciliario---Sistemas-de-Procesamiento-de-Datos/assets/138243106/05cfec5d-a41e-46d2-a83b-56bbadf042af)

### Modificaciones Realizadas

1. **Interruptor Deslizante**: Se ha sustituido uno de los botones por un interruptor deslizante de dos posiciones. Dependiendo de la posición del interruptor, el display mostrará o bien el contador (como en la "Parte 1") o los números primos en el rango de 0 a 99. Esto se ha logrado mediante una lógica de selección en el código que interpreta la posición del interruptor y actúa en consecuencia.

2. **Números Primos**: Se ha añadido una funcionalidad que permite mostrar los números primos en el rango de 0 a 99 cuando el interruptor está en la posición correspondiente. Esto implica una verificación de los números primos en el rango y su visualización en el display de 7 segmentos.

### Componente Electrónico Adicional: Motor de Aficionado

- **Descripción del Componente**: El "Motor de Aficionado" es un componente electrónico utilizado para generar movimiento en proyectos electrónicos. Este motor puede controlarse para girar en diferentes direcciones y velocidades.

- **Función en el Proyecto**: El motor de aficionado se ha agregado al proyecto para crear una representación física del contador. Cuando el contador se incrementa o decrementa, el motor gira en consecuencia, proporcionando una representación visual y atractiva del proceso de conteo.

- **Integración en el Proyecto**: La integración del motor de aficionado ha requerido la adición de circuitos de control y programación en el código. Se han utilizado pines específicos para controlar la velocidad y dirección del motor. Esto agrega una dimensión física al proyecto, mejorando la experiencia del usuario.


### Autor

- Carbonaro Joaquin








# Parte 2: Modificación con Interruptor Deslizante y Números Primos
Modifica el proyecto de la Parte 1 de la siguiente manera:
1. Sustituye uno de los botones por un interruptor deslizante (switch) de dos posiciones.
Dependiendo de la posición del interruptor, el display debe mostrar o bien el contador (como
en la Parte 1) o los números primos en el rango de 0 a 99.
2. Investiga un componente electrónico adicional que podría mejorar este proyecto.
Proporciona una descripción detallada del componente, su función y cómo se podría
integrar en el proyecto.
3.Investigar en la semana y agregar uno de los siguientes componentes:
-Sensor de flexión
-Sensor de fuerza
-Sensor de temperatura


# Parte 3: Modificación según el Último Número de Documento
Modifica el proyecto de la Parte 2 de la siguiente manera:
1. Considerando el último número de tu número de documento (DNI o documento de
identidad), agrega un componente adicional que afecte el funcionamiento del proyecto.
Describe en detalle qué hace este nuevo componente y cómo se integra en el proyecto.
-Si tu número de documento termina en (0-3) deberás implementar a tu proyecto la
fotoresistencia

![Parcial - parte 3](https://github.com/JoaquinCarbonaro/Parcial-Domiciliario---Sistemas-de-Procesamiento-de-Datos/assets/138243106/2c39fb05-f3ae-4ad0-83cc-0a2f1d1419f1)
