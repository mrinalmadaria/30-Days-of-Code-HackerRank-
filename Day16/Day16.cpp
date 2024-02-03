#include <bits/stdc++.h>

using namespace std;



int main()
{
    string S;
    getline(cin, S);
    
    try{
        int n = stoi(S);
        cout<<n;
    } catch (invalid_argument){
        cout<<"Bad String";
    }

    return 0;
}