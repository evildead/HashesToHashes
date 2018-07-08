/******************************************************
 *                                                    *
 *   Author: Danilo Carrabino                         *
 *                                                    *
 ******************************************************/


#ifndef CRC16FAMILY_H
#define CRC16FAMILY_H

#include <string>

namespace crc16 {

    class CRC16Family
    {
    public:
        CRC16Family();
        virtual ~CRC16Family();

        /**
         * @brief computeHash: TEMPLATE METHOD
         * @param buffer
         * @param size
         * @return The Hash
         */
        virtual unsigned short computeHash(unsigned char const* buffer, unsigned int size);

    protected:
        virtual unsigned short getInitialRemainder() = 0;
        virtual bool doReflectData() = 0;
        virtual bool doReflectRemainder() = 0;
        virtual unsigned short getPolynomial() = 0;
        virtual unsigned short getFinalXorValue() = 0;
        virtual unsigned short getCheckValue() = 0;
        virtual std::string hashName() = 0;

    private:
        static unsigned long reflect(unsigned long data, unsigned char nBits);
        static unsigned short getWidth();
        static unsigned short getTopBit();

        /**
         * @brief reflectData
         * @param val
         * @return
         */
        unsigned short reflectData(unsigned long val);

        /**
         * @brief reflectRemainder
         * @param val
         * @return
         */
        unsigned short reflectRemainder(unsigned long val);
    };

}

#endif // CRC16FAMILY_H
