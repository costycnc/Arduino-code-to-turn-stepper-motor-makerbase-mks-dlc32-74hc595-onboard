# Arduino-code-to-turn-stepper-motor-mks-dlc32-74hc595-onboard

The Makerbase MKS DLC32 v2.1 uses an onboard 74HC595 high-speed CMOS 8-bit shift register with output latches (3-state).

This example demonstrates the pins used to control all three stepper motors.  A sample code snippet is provided to control the X-axis stepper motor.

During my research, I encountered inconsistencies in how the pins are named and referenced in various sources.  This code aims to clarify these discrepancies.

![Alt text](https://github.com/costycnc/Arduino-code-to-turn-stepper-motor-mks-dlc32-74hc595-onboard/blob/main/mks.png)

![image](https://github.com/user-attachments/assets/39e4adbb-b22f-49b7-b71b-c8c5590ea13a)

     BIT0 -QA-XYZ ENABLE
     BIT1 -QB-STEPX
     BIT2 -QC-DIRX
     BIT3 -QD-STEPZ
     BIT4 -QE-DIRZ
     BIT5 -QF-STEPY
     BIT6 -QG-DIRY
     BIT7 -QH-BEEPER

     


    ESP32 IO17  -->   74HC595 PIN12-Storage register clock input
    ESP32 IO16  -->   74HC595 PIN11-Shift register clock input 
    ESP32 IO21  -->   74HC595 PIN14-Serial data input


