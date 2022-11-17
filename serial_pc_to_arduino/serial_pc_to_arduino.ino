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
    Serial.println("1");
    delay(1000);
    Serial.println("2");
    delay(800);
    Serial.println("3");
    delay(600);
    Serial.println("4");
    delay(400);
    Serial.println("5");
    delay(200);
}
