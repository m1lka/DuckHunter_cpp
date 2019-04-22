#ifndef _OBJECT_HPP
#define _OBJECT_HPP

#include <string>
using std::string;

#include "mEngine/Core/Context.hpp"

#define TypeInfo(type) (#type)

class Object 
{
public:
    Object(Context* context): _context(context) {}
    virtual ~Object() {}

    static std::string GetTypeInfo() { return std::string(TypeInfo(Object)); }
    static std::string GetBaseTypeInfo() { return std::string(""); }

    Context* GetContext() const { return _context; }

    template<typename T>
    T* GetSubsystem() const
    {
        return _context->GetSubsystem<T>();
    }

    Subsystem* GetSubsystem(string type) const
    {
        return _context->GetSubsystem(type);
    }

protected:
    Context* _context;
};

#endif // _OBJECT_HPP
