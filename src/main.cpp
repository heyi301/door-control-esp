#include <Arduino.h>
#include <Servo.h>

#define box1 18
#define box2 19
#define box3 21
#define box4 22

#define door1 23
#define door2 25
#define door3 26
#define door4 27

#define cmd_led 4

#define box_led 13

#define door_led 14



Servo servo_box1;
Servo servo_box2;
Servo servo_box3;
Servo servo_box4;

Servo servo_door1;
Servo servo_door2;
Servo servo_door3;
Servo servo_door4;

String command;
bool CMD = false;
int box_id = 0;
int box_status = 0;
int door_status = 0;
int cmd_status = 0;
int box1_up = 0,box2_up = 0,box3_up = 0,box4_up = 0;
int box1_down = 0,box2_down = 0,box3_down = 0,box4_down = 0;
int door1_down = 0,door2_down = 0,door3_down = 0,door4_down = 0;
int door1_up = 0,door2_up = 0,door3_up = 0, door4_up = 0;
void setup() {
    Serial.begin(115200);

    pinMode(cmd_led,OUTPUT);
    pinMode(box_led,OUTPUT);
    // pinMode(box2_led,OUTPUT);
    // pinMode(box3_led,OUTPUT);
    // pinMode(box4_led,OUTPUT);
    pinMode(door_led,OUTPUT);
    // pinMode(door2_led,OUTPUT);
    // pinMode(door3_led,OUTPUT);
    // pinMode(door4_led,OUTPUT);


    servo_box1.attach(box1);
    servo_box2.attach(box2);
    // servo_box3.attach(box3);
    // servo_box4.attach(box4);
    servo_door1.attach(door1);
    servo_door2.attach(door2);
    // servo_door3.attach(door3);
    // servo_door4.attach(door4);
    // write your initialization code here
}


void loop() {
    if (CMD) {
        box_id = command[0]-'0';
        box_status = command[1]-'0';
        door_status = command[2]-'0';
        if (box_id == 1) {
            if (box_status == 0) {
                servo_box1.write(box1_down);
                digitalWrite(box_led,LOW);
            }
            else {
                servo_box1.write(box1_up);
                digitalWrite(box_led,HIGH);
            }
            if (door_status == 0) {
                servo_door1.write(door1_down);
                digitalWrite(door_led,LOW);
            }
            else {
                servo_door1.write(door1_up);
                digitalWrite(door_led,HIGH);
            }
            cmd_status = true;
        }
        else if (box_id == 2) {
            if (box_status == 0) {
                servo_box2.write(box2_down);
                digitalWrite(box_led,LOW);
            }
            else {
                servo_box2.write(box2_up);
                digitalWrite(box_led,HIGH);
            }
            if (door_status == 0) {
                servo_door2.write(door2_down);
                digitalWrite(door_led,LOW);
            }
            else {
                servo_door2.write(door2_up);
                digitalWrite(door_led,HIGH);
            }
            cmd_status = true;
        }
        else if (box_id == 3) {
            if (box_status == 0) {
                servo_box3.write(box3_down);
                digitalWrite(box_led,LOW);
            }
            else {
                servo_box3.write(box3_up);
                digitalWrite(box_led,HIGH);
            }
            if (door_status == 0) {
                servo_door3.write(door3_down);
                digitalWrite(door_led,LOW);
            }
            else {
                servo_door3.write(door3_up);
                digitalWrite(door_led,HIGH);
            }
            cmd_status = true;
        }
        else if (box_id == 4) {
            if (box_status == 0) {
                servo_box4.write(box4_down);
                digitalWrite(box_led,LOW);
            }
            else {
                servo_box4.write(box4_up);
                digitalWrite(box_led,HIGH);
            }
            if (door_status == 0) {
                servo_door4.write(door4_down);
                digitalWrite(door_led,LOW);
            }
            else {
                servo_door4.write(door4_up);
                digitalWrite(door_led,HIGH);
            }
            cmd_status = true;
        }
        else {
            cmd_status = false;
        }
        CMD = false;
        command = "";
        // digitalWrite(cmd_led,LOW);
        Serial.print("11111111#");
    }
// Serial.println("running");
//     delay(500);
}

void serialEvent() {
    // Serial.println("SerialEvent");
    while (Serial.available() > 0) {
        char c = Serial.read();
        // Serial.print(c);
        if (c != '#') {
            command += c;
        } else {
            digitalWrite(cmd_led,!digitalRead(cmd_led));
            CMD=true;
        }
    }
}
