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
