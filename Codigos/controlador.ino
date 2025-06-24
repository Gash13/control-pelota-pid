%// Pines
const int trigPin = 9;
const int echoPin = 10;
const int motorPin = 3;

// Setpoint deseado
const float setpoint = 15.0;  // distancia en cm

// Variables PID
float input = 0;
float error = 0;
float lastError = 0;
float integral = 0;
float derivative = 0;
float output = 0;

// Constantes PID (ajustadas con prueba y error)
float Kp = 6.6;
float Ki = 1.9;
float Kd = 1.2;

unsigned long lastTime = 0;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motorPin, OUTPUT);
}

void loop() {
  // Medición distancia
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000);
  input = duration * 0.034 / 2.0;

  // PID simple
  unsigned long now = millis();
  float dt = (now - lastTime) / 1000.0;
  lastTime = now;

  error = input - setpoint;
  integral += error * dt;
  derivative = (error - lastError) / dt;
  output = Kp * error + Ki * integral + Kd * derivative;
  lastError = error;

  // Limitar PWM entre 0 y 255
  output = constrain(output, 0, 255);

  // Aplicar PWM al motor
  analogWrite(motorPin, (int)output);

  // Mostrar en Serial
  Serial.print("Distancia: ");
  Serial.print(input);
  Serial.print(" cm | PWM: ");
  Serial.println(output);

  delay(100);
}
