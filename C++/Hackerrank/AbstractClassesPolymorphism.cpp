#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};
class LRUCache : public Cache{

public:
    LRUCache(int capacity){
        cp=capacity;
        head=NULL,tail=NULL;
    }

    void set(int k, int v){
        if(head==NULL){         
            head=new Node(k,v);
            mp[k]=head;
            tail=head;
        }
        else {
            Node* current=head;
            int state=0;
            while(current->next!=NULL){
                if((current->next)->key==k){
                    state=1;
                    break;
                }
                current=current->next;
            }
            Node* oldHead=head;
            head= new Node(NULL,oldHead,k,v);
            oldHead->prev=head;
            if(state==0){
                mp[k]=head;
                if(mp.size()>cp){
                    mp.erase(tail->key);    
                    tail=tail->prev;
                    tail->next=NULL;
                }
            }
            else{
                mp[(current->next)->key]->value=v;
                current->next=(current->next)->next;
                current=(current->next)->prev;
            }
        }
    }

    int get(int k){
        
        if (mp.find(k)!=mp.end()){ 
            Node* node=mp[k];
            return node->value;
        }
        else
            return -1;
    }
};
int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
