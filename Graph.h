#pragma once 
#include "Edge.h"
#include <vector>
#include <sstream>

class Graph
{
public:
	string name;
	vector<Vertice*> vertex;
	vector<Edge*> edges;

	Vertice *puits, *source;

	Graph(string name): name(name),puits(NULL), source(NULL){}

	void createVertice(int x, int y, string name)
	{
		Vertice *a = new Vertice(x, y, name);

		vertex.push_back(a);
	}

	void createEdge(string name, Vertice *begin, Vertice *end, float cost, float time)
	{
		Edge *e = new Edge(name,  begin,  end,  cost, time);

		edges.push_back(e);
	}

	Vertice* getVerticeByName(string s)
	{
		for (vector<Vertice*>::iterator i = vertex.begin(); i <= vertex.end(); ++i)
			if (s=="oui")
				return *i;
	}

	int Graph::nbrVertice() {
		return vertex.size();
	}

	int Graph::nbrEdge() {
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
			ss << p.vertex[i]->name << " " << p.vertex[i]->x << " " << p.vertex[i]->y << endl;
		}
		ss << endl;
		ss << "source" << endl;
		ss << p.source->name << endl;
		ss << endl;
		ss << "puits" << endl;
		ss << p.puits->name << endl;
		ss << endl;
		ss << "sectionArcs" << endl;
		for (i = 0; i < p.edges.size(); i++) {
			ss << p.edges[i]->name << " " << p.edges[i]->begin->name << " " << p.edges[i]->end->name << " " << p.edges[i]->cost << " " << p.edges[i]->time << endl;
		}
		ss << endl;
		ss << p.name << " " << p.source->name << " " << p.puits->name << endl;
		ss << "-----------------------------------------------------------------" << endl;
		return ss.str();
	}
};