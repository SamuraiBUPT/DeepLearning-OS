#ifndef __PORT_H
#define __PORT_H

#include "types.h"

class Port
{
protected:
    uint16_t portNumber;
    Port(uint16_t portNumber);
    ~Port();
};

class Port_8bit : public Port
{
public:
    Port_8bit(uint16_t portNumber);
    ~Port_8bit();
    virtual void Write(uint8_t data);
    virtual uint8_t Read();
};

class Port_8bitSlow : public Port_8bit
{
public:
    Port_8bitSlow(uint16_t portNumber);
    ~Port_8bitSlow();
    virtual void Write(uint8_t data);
};

class Port_16bit : public Port
{
public:
    Port_16bit(uint16_t portNumber);
    ~Port_16bit();
    virtual void Write(uint16_t data);
    virtual uint16_t Read();
};

class Port_32bit : public Port
{
public:
    Port_32bit(uint16_t portNumber);
    ~Port_32bit();
    virtual void Write(uint32_t data);
    virtual uint32_t Read();
};

#endif