#include "Graph.h"
#include <iostream>
#include <set>
#include <map>

using namespace std;

void test_addNode(Graph* g)
{
	Node* n1=g->addNode("n1");
	Node* n2=g->addNode("n2");
	Node* n3=g->addNode("n3");
	if(n1->name=="n1" && g->hasNode("n1") && n2->name=="n2" && g->hasNode("n2") && n3->name=="n3" && g->hasNode("n3"))
		cout<<"Adding n1,n2,n3 nodes was Successful."<<endl;
	else
		cout<<"Adding n1,n2,n3 nodes was Unsuccessful!"<<endl;
}

void test_addEdge(Graph* g)
{
	Node* n1,*n2,*n3;
	n1=g->getNode("n1");
	n2=g->getNode("n2");
	n3=g->getNode("n3");
	Edge* e1=g->addEdge(n1,n2,5);
	Edge* e2=g->addEdge(n1,n3,10);
	Edge* e3=g->addEdge(n3,n2,3);
	Edge* e4=g->addEdge(n2,n3,7);
	const  map<string,set<Edge*>> Edges=g->get_Edges();
	auto itr=Edges.find("n1");
	if(e1->start->name=="n1" && e1->finish->name=="n2" && itr!=Edges.end()) 
		cout<<"Adding edge n1->n2,n1->n3,n2->n3,n3->n2 was Successful."<<endl;
	else
		cout<<"Adding edge n1->n2,n1->n3,n2->n3,n3->n2 was Unsuccessful!"<<endl;
}

int main(){

	Graph* gr=new Graph;
	test_addNode(gr);
	test_addEdge(gr);
	gr->printGraph();
	return 0;
}

