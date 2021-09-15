#include "motor_control.h"

MotorControl motor(45,135,225,315); //クラス関数の定義 MotorControl □□□(モーターの位置角)

void setup() {
  
}

void loop() {
  motor.ctl(0,0,0,0); // 出力値算出関数の呼び出し □□□.ctl(速さ,フィールド座標系上の目標角,機体座標系とフィールド座標系のずれの角度、角速度)
  
  //算出された値はint型のMotorOut[i](iは0~3,値は0~255)に格納される。
}

