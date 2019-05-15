#ifndef VECTOR2_HPP
#define VECTOR2_HPP

struct Vector2_t
{
public:
	Vector2_t(float X, float Y): x(X), y(Y) { }
	
	float x;
	float y;
};

using Vector2 = struct Vector2_t;

#endif