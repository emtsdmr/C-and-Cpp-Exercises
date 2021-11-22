#include "Graph.h"
#include <iostream>
#include <string>

using namespace std;

Graph::Graph()
{
	/*set<Node*> Nodes;
	map<string,set<Edge*>> Edges;*/
}

Graph::~Graph()
{

}

const set<Node*> Graph::get_Nodes() const
{
	return Nodes;
}

const  map<string,set<Edge*>> Graph::get_Edges() const
{
	return Edges;
}

void Graph::printGraph()const
{
	//map<string,set<Edge*>>::iterator itr0;//remove const to make it work
	for(auto itr0=Edges.begin();itr0!=Edges.end();itr0++)//_Rb_tree_iterator
	{
		cout<<"Source:"<<itr0->first<<" -> "<<"Destinations,Weights:";
		if(!(itr0->second).empty())
		{
			set<Edge*>::iterator itr1;
			for(itr1=(itr0->second).begin();itr1!=(itr0->second).end();itr1++)
				cout<<(*itr1)->finish->name<<","<<(*itr1)->weight<<" ";
		}
		cout<<endl;
	}
}

Node* Graph::getNode(string name) const
{

	if(!Nodes.empty())
	{
		set<Node*>::iterator itr;
		for(itr=Nodes.begin();itr!=Nodes.end();itr++)
		{
			if((*itr)->name == name)
				return *itr;
		}
	}
	cout<<"There is no node named "<<name<<"!"<<endl;
	return NULL;
}
bool Graph::hasNode(string name)
{
	if(!Nodes.empty())
	{
		set<Node*>::iterator itr;
		for(itr=Nodes.begin();itr!=Nodes.end();itr++)
		{
			if((*itr)->name == name)
				return true;
		}
	}
	return false;
}

Node* Graph::addNode(string name)
{
	Node* n=NULL;
	if(hasNode(name))
		cout<<name<<" node has already been added!"<<endl;
	else
	{
		n=new Node(name);
		Nodes.insert(n);
	}
	return n;
}

Edge* Graph::addEdge(Node* n1, Node* n2, int w)
{
	Edge* e=NULL;
	if(hasNode(n1->name) && hasNode(n2->name))
	{
		e=new Edge(n1,n2,w);
		auto itr=Edges.find(n1->name);
		if(itr==Edges.end())
		{
			Edges[n1->name]={e};
		}
		else
		{
			Edges[n1->name].insert(e);
		}
	}
	else
		cout<<"Unvalid node(s) for edge!"<<endl;

	return e;
}
 /*
const set<Edges*>& getEdgeSet() const 
{



const set<Edges*>& getEdgeSet(Node* n) const
{
	return v->edges;
}


void clear();
const set<Node*> getNeighbors(Node* v) const;
Node* getNode(string name) const;
const set<Node*>& getNodeSet() const;
bool isEmpty() const;
bool isNeighbor(Node* v1, Node* v2) const;
void removeEdge(Node* v1, Node* v2);
void removeNode(string name);
int size() const;
string toString() const;*/
