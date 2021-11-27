#include "Graph.h"
#include <iostream>
#include <set>
#include <map>

using namespace std;

void test_addNode(Graph* g)
{
	Node* n0=g->getNode("n0");//empty node exception, returns nullptr
	Node* n1=g->addNode("n1");
	Node* n2=g->addNode("n2");
	Node* n3=g->addNode("n3");
	Node* n4=g->getNode("n4");//exception of the node which doesnt exist
	if(n1->name=="n1" && g->hasNode("n1") && n2->name=="n2" && g->hasNode("n2") && n3->name=="n3" && g->hasNode("n3"))
		cout<<"Adding n1,n2,n3 nodes was Successful."<<endl;
	else
		cout<<"Adding n1,n2,n3 nodes was Unsuccessful!"<<endl;
}

void test_addEdge(Graph* g)
{
	Node* n0=NULL,*n1,*n2,*n3;
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
	
	Edge* e5=g->addEdge(n0,n1);//nulptr exception
	Node* n02=new Node("n2");//n02 doesnt belong to graph,graph has a node with the same name "n2"
	Edge* e6=g->addEdge(n2,n1);//no error or exception
	Node* n4=new Node("n4");//unvalid node exception,graph doesnt have n4 node
	Edge* e7=g->addEdge(n1,n4);
}

int main(){

	Graph* gr=new Graph;
	test_addNode(gr);
	test_addEdge(gr);
	gr->printGraph();
	return 0;
}

