#include "MathProblems.h"

bool FEqual(float a, float b, float epsilon) {
	float x = a - b;
	x = (x > 0) ? x : (-1) * x;
	return (x < epsilon);
}
bool FLess(float a, float b, float epsilon)
{
	float x = a - b; 
	return (x < 0 && FEqual(a, b) == false);
}
bool FGreater(float a, float b, float epsilon)
{
	float x = a - b;
	return (x > 0 && FEqual(a, b, epsilon) == false);
}
bool FGreaterEqual(float a, float b, float epsilon)
{
	return FGreater(a,b,epsilon)||FEqual(a,b,epsilon);
}
bool FLessEqual(float a, float b, float epsilon)
{
	return FLess(a, b, epsilon) || FEqual(a, b, epsilon);
}
bool DEqual(double a, double b, double epsilon) {
	double x = a - b;
	x = (x > 0) ? x : (-1) * x;
	return (x < epsilon);
}

bool DLess(double a, double b, double epsilon)
{
	double x = a - b;
	return (x < 0 && DEqual(a, b) == false);
}

bool DGreater(double a, double b, double epsilon)
{
	double x = a - b;
	return (x > 0 && DEqual(a, b, epsilon) == false);
}

bool DGreaterEqual(double a, double b, double epsilon)
{ 
	return DGreater(a, b, epsilon) || DEqual(a, b, epsilon);
}

bool DLessEqual(double a, double b, double epsilon)
{ 
	return DLess(a, b, epsilon) || DEqual(a, b, epsilon);
}
float Q_rsqrt(float number)
{
	const float x2 = number * 0.5F;
	const float threehalfs = 1.5F;

	union {
		float f;
		uint32_t i;
	} conv = { number }; // member 'f' set to value of 'number'.
	conv.i = 0x5f3759df - (conv.i >> 1);
	conv.f *= (threehalfs - (x2 * conv.f * conv.f));
	return conv.f;
}