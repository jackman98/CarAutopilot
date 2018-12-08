#pragma once

#include "asn_src/BIT_STRING.h"
#include "asn_src/OCTET_STRING.h"

#include <bitset>
#include <vector>
#include <memory>


namespace v2x {
namespace element {

#define BIT_STRING_SIZE 16
#define BITS_IN_BYTE    8

class CBitString {
private:
    std::bitset<BIT_STRING_SIZE> bits;

public:
    CBitString();
    CBitString(const CBitString&);
    CBitString(uint32_t value);
    ~CBitString();
    CBitString(const std::bitset<BIT_STRING_SIZE>&);
    CBitString& operator=(const CBitString&);

    int operator==(const CBitString&) const;
    int operator!=(const CBitString&) const;

    std::size_t length() const;

    void set(uint32_t, const unsigned char);
    void set(uint32_t);
    void clear(uint32_t);
    void invert(uint32_t);
    std::string to_string() const;    
    unsigned long to_ulong() const;
    operator std::string() const;
    operator unsigned long() const;
    int operator[](uint32_t) const;
    bool test(uint32_t) const;

    void fillASNBitString(BIT_STRING_t* bitString);
    void extractFromASNBitString(BIT_STRING_t *bitString);
    void reset();
private:
    uint32_t getBytesOccupied(const std::vector<bool> &vec);
    uint32_t getBitsUnused(const std::vector<bool> &vec);
    void fillBitStringBuf(const std::vector<bool> &vec, uint8_t *buffer);
};

class CBitStringCorrect {
public:
    CBitStringCorrect(const size_t size);
    CBitStringCorrect(const BIT_STRING_t &bitString);
    CBitStringCorrect(const CBitStringCorrect &bitString) = default;

    void set(size_t pos);
    void set(size_t pos, bool flag);
    void reset(size_t pos);
    bool test(size_t pos) const;

    size_t size() const;
    size_t count() const;
    size_t bits_unused() const;
    size_t bits_occupied() const;

    long to_long() const;

    void convertToASN(BIT_STRING_t* bitString);

    CBitStringCorrect &operator=(const BIT_STRING_t &bitString);
    CBitStringCorrect &operator=(const CBitStringCorrect&) = default;

    bool operator==(const CBitStringCorrect& rhs) const;
    bool operator!=(const CBitStringCorrect& rhs) const;

    void reset();
private:
    long transformPos(size_t pos) const;
    long trasformValue(const BIT_STRING_t &bitString) const;

private:
    size_t userSize = 0;
    size_t fullSize = 0;
    long value = 0;
};

class COctetString {
public:
    static std::string getStringFromOctet(const OCTET_STRING *str);
    static std::string getStringFromOctet(const OCTET_STRING &str);
    static void setOctetString(const std::string &src, OCTET_STRING *dst);
};

} //v2x
} //element
