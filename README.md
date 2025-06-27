#  Proyecto: Levitación de Pelota con Control PID

Este proyecto consiste en controlar la posición de una pelota de ping pong suspendida en el aire mediante un flujo de aire generado por un ventilador, todo controlado con un sistema PID implementado en un Arduino UNO.

## Componentes Principales

- Arduino UNO
- Sensor ultrasónico HC-SR04
- MOSFET IRLZ44N (o equivalente)
- Motor de aspiradora 7.4 V
- Batería de 7.4 V de ion-litio (son dos celdas 18650)
- Diodo 1N4001 (flyback)
- Resistencia de 220 Ω (Gate)
- Resistencia de 10k Ω (pull-down)

## ¿Cómo funciona?

- El sensor ultrasónico mide la distancia entre el emisor y la pelota.
- El Arduino lee esa distancia y la compara con un **setpoint** deseado.
- Con esa diferencia, calcula una señal de control usando un **algoritmo PID**.
- Esa señal regula el **PWM** que controla la velocidad del ventilador.
- Así, se ajusta el flujo de aire hasta mantener la pelota en equilibrio.


Si deseas contactarme para más detalles, puedes hacerlo a través de mi correo.You can ask for more details here:
**Benjamín C.**  
bcollao.17@gmail.com  
Ingeniería Civil Eléctrica – PUCV  
