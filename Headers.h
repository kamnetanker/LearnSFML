#pragma once
#ifndef HEADERS
#define HEADERS
#endif
#ifndef _IOSTREAM_
#include <iostream>
#endif // _IOSTREAM_
#ifndef _CSTDLIB_
#include <cstdlib>
#endif // _IOSTREAM_
#ifndef _CMATH_
#include <cmath>
#endif // _CMATH_
#ifndef _INC_TIME
#include <time.h>
#endif // _INC_TIME
#ifndef _RANDOM_
#include <random>
#endif // _RANDOM_ 
#ifndef _CSTDINT_
#include <cstdint>
#endif//_CSTDINT_

#ifdef _IOSTREAM_
using namespace std;
#endif // _IOSTREAM_

//SelfWrited headers
#ifndef _MMG_
#include "MemoryManager.h"
#include "MemoryManager.cpp"
#endif

#ifndef _NODE_
#include "Nodes.h"
#endif

#ifndef _LST_
#include "Lst.h"
#include "Lst.cpp"
#endif

#ifndef _MATH_PROBLEMS_
#include "MathProblems.h"
//#include "MathProblems.cpp"
#endif
//End SelfWrited headers

#ifndef SFML_GRAPHICS_HPP
#include <SFML/Graphics.hpp>
using namespace sf;
#endif
#ifndef _SFML_Engine
#include "Engine.h"
//#include "Engine.cpp"
#endif