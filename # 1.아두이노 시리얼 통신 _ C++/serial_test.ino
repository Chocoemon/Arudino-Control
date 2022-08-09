#include <SoftwareSerial.h> 
// 명령을 보내는 Master 부분의 코드  (uno에 업로드 )
// # 1. 프로그램에서 받은 명령을 TX/RX 부분으로 쪼개어 명령을 내림 
// # 2. C++ 프로그램에서 명령만 받아 처리하므로 Serial Read/Write 코드만 존재함. 
int count = 0;
SoftwareSerial test(7,8); // RX,TX
void setup() {

  Serial.begin(57600);
  test.begin(57600);
  //pinMode(13,OUTPUT);
}
void loop() {
  
  // Serial과 test에서 명령주고 받는걸 좀 구분을 해야함.
  // Serial : 컴퓨터와 TX/RX하는데 사용함 
  // Test: slave 보드와 TX/RX하는데 사용함 
    if(test.available())
    {
        String str;
        char* buf;
        str = test.readStringUntil('\n');
        buf = (char*) malloc(sizeof(char)*str.length()+1);
        buf[str.length()+1] = '\n';
        str.toCharArray(buf,str.length()+2);
        Serial.write(buf);
        test.flush();
        free(buf);
    }

    if(Serial.available()){
      String str;
      char* buf;
      str = Serial.readStringUntil('\n');
      buf = (char*) malloc(sizeof(char)*str.length()+1);
      buf[str.length()+1] = '\n';
      str.toCharArray(buf,str.length()+2);
      test.write(buf);
      free(buf);
      Serial.flush();
    }

}


