#pragma once

#include"Graph.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;
class gprLoader
{
public:

	void vertexListConstructor(ifstream& doc, string& content, Graph &graph)
	{

		vector<string> verticeBuffer;
		getline(doc, content, '\n');

		do{
			split(content, '  ', verticeBuffer);
			graph.createVertice(stoi(verticeBuffer[1]), stoi(verticeBuffer[2]), verticeBuffer[0]);
			getline(doc, content, '\n');
		} while (!content.empty());




	}
	void edgesListConstructor(ifstream& doc, string& content, Graph &graph)
	{
		vector<string> edgeBuffer;
		getline(doc, content, '\n');

		do{
			split(content, '  ', edgeBuffer);
			graph.createEdge(edgeBuffer[0], graph.getVerticeByName(edgeBuffer[1]), graph.getVerticeByName(edgeBuffer[2]), stof(edgeBuffer[3], nullptr), stof(edgeBuffer[4], nullptr));
			getline(doc, content, '\n');
		} while (!content.empty());
	}
	void split(const string& s, char delimiter, vector<string>& tokens)
	{

		string token;
		istringstream tokenStream(s);
		while (getline(tokenStream, token, delimiter))
		{
			if(!token.empty())
				tokens.push_back(token);
		}

	}

	Graph operator() (string path)
	{

		string content;

		ifstream document(path, ios::in);
		if (!document)
		{
			cout << "Impossible d'ouvrir le fichier, le graphe n'as pas été chargé" << endl;
			return NULL;
		}
		Graph graph("test");
	
		
		
	


		while (getline(document, content, '\n'))
		{
			if (content == "sectionSommets")
			{
				vertexListConstructor(document, content, graph);
			}
			if (content == "sectionArcs")
			{
				edgesListConstructor(document, content, graph);
			}
			if (content == "puits")
			{
				getline(document, content, '\n');
				graph.puits = graph.getVerticeByName(content);
			}
			if (content == "sources")
			{
				getline(document, content, '\n');
				graph.source = graph.getVerticeByName(content);
			}
		}
		document.close();
		return graph;

	
	}


};
