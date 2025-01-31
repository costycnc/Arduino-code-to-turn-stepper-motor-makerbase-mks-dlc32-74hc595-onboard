# Arduino-code-to-turn-stepper-motor-mks-dlc32-74hc595-onboard

The Makerbase MKS DLC32 v2.1 uses an onboard 74HC595 high-speed CMOS 8-bit shift register with output latches (3-state).

This example demonstrates the pins used to control all three stepper motors.  A sample code snippet is provided to control the X-axis stepper motor.

During my research, I encountered inconsistencies in how the pins are named and referenced in various sources.  This code aims to clarify these discrepancies.

![Alt text](https://github.com/costycnc/Arduino-code-to-turn-stepper-motor-mks-dlc32-74hc595-onboard/blob/main/mks.png)

![image](https://github.com/user-attachments/assets/39e4adbb-b22f-49b7-b71b-c8c5590ea13a)

//BIT0-XYZ ENABLE,BIT1-STEPX,BIT2-DIRX,BIT3-STEPZ,BIT4-DIRZ,BIT5-STEPY,BIT6-DIRY,BIT7-BEEPER
void setup() {

pinMode(17, OUTPUT);//ESP32 IO17,I2S-WS   74HC595 PIN12,RCLK,RCK,ST_CP,STCP,LATCH,STORAGE REG-Storage register clock input
pinMode(16, OUTPUT);//ESP32 IO16,I2S-BCK  74HC595 PIN11,SRCLK,SCK,SH_CP,SHCP,CLK,SHIFT REG,CLOCK-Shift register clock input 
pinMode(21, OUTPUT);//ESP32 IO21,I2S-DATA 74HC595 PIN14,SER,SERIAL IN,DS,DATA,SERIAL INPUT-Serial data input


