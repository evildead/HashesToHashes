/******************************************************
 *                                                    *
 *   Author: Danilo Carrabino                         *
 *                                                    *
 ******************************************************/


#ifndef CRC16FACTORY_H
#define CRC16FACTORY_H

#include "crc16familyfactory.h"

namespace crc16 {

    /**
     * @brief The CRC16Factory class
     * This class creates CRC16 objects (a subclass of CRC16Family)
     */
    class CRC16Factory : public CRC16FamilyFactory
    {
    public:
        CRC16Factory();

        // CRC16FamilyFactory interface
    public:
        std::unique_ptr<CRC16Family> makeCRC16Family() override;
    };

}

#endif // CRC16FACTORY_H
