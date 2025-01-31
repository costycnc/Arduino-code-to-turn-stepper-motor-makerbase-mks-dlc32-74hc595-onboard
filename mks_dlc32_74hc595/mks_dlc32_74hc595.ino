//**************************************************************//
//  Name    : Makerbase Mks Dlc32 V2.1 turn stepper motor directly
//  Author  : Costycnc
//  Date    : 31 Jan, 2025
//  Notes   : Code for using a onboard 74HC595 Shift Register           //
//          : to turn stepper motor axe x
//****************************************************************
//onboard 74hc595 on makerbase mks dlc32
//BIT0-XYZ ENABLE,BIT1-STEPX,BIT2-DIRX,BIT3-STEPZ,BIT4-DIRZ,BIT5-STEPY,BIT6-DIRY,BIT7-BEEPER
void setup() {

pinMode(17, OUTPUT);//ESP32 IO17,I2S-WS   74HC595 PIN12,RCLK,RCK,ST_CP,STCP,LATCH,STORAGE REG-Storage register clock input
pinMode(16, OUTPUT);//ESP32 IO16,I2S-BCK  74HC595 PIN11,SRCLK,SCK,SH_CP,SHCP,CLK,SHIFT REG,CLOCK-Shift register clock input 
pinMode(21, OUTPUT);//ESP32 IO21,I2S-DATA 74HC595 PIN14,SER,SERIAL IN,DS,DATA,SERIAL INPUT-Serial data input
}
void loop() {

//write LOW to pin RCK 74HC595
digitalWrite(17, LOW);// Storage register state is not changed

shiftOut(21, 16, MSBFIRST, 2);// shift out the bits (STEP)

//write HIGH to pin RCK 74HC595
digitalWrite(17, HIGH);// stored data into storage register

delayMicroseconds(1);
//write LOW to pin RCK 74HC595
digitalWrite(17, LOW);// Storage register state is not changed

shiftOut(21, 16, MSBFIRST, 0); // shift out the bits 

//write HIGH to pin ST_CP 74HC595
digitalWrite(17, HIGH);// stored data into storage register
delayMicroseconds(50);
}
