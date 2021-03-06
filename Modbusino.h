/*
 * Copyright © 2011 Stéphane Raimbault <stephane.raimbault@gmail.com>
 *
 * License ISC, see LICENSE for more details.

 * This library implements the Modbus protocol.
 * http://libmodbus.org/
 *
 */

#ifndef Modbusino_h
#define Modbusino_h

#include <inttypes.h>
#include <AltSoftSerial.h>

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
  #include <pins_arduino.h>
#endif

#define MODBUS_BROADCAST_ADDRESS 0

/* Protocol exceptions */
#define MODBUS_EXCEPTION_ILLEGAL_FUNCTION     1
#define MODBUS_EXCEPTION_ILLEGAL_DATA_ADDRESS 2
#define MODBUS_EXCEPTION_ILLEGAL_DATA_VALUE   3

class ModbusinoSlave {
public:
    ModbusinoSlave(uint8_t slave, int MaxPin);
    void setup(long baud, uint8_t config, uint8_t rxPin, uint8_t txPin);
    int loop(uint16_t *tab_reg, uint16_t nb_reg);
private:
    int _slave;
    AltSoftSerial _mySerial;
    int _MaxPin;

};

#endif
