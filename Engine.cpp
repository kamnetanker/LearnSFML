#include "Engine.h"
#ifndef NULLPTRARGEX//The row definition that is used when receiving a null pointer in the function arguments.
#define NULLPTRARGEX L"Nullptr argument exception"
#endif
Position::Position(float _x, float _y) {
	this->x = _x;
	this->y = _y;
}

void Position::SetX(float _x) {
	this->x = _x;
}
void Position::SetY(float _y) {
	this->y = _y;
}
void Position::SetPosition(float _x, float _y) {
	this->x = _x;
	this->y = _y;
}
float Position::GetX() {
	return this->x;
}
float Position::GetY() {
	return this->y;
}
Vector::Vector(float _x, float _y) : Position(_x, _y) { 
	this->length = sqrt(_x * _x + _y * _y);
	if (this->GetLength() != 0) {
		this->x /= this->length;
		this->y /= this->length;
	}
}
void Vector::SetVector(float _x, float _y) {
	this->SetPosition(_x, _y);
	this->length = sqrt(_x * _x + _y * _y);
	if (this->GetLength() != 0) {
		this->x /= this->length;
		this->y /= this->length;
	}
}
void Vector::SetX(float _x) {
	this->SetVector(_x, this->y);
}
void Vector::SetY(float _y) {
	this->SetVector(this->x, _y);
}
float Vector::GetLength()
{
	return this->length;
}
Vector* Vector::operator+(Vector* _b) {
	if(_b!=nullptr){
	float x = this->GetX() * this->GetLength()+_b->GetX()*_b->GetLength();
	float y = this->GetY() * this->GetLength() + _b->GetY() * _b->GetLength();
	return new Vector(x, y); 
	}
	else {
		throw NULLPTRARGEX;
	}
}

Vector* Vector::operator-(Vector* _b)
{
	if (_b != nullptr) {
		float x = this->GetX() * this->GetLength - _b->GetX() * _b->GetLength();
		float y = this->GetY() * this->GetLength - _b->GetY() * _b->GetLength();
		return new Vector(x, y);
	}
	else {
		throw NULLPTRARGEX;
	}
}

void Vector::operator+=(Vector* _b)
{
	if (_b != nullptr) {
		float x = this->GetX() * this->GetLength() + _b->GetX() * _b->GetLength();
		float y = this->GetY() * this->GetLength() + _b->GetY() * _b->GetLength();
		this->SetVector(x, y);
	}
	else {
		throw NULLPTRARGEX;
	}
}

void Vector::operator-=(Vector* _b)
{
	if(_b!=nullptr){
	float x = this->GetX() * this->GetLength - _b->GetX() * _b->GetLength();
	float y = this->GetY() * this->GetLength - _b->GetY() * _b->GetLength();
	this->SetVector(x, y);
	}
	else {
		throw NULLPTRARGEX;
	}
}
 

Vector* Vector::operator*(float* _b)
{
	if(_b!=nullptr){
	float x= this->GetX() * this->GetLength() * (*_b);
	float y= this->GetY() * this->GetLength() * (*_b);
	return new Vector(x, y);
	}
	else {
		throw NULLPTRARGEX;
	}
}

Vector* Vector::operator/(float* _b)
{
	if(_b!=nullptr){
	float x;
	float y;
	if(*_b!=0){
	 x = this->GetX() * this->GetLength() / (*_b);
	 y = this->GetY() * this->GetLength() / (*_b);
	}
	else {
		x = 0;
		y = 0;
	}
	return new Vector(x, y);
	}
	else {
		throw NULLPTRARGEX;
	}
}
 

void Vector::operator*=(float* _b)
{
	if(_b!=nullptr){
	float x = this->GetX() * this->GetLength() * (*_b);
	float y = this->GetY() * this->GetLength() * (*_b);
	this->SetVector(x, y);
	}
	else {
		throw NULLPTRARGEX;
	}
}

void Vector::operator/=(float* _b)
{
	if(_b!=nullptr){
	float x;
	float y;
	if (*_b != 0) {
		x = this->GetX() * this->GetLength() / (*_b);
		y = this->GetY() * this->GetLength() / (*_b);
	}
	else {
		x = 0;
		y = 0;
	}
	this->SetVector(x,y);
	}
	else {
		throw NULLPTRARGEX;
	}
}
Line::Line(Position* _a, Position* _b) { 
	if(_a!=nullptr&&_b!=nullptr){
	this->A = _a;
	this->B = _b;

	}
	else {
		throw NULLPTRARGEX;
	}
}
void Line::SetA(Position* _a) {
	if (_a != nullptr) {

	}
	else {
		throw NULLPTRARGEX;
	}
}
void Line::SetB(Position* _b) {

}
Position* Line::GetA() {

}
Position* Line::GetB() {

}
Vector Line::GetNormal() {

}
Position* Line::CheckIntersection(Line* _b) {

}
 

void Collision::SetVelocity(int _x, int _y)
{
	this->mv->SetVector(_x, _y);
}

void Collision::SetVelocity(Vector* _v)
{
	delete this->mv;
	this->mv = _v;
}

Vector Collision::CheckCollision(Collision& _b)
{
	return Vector(0,0);
}

Engine::Engine(RenderWindow* _window) {
	this->window = _window;
	this->event = new Event();
}
void Engine::Update() {
	CircleShape shape(100.f);
	shape.setFillColor(Color::Green);
	while (this->window->isOpen()) {
		while (this->window->pollEvent(*(this->event))) {
			if (this->event->type == Event::Closed) {
				this->window->close();
			}
			if (this->event->type == Event::Resized) {
				this->window->setSize(Vector2u(this->event->size.width, this->event->size.height));
				this->window->setView(View(Vector2f(this->event->size.width/2, this->event->size.height/2), Vector2f(this->event->size.width, this->event->size.height)));
			}
		}
		this->window->clear();
		for (int i = 0; i < this->objects.size(); i++) {
			this->objects[i]->Update(this->window);
		}
		this->window->draw(shape);
		this->window->display();
	}
}
void Engine::AddObj(Object* _newObj) {
	if(_newObj!=nullptr)this->objects.push_back(_newObj);
}


