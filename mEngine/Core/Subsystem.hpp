#ifndef SUBSYSTEM_H
#define SUBSYSTEM_H

#pragma once

#include "mEngine/Core/Object.hpp"

class Subsystem: public Object
{
public:
    Subsystem(Context* context);
    virtual ~Subsystem();

    static string GetTypeInfo() { return string("Subsystem"); }
    static string GetBaseTypeInfo() { return string("Object"); }
};

#endif // _SUBSYSTEM_H
