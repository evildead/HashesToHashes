/******************************************************
 *                                                    *
 *   Author: Danilo Carrabino                         *
 *                                                    *
 ******************************************************/


#ifndef CRCCCITTFACTORY_H
#define CRCCCITTFACTORY_H

#include "crc16familyfactory.h"

namespace crc16 {

    /**
     * @brief The CRCCCITTFactory class
     * This class creates CRCCCITT objects (a subclass of CRC16Family)
     */
    class CRCCCITTFactory : public CRC16FamilyFactory
    {
    public:
        CRCCCITTFactory();

        // CRC16FamilyFactory interface
    public:
        std::unique_ptr<CRC16Family> makeCRC16Family() override;
    };

}

#endif // CRCCCITTFACTORY_H
