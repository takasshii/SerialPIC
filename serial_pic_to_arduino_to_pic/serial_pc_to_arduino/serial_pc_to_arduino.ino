#define NUMBER 30 
const int LED_PIN = 13;

char input;
int i = 0;  // 文字数のカウンタ

void setup() {
  int signal_speed = 9600;
  Serial.begin(signal_speed);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
    if(Serial.available() > 0) {
      input = Serial.read();
      Serial.println(input);
    }
}
