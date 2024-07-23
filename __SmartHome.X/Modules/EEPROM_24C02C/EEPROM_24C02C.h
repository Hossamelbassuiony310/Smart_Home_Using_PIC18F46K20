/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef EEPROM_24C02C.H
#define	EEPROM_24C02C.H

#include "../../mcc_generated_files/i2c_master.h"
#include "../../mcc_generated_files/examples/i2c_master_example.h"

void EEPROM_240C02C_Write_Byte(i2c_address_t EEPROM_Address, i2c_address_t Byte_Address, uint8_t Data);
uint8_t EEPROM_240C02C_Read_Byte(i2c_address_t EEPROM_Address, i2c_address_t Byte_Address);

#endif	/* EEPROM_24C02C.H */

