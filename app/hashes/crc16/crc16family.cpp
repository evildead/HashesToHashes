/******************************************************
 *                                                    *
 *   Author: Danilo Carrabino                         *
 *                                                    *
 ******************************************************/


#include "crc16family.h"

using namespace crc16;

CRC16Family::CRC16Family()
{

}

CRC16Family::~CRC16Family()
{

}

unsigned long CRC16Family::reflect(unsigned long data, unsigned char nBits)
{
    unsigned long reflection = 0x00000000;
    unsigned char bit;

    // Reflect the data about the center bit.
    for (bit = 0; bit < nBits; ++bit) {
        // If the LSB bit is set, set the reflection of it.
        if (data & 0x01) {
            reflection |= (1 << ((nBits - 1) - bit));
        }

        data = (data >> 1);
    }

    return (reflection);
}

unsigned short CRC16Family::getWidth()
{
    return(8 * sizeof(unsigned short));
}

unsigned short CRC16Family::getTopBit()
{
    return( 1 << (getWidth() - 1) );
}

unsigned short CRC16Family::reflectData(unsigned long val)
{
    if( doReflectData() ) {
        return (unsigned char)reflect((val), 8);
    }
    else {
        return (unsigned short)val;
    }
}

unsigned short CRC16Family::reflectRemainder(unsigned long val)
{
    if( doReflectRemainder() ) {
        return (unsigned short) reflect((val), getWidth());
    }
    else {
        return (unsigned short)val;
    }
}

unsigned short CRC16Family::computeHash(unsigned char const* buffer, unsigned int size)
{
    unsigned short remainder = getInitialRemainder();
    int            byte;
    unsigned char  bit;

    // Perform modulo-2 division, a byte at a time.
    for (byte = 0; byte < size; ++byte) {
        // Bring the next byte into the remainder.
        remainder ^= (reflectData(buffer[byte]) << (getWidth() - 8));

        // Perform modulo-2 division, a bit at a time.
        for (bit = 8; bit > 0; --bit) {
            // Try to divide the current data bit.
            if (remainder & getTopBit()) {
                remainder = (remainder << 1) ^ getPolynomial();
            }
            else {
                remainder = (remainder << 1);
            }
        }
    }

    // The final remainder is the CRC result.
    return (reflectRemainder(remainder) ^ getFinalXorValue());
}
