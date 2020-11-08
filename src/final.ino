/*
 * @Author: Wind-Gone Hu 
 * @Date: 2020-08-13 15:39:33 
 * @Last Modified by: Wind-Gone Hu
 * @Last Modified time: 2020-08-13 16:52:44
 */
#include <MsTimer2.h>
#include "interface.h"
void flash() //�жϴ��������ı�Ƶ�״̬
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
    if (Serial.available() > 0) // �����ж���ʻ���
    {
        char c = Serial.read();
        switch (c)
        {
        case '1':
            n = analogRead(A0);
            if (n <= threshold) //�Թ���ǿ�Ƚ����жϣ�С��Ԥ��ֵ�ر�LED,����͵���
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
            MsTimer2::set(500, flash); // �ж����ú�����ÿ 500ms ����һ���ж�
            MsTimer2::start();         //��ʼ��ʱ
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
//ǰ��
void motor_forword()
{
    Serial.println("FORWARD"); //���״̬
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
//����
void motor_backward()
{
    Serial.println("BACKWARD"); //���״̬
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
//ǰ����ת
void motor_left_fo()
{
    Serial.println("TURN  LEFT"); //���״̬
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
//ǰ����ת
void motor_right_fo()
{
    Serial.println("TURN  RIGHT"); //���״̬
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
//������ת
void motor_right_ba()
{
    Serial.println("TURN  RIGHT"); //���״̬
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

//������ת
void motor_left_ba()
{
    Serial.println("TURN  LEFT"); //���״̬
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
//ֹͣ
void motor_stop()
{
    Serial.println("STOP"); //���״̬
    digitalWrite(leftMotor1_1, LOW);
    digitalWrite(leftMotor1_2, LOW);
    digitalWrite(leftMotor2_1, LOW);
    digitalWrite(leftMotor2_2, LOW);
    digitalWrite(rightMotor1_1, LOW);
    digitalWrite(rightMotor1_2, LOW);
    digitalWrite(rightMotor2_1, LOW);
    digitalWrite(rightMotor2_2, LOW);
}

//����������ʻ
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
    if (barrier >= 500) //�����⵽�ϰ��ﳵ��
    {
        if (!data[0] && data[1] && !data[2]) //���Ҷ�û�м�⵽����
        {
            motorRun(FORWARD);
            Serial.println(1);
            digitalWrite(led_1, LOW);
            digitalWrite(led_2, LOW);
        }

        if (data[1] || data[2]) //�ұ߼�⵽����
        {
            motorRun(TURNRIGHT_FO);
            digitalWrite(led_1, HIGH);
            digitalWrite(led_2, LOW);
            Serial.println(2);
        }

        if (data[0] || data[1]) //��߼�⵽����
        {
            motorRun(TURNLEFT_FO);
            digitalWrite(led_2, HIGH);
            digitalWrite(led_1, LOW);
            Serial.println(3);
        }

        else if (data[0] && data[2]) //���Ҷ���⵽������ֹͣ
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
        for (int i = 0; i < 80; i++) //���һ��Ƶ�ʵ�����������2ms��f=500Hz
        {
            digitalWrite(alarm, HIGH); //������
            delay(1);                  //���� 1ms
            digitalWrite(alarm, LOW);  //��������
            delay(1);
        }
        for (int i = 0; i < 100; i++) //�����һ��Ƶ�ʵ�����������4ms��f=250Hz
        {
            digitalWrite(alarm, HIGH); //������
            delay(2);                  // 2ms
            digitalWrite(alarm, LOW);  //��������
            delay(2);                  //��ʱ 2ms
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

    if (data[0] && data[2]) //���Ҷ���⵽������ֹͣ
    {
        motorRun(STOP);
        Serial.println(4);
        digitalWrite(led_1, HIGH);
        digitalWrite(led_2, HIGH);
    }
    else{
      if (!data[0] && data[1] && !data[2]) //���Ҷ�û�м�⵽����
    {
        motorRun(BACKWARD);
        Serial.println(1);
        digitalWrite(led_1, LOW);
        digitalWrite(led_2, LOW);
    }

    if (data[1] || data[2] && !data[0]) //�ұ߼�⵽����
    {
        motorRun(TURNRIGHT_BA);
        digitalWrite(led_1, HIGH);
        digitalWrite(led_2, LOW);
        Serial.println(2);
    }

    if (data[0] || data[1] &&!data[2]) //��߼�⵽����
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