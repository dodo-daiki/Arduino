#ifndef _MOTOR_CONTROL_
#define _MOTOR_CONTROL_

class MotorControl {
    private:
        float MotorAngle[4];
        const float basis = 1.00;
        float MaxRatio = 0.00;
        float MotorRatio[4];
    public:
        MotorControl(float M1,float M2,float M3,float M4);
        void ctl(int speed,float theta,float alpha,int omega);
        int MotorOut[4]; //出力値の配列
       

};

MotorControl::MotorControl(float M1,float M2,float M3,float M4) { //引数をpublic変数に代入
    MotorAngle[0] = M1;
    MotorAngle[1] = M2;
    MotorAngle[2] = M3;
    MotorAngle[3] = M4;
}

void MotorControl::ctl(int speed,float theta,float alpha,int omega) { //出力値を計算(速さ,フィールド座標系上の目標角,機体座標系とフィールド座標系のずれの角度、角速度)
    for (int i=0;i < 4;i++) {
        MotorRatio[i] = sin((theta + alpha + MotorAngle[i] +90) * PI/180) *basis;   //出力の比率を計算
        if(MotorRatio[i] > MaxRatio) MaxRatio = MotorOut[i];                        //最大値を算出
    }

    for(int i=0;i < 4;i++) {
        MotorOut[i] = speed * MotorRatio[i] / MaxRatio *basis + omega; //出力値の計算
    } 
}

#endif