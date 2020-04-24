#pragma once
#define _MATH_PROBLEMS_
#define _PROBLEM_EPSILON 0.00001
#ifndef HEADERS
#include "Headers.h"
#endif
bool FEqual(float a, float b, float epsilon = _PROBLEM_EPSILON);
bool FLess(float a, float b, float epsilon = _PROBLEM_EPSILON);
bool FGreater(float a, float b, float epsilon = _PROBLEM_EPSILON);
bool FGreaterEqual(float a, float b, float epsilon = _PROBLEM_EPSILON);
bool FLessEqual(float a, float b, float epsilon = _PROBLEM_EPSILON);
bool DEqual(double a, double b, double epsilon = _PROBLEM_EPSILON);
bool DLess(double a, double b, double epsilon = _PROBLEM_EPSILON);
bool DGreater(double a, double b, double epsilon = _PROBLEM_EPSILON);
bool DGreaterEqual(double a, double b, double epsilon = _PROBLEM_EPSILON);
bool DLessEqual(double a, double b, double epsilon = _PROBLEM_EPSILON);
float Q_rsqrt(float number);//Thanks John Carmack for this.