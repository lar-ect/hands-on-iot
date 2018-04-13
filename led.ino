void setup() {
  // inicia o pino 13 como sendo a saída
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(13, HIGH);   // liga o LED (HIGH é o nivel de voltagem)
  delay(1000);              // espera por um segundo
  digitalWrite(13, LOW);    // desliga o LED fazendo a voltagem ficar LOW
  delay(1000);              // espera por um segundo
}
