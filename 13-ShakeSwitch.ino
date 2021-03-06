/*
   ShakeSwitch
   中断检测振动传感器，控制LED灯亮灭
*/
int SensorLED = 9;       //定义LED为数字引脚8
int SensorINPUT = 2;      //连接震动开关到中断0，也就是数字引脚2
char state = LOW;

void setup() {

  pinMode(SensorLED, OUTPUT);         //LED为输出模式
  pinMode(SensorINPUT, INPUT_PULLUP);        //震动开关为输入模式

  //下降沿触发，触发中断0，调用blink函数
  attachInterrupt(0, blink, FALLING);
}

void loop() {

  if (state == HIGH) {        // 如果state为HIGH
    state = LOW;
    digitalWrite(SensorLED, HIGH);  // 亮灯
    delay(500);          //延时500ms
  }
  else {
    digitalWrite(SensorLED, LOW);    // 否则，关灯
  }
}
void blink() {               //中断函数blink()
  state = !state;             //一旦中断触发，state状态反转
}

