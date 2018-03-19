#pragma once

#include"Graph.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;
class gprLoader
{
	void vertexListConstructor(ifstream& doc, string& content, Graph graph)
	{

		vector<string> verticeBuffer;
		getline(doc, content, '\n');

		do{
			split(content, '  ', verticeBuffer);
			graph.createVertice(stoi(verticeBuffer[0]), stoi(verticeBuffer[1]), verticeBuffer[2]);
		} while (!content.empty());




	}
	void edgesListConstructor(ifstream& doc, string& content, Graph *graph)
	{
		vector<string> edgeBuffer;
		getline(doc, content, '\n');

		do{
			split(content, '  ', edgeBuffer);
			graph->createEdge(edgeBuffer[0], graph->getVerticeByName(edgeBuffer[1]), graph->getVerticeByName(edgeBuffer[2]), stof(edgeBuffer[3]), stof(edgeBuffer[4]));
		} while (!content.empty());
	}

	void split(const string& s, char delimiter, vector<string>& tokens)
	{

		string token;
		istringstream tokenStream(s);
		while (getline(tokenStream, token, delimiter))
		{
			tokens.push_back(token);
		}

	}


};
