#pragma once
#ifndef HEADERS
#include "Headers.h"
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
	Vector* operator/(float* _b); 
	void operator*=(float* _b);
	void operator/=(float* _b);
};
class Line {
protected: 
	Vector* normal;
	Position* A;
	Position* B;
private: 
public: 
	Line(Position* _a, Position* _b);
	void SetA(Position* _a);
	void SetB(Position* _b);
	Position* GetA();
	Position* GetB();
	Vector GetNormal();
	Position* CheckIntersection(Line* _b);
};

class Collision {
protected:
	Position* position;
	Vector* mv;//Movement Vector = mv
public:
	virtual void SetVelocity(int _x, int _y);
	virtual void SetVelocity(Vector* _v);
	virtual Vector CheckCollision(Collision& _b);
	virtual void Move();
};
class Sphere:public Collision {
protected:
	float radius; 
public:
	Sphere(float radius, Position* initPos, Vector* initMV = new Vector(0, 0));
	Vector CheckCollision(Collision& _b);
	void Move();
};
class Box :public Collision{
protected:
	float width, height;
	Line square[4];//Square collider
public:
	Box(float _width, float _height, Position* initPos, Vector* initMV = new Vector(0, 0));
	Vector CheckCollision(Collision& _b);
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








