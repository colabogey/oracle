#pragma once

#include "IHashFunction.h"
#include <string>

class HashFunction: public IHashFunction
{
public:
    HashFunction();
    virtual ~HashFunction();
    HashFunction& operator=(HashFunction& other) {return *this;};
    HashFunction(HashFunction& other) {};

    virtual int hash(const std::string&) override;

private:

};
