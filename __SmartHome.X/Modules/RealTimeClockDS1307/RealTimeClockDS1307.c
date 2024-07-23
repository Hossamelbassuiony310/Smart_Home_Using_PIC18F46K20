/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

#include "RealTimeClockDS1307.h"

static RTCDS1307_t RealTimeClockDS1307;
/* "Year" - "Month" - "_Day" : "_Hours" -  "_Minutes" - "_Second"*/
static uint8_t DATE_PACK[18];

/**
 * 
 * @return 
 */
RTCDS1307_t RealTimeClockDS1307_Get_Date_Time(void){
    RealTimeClockDS1307._Second = I2C_Read1ByteRegister( 0xD0, 0x00);
    RealTimeClockDS1307._Minutes = I2C_Read1ByteRegister( 0xD0, 0x01);
    RealTimeClockDS1307._Hours = I2C_Read1ByteRegister( 0xD0, 0x02);
    RealTimeClockDS1307._Day = I2C_Read1ByteRegister( 0xD0, 0x04);
    RealTimeClockDS1307._Month = I2C_Read1ByteRegister( 0xD0, 0x05);
    RealTimeClockDS1307._Years = I2C_Read1ByteRegister( 0xD0, 0x06);
    
    return RealTimeClockDS1307;
}



void Print_DATE(void){
    DATE_PACK[0] = ((RealTimeClockDS1307._Day >> 4) + '0');
    DATE_PACK[1] = ((RealTimeClockDS1307._Day & 0x0F) + '0');
    DATE_PACK[2] = '-';
    DATE_PACK[3] = ((RealTimeClockDS1307._Month >> 4) + '0');
    DATE_PACK[4] = ((RealTimeClockDS1307._Month & 0x0F) + '0');
    DATE_PACK[5] = '-';
    DATE_PACK[6] = ((RealTimeClockDS1307._Years >> 4) + '0');
    DATE_PACK[7] = ((RealTimeClockDS1307._Years & 0x0F) + '0');
    DATE_PACK[8] = '/';
    DATE_PACK[9] = ((RealTimeClockDS1307._Hours >> 4) + '0');
    DATE_PACK[10] = ((RealTimeClockDS1307._Hours & 0x0F) + '0');
    DATE_PACK[11] = '-';
    DATE_PACK[12] = ((RealTimeClockDS1307._Minutes >> 4) + '0');
    DATE_PACK[13] = ((RealTimeClockDS1307._Minutes & 0x0F) + '0');
    DATE_PACK[14] = '-';
    DATE_PACK[15] = ((RealTimeClockDS1307._Second >> 4) + '0');
    DATE_PACK[16] = ((RealTimeClockDS1307._Second & 0x0F) + '0');
    DATE_PACK[17] = '\r';
    
    UART_LOGGINGDATA_send_string("Date: ", 6);
    UART_LOGGINGDATA_send_string(DATE_PACK, 18);
}

