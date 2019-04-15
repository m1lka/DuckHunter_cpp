#ifndef _OBJECT_HPP
#define _OBJECT_HPP

#include <string>

#define TypeInfo(type) (#type)

class Context;

class Object 
{
public:
    Object(Context* context): _context(context) {}
    virtual ~Object() {}

    static std::string GetTypeInfo() { return std::string(TypeInfo(Object)); }
    static std::string GetBaseTypeInfo() { return std::string(""); }

    Context* GetContext() const { return _context; }

private:
    Context* _context;
};

#endif // _OBJECT_HPP
