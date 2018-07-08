/******************************************************
 *                                                    *
 *   Author: Danilo Carrabino                         *
 *                                                    *
 ******************************************************/


#include "crc16factory.h"
#include "crc16.h"

using namespace crc16;

CRC16Factory::CRC16Factory()
{

}

std::unique_ptr<CRC16Family> CRC16Factory::makeCRC16Family()
{
    return std::unique_ptr<CRC16Family>(new CRC16);
}
