#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the minimumBribes function below.
void minimumBribes(vector<int> q) {
    int brbs=0,diff=0,status=1,temp0=0,temp1=0;
    int size = q.size();
    vector<int> cq(size);
    iota(cq.begin(), cq.end(), 1);
    for (int i=1; i<=size;i++){
        diff=q[i-1]-i;
        if(diff>2){
            cout<<"Too chaotic"<<endl;
            status=0;
            break;
        }
        else{ 
            if(diff==1){
                temp0=cq[i-1];
                cq[i-1]=cq[i];
                cq[i]=temp0;
                brbs++;
            }

            else if(diff==2){    
                temp0=cq[i-1];
                temp1=cq[i];
                cq[i-1]=cq[i+1];
                cq[i]=temp0;
                cq[i+1]=temp1;
                brbs+=2;
            }
            else if(q[i-1]!=cq[i-1]&&q[i-1]==cq[i]){
                brbs++;
                temp0=cq[i-1];
                cq[i-1]=cq[i];
                cq[i]=temp0;
            }
        }
    }
    if(status)
        cout<<brbs<<endl;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string q_temp_temp;
        getline(cin, q_temp_temp);

        vector<string> q_temp = split_string(q_temp_temp);

        vector<int> q(n);

        for (int i = 0; i < n; i++) {
            int q_item = stoi(q_temp[i]);

            q[i] = q_item;
        }

        minimumBribes(q);
    }

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
