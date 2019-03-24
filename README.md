# Seguidor de línea activado por sonido (Arduinos)

Santiago Bermúdez
John Alexander Torres

El proyecto consta de un vehículo controlado por un sistema empotrado distribuido, en el cual, con una placa Arduino Uno (integrada con un ATmega328P) se muestran los estados del vehículo mediante Leds, el primer estado es estático y con leds de stop encendidos; una vez emitido un sonido fuerte que sobrepase el umbral preestablecido en el sensor de sonido KY-038, la placa libera la señal para activar los leds de funcionamiento del vehículo (segundo estado) y para iniciar el bucle de la segunda placa Arduino Uno (estas 2 placas están conectadas mediante I2C), la cual controla el módulo PWM y la salida de los motores conectados a la misma y al controlador L298N, esta placa también recibe la señal de los sensores ópticos TRCT5000 con los cuales se leerá el valor de cambio para efectuar seguiminento de línea mediante la señal infraroja emitida por los sensores; recibiendo el estado de cada sensor se controlará mediante la segunda placa la velocidad de los motores y el sentido de giro de los mismos para efectuar el seguimiento de línea.

Se contará con 2 motores DC de 6V con caja reductora para controlar el sentido de giro de las ruedas en la versión inicial, pues el sistema mecánico será operado por 2 ruedas que controlarán la tracción y una rueda "loca" para darle estabilidad al vehículo.

Con esto se pretende manipular el módulo PWM, I2C y la lectura y escritura de datos analógicos y digitales mediante los pines y las funciones correspondientes así como el manejo adecuado de la etapa de potencia requerida para el funcionamiento del proyecto.

Como resumen se contará con 		

Sensor óptico	TCRT5000 X 2
Controlador motores	L298N	X 1
Potencia	Pilas 1.5V	X 4
Motores	DC (con caja reductora) 6V	X 2
Microcontroladores	Arduino Uno (ATmega328P)	X 2
Sensor de sonido	KY-038 o KY-037 o LM393	X 1
Resistencias varias
Leds varios
Ruedas X 2
Cables varios
Rueda loca o de mouse	x 1
