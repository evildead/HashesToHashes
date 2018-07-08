/******************************************************
 *                                                    *
 *   Author: Danilo Carrabino                         *
 *                                                    *
 ******************************************************/


#ifndef CRCCCITT_H
#define CRCCCITT_H

#include "crc16family.h"

namespace crc16 {

    class CRCCCITT : public CRC16Family
    {
    public:
        CRCCCITT();
        virtual ~CRCCCITT();

        // CRC16Family interface
    protected:
        unsigned short getInitialRemainder() override;
        bool doReflectData() override;
        bool doReflectRemainder() override;
        unsigned short getPolynomial() override;
        unsigned short getFinalXorValue() override;
        unsigned short getCheckValue() override;
        std::string hashName() override;
    };

}

#endif // CRCCCITT_H
