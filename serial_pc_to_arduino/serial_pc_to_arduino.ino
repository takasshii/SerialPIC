#define NUMBER 20 

char input[NUMBER];   // 文字列格納 PICのメモリの制限から20文字
int i = 0;  // 文字数のカウンタ

void setup() {
  int signal_speed = 9600;
  Serial.begin(signal_speed);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  if(Serial.available()>0){
    input[i] = Serial.read();
    // 20文字以上なら一旦出力する
    if (i > NUMBER - 1) {
      input[i+1] = '\0';
      Serial.write(input);
      Serial.write("\n");
      i = 0;
    } else { 
      i++; 
    }
 }
}
