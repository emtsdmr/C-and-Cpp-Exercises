#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
	// Complete this function
    stringstream ss(str);   
    vector<int> integers;
    char c;
    int tmp;
    while(ss >> tmp) {      
        integers.push_back(tmp);
        ss >> c;           
    }
    return integers;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}
