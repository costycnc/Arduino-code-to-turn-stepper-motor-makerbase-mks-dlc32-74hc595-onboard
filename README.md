# Arduino-code-to-turn-stepper-motor-makerbase-mks-dlc32-74hc595-onboard

This example demonstrates the pins used to control all three stepper motors.  A sample code snippet is provided to control the X-axis stepper motor.

The Makerbase MKS DLC32 v2.1 uses an onboard 74HC595 high-speed CMOS 8-bit shift register with output latches (3-state).

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

     ![image](https://github.com/user-attachments/assets/940dd2f8-e103-42f1-9925-e1328d4435b8)

     
source https://techoverflow.net/2021/07/26/how-to-connect-esp32-wroom-32-sensor_vp-sensor_vn-pins/

         If you are making a PCB using the ESP32-WROOM-32 module, you might be wondering how to connect theSENSOR_VP and SENSOR_VN pins (pins 4 & 5).

        These pins are made to accurately measure differential low-voltage signals using the ESP32 12-bit ADC.
        If you want to measure a differential signal, connect SENSOR_VP to the positive voltage of your analog
        signal and connect SENSOR_VN to the negative voltage of your analog signal.
        Take care not to exceed the maximum voltage range of approx. 0..3.3V for the ESP32, else you will damage the chip!
        These pins can be used as normal GPIOs: SENSOR_VP is GPIO36 and SENSOR_VN is GPIO39, 
        however these are input-only, you can’t use them as output!
        If you don’t need the pins, connect them to GND, or just leave them open (i.e. don’t connect them at all)
        Source & further reading: ESP32-WROOM-32 reference manual
     

     

     





