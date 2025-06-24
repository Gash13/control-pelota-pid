const int pwmPin = 5; // Pin PWM conectado al ventilador
int currentSpeed = 0;

void setup() {
  Serial.begin(9600);
  pinMode(pwmPin, OUTPUT);
  analogWrite(pwmPin, currentSpeed);  // Valor inicial
  Serial.println("Ingresa un valor entre 0 y 255 para controlar la velocidad del ventilador:");
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    int speed = input.toInt();

    if (speed >= 0 && speed <= 255) {
      currentSpeed = speed;
      analogWrite(pwmPin, currentSpeed);
      Serial.print("Velocidad establecida en: ");
      Serial.println(currentSpeed);
    } else {
      Serial.println("Valor fuera de rango. Ingresa un número entre 0 y 255.");
    }
  }

  // Nada más en el loop, no se vuelve a escribir si no hay datos nuevos
}


