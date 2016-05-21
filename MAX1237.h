#ifndef __MAX1237_H__
#define __MAX1237_H__

#include "Energia.h"
#include <Wire.h>

#define ADDRESS		0x34


#define SCAN0		0x00
#define SCAN1		0x20
#define SCAN2		0x40
#define SCAN3		0x60

#define CS0			0x00
#define CS1			0x02
#define CS2			0x04
#define CS3			0x06

//#define SEL5

class MAX1237
{
protected:
    unsigned char address;


public:

    MAX1237();
    virtual ~MAX1237() {};
    
    unsigned short readSingleChannel();
    void writeRegister(unsigned char); 

private:
    
    
};

#endif // __MAX1237_H__ 