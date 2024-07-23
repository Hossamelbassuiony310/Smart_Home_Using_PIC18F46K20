/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

#include "UART_LoggingDate.h"


void UART_LOGGINGDATA_send_string(uint8_t *string, uint8_t string_length){
    uint16_t l_string_length = 0;
    for(l_string_length = 0; l_string_length < string_length; ++l_string_length){
        EUSART_Write(*string++);
    }
}
