#include "MAX1237.h"

/**
 *
 *   MAX1237 class creator function
 *   
 *   Parameters:
 *   none
 *
 */
MAX1237:: MAX1237()
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
    if (Wire.requestFrom(ADDRESS, (unsigned char)2) == 2)
    {
        ((unsigned char*)&ret)[1] = Wire.read() & 0x0F;
        ((unsigned char*)&ret)[0] = Wire.read();
    }

    Wire.endTransmission(true);
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
    Wire.beginTransmission(ADDRESS);
    Wire.write(val);    

    Wire.endTransmission(true);
}