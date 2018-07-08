/******************************************************
 *                                                    *
 *   Author: Danilo Carrabino                         *
 *                                                    *
 ******************************************************/


#include "hashesmanager.h"
#include "crc16/crc16factory.h"
#include "crc16/crcccittfactory.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>

HashesManager::HashesManager()
{

}


std::string HashesManager::charVectorToHexString(const std::vector<unsigned char>& val)
{
    std::stringstream strStream;
    for(unsigned int i = 0; i < val.size(); i++) {
        strStream << std::setfill('0') << std::setw(2) << std::hex << std::uppercase << ((int)val.at(i) & 0x000000FF);
    }

    return strStream.str();
}

std::vector<unsigned char> HashesManager::hexStringToCharVector(const std::string& val)
{
    std::vector<unsigned char> charVector;
    if((val.size() % 2) != 0) {
        return charVector;
    }

    for(unsigned int i = 0; i < val.size(); i+=2) {
        int i_hex = std::stoi(val.substr(i, 2), nullptr, 16);
        charVector.push_back((unsigned char) i_hex);
    }

    return charVector;
}

CryptoPP::SecByteBlock HashesManager::computeCryptoPPHash(CryptoPP::HashTransformation& hash, std::string const& strData)
{
    // Cannot use std::string for buffer;
    // its internal storage might not be contiguous
    CryptoPP::SecByteBlock sbbDigest(hash.DigestSize());

    hash.CalculateDigest(
        sbbDigest.begin(),
        (byte const*) strData.data(),
        strData.size());

    return sbbDigest;
}

bool HashesManager::computeCrc32CryptoPP(const unsigned char* buffer, unsigned int size, std::vector<unsigned char>& crc32Val)
{
    std::string strData((const char*)buffer, size);

    try {
        CryptoPP::CRC32 crc32Alg;
        CryptoPP::SecByteBlock crc32ByteArray = computeCryptoPPHash(crc32Alg, strData);
        if(crc32ByteArray.size() < 4) {
            return false;
        }

        crc32Val.assign(crc32ByteArray.begin(), crc32ByteArray.end());
        // for CRC32 the vector should be reversed
        std::reverse(crc32Val.begin(), crc32Val.end());

        return true;
    }
    catch (CryptoPP::Exception const& e)
    {
        std::cout << "CryptoPP::Exception caught: " << std::endl << e.what() << std::endl;
        return false;
    }
}

bool HashesManager::computeMD5CryptoPP(const unsigned char* buffer, unsigned int size, std::vector<unsigned char>& md5Val)
{
    std::string strData((const char*)buffer, size);

    try {
        CryptoPP::MD5 md5Alg;
        CryptoPP::SecByteBlock md5ByteArray = computeCryptoPPHash(md5Alg, strData);
        if(md5ByteArray.size() < 16) {
            return false;
        }

        md5Val.assign(md5ByteArray.begin(), md5ByteArray.end());

        return true;
    }
    catch (CryptoPP::Exception const& e)
    {
        std::cout << "CryptoPP::Exception caught: " << std::endl << e.what() << std::endl;
        return false;
    }
}

bool HashesManager::computeSHA1CryptoPP(const unsigned char* buffer, unsigned int size, std::vector<unsigned char>& sha1Val)
{
    std::string strData((const char*)buffer, size);

    try {
        CryptoPP::SHA1 sha1Alg;
        CryptoPP::SecByteBlock sha1ByteArray = computeCryptoPPHash(sha1Alg, strData);
        if(sha1ByteArray.size() < 20) {
            return false;
        }

        sha1Val.assign(sha1ByteArray.begin(), sha1ByteArray.end());

        return true;
    }
    catch (CryptoPP::Exception const& e)
    {
        std::cout << "CryptoPP::Exception caught: " << std::endl << e.what() << std::endl;
        return false;
    }
}

bool HashesManager::computeSHA256CryptoPP(const unsigned char* buffer, unsigned int size, std::vector<unsigned char>& sha256Val)
{
    std::string strData((const char*)buffer, size);

    try {
        CryptoPP::SHA256 sha256Alg;
        CryptoPP::SecByteBlock sha256ByteArray = computeCryptoPPHash(sha256Alg, strData);
        if(sha256ByteArray.size() < 32) {
            return false;
        }

        sha256Val.assign(sha256ByteArray.begin(), sha256ByteArray.end());

        return true;
    }
    catch (CryptoPP::Exception const& e)
    {
        std::cout << "CryptoPP::Exception caught: " << std::endl << e.what() << std::endl;
        return false;
    }
}

bool HashesManager::computeRIPEMD160CryptoPP(const unsigned char* buffer, unsigned int size, std::vector<unsigned char>& ripemd160Val)
{
    std::string strData((const char*)buffer, size);

    try {
        CryptoPP::RIPEMD160 ripemd160Alg;
        CryptoPP::SecByteBlock ripemd160ByteArray = computeCryptoPPHash(ripemd160Alg, strData);
        if(ripemd160ByteArray.size() < 20) {
            return false;
        }

        ripemd160Val.assign(ripemd160ByteArray.begin(), ripemd160ByteArray.end());

        return true;
    }
    catch (CryptoPP::Exception const& e)
    {
        std::cout << "CryptoPP::Exception caught: " << std::endl << e.what() << std::endl;
        return false;
    }
}

bool HashesManager::computeCRC16(unsigned char const* buffer, unsigned int size, std::vector<unsigned char>& crc16Val)
{
    crc16::CRC16Factory crc16HashFactory;
    std::unique_ptr<crc16::CRC16Family> crc16Hash = crc16HashFactory.makeCRC16Family();
    unsigned short uShortVal = crc16Hash->computeHash(buffer, size);
    crc16Val.push_back( ((unsigned char)((uShortVal & 0xFF00) >> 8)) );
    crc16Val.push_back( ((unsigned char)(uShortVal & 0x00FF)) );
    return true;
}

bool HashesManager::computeCRCCCITT(unsigned char const* buffer, unsigned int size, std::vector<unsigned char>& crcCCITTVal)
{
    crc16::CRCCCITTFactory crcCCITTHashFactory;
    std::unique_ptr<crc16::CRC16Family> crcCCITTHash = crcCCITTHashFactory.makeCRC16Family();
    unsigned short uShortVal = crcCCITTHash->computeHash(buffer, size);
    crcCCITTVal.push_back( ((unsigned char)((uShortVal & 0xFF00) >> 8)) );
    crcCCITTVal.push_back( ((unsigned char)(uShortVal & 0x00FF)) );
    return true;
}

std::map<std::string, std::string> HashesManager::computeAllHashes(const unsigned char* buffer, unsigned int size)
{
    std::map<std::string, std::string> hashesMap;

    std::vector<unsigned char> crc32Str;
    HashesManager::computeCrc32CryptoPP(buffer, size, crc32Str);
    hashesMap["CRC-32"] = HashesManager::charVectorToHexString(crc32Str);

    std::vector<unsigned char> md5Str;
    HashesManager::computeMD5CryptoPP(buffer, size, md5Str);
    hashesMap["MD5"] = HashesManager::charVectorToHexString(md5Str);

    std::vector<unsigned char> sha1Str;
    HashesManager::computeSHA1CryptoPP(buffer, size, sha1Str);
    hashesMap["SHA1"] = HashesManager::charVectorToHexString(sha1Str);

    std::vector<unsigned char> sha256Str;
    HashesManager::computeSHA256CryptoPP(buffer, size, sha256Str);
    hashesMap["SHA256"] = HashesManager::charVectorToHexString(sha256Str);

    std::vector<unsigned char> ripemd160Str;
    HashesManager::computeRIPEMD160CryptoPP(buffer, size, ripemd160Str);
    hashesMap["RIPEMD160"] = HashesManager::charVectorToHexString(ripemd160Str);

    std::vector<unsigned char> crc16Str;
    HashesManager::computeCRC16(buffer, size, crc16Str);
    hashesMap["CRC-16"] = HashesManager::charVectorToHexString(crc16Str);

    std::vector<unsigned char> crcCCITTStr;
    HashesManager::computeCRCCCITT(buffer, size, crcCCITTStr);
    hashesMap["CRC-CCITT"] = HashesManager::charVectorToHexString(crcCCITTStr);

    return hashesMap;
}
