#pragma once
#include <string>
#include <iostream>

using namespace std;

class Vertice
{
public: 
	int x, y;
	string name;

	Vertice(int x, int y, string name) :x(x), y(y), name(name){}
	Vertice() :x(0), y(0), name("NULL") {}



	friend ostream & operator<< (ostream & os, const Vertice & v) {
		os << v.name << v.x << v.y << endl;
		return os;
	}
};