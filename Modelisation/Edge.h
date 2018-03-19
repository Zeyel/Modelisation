#include "Vertice.h"


class Edge
{
public:
	Vertice *begin, *end;
	float time, cost;
	string name;


	Edge(string name, Vertice *begin, Vertice *end, float cost, float time) :name(name), begin(begin), end(end), cost(cost), time(time) {}
	Edge() :name(NULL), cost(NULL), time(NULL), begin(NULL), end(NULL) {
	}

	friend ostream & operator<< (ostream & os, const Edge & v) {
		os << v.name << v.begin << v.end << v.cost << v.time << endl;
		return os;
	}
};