#include<iostream>
#include"Graph.h"
using namespace std;

int main() {
	int value;
	int maxNodes;
	/*do {
		cout << "What would you like the maximum number of nodes in the graph to be: ";
		cin >> maxNodes;
	} while (maxNodes <= 0);
	*/
	//Graph myGraph = Graph(maxNodes);
	Graph myGraph = Graph(10);
	int choice = 0;
	int tempNode, tempEdge1, tempEdge2;
	bool edgeFound;
	vector<int> tempEdges;
	// bool flag;

	//Task 2
	for (int i = 0; i < 10; i++) {
		myGraph.addNode(i);
	}
	myGraph.addEdge(0, 2); 
	myGraph.addEdge(0, 3); 
	myGraph.addEdge(0, 5); 
	myGraph.addEdge(1, 3);
	myGraph.addEdge(1, 4);
	myGraph.addEdge(1, 6);
	myGraph.addEdge(2, 4);
	myGraph.addEdge(2, 0);
	myGraph.addEdge(2, 7);
	myGraph.addEdge(3, 0);
	myGraph.addEdge(3, 1);
	myGraph.addEdge(3, 8);
	myGraph.addEdge(4, 1);
	myGraph.addEdge(4, 2);
	myGraph.addEdge(4, 9);
	myGraph.addEdge(5, 9);
	myGraph.addEdge(5, 0);
	myGraph.addEdge(5, 6);
	myGraph.addEdge(6, 5);
	myGraph.addEdge(6, 1);
	myGraph.addEdge(6, 7);
	myGraph.addEdge(7, 6);
	myGraph.addEdge(7, 2);
	myGraph.addEdge(7, 8);
	myGraph.addEdge(8, 7);
	myGraph.addEdge(8, 3);
	myGraph.addEdge(8, 9);
	myGraph.addEdge(9, 8);
	myGraph.addEdge(9, 4);
	myGraph.addEdge(9, 5);

	do {
		cout << "***************************************" << endl;
		cout << "Please select the the action you would like to complete" << endl;
		cout << "1. Add a node to the graph" << endl;
		cout << "2. Add an edge to the graph" << endl;
		cout << "3. Remove an edge from the graph" << endl;
		cout << "4. Find an edge in the graph" << endl;
		cout << "5. Find the out edges of a node" << endl;
		cout << "6. Find the in edges of a node" << endl;
		cout << "7. Display the graph as adjacency lists" << endl;
		cout << "8. Perform a breadth first search" << endl;
		cout << "0. Exit" << endl;
		cout << "Enter the number of the choice you wish to select: ";
		cin >> choice;
		if (cin.fail()) {
			choice = 10;
			cin.clear();
			cin.ignore(10000, '\n');
		}
		switch (choice) {
		case 1: cout << "You have chosen to add a node to the graph. " << endl;
			cout << "Enter the number you would like to add ";
			cin >> tempNode;
			try {
				myGraph.addNode(tempNode);
			}
			catch (Graph::ItemAlreadyExists err) {
				cout << "This node already exists. Cannot have multiple nodes of same value." << endl;
			}
			break;
		case 2: cout << "You have chosen to add an edge." << endl;
			cout << "Enter the node from which the edge originates: ";
			cin >> tempEdge1;
			cout << "Enter the node which the edge is pointing to: ";
			cin >> tempEdge2;
			try {
				myGraph.addEdge(tempEdge1, tempEdge2);
			}
			catch (Graph::ItemNotFound err) {
				cout << "Node does not exist. Edge could not be added." << endl;
			}
			catch (Graph::ItemAlreadyExists err) {
				cout << "This edge already exists. Cannot add it again." << endl;
			}
			break;
		case 3: cout << "Enter the edge you would like to remove- In Edge: ";
			cin >> tempEdge1;
			cout << "Enter the edge you would like to remove- Out Edge: ";
			cin >> tempEdge2;
			try {
				myGraph.removeEdge(tempEdge1, tempEdge2);
			}
			catch (Graph::ItemNotFound err) {
				cout << "Edge not found" << endl;
			}
			break;
		case 4: cout << "Enter the edge you would like to find- In Node: ";
			cin >> tempEdge1;
			cout << "Enter the edge you would like to find- Out Node: ";
			cin >> tempEdge2;
			try {
				edgeFound = myGraph.hasEdge(tempEdge1, tempEdge2);


				if (myGraph.hasEdge(tempEdge1, tempEdge2)) {
					cout << "The edge has been found." << endl;
				}
				else {
					cout << "Edge not found." << endl;
				}
			}
			catch (Graph::ItemNotFound err) {
				cout << "A node in the edge does not exist." << endl;
			}
			break;
		case 5: cout << "Enter the node whose out edges you would like to find: ";
			cin >> tempNode;
			cout << "Out edges of " << tempNode << ": ";
			try {
				tempEdges = myGraph.outEdges(tempNode);
				for (int j = 0; j < tempEdges.size(); j++) {
					cout << tempEdges.at(j) << " ";
				}
				cout << endl;
			}
			catch (Graph::ItemNotFound err) {
				cout << "Node not found in graph." << endl;
			}
			break;
		case 6: cout << "Enter the node whose in edges you would like to find: ";
			cin >> tempNode;
			cout << "In edges of " << tempNode << ": ";
			try {
				tempEdges = myGraph.inEdges(tempNode);
				for (int j = 0; j < tempEdges.size(); j++) {
					cout << tempEdges.at(j) << " ";
				}
				cout << endl;
			}
			catch (Graph::ItemNotFound err) {
				cout << "Node not found in graph." << endl;
			}
			break;
		case 7: myGraph.displayGraph();
			break;
		case 8:
			cout << "Enter the value of the node you would like to start from: ";
			cin >> value;
			myGraph.breadthFirstSearch(myGraph.adj[myGraph.findNodePos(value)]);
			break;
		case 0: cout << "You have chosen to exit." << endl;
			break;
		default: cout << "You have entered an invalid choice." << endl;
			break;
		}
	} while (choice != 0);
	return 0;
}