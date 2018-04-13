void setup() {
  Serial.begin(9600);   // inicilaizando o serial
}

void loop() {

  int sensorValue = analogRead(A0);   // leitura da porta analogica no pino A0
  Serial.println(sensorValue);   // Plotar o valor da leitura no serial

}
