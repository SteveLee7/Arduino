void setup() {

  Serial.begin(9600); /* PC모니터로 결과를 쉽게 확인하기위해

                          시리얼 통신을 정의해 줍니다.

                         */
}

void loop() {



  Serial.println(analogRead(A0));  //조도센서의 감지되는 광량을 출력합니다. photo sensor





  delay(500);



}

