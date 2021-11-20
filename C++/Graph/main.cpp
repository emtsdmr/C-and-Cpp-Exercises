#include "Graph.h"
#include <iostream>
#include <set>
#include <map>

using namespace std;

void test_addNode(Graph* g)
{
	Node* n1=g->addNode("n1");
	if(n1->name=="n1" && g->hasNode("n1"))
		cout<<"Adding node n1 was Successful."<<endl;
	else
		cout<<"Adding node n1 was Unsuccessful!"<<endl;
}

void test_addEdge(Graph* g)
{
	Node* n1,*n2;
	n1=new Node("n1");
	n2=new Node("n2");
	Edge* e=g->addEdge(n1,n2);
	const  map<string,set<Edge*>> Edges=g->get_Edges();
	auto itr=Edges.find("n1");
	if(e->start->name=="n1" && e->finish->name=="n2" && itr!=Edges.end()) 
		cout<<"Adding edge n1->n2 was Successful."<<endl;
	else
		cout<<"Adding edge n1->n2 was Unsuccessful!"<<endl;
}

int main(){

	Graph* gr=new Graph;
	test_addNode(gr);
	test_addEdge(gr);
	return 0;
}

