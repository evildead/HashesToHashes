/******************************************************
 *                                                    *
 *   Author: Danilo Carrabino                         *
 *                                                    *
 ******************************************************/


#include "crcccittfactory.h"
#include "crcccitt.h"

using namespace crc16;

CRCCCITTFactory::CRCCCITTFactory()
{

}

std::unique_ptr<CRC16Family> CRCCCITTFactory::makeCRC16Family()
{
    return std::unique_ptr<CRC16Family>(new CRCCCITT);
}
