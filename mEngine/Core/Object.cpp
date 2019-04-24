#include "mEngine/Core/Object.hpp"
#include "mEngine/Core/Context.hpp"

Object::Object(Context* context):
    _context(context)
{
    cerr << "Goodbye Object::Object\n";
}

Object::~Object()
{

}
