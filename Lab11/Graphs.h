#pragma once
#ifndef GRAPHS_H
#define GRAPHS_H
#include<vector>

template<class T> class Edge {
public:
	Edge* next;
	T* data;
};

template<class T> class Node {
public:
	T* data;
	Node* next;
	Edge* edges;
};

template<class T> class Graph {
private:
	Node<T>* root;
	Node<T>* findNode(T*);
	int numNodes;
public:
	Graph(T*);
	void addNode(T*);
	void addEdge(T*, T*);
	void removeEdge(T*, T*);
	bool hasEdge(T* start, T* end);
	vector<T> outEdges(T*); //returns array of items TODO: change to vectors
	vector<T> inEdges(T* ); //returns array of items TODO: change to vectors
	void displayGraph();
};

#endif


template<class T>
inline Graph::Graph() {
	root = nullptr;
	numNodes = 0;
}

template<class T>
inline void Graph::findNode(T* valToFind) {
	
}
