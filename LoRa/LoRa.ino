// #include <LoRa.h>
// #include <SPI.h>
#include <SoftwareSerial.h> //Rx, Tx에 연결된 모듈과 UART 통신

//SoftwareSerial(Rx, Tx)
SoftwareSerial lora(2, 3);

void setup() {
  Serial.begin(9600);
  lora.begin(9600);
}

void loop() {
  //송신 코드
  while (Serial.available() < 1);
  while (Serial.available() > 0){
    char data;
    data = Serial.read();
    lora.write(data) //데이터를 가공하지 않고 1바이트씩 보냄
    // lora.println("Hello, Lora!\n") //문자열 형태로 데이터를 보냄
  }
  
  //수신 코드
  while (lora.available() < 1);
  while (lora.available() > 0){
    char data;
    data = lora.read();
    Serial.write(data); 
  }

}
