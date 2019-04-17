#ifndef _OBJECT_HPP
#define _OBJECT_HPP

#include <string>
using std::string;

class Context;

#define TypeInfo(type) (#type)

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
