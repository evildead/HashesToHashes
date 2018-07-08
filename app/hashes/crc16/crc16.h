/******************************************************
 *                                                    *
 *   Author: Danilo Carrabino                         *
 *                                                    *
 ******************************************************/


#ifndef CRC16_H
#define CRC16_H

#include "crc16family.h"

namespace crc16 {

    class CRC16 : public CRC16Family
    {
    public:
        CRC16();
        virtual ~CRC16();

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

#endif // CRC16_H
