/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef REALTIMECLOCKDS1307.H
#define	REALTIMECLOCKDS1307.H

#include "../../mcc_generated_files/mcc.h"
#include "../../mcc_generated_files/examples/i2c_master_example.h"
#include "../Uart_LoggingDate/UART_LoggingDate.h"

typedef struct{
    uint8_t _Minutes;
    uint8_t _Second;
    uint8_t _Hours;
    uint8_t _Day;
    uint8_t _Month;
    uint8_t _Years;
}RTCDS1307_t;

RTCDS1307_t RealTimeClockDS1307_Get_Date_Time(void);
void Print_DATE(void);

#endif	/* REALTIMECLOCKDS1307.H */

