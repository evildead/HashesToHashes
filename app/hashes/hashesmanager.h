/******************************************************
 *                                                    *
 *   Author: Danilo Carrabino                         *
 *                                                    *
 ******************************************************/


#ifndef HASHESMANAGER_H
#define HASHESMANAGER_H

#include <cstdlib>
#include <cstdint>
#include <QString>
#include <map>
#include "sha.h"        // SHA-1, SHA-256, SHA-384, SHA-512
#include "ripemd.h"     // RIPEMD160
#include "md5.h"        // MD5
#include "crc.h"        // CRC-32

class HashesManager
{
public:
    HashesManager();

    static std::string charVectorToHexString(const std::vector<unsigned char>& val);
    static std::vector<unsigned char> hexStringToCharVector(const std::string& val);

    /**
     * HASHES computed using CryptoPP
     */
    static bool computeCrc32CryptoPP(const unsigned char* buffer, unsigned int size, std::vector<unsigned char>& crc32Val);
    static bool computeMD5CryptoPP(const unsigned char* buffer, unsigned int size, std::vector<unsigned char>& md5Val);
    static bool computeSHA1CryptoPP(const unsigned char* buffer, unsigned int size, std::vector<unsigned char>& sha1Val);
    static bool computeSHA256CryptoPP(const unsigned char* buffer, unsigned int size, std::vector<unsigned char>& sha256Val);
    static bool computeRIPEMD160CryptoPP(const unsigned char* buffer, unsigned int size, std::vector<unsigned char>& ripemd160Val);

    /**
     * HASHES computed using CRC16Family classes
     */
    static bool computeCRC16(unsigned char const* buffer, unsigned int size, std::vector<unsigned char>& crc16Val);
    static bool computeCRCCCITT(unsigned char const* buffer, unsigned int size, std::vector<unsigned char>& crcCCITTVal);

    /**
     * @brief computeAllHashes
     * @param buffer
     * @param size
     * @return
     */
    static std::map<std::string, std::string> computeAllHashes(const unsigned char* buffer, unsigned int size);

private:
    static CryptoPP::SecByteBlock computeCryptoPPHash(CryptoPP::HashTransformation& hash, std::string const& strData);
};

#endif // HASHESMANAGER_H
