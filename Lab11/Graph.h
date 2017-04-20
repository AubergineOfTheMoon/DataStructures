#pragma once
#ifndef GRAPH_H
#define GRAPH_H
#include<iostream>
#include <algorithm>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

class Node {
public:
	int val;
	vector<int> out;
	vector<int> in;
	Node(int);
};

Node::Node(int v = NULL) {
	val = v;
}

class Graph {
private:
	vector<int> visited;
	int size;
	int pos;
public:
	Graph(int);
	Node* adj;
	void addNode(int);
	void addEdge(int, int);
	void removeEdge(int, int);
	bool hasEdge(int, int);
	vector<int> outEdges(int);
	vector<int> inEdges(int);
	void displayGraph();
	int findNodePos(int);
	class ItemNotFound {
	public: ItemNotFound() {}
	};
	class ItemAlreadyExists {
	public: ItemAlreadyExists() {}
	};
	void DFS(Node);
};

Graph::Graph(int s) {
	size = s;
	pos = 0;
	adj = new Node[size];
}

int Graph::findNodePos(int findVal) {
	for (int i = 0;i < pos;i++) {
		if (adj[i].val == findVal) {
			return i;
		}
	}
	throw ItemNotFound();
}

void Graph::addNode(int j) {
	try {
		int trialPos = findNodePos(j);
	}
	catch (Graph::ItemNotFound err) {
		adj[pos] = Node(j);
		pos++;
		return;
	}
	throw ItemAlreadyExists();
}

void Graph::addEdge(int in, int out) {
	if (!hasEdge(in, out)) {
		int inNodePos = findNodePos(in);
		adj[inNodePos].out.push_back(out);
		int outNodePos = findNodePos(out);
		adj[outNodePos].in.push_back(in);
	}
	else {
		throw ItemAlreadyExists();
	}
}

void Graph::removeEdge(int in, int out) {
	if (hasEdge(in, out)) {
		int inNodePos = findNodePos(in);
		adj[inNodePos].out.erase(std::remove(adj[inNodePos].out.begin(), adj[inNodePos].out.end(), out), adj[inNodePos].out.end());
		int outNodePos = findNodePos(out);
		adj[outNodePos].in.erase(std::remove(adj[outNodePos].in.begin(), adj[outNodePos].in.end(), in), adj[outNodePos].in.end());
	}
	else {
		throw ItemNotFound();
	}
}

bool Graph::hasEdge(int in, int out) {
	int inNodePos = findNodePos(in);
	if (adj[inNodePos].val != NULL) {
		for (int j = 0; j < adj[inNodePos].out.size(); j++) {
			if (adj[inNodePos].out.at(j) == out) {
				return true;
			}
		}
	}
	return false;
}

vector<int> Graph::inEdges(int out) {
	int outNodePos = findNodePos(out);
	return adj[outNodePos].in;
}

vector<int> Graph::outEdges(int in) {
	int inNodePos = findNodePos(in);
	return adj[inNodePos].out;
}

void Graph::displayGraph() {
	cout << "Nodes: Out edges" << endl;
	for (int i = 0; i < pos; i++) {
		cout << adj[i].val << ": ";
		for (int j = 0; j < adj[i].out.size(); j++) {
			cout << adj[i].out.at(j) << " ";
		}
		cout << endl;
	}
}
void Graph::DFS(Node n) {
	if (find(visited.begin(),visited.end(),n.val) == visited.end()) {
		visited.push_back(n.val);
		cout << n.val << endl;
		for (int s = 0; s < n.out.size();s++) {
			DFS(adj[findNodePos(n.out[s])]);
		}
	}
}
#endif