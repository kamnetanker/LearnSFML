#pragma once
#ifndef HEADERS
#include "Headers.h"
#endif
#ifndef _MATH_PROBLEMS_
#include "MathProblems.h"
#endif
#ifndef _SFML_Engine
#define _SFML_Engine
#endif 
class Position {
protected:
	float x, y; 
public: 
	Position(float _x, float _y);
	virtual void SetX(float _x);
	virtual void SetY(float _y);
	virtual void SetPosition(float _x, float _y);
	virtual float GetX();
	virtual float GetY();
};
class Vector:public Position{
protected: 
	float length;
public: 
	Vector(float _x, float _y);
	void SetVector(float _x, float _y);
	void SetX(float _x);
	void SetY(float _y);
	float GetLength();
	Vector* operator+(Vector* _b);
	Vector* operator-(Vector* _b); 
	void operator+=(Vector* _b);
	void operator-=(Vector* _b); 
	Vector* operator*(float* _b);
	Vector* operator*(Vector* _b);
	Vector* operator/(float* _b); 
	Vector* operator/(Vector* _b);
	void operator*=(float* _b);
	void operator/=(float* _b);
	void operator*=(Vector* _b);
	void operator/=(Vector* _b);
};
class Line {
protected:  
	Position* Apoint;
	Position* Bpoint;
	float a,b,c;
private: 
public: 
	Line(Position* _a, Position* _b);
	Line(Position* _a, float _normalx, float _normaly);
	Line(Position* _a, Vector* _normal);
	void SetA(Position* _a);
	void SetB(Position* _b);
	Position* GetApoint();
	Position* GetBpoint();
	float GetA();
	float GetB();
	float GetC();
	float GetY(float x);
	Vector GetNormal();
	bool SegmentBelongment(Position* _arg);
	Position* CheckIntersection(Line* _b, bool _checkBelongment = true);
};

class Collision {
protected:
	Collision();
	Position* position;
	Vector* mv;//Movement Vector = mv
public:
	virtual void SetVelocity(int _x, int _y);
	virtual void SetVelocity(Vector* _v);
	virtual Position* CheckLine(Position* _from, Line* _to);//checking the object's own intersections. I will use delegation of responsibilities.
	virtual Vector* GetNormal(Position* _b);
	virtual Vector* CheckCollision(Collision* _b);
	virtual void Move();
};
class Circle :public Collision {
protected:
	float radius; 
public:
	Circle(float _radius, Position* _initPos, Vector* _initMV = new Vector(0, 0));
	Position* CheckLine(Position* _from, Line* _to);
	Vector* GetNormal(Position* _b);
	Vector* CheckCollision(Collision* _b);
	void Move();
};
class Box :public Collision{
protected:
	float width, height;
	Line square[4];//Square collider
public:
	Box(float _width, float _height, Position* _initPos, Vector* _initMV = new Vector(0, 0));
	Position* CheckLine(Position* _from, Line* _to);
	Vector* GetNormal(Position* _b);
	Vector* CheckCollision(Collision* _b);
	void Move();
};

class Object {
protected:
	Collision* collision; 
public: 
	virtual void Update(RenderWindow* _window)=0;
}; 
class Engine {
protected: 
	RenderWindow* window;
	Event* event;
	vector<Object*> objects;
public:
	Engine(RenderWindow* _window);
	void Update();
	void AddObj(Object* _newObj);
};









