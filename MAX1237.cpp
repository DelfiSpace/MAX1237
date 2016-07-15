/*
 * Copyright (c) 2016 by Stefano Speretta <s.speretta@tudelft.nl>
 *
 * MAX1237: a library to provide high level APIs to interface with the 
 * MAXIM MAX1237 ADC. It is possible to use this library in Energia 
 * (the Arduino port for MSP microcontrollers) or in other toolchains.
 *
 * This file is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License 
 * version 3, both as published by the Free Software Foundation.
 *
 */
 
#include <MAX1237.h>

/**
 *
 *   MAX1237 class creator function
 *   
 *   Parameters:
 *   DWire &i2c             I2C object
 *
 */
MAX1237:: MAX1237(DWire &i2c): wire(i2c)
{
}

/**
 *
 *   Returns the value of the selected internal register
 *   
 *
 *   Parameters:
 *   unsigned char reg     register number
 *
 *   Returns:
 *   unsigned short        register value
 *
 */
unsigned short MAX1237::readSingleChannel()
{
    unsigned short ret = -1;
  
    // use the casting to prevent warning on ambiguous conversion
    if (wire.requestFrom(ADDRESS, (unsigned char)2) == 2)
    {
        ((unsigned char*)&ret)[1] = wire.read() & 0x0F;
        ((unsigned char*)&ret)[0] = wire.read();
    }

    return ret;
}

/**
 *
 *   Sets the value of the selected internal register
 *   
 *
 *   Parameters:
 *   unsigned char reg     register number
 *   unsigned short        register value
 *
 */
void MAX1237::writeRegister(unsigned char val)
{
    wire.beginTransmission(ADDRESS);
    wire.write(val);    
    wire.endTransmission();
}