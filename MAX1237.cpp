#include "MAX1237.h"

/**
 *
 *   MAX1237 class creator function
 *   
 *   Parameters:
 *   DWire *i2c             I2C object pointer
 *
 */
MAX1237:: MAX1237(DWire *i2c)
{
    wire = i2c;
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
    if (wire->requestFrom(ADDRESS, (unsigned char)2) == 2)
    {
        ((unsigned char*)&ret)[1] = wire->read() & 0x0F;
        ((unsigned char*)&ret)[0] = wire->read();
    }

    wire->endTransmission(true);
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
    wire->beginTransmission(ADDRESS);
    wire->write(val);    

    wire->endTransmission(true);
}