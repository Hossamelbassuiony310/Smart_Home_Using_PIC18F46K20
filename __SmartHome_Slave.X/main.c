/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */


#include "mcc_generated_files/mcc.h"

/*
                         Main application
*/

uint8_t temp_A7 = 0;
static void custom_I2C_SlaveDefRdInterruptHandler() {
    temp_A7 = SSPBUF;
}
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable high priority global interrupts
    INTERRUPT_GlobalInterruptHighEnable();

    // Enable low priority global interrupts.
    INTERRUPT_GlobalInterruptLowEnable();

    // Disable high priority global interrupts
    //INTERRUPT_GlobalInterruptHighDisable();

    // Disable low priority global interrupts.
    //INTERRUPT_GlobalInterruptLowDisable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    I2C_Open();
    I2C_SlaveSetReadIntHandler(custom_I2C_SlaveDefRdInterruptHandler);

    while (1)
    {
        
        if(temp_A7 > 35){
            Dc_MotorPin0_SetHigh();
            Dc_MotorPin1_SetLow();
        }
        else{
            Dc_MotorPin0_SetLow();
            Dc_MotorPin1_SetLow();
        }
        // Add your application code
    }
}
/**
 End of File
*/