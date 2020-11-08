/*
 * @Author: Wind-Gone Hu 
 * @Date: 2020-08-13 15:39:33 
 * @Last Modified by: Wind-Gone Hu
 * @Last Modified time: 2020-08-13 16:52:44
 */
#include <MsTimer2.h>
#include "interface.h"
void flash() //中断处理函数，改变灯的状态
{
    static boolean output = HIGH;
    digitalWrite(led_1, output);
    output = !output;
}

const int threshold = 200;
void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(leftMotor1_1, OUTPUT);
    pinMode(leftMotor1_2, OUTPUT);
    pinMode(leftMotor2_1, OUTPUT);
    pinMode(leftMotor2_2, OUTPUT);
    pinMode(rightMotor1_1, OUTPUT);
    pinMode(rightMotor1_2, OUTPUT);
    pinMode(rightMotor2_1, OUTPUT);
    pinMode(rightMotor2_2, OUTPUT);
    pinMode(led_2, OUTPUT);
    pinMode(led_1, OUTPUT);
    pinMode(led_3, OUTPUT);
    pinMode(alarm, OUTPUT);
    pinMode(trac1, INPUT);
    pinMode(trac2, INPUT);
    pinMode(trac3, INPUT);
    pinMode(trac4, INPUT);
}

void loop()
{
    if (Serial.available() > 0) // 蓝牙判断行驶情况
    {
        char c = Serial.read();
        switch (c)
        {
        case '1':
            n = analogRead(A0);
            if (n <= threshold) //对光线强度进行判断，小于预设值关闭LED,否则就点亮
            {
                digitalWrite(led_3, HIGH);
            }
            else
            {
                digitalWrite(led_3, LOW);
            }
            tracing_forward();
            break;
        case '2':
            tracing_back();
            break;
        case '3':
            tracing_back();
            MsTimer2::set(500, flash); // 中断设置函数，每 500ms 进入一次中断
            MsTimer2::start();         //开始计时
            break;
        case '0':
            digitalWrite(led_1, LOW);
            digitalWrite(led_2, LOW);
            break;
        default:
            digitalWrite(led_1, LOW);
            digitalWrite(led_2, LOW);
            ;
        }
    }
}
//前进
void motor_forword()
{
    Serial.println("FORWARD"); //输出状态
    digitalWrite(leftMotor1_1, HIGH);
    digitalWrite(leftMotor1_2, LOW);
    digitalWrite(leftMotor2_1, HIGH);
    digitalWrite(leftMotor2_2, LOW);
    digitalWrite(rightMotor1_1, HIGH);
    digitalWrite(rightMotor1_2, LOW);
    digitalWrite(rightMotor2_1, HIGH);
    digitalWrite(rightMotor2_2, LOW);
    delay(1);
    digitalWrite(leftMotor1_1, LOW);
    digitalWrite(leftMotor1_2, LOW);
    digitalWrite(leftMotor2_1, LOW);
    digitalWrite(leftMotor2_2, LOW);
    digitalWrite(rightMotor1_1, LOW);
    digitalWrite(rightMotor1_2, LOW);
    digitalWrite(rightMotor2_1, LOW);
    digitalWrite(rightMotor2_2, LOW);
    delay(9);
}
//后退
void motor_backward()
{
    Serial.println("BACKWARD"); //输出状态
    digitalWrite(leftMotor1_1, LOW);
    digitalWrite(leftMotor1_2, HIGH);
    digitalWrite(leftMotor2_1, LOW);
    digitalWrite(leftMotor2_2, HIGH);
    digitalWrite(rightMotor1_1, LOW);
    digitalWrite(rightMotor1_2, HIGH);
    digitalWrite(rightMotor2_1, LOW);
    digitalWrite(rightMotor2_2, HIGH);
    delay(2);
    digitalWrite(leftMotor1_1, LOW);
    digitalWrite(leftMotor1_2, LOW);
    digitalWrite(leftMotor2_1, LOW);
    digitalWrite(leftMotor2_2, LOW);
    digitalWrite(rightMotor1_1, LOW);
    digitalWrite(rightMotor1_2, LOW);
    digitalWrite(rightMotor2_1, LOW);
    digitalWrite(rightMotor2_2, LOW);
    delay(8);
}
//前进左转
void motor_left_fo()
{
    Serial.println("TURN  LEFT"); //输出状态
    digitalWrite(leftMotor1_1, LOW);
    digitalWrite(leftMotor1_2, LOW);
    digitalWrite(leftMotor2_1, LOW);
    digitalWrite(leftMotor2_2, LOW);
    digitalWrite(rightMotor1_1, HIGH);
    digitalWrite(rightMotor1_2, LOW);
    digitalWrite(rightMotor2_1, HIGH);
    digitalWrite(rightMotor2_2, LOW);
    delay(8);
    digitalWrite(leftMotor1_1, LOW);
    digitalWrite(leftMotor1_2, LOW);
    digitalWrite(leftMotor2_1, LOW);
    digitalWrite(leftMotor2_2, LOW);
    digitalWrite(rightMotor1_1, LOW);
    digitalWrite(rightMotor1_2, LOW);
    digitalWrite(rightMotor2_1, LOW);
    digitalWrite(rightMotor2_2, LOW);
    delay(2);
    digitalWrite(led_1, HIGH);
}
//前进右转
void motor_right_fo()
{
    Serial.println("TURN  RIGHT"); //输出状态
    digitalWrite(leftMotor1_1, HIGH);
    digitalWrite(leftMotor1_2, LOW);
    digitalWrite(leftMotor2_1, HIGH);
    digitalWrite(leftMotor2_2, LOW);
    digitalWrite(rightMotor1_1, LOW);
    digitalWrite(rightMotor1_2, LOW);
    digitalWrite(rightMotor2_1, LOW);
    digitalWrite(rightMotor2_2, LOW);
    delay(8);
    digitalWrite(leftMotor1_1, LOW);
    digitalWrite(leftMotor1_2, LOW);
    digitalWrite(leftMotor2_1, LOW);
    digitalWrite(leftMotor2_2, LOW);
    digitalWrite(rightMotor1_1, LOW);
    digitalWrite(rightMotor1_2, LOW);
    digitalWrite(rightMotor2_1, LOW);
    digitalWrite(rightMotor2_2, LOW);
    delay(2);
}
//后退右转
void motor_right_ba()
{
    Serial.println("TURN  RIGHT"); //输出状态
    digitalWrite(leftMotor1_1, LOW);
    digitalWrite(leftMotor1_2, HIGH);
    digitalWrite(leftMotor2_1, LOW);
    digitalWrite(leftMotor2_2, HIGH);
    digitalWrite(rightMotor1_1, LOW);
    digitalWrite(rightMotor1_2, LOW);
    digitalWrite(rightMotor2_1, LOW);
    digitalWrite(rightMotor2_2, LOW);
    delay(8);
    digitalWrite(leftMotor1_1, LOW);
    digitalWrite(leftMotor1_2, LOW);
    digitalWrite(leftMotor2_1, LOW);
    digitalWrite(leftMotor2_2, LOW);
    digitalWrite(rightMotor1_1, LOW);
    digitalWrite(rightMotor1_2, LOW);
    digitalWrite(rightMotor2_1, LOW);
    digitalWrite(rightMotor2_2, LOW);
    delay(2);
}

//后退左转
void motor_left_ba()
{
    Serial.println("TURN  LEFT"); //输出状态
    digitalWrite(leftMotor1_1, LOW);
    digitalWrite(leftMotor1_2, LOW);
    digitalWrite(leftMotor2_1, LOW);
    digitalWrite(leftMotor2_2, LOW);
    digitalWrite(rightMotor1_1, LOW);
    digitalWrite(rightMotor1_2, HIGH);
    digitalWrite(rightMotor2_1, LOW);
    digitalWrite(rightMotor2_2, HIGH);
    delay(8);
    digitalWrite(leftMotor1_1, LOW);
    digitalWrite(leftMotor1_2, LOW);
    digitalWrite(leftMotor2_1, LOW);
    digitalWrite(leftMotor2_2, LOW);
    digitalWrite(rightMotor1_1, LOW);
    digitalWrite(rightMotor1_2, LOW);
    digitalWrite(rightMotor2_1, LOW);
    digitalWrite(rightMotor2_2, LOW);
    delay(2);
    digitalWrite(led_1, HIGH);
}
//停止
void motor_stop()
{
    Serial.println("STOP"); //输出状态
    digitalWrite(leftMotor1_1, LOW);
    digitalWrite(leftMotor1_2, LOW);
    digitalWrite(leftMotor2_1, LOW);
    digitalWrite(leftMotor2_2, LOW);
    digitalWrite(rightMotor1_1, LOW);
    digitalWrite(rightMotor1_2, LOW);
    digitalWrite(rightMotor2_1, LOW);
    digitalWrite(rightMotor2_2, LOW);
}

//驱动车辆行驶
void motorRun(int cmd)
{
    switch (cmd)
    {
    case FORWARD:
        motor_forword();
        break;

    case BACKWARD:
        motor_backward();
        break;

    case TURNLEFT_FO:
        motor_left_fo();
        break;

    case TURNRIGHT_FO:
        motor_right_fo();
        break;
    case TURNLEFT_BA:
        motor_left_ba();
        break;

    case TURNRIGHT_BA:
        motor_right_ba();
        break;
    default:
        motor_stop();
    }
}

void tracing_forward()
{
    int barrier = analogRead(trac4);
    Serial.println(barrier);
    int data[3];
    data[0] = digitalRead(trac1);
    data[1] = digitalRead(trac2);
    data[2] = digitalRead(trac3);
    if (barrier >= 500) //如果检测到障碍物车辆
    {
        if (!data[0] && data[1] && !data[2]) //左右都没有检测到黑线
        {
            motorRun(FORWARD);
            Serial.println(1);
            digitalWrite(led_1, LOW);
            digitalWrite(led_2, LOW);
        }

        if (data[1] || data[2]) //右边检测到黑线
        {
            motorRun(TURNRIGHT_FO);
            digitalWrite(led_1, HIGH);
            digitalWrite(led_2, LOW);
            Serial.println(2);
        }

        if (data[0] || data[1]) //左边检测到黑线
        {
            motorRun(TURNLEFT_FO);
            digitalWrite(led_2, HIGH);
            digitalWrite(led_1, LOW);
            Serial.println(3);
        }

        else if (data[0] && data[2]) //左右都检测到黑线是停止
        {
            motorRun(STOP);
            Serial.println(4);
            digitalWrite(led_1, HIGH);
            digitalWrite(led_2, HIGH);
            delay(300);
        }
        else
        {
            Serial.println(5);
            motorRun(STOP);
            digitalWrite(led_1, HIGH);
            digitalWrite(led_2, HIGH);
        }

        Serial.print(data[0]);
        Serial.print("---");
        Serial.print(data[1]);
        Serial.print("---");
        Serial.print(data[2]);
        Serial.print("---");
        Serial.println(data[3]);
    }
    else
    {
        motorRun(STOP);
        for (int i = 0; i < 80; i++) //输出一个频率的声音，周期2ms，f=500Hz
        {
            digitalWrite(alarm, HIGH); //发声音
            delay(1);                  //保持 1ms
            digitalWrite(alarm, LOW);  //不发声音
            delay(1);
        }
        for (int i = 0; i < 100; i++) //输出另一个频率的声音，周期4ms，f=250Hz
        {
            digitalWrite(alarm, HIGH); //发声音
            delay(2);                  // 2ms
            digitalWrite(alarm, LOW);  //不发声音
            delay(2);                  //延时 2ms
        }
        Serial.println(6);

        digitalWrite(led_1, HIGH);
        digitalWrite(led_2, HIGH);
    }
}

void tracing_back()
{
    int data[3];
    data[0] = digitalRead(trac1);
    data[1] = digitalRead(trac2);
    data[2] = digitalRead(trac3);
    // data[3] = digitalRead(12);

    if (data[0] && data[2]) //左右都检测到黑线是停止
    {
        motorRun(STOP);
        Serial.println(4);
        digitalWrite(led_1, HIGH);
        digitalWrite(led_2, HIGH);
    }
    else{
      if (!data[0] && data[1] && !data[2]) //左右都没有检测到黑线
    {
        motorRun(BACKWARD);
        Serial.println(1);
        digitalWrite(led_1, LOW);
        digitalWrite(led_2, LOW);
    }

    if (data[1] || data[2] && !data[0]) //右边检测到黑线
    {
        motorRun(TURNRIGHT_BA);
        digitalWrite(led_1, HIGH);
        digitalWrite(led_2, LOW);
        Serial.println(2);
    }

    if (data[0] || data[1] &&!data[2]) //左边检测到黑线
    {
        motorRun(TURNLEFT_BA);
        digitalWrite(led_2, HIGH);
        digitalWrite(led_1, LOW);
        Serial.println(3);
    }
    }
    Serial.print(data[0]);
    Serial.print("---");
    Serial.print(data[1]);
    Serial.print("---");
    Serial.print(data[2]);
    Serial.print("---");
    Serial.println(data[3]);
}