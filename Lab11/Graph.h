#pragma once
#ifndef GRAPH_H
#define GRAPH_H
#include<iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include "OrderedList.h"

using namespace std;

class Node {
public:
	int val;
	int distance;
	vector<int> out;
	vector<int> in;
	Node(int);
	bool operator==(Node);
};

Node::Node(int v = NULL) {
	val = v;
}

bool Node::operator==(Node n) {
	return val == n.val;
}

class Graph {
private:
	int size;
	int pos;
	vector<int> visited;
	vector<Node> vals;
public:
	Node* adj;
	int findNodePos(int);
	Graph(int);
	void addNode(int);
	void addEdge(int, int);
	void removeEdge(int, int);
	bool hasEdge(int, int);
	vector<int> outEdges(int);
	vector<int> inEdges(int);
	void displayGraph();
	void breadthFirstSearch(Node);
	void recursiveBFS(Node, int);
	class ItemNotFound {
	public: ItemNotFound() {}
	};
	class ItemAlreadyExists {
	public: ItemAlreadyExists() {}
	};
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

void Graph::breadthFirstSearch(Node n) {
	visited= vector<int>(0);
	vals= vector<Node>(0);
	recursiveBFS(n, 0);
	for (int i = 0; i < vals.size(); i++) {
		cout << vals[i].val << " ";
	}
	cout << endl;
}

void Graph::recursiveBFS(Node n, int d) {
	
	if (find(visited.begin(), visited.end(), findNodePos(n.val)) == visited.end() || d < n.distance) {// If the node is in the visited list
		if (d < n.distance) {
			// Remove old ones to be readded
			vals.erase(remove(vals.begin(), vals.end(), findNodePos(n.val)), vals.end());
		}
		else {
			visited.insert(visited.begin(), findNodePos(n.val));
		}
		n.distance = d;
		// If the node isn't found in the visited, add it to visited
		adj[findNodePos(n.val)].distance = d;

		// Put node in vector 
		int j = 0; // index of sorted vector
		int thisDistance = adj[findNodePos(n.val)].distance;
		while (j < vals.size() && thisDistance > vals[j].distance) { // while you are 
			j++;
		}
		vals.insert(vals.begin()+j, adj[findNodePos(n.val)]);
		for (int j = 0; j < n.out.size(); j++) {
			Node outNode = adj[n.out[j]];
			recursiveBFS(outNode, d + 1);
		}
			
	}
}

#endif