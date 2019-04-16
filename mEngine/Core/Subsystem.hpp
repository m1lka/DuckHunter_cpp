#ifndef SUBSYSTEM_H
#define SUBSYSTEM_H

#include "mEngine/Core/Object.hpp"

class Subsystem: public Object
{
public:
    Subsystem(Context* context);
    virtual ~Subsystem();

    static string GetTypeInfo() { return string(TypeInfo(Subsystem)); }
    static string GetBaseTypeInfo() { return string(TypeInfo(Obj)); }
};

#endif // SUBSYSTEM_H
