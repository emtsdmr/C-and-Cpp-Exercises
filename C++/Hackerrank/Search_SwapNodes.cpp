#include <bits/stdc++.h>

using namespace std;

struct Node{
    Node* left;
    Node* right;
    int data;
    Node(int d, Node* l,Node* r):data(d),left(l),right(r){};
    Node(int d):data(d),left(NULL),right(NULL){};
};

class Tree{
    private:
        Node* root;
    public:
        void makeHelper(Node* n,vector<vector<int>> &newindexes,int j,int k,int size,map<int,int> &mp){
            if(newindexes[j][k]!= -1){
                n->left=new Node(newindexes[j][k]);
                makeHelper(n->left,newindexes,j+1,(2*k)+mp[j+1]+(-2)*mp[j],size,mp);
            }
            else {
                n->left=NULL;
                int count=2;
                for(int x=j+1;x<size;x++){
                    mp[x]=mp[x]-count;
                    count*=2;
                }
            }
            if(newindexes[j][k+1]!= -1){
                n->right=new Node(newindexes[j][k+1]);
                makeHelper(n->right,newindexes,j+1,(2*(k+1))+mp[j+1]+(-2)*mp[j],size,mp);
            }    
            else{
                n->right=NULL;
                int count=2;
                for(int x=j+1;x<size;x++){
                    mp[x]=mp[x]-count;
                    count*=2;
                }
            }
        }
        void makeTree(vector<vector<int>> &newindexes){
            root=new Node(newindexes[0][0]);
            int size=newindexes.size();
            map<int,int> mp;
            for(int i=0;i<size;i++){
                mp[i]=0;
            }
            makeHelper(root,newindexes,1,0,size,mp);
        }
        void readHelp(Node* n,vector<int> &temp){
            if(n!=NULL){
                readHelp(n->left,temp);
                temp.push_back(n->data);
                readHelp(n->right,temp);
            }
        }
        vector<int> readTree(){
            vector<int> temp;
            readHelp(root,temp);
            return temp;
        }
        void swapHelp(Node* n,int i,int j){
            if(n!=NULL){
                if((j+1)%i==0){
                    Node* temp=n->left;
                    n->left=n->right;
                    n->right=temp;
                }
                swapHelp(n->left,i,j+1);
                swapHelp(n->right,i,j+1);
            }
        }
        void swapTree(vector<vector<int>> &solution,vector<int> &queries){
            for(int i : queries){
                swapHelp(root,i,0);
                solution.push_back(readTree());
            }
        }
};

vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
    int minusOnes=0,count=0,j=0,twoPower=2;
    int lindx=indexes.size();
    vector<vector<int>> solution;
    vector<vector<int>> newindexes{{1}};
    vector<int> temp;
    while(j!=lindx){
        count+=2; 

            temp.push_back(indexes[j][0]);
            temp.push_back(indexes[j][1]);

        if (indexes[j][0]==-1){
             minusOnes++;
        }
        if (indexes[j][1]==-1){
             minusOnes++;
        }
        if(count==twoPower){
            twoPower*=2;
            newindexes.push_back(temp);
            temp.clear();
            minusOnes*=2;
            count=minusOnes;
        }
        j++;
    }

    Tree t;
    t.makeTree(newindexes);
    t.swapTree(solution,queries);
    t.readTree();
    
return solution;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> indexes(n);
    for (int indexes_row_itr = 0; indexes_row_itr < n; indexes_row_itr++) {
        indexes[indexes_row_itr].resize(2);

        for (int indexes_column_itr = 0; indexes_column_itr < 2; indexes_column_itr++) {
            cin >> indexes[indexes_row_itr][indexes_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(queries_count);

    for (int queries_itr = 0; queries_itr < queries_count; queries_itr++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[queries_itr] = queries_item;
    }

    vector<vector<int>> result = swapNodes(indexes, queries);

    for (int result_row_itr = 0; result_row_itr < result.size(); result_row_itr++) {
        for (int result_column_itr = 0; result_column_itr < result[result_row_itr].size(); result_column_itr++) {
            fout << result[result_row_itr][result_column_itr];

            if (result_column_itr != result[result_row_itr].size() - 1) {
                fout << " ";
            }
        }

        if (result_row_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
