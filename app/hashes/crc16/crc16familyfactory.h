/******************************************************
 *                                                    *
 *   Author: Danilo Carrabino                         *
 *                                                    *
 ******************************************************/


#ifndef CRC16FAMILYFACTORY_H
#define CRC16FAMILYFACTORY_H

#include "crc16family.h"
#include <memory>

namespace crc16 {

    /**
     * @brief The CRC16FamilyFactory class
     * This is part of the FACTORY METHOD TEMPLATE
     */
    class CRC16FamilyFactory
    {
    public:
        virtual std::unique_ptr<CRC16Family> makeCRC16Family() = 0;
    };

}

#endif // CRC16FAMILYFACTORY_H
