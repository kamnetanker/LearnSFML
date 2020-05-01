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
	float q = _x * _x + _y * _y;
	if (!FEqual(q, 0.0f)) {
		q = Q_rsqrt(q);
		this->x *= q;
		this->y *= q;
		this->length = 1 / q;
	}
}
void Vector::SetVector(float _x, float _y) {
	this->SetPosition(_x, _y);
	float q = _x * _x + _y * _y;
	if (!FEqual(q, 0.0f)) {
		q= Q_rsqrt(q);
		this->x *= q;
		this->y *=q;
		this->length = 1/ q;
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

Vector* Vector::operator*(Vector* _b)
{
	if (_b != nullptr) {
		float x = this->GetX() * _b->GetX() / _b->GetLength();
		float y = this->GetY() * _b->GetY() / _b->GetLength();
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

Vector* Vector::operator/(Vector* _b)
{
	if (_b != nullptr) {
		float x = (this->GetX() / _b->GetX()) * _b->GetLength();
		float y = (this->GetY() / _b->GetY()) * _b->GetLength();
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
void Vector::operator*=(Vector* _b)
{
	if (_b != nullptr) {
		float x = this->GetX() * _b->GetX() / _b->GetLength();
		float y = this->GetY() * _b->GetY() / _b->GetLength();
		this->SetVector(x, y);
	}
	else {
		throw NULLPTRARGEX;
	}
}
void Vector::operator/=(Vector* _b)
{
	if (_b != nullptr) {
		float x = this->GetX() / _b->GetX() * _b->GetLength();
		float y = this->GetY() / _b->GetY() * _b->GetLength();
		this->SetVector(x, y);
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
Line::Line(Position* _a, float _normalx, float _normaly) {
	if (_a != nullptr) {
		this->a = _normalx;
		this->b = _normaly;
		this->Apoint = _a;
		this->c = (-1) * (this->a*_a->GetX()+this->b*_a->GetY());
		this->Bpoint = new Position(_a->GetX() + 1, this->GetY(_a->GetX()+1));
	}
	else {
		throw NULLPTRARGEX;
	}
}
Line::Line(Position* _a, Vector* _normal) {
	if (_a != nullptr&&_normal!=nullptr) {
		this->a = _normal->GetX()*_normal->GetLength();
		this->b = _normal->GetY() * _normal->GetLength();
		this->Apoint = _a;
		this->c = (-1) * (this->a * _a->GetX() + this->b * _a->GetY());
		this->Bpoint = new Position(_a->GetX() + 1, this->GetY(_a->GetX() + 1));
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
bool Line::SegmentBelongment(Position* _arg) {
	float x1 = this->Apoint->GetX(), y1 = this->Apoint->GetY(), x2 = this->Bpoint->GetX(), y2 = this->Bpoint->GetY();
	float x = _arg->GetX(), y = _arg->GetY();
	float ratioX = 0, ratioY = 0;
	if (FEqual(x, x1) && FEqual(y, y1) || FEqual(x, x2) && FEqual(y, y2)) {
		return true;
	}
	else if (!FEqual(x, x1) && !FEqual(y, y1) || !FEqual(x, x2) || !FEqual(y, y2)) {
		ratioX = (x2 - x1) / (x - x1);
		ratioY = (y2 - y1) / (y - y1);
		if (FEqual(ratioX, ratioY) && ratioX >= 1 && ratioY >= 1) {
			return true;
		}
		else if (FEqual(x, x1) && ratioY >= 1) {
			return true;
		}
		else if (FEqual(y, y1) && ratioX >= 1) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}
Position* Line::CheckIntersection(Line* _b, bool _checkBelongment) {
	if (_b != nullptr) {
		float tmp = this->GetB() * _b->GetA() - this->GetA() * _b->GetB();
		float x = 0, y = 0;
		if (tmp != 0) {
			x = (this->GetC() * _b->GetB() - _b->GetC() * this->GetB()) / tmp;
			if (this->GetB() != 0) {
				y = this->GetY(x);
			}
			else if (_b->GetB() != 0) {
				y = _b->GetY(x);
			}
			else {
				return nullptr;
			}
			Position* ret = new Position(x, y);
			if (this->SegmentBelongment(ret) && _b->SegmentBelongment(ret)) {
				return ret;
			}
			else if (_checkBelongment==false) {
				return ret;
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

Position* Collision::CheckLine(Position* _from, Line* _to)
{
	return nullptr;
}

Vector* Collision::GetNormal(Position* _b)
{
	return nullptr;
}

Vector* Collision::CheckCollision(Collision* _b)
{
	if (_b != nullptr) {

		return &Vector(0, 0);
	}
	else {
		throw NULLPTRARGEX;
	}
}

void Collision::Move()
{
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

Ñircle::Circle(float _radius, Position* _initPos, Vector* _initMV)
{
	if (_initPos!=nullptr&&_initMV!=nullptr) {
		this->radius = _radius;
		this->position = _initPos;
		this->mv = _initMV;
	}
	else {
		throw NULLPTRARGEX;
	}
}
Position* Circle::CheckLine(Position* _from, Line* _to) {
	if (_from != nullptr && _to != nullptr) {
		Line tmp = Line(this->position, _to->GetB(), (-1) * _to->GetA());
		Position* bpos = tmp.CheckIntersection(_to, false);
		Vector avec = Vector(bpos->GetX()-_from->GetX(),bpos->GetY()-_from->GetY());
		float newLength = this->radius * this->radius - Vector(bpos->GetX() - this->position->GetX(), bpos->GetY() - this->position->GetY()).GetLength();
		bpos->SetPosition(bpos->GetX()+avec.GetX()*newLength, bpos->GetY()+avec.GetY()*avec.GetLength());
		return bpos;//this is bullshit algorithm.
	}
	else {
		throw NULLPTRARGEX;
	}
}

Vector* Circle::GetNormal(Position* _b)
{
	if (_b != nullptr) {
		float x, y;
		x = _b->GetX() - this->position->GetX();
		y = _b->GetY() - this->position->GetY();
		return new Vector(x,y);
	}
	else {
		throw NULLPTRARGEX;
	}
}

Vector* Circle::CheckCollision(Collision* _b)
{
	if (_b != nullptr) {
		float x, y;
		x = this->position->GetX() + (this->mv->GetX() * this->mv->GetLength());
		y = this->position->GetY() + (this->mv->GetY() * this->mv->GetLength());
		Line* MoveLine = new Line(this->position, new Position(x, y));
		Position* check = _b->CheckLine(this->position, MoveLine);
		if (check != nullptr) {
			if (MoveLine->SegmentBelongment(check)) {

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

void Circle::Move()
{
}

Box::Box(float _width, float _height, Position* _initPos, Vector* _initMV)
{
	if (_initPos != nullptr && _initMV != nullptr) {

	}
	else {
		throw NULLPTRARGEX;
	}

}
Position* Box::CheckLine(Position* _from, Line* _to) {
	if (_from != nullptr && _to != nullptr) {

	}
	else {
		throw NULLPTRARGEX;
	}
}
Vector* Box::GetNormal(Position* _b)
{
	return nullptr;
}
Vector* Box::CheckCollision(Collision* _b)
{
	if (_b!=nullptr) {

	}
	else {
		throw NULLPTRARGEX;
	}
}

void Box::Move()
{
}
