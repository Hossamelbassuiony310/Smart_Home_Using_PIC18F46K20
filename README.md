I used a PIC18f46K20 and used a DS1307 module, the time and date results are displayed on the virtual terminal.
Then I created an EEPROM_24C02C driver, but I didn't use it. I just did this,
and connected a TC74 sensor to measure the temperature so that when it exceeds 35, 
a signal is sent to another PIC18f46K20 microcontroller via I2C Protocol to start the engine to simulate a fire suppression system.
