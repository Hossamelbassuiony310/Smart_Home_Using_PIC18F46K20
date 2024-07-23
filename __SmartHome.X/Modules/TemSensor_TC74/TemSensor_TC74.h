/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef TEMSENSOR_TC74.H
#define	TEMSENSOR_TC74.H

#include "../../mcc_generated_files/mcc.h"
#include "../../mcc_generated_files/examples/i2c_master_example.h"

uint8_t  TEMSENSOR_TC74_Read_Temp(i2c_address_t TC74_Address);


#endif	/* TEMSENSOR_TC74.H */

