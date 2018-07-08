/******************************************************
 *                                                    *
 *   Author: Danilo Carrabino                         *
 *                                                    *
 ******************************************************/


#include "crcccitt.h"
#include <iostream>

using namespace crc16;

CRCCCITT::CRCCCITT()
{

}

CRCCCITT::~CRCCCITT()
{
    std::cout << "CRCCCITT destructor invoked!" << std::endl;
}

unsigned short CRCCCITT::getInitialRemainder()
{
    return 0xFFFF;
}

bool CRCCCITT::doReflectData()
{
    return false;
}

bool CRCCCITT::doReflectRemainder()
{
    return false;
}

unsigned short CRCCCITT::getPolynomial()
{
    return 0x1021;
}

unsigned short CRCCCITT::getFinalXorValue()
{
    return 0x0000;
}

unsigned short CRCCCITT::getCheckValue()
{
    return 0x29B1;
}

std::string CRCCCITT::hashName()
{
    return "CRC-CCITT";
}
