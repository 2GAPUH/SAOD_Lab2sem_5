#include "OrgGraph.h"
#include <unordered_set>

Edge* OrgGraph::StartSearch(std::string name)
{
	for (auto n : graph)
		if (n->begin == name)
			return n;
	return nullptr;
}

Answer OrgGraph::Search(std::string node, std::unordered_set<std::string> visited, Answer answer)
{
	Answer tmp(0, "");
	Answer maxValue(0, "");
	bool flag = false;
	answer.path += node;
	visited.insert(node);

	for (auto n : graph)
		if (n->begin == node && visited.end() == visited.find(n->end))
		{
			
			tmp = Search(n->end, visited, Answer(answer.value + n->value, answer.path + "->"));
			if (tmp.value > maxValue.value)
				maxValue = tmp;
			flag = true;
		}

	if (flag == false)
	{
		return answer;
	}
	else
		return maxValue;
}

Answer OrgGraph::Search(std::string node)
{
	std::unordered_set<std::string> set;
	return Search(node, set, Answer(0, ""));
}

void OrgGraph::AddEdge()
{
	graph.push_back(new Edge);

	bool flag = true;
	while (flag)
	{
		flag = false;
		std::cout << "Enter start operation name: ";
		
		std::cin >> graph.back()->begin;

		if (graph.back()->begin.empty())
		{
			std::cout << "Enter value!" << std::endl;
			flag = true;
		}

		for (auto n : graph.back()->begin)
		{
			if ((n >= 'A' && n <= 'Z') || (n >= 'a' && n <= 'z'))
				continue;
			else
			{
				std::cout << "The operation name must contain only Latin characters" << std::endl;
				flag = true;
				break;
			}
		}
	}

	flag = true;
	while (flag)
	{
		flag = false;
		std::cout << "Enter end operation name: ";

		std::cin >> graph.back()->end;

		if (graph.back()->end.empty())
		{
			std::cout << "Enter value!" << std::endl;
			flag = true;
		}

		for (auto n : graph.back()->end)
		{
			if ((n >= 'A' && n <= 'Z') || (n >= 'a' && n <= 'z'))
				continue;
			else
			{
				std::cout << "The operation name must contain only Latin characters" << std::endl;
				flag = true;
				break;
			}
		}
	}

	flag = true;
	while (flag)
	{
		flag = false;
		std::cout << "Enter duration of operation : ";

		std::cin >> graph.back()->value;

		if (graph.back()->value <= 0)
		{
			std::cout << "The duration of operation must be greater than zero" << std::endl;
			flag = true;
		}
	}
}

void OrgGraph::ConsolePrint()
{
	int tmp2 = 0;

	for (auto n : graph)
	{
		std::cout << n->begin;
		tmp2 = n->begin.length();
		for (int i = 0; i < 6 - tmp2; i++)
			std::cout << "-";
		std::cout << ">";

		std::cout << n->end;
		tmp2 = n->end.length();
		for (int i = 0; i < 6 - tmp2; i++)
			std::cout << " ";
	
		std::cout << n->value << std::endl;
	}
}

void OrgGraph::Task()
{
	std::string tmp;

	std::cout << "Enter start operation: ";

	std::cin >> tmp;

	if (StartSearch(tmp) == nullptr)
	{
		std::cout << "This vertex does not exist!" << std::endl;
		return;
	}

	Answer tmp1 = Search(tmp);
	std::cout << "Max value: " << tmp1.value << std::endl;
	std::cout << "Path: " << tmp1.path << std::endl;
}

OrgGraph::~OrgGraph()
{
	for (auto n : graph)
		delete n;

	graph.clear();
}
