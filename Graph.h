#pragma once 
#include "Edge.h"
#include <vector>
#include <sstream>

class Graph
{
public:
	string name;
	vector<Vertice> vertex;
	vector<Edge> edges;

	Vertice puits, source;

	Graph(): name("NULL"), vertex(NULL), edges(NULL), puits(NULL), source(NULL) {}

	void createVertice(int x, int y, string name)
	{
		Vertice a(x, y, name);

		vertex.push_back(a);
	}

	void createEdge(string name, Vertice *begin, Vertice *end, float cost, float time)
	{
		Edge e(name,  begin,  end,  cost, time);

		edges.push_back(e);
	}

	Vertice getVerticeByName(string s)
	{
		for (vector<Vertice>::iterator i = vertex.begin(); i != vertex.end(); ++i)
			if (i->name == s)
				return *i;
	}

	int nbrVertice() {
		return vertex.size();
	}

	int nbrEdge() {
		return edges.size();
	}


	string toString(Graph & p) const {
		stringstream ss;
		int i;

		ss << "-----------------------------------------------------------------" << endl;
		ss << "# Instance " << name << " a " << p.nbrVertice() << " sommets et " << p.nbrEdge() << " arcs" << endl;
		ss << endl;
		ss << "ressource 1" << endl;
		ss << endl;
		ss << "sectionSommets" << endl;
		for (i = 0; i < p.vertex.size(); i++) {
			ss << p.vertex[i] << endl;
		}
		ss << endl;
		ss << "source" << endl;
		ss << p.source << endl;
		ss << endl;
		ss << "puits" << endl;
		ss << p.puits << endl;
		ss << endl;
		ss << "sectionArcs" << endl;
		for (i = 0; i < p.edges.size(); i++) {
			ss << p.edges[i] << endl;
		}
		ss << endl;
		ss << p.name << " " << p.source << " " << p.puits << endl;
		ss << "-----------------------------------------------------------------" << endl;
		return ss.str();
	}
};