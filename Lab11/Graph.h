#pragma once
#ifndef GRAPH_H
#define GRAPH_H
#include <list>
#include <vector>

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
	int size;
	int pos;
	Node* adj;
	Node findNode(int);
public:
	Graph(int);
	void addNode(int);
	void addEdge(int, int);
	void removeEdge(int, int);
	bool hasEdge(int, int);
	int outEdges(int);
	int inEdges(int);
	int displayGraph();

};

Graph::Graph(int s) {
	size = s;
	pos = 0;
	adj = new Node[size];
}

Node Graph::findNode(int findVal) {
	for (int i = 0;i < pos;i++) {
		if (adj[i].val == findVal) {
			return adj[i];
		}
	}
	return Node(); // Returns empty node if node not found
}

void Graph::addNode(int j) {
	adj[pos] = Node(j);
}

void Graph::addEdge(int in, int out) {
	Node inNode = findNode(in);
	inNode.out.push_back(out);
	Node outNode = findNode(out);
	outNode.in.push_back(in);
}

void Graph::removeEdge(int in, int out) {
	Node inNode = findNode(in);
	inNode.out.;
	Node outNode = findNode(out);
	outNode.in.push_back(in);
}

#endif