# Arduino-code-to-turn-stepper-motor-mks-dlc32-74hc595-onboard

The Makerbase MKS DLC32 v2.1 uses an onboard 74HC595 high-speed CMOS 8-bit shift register with output latches (3-state).

This example demonstrates the pins used to control all three stepper motors.  A sample code snippet is provided to control the X-axis stepper motor.

During my research, I encountered inconsistencies in how the pins are named and referenced in various sources.  This code aims to clarify these discrepancies.

![Alt text](https://github.com/costycnc/Arduino-code-to-turn-stepper-motor-mks-dlc32-74hc595-onboard/blob/main/mks.png)

![image](https://github.com/user-attachments/assets/39e4adbb-b22f-49b7-b71b-c8c5590ea13a)


    ESP32 IO17  -->   74HC595 PIN12-Storage register clock input
    ESP32 IO16  -->   74HC595 PIN11-Shift register clock input 
    ESP32 IO21  -->   74HC595 PIN14-Serial data input

     BIT0 -QA-XYZ ENABLE
     BIT1 -QB-STEPX
     BIT2 -QC-DIRX
     BIT3 -QD-STEPZ
     BIT4 -QE-DIRZ
     BIT5 -QF-STEPY
     BIT6 -QG-DIRY
     BIT7 -QH-BEEPER

     In this instruction shiftOut(21, 16, MSBFIRST, 0) mean that the final value (0) will be write on register

     So all outputs wil be 0

     PB6  PB5   PB4  PB3   PB2  PB1   PB0
     DIRY STEPY DIRZ STEPZ DIRX STEPX ENABLEXYZ
     LOW  LOW   LOW  LOW   LOW  LOW   LOW

     Keep in mind that PIN ENABLE LOW make the driver active (PIN ENABLE HIGH make the driver inactive)

     In this instruction shiftOut(21, 16, MSBFIRST, 2) mean that all pins will be LOW only BIT1 will be HIGH

     PB6  PB5   PB4  PB3   PB2  PB1   PB0
     DIRY STEPY DIRZ STEPZ DIRX STEPX ENABLEXYZ
     LOW  LOW   LOW  LOW   LOW  HIGH  LOW     

     So ... if write 0 wait and after 2 and wait at infinite , all drivers will be active because PBO rimain all time LOW
     only PB1 STEPX will be high and low intermitent , so motor axe x will turn

     So ...in this instruction shiftOut(21, 16, MSBFIRST, X) if change X with values from 0 to 255 you can control all pins of driver X,Y,Z inclusive the beeper!!!
     

     

     





