#ifndef ARM_H
#define ARM_H

#include <PCA9685.h>
#include <unistd.h>
#include <iostream>
#include <wiringPi.h>
using namespace std;

/***Servo Pickup Positions***
    Right_Servo: 400   
    Left_Servo: 370
    Center_Servo: 430
*/
#define RIGHT_SERVO_PICKUP_POS 400
#define LEFT_SERVO_PICKUP_POS 370
#define CENTER_SERVO_PICKUP_POS 430

/***Servo Raised Positions***
    Right_Servo: 100   
    Left_Servo: 670
    Center_Servo: 660
*/
#define RIGHT_SERVO_RAISED_POS 100
#define LEFT_SERVO_RAISED_POS 670
#define CENTER_SERVO_RAISED_POS 660

void set_raised_pos();
void set_pickup_pos();
void arm_pickup();


typedef enum {
    RIGHT_SERVO_CHANNEL = 0,
    LEFT_SERVO_CHANNEL = 1,
    CENTER_SERVO_CHANNEL = 2
} SERVO_CHANNEL;



void set_raised_pos(PCA9685 pca) {
    pca.set_pwm(CENTER_SERVO_CHANNEL, 0, CENTER_SERVO_RAISED_POS);
    delay(700);
    pca.set_pwm(RIGHT_SERVO_CHANNEL, 0, RIGHT_SERVO_RAISED_POS);
    pca.set_pwm(LEFT_SERVO_CHANNEL, 0, LEFT_SERVO_RAISED_POS);
}

void set_pickup_pos(PCA9685 pca) {
    pca.set_pwm(CENTER_SERVO_CHANNEL, 0, CENTER_SERVO_PICKUP_POS);
    delay(700);
    pca.set_pwm(RIGHT_SERVO_CHANNEL, 0, RIGHT_SERVO_PICKUP_POS);
    pca.set_pwm(LEFT_SERVO_CHANNEL, 0, LEFT_SERVO_PICKUP_POS);
}

void arm_pickup(PCA9685 pca) {
    set_pickup_pos(pca);
    delay(1000);
    set_raised_pos(pca);
}



#endif
