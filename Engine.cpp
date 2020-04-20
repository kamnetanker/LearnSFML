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
	this->length = sqrt(_x * _x + _y * _y);//this is Shit
	if (this->GetLength() != 0) {
		this->x /= this->length;
		this->y /= this->length;
	}
}
void Vector::SetVector(float _x, float _y) {
	this->SetPosition(_x, _y);
	this->length = sqrt(_x * _x + _y * _y);//this is Shit too
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
		throw NULLPTRARGEX;//I use non-wrapped "throws" so that when debugging, you can see exactly where the erroneous data was passed
	}
}

Vector* Vector::operator-(Vector* _b)
{
	if (_b != nullptr) {
		float x = this->GetX() * this->GetLength() - _b->GetX() * _b->GetLength();
		float y = this->GetY() * this->GetLength() - _b->GetY() * _b->GetLength();
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
	float x = this->GetX() * this->GetLength() - _b->GetX() * _b->GetLength();
	float y = this->GetY() * this->GetLength() - _b->GetY() * _b->GetLength();
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
	this->Apoint = _a;
	this->Bpoint = _b; 
	float x1=_a->GetX(), y1=_a->GetY(), x2=_b->GetX(), y2=_b->GetY();  
	this->a = y1 - y2;
	this->b = x2 - x1;
	this->c = x1 * y2 - x2 * y1;
	}
	else {
		throw NULLPTRARGEX;
	}
}
void Line::SetA(Position* _a) {
	if (_a != nullptr) {
		this->Apoint = _a;
		float x1 = _a->GetX(), y1 = _a->GetY(), x2 = this->Bpoint->GetX(), y2 = this->Bpoint->GetY(); 
		this->a = y1 - y2;
		this->b = x2 - x1;
		this->c = x1 * y2 - x2 * y1;
	}
	else {
		throw NULLPTRARGEX;
	}
}
void Line::SetB(Position* _b) {
	if (_b != nullptr) {
		this->Bpoint = _b;
		float x1 = this->Apoint->GetX(), y1 = this->Apoint->GetY(), x2 = _b->GetX(), y2 = _b->GetY();
		 
		this->a = y1 - y2;
		this->b = x2 - x1;
		this->c = x1 * y2 - x2 * y1;
	}
	else {
		throw NULLPTRARGEX;
	}
}
Position* Line::GetApoint() {
	return this->Apoint;
}
Position* Line::GetBpoint() {
	return this->Bpoint;
}
float Line::GetA() {
	return this->a;
}
float Line::GetB() {
	return this->b;
}
float Line::GetC() {
	return this->c;
}
float Line::GetY(float x) {
	if (this->GetB() == 0) {
		return 0;
	}
	else {
		return ((-1) * this->GetA() * x - this->GetC()) / this->GetB();
	}
}
Vector Line::GetNormal() {//this returns copy of normal
	Vector ret(this->GetA(), this->GetB());
	return ret;
}
Position* Line::CheckIntersection(Line* _b) {
	if (_b != nullptr) {
		float tmp = this->GetB() * _b->GetA() - this->GetA() * _b->GetB();
		float x = 0, y = 0;
		if (tmp != 0) {
			x = (this->GetC() - _b->GetC()) / tmp;
			if (this->GetB() != 0) {
				y = this->GetY(x);
			}
			else if (_b->GetB() != 0) {
				y = _b->GetY(x);
			}
			else {
				return nullptr;
			}
			float x1 = this->Apoint->GetX(), y1 = this->Apoint->GetY(), x2 = this->Bpoint->GetX(), y2 = this->Bpoint->GetY();
			float ratioX, ratioY;
			if (FEqual(x,x1) && FEqual(y,y1)) {
				return new Position(x, y);
			}
			else if (!FEqual(x,x1) && !FEqual(y,y1)) {
				ratioX = (x2 - x1) / (x - x1);
				ratioY = (y2 - y1) / (y - y1);
				if (FEqual(ratioX, ratioY) && ratioX>=1 && ratioY>=1) {
					return new Position(x, y);
				}
				else {
					return nullptr;
				}
			}
			else {
				return nullptr;
			}
		}
		else {
			return nullptr;
		}
	}
	else {
		throw NULLPTRARGEX;
	}
}
 

void Collision::SetVelocity(int _x, int _y)
{
	this->mv->SetVector(_x, _y);
}

void Collision::SetVelocity(Vector* _v)
{
	if(_v!=nullptr){
	delete this->mv;
	this->mv = _v;
	}
	else {
		throw NULLPTRARGEX;
	}
}

Vector Collision::CheckCollision(Collision* _b)
{
	if (_b != nullptr) {
		return Vector(0, 0);
	}
	else {
		throw NULLPTRARGEX;
	}
}

Engine::Engine(RenderWindow* _window) {
	if (_window != nullptr) {
		this->window = _window;
		this->event = new Event();
	}
	else {
		throw NULLPTRARGEX;
	}
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
	if (_newObj != nullptr) {
		this->objects.push_back(_newObj);
	}
	else {
		throw NULLPTRARGEX;
	}

}


