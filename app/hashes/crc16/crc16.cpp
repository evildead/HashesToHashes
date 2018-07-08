/******************************************************
 *                                                    *
 *   Author: Danilo Carrabino                         *
 *                                                    *
 ******************************************************/


#include "crc16.h"
#include <iostream>

using namespace crc16;

CRC16::CRC16()
{

}

CRC16::~CRC16()
{
    std::cout << "CRC16 destructor invoked!" << std::endl;
}

unsigned short CRC16::getInitialRemainder()
{
    return 0x0000;
}

bool CRC16::doReflectData()
{
    return true;
}

bool CRC16::doReflectRemainder()
{
    return true;
}

unsigned short CRC16::getPolynomial()
{
    return 0x8005;
}

unsigned short CRC16::getFinalXorValue()
{
    return 0x0000;
}

unsigned short CRC16::getCheckValue()
{
    return 0xBB3D;
}

std::string CRC16::hashName()
{
    return "CRC-16";
}
