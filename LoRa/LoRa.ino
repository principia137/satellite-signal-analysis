// #include <LoRa.h>
// #include <SPI.h>
#include <SoftwareSerial.h> // Rx, Tx에 연결된 모듈과 UART 통신

SoftwareSerial lora(0, 1);// SoftwareSerial(Rx, Tx)
const char EN = 4;  // LoRa 모듈 활성화(Enable) 핀
const char AUX = 5; // 보조(Auxiliary) 핀 (코드에서는 사용되지 않음)

void setup() {
  Serial.begin(9600);
  lora.begin(9600);
  pinMode(EN, OUTPUT);
  digitalWrite(EN, LOW); // LOW:작동, HIGH:절전모드
}

void loop() {
  //송신 코드
  if (Serial.available()){
    String message_send;
    message_send = Serial.readStringUntil('\n');
    //lora.write(message_send) // 데이터를 가공하지 않고 1바이트씩 보냄
     lora.println(message_send); // 문자열 형태로 데이터를 보냄
     Serial.println("sent:"+message_send);
  }
  
  //수신 코드
  if (lora.available()){
    String message_recieved;
    message_recieved = lora.readStringUntil('\n');
    Serial.println(message_recieved); 
  }
}
