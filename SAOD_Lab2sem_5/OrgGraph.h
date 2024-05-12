#pragma once
#include <vector>
#include <iostream>
#include <unordered_set>

class Answer
{
public:
	int value;
	std::string path;
	
	Answer(int value, std::string path) : value(value), path(path) {};
};

class Edge
{
public:
	int value = NULL;
	std::string begin = "";
	std::string end = "";
};

class OrgGraph
{
private:
	std::vector<Edge*> graph;
	Edge* StartSearch(std::string name);
	Answer Search(std::string node, std::unordered_set<std::string> visited, Answer answer);
	Answer Search(std::string node);

public:
	void AddEdge();
	void ConsolePrint();
	void Task();

	~OrgGraph();

};

