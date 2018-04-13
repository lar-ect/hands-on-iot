//Include da biblioteca das placas Esp
#include <ESP8266WiFi.h>  

//Definir o SSID da rede WiFi
const char* ssid = "NOME REDE";  //nome da rede
const char* password = "senha"; // senha da rede
 
//Colocar a API Key para escrita neste campo
//Ela é fornecida no canal que foi criado na aba API Keys
String apiKeyE = "PA4XARU64ERAGXYI";
const char* server = "api.thingspeak.com";
 
WiFiClient client;
 
void setup() {
  //Configuração da UART/USB para escita e leitura de dados no monitor
  Serial.begin(9600);
  //Inicia o WiFi
  WiFi.begin(ssid, password);
 
  //Espera a conexão
  //enquanto não conecta ele vai imprimir . a cada meio segundo 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connectedo!");
 
  //Logs na porta serial
  Serial.println("");
  Serial.print("Conectado na rede ");
  Serial.println(ssid);
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
}
 
void loop() {
 
  //Espera 20 segundos para fazer a leitura
  digitalWrite(LED_BUILTIN, HIGH);
  delay(20000);
  
  //Leitura LDR
  int sensorValue = analogRead(A0);   // leitura da porta analogica no pino A0

 
  //Inicia um client TCP para o envio dos dados
  if (client.connect(server,80)) {
    String postStr = apiKeyE;
           postStr +="&amp;field1=";
           postStr += String(sensorValue);
           postStr += "\r\n\r\n";
 
     client.print("POST /update HTTP/1.1\n");
     client.print("Host: api.thingspeak.com\n");
     client.print("Connection: close\n");
     client.print("X-THINGSPEAKAPIKEY: "+apiKeyE+"\n");
     client.print("Content-Type: application/x-www-form-urlencoded\n");
     client.print("Content-Length: ");
     client.print(postStr.length());
     client.print("\n\n");
     client.print(postStr);
 
     //Logs na porta serial
     Serial.print("LDR: ");
     Serial.println(sensorValue);
     
  }
  
  client.stop();
}
