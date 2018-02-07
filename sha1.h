/*
    sha1.cpp - source code of
    ============
    SHA-1 in C++
    ============
    100% Public Domain.
    Original C Code
        -- Steve Reid <steve@edmweb.com>
    Small changes to fit into bglibs
        -- Bruce Guenter <bruce@untroubled.org>
    Translation to simpler C++ Code
        -- Volker Grabsch <vog@notjusthosting.com>
*/
#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include "utils.h"

class SHA1
{
public:
    SHA1();
    SHA1(std::string); // this method was added to use a custom IV
    void update(const std::string &s);
    void update(std::istream &is);
    std::string final();
    std::string final(uint64_t msg_length); // this method was added to use a custom messag length
    static std::string from_file(const std::string &filename);

private:
    uint32_t digest[5];
    std::string buffer;
    uint64_t transforms;
};
