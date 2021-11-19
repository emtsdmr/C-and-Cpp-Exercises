#include "Graph.h"
#include <iostream>
#include <set>
#include <map>

using namespace std;


int main(){

	Graph gr;//* gr=new Graph;
	Node* n1=gr.addNode("n1");
	cout<<n1->name<<endl;
	cout<<gr.getNode("n1")->name<<endl;
	cout<<gr.hasNode("n0")<<endl;
	Node* n2=gr.addNode("n1");

	return 0;
}
