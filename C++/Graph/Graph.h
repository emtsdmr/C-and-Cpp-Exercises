#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;
struct Node;
struct Edge{
	Node* start;
	Node* finish;
	double weight;
	Edge(Node* s, Node* f, double w=0)
	{
		start=s;
		finish=f;
		weight=w;
	}
};

struct Node {
	string name;
	bool visited;
	set<Edge*> edges;
	Node(string n, bool v=false,  set<Edge*> e={})
	{
		name=n;
		visited=v;
		edges=e;
	}
};

class Graph{

		private:
		set<Node*> Nodes;
		map<string,set<Edge*>> Edges;

		public:
		Graph();
		~Graph();

		const set<Node*> get_Nodes() const;
		const map<string,set<Edge*>> get_Edges() const;
		void printGraph()const;
		Node* getNode(string name) const;
		bool hasNode(string name);
		Node* addNode(string name);
		Edge* addEdge(Node* n1, Node* n2, int w=0);
		const set<Edge*>& getEdgeSet() const ;
		const set<Edge*>& getEdgeSet(Node* n) const;
		const set<Node*> getNeighbors(Node* n) const;
		const set<Node*>& getNodeSet() const;
		bool isEmpty() const;
		bool isNeighbor(Node* n1, Node* n2) const;
		void removeEdge(Node* n1, Node* n2);
		void removeNode(string name);
		int size() const;
		void clear();
		string toString() const;

};	

#endif	
