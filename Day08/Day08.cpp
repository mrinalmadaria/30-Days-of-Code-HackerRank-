#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int entries = 0;
    cin>>entries;
    cin.ignore();
    
    map<string, int> phoneBook;


for (int i = 0; i < entries; i++) {
    string name, number;
    cin >> name >> number;
    phoneBook[name] = stoi(number);
}


string query;
while (cin >> query) {

    if (phoneBook.find(query) != phoneBook.end()) {

        cout << query << "=" << phoneBook[query] << endl;
    } else {

        cout << "Not found" << endl;
    }
}  
    return 0;
}