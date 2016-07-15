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
 
#ifndef __MAX1237_H__
#define __MAX1237_H__

#include <Energia.h>
#include <DWire.h>

#define ADDRESS		0x34

#define SCAN0		0x00
#define SCAN1		0x20
#define SCAN2		0x40
#define SCAN3		0x60

#define CS0			0x00
#define CS1			0x02
#define CS2			0x04
#define CS3			0x06

class MAX1237
{
protected:
    DWire &wire;
    unsigned char address;

public:
    MAX1237(DWire&);
    virtual ~MAX1237() {};
    
    unsigned short readSingleChannel();
    void writeRegister(unsigned char); 

private:
     
};

#endif // __MAX1237_H__ 