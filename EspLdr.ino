void setup() {
  Serial.begin(9600);   // inicilaizando o serial
}

void loop() {

  int sensorValue = analogRead(A0);   // leitura da porta analogica no pino A0

  float voltage = sensorValue * (5.0 / 1023.0);   // converte a leitura para a voltagem sendo passda pelo resistor (which goes from 0 - 1023) to a voltage (0 - 3.3V)

  Serial.println(sensorValue);   // Plotar o valor da leitura no serial

}
