#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int i,j;
    int T;
    cin>>T;
    cin.ignore();
    
    for(i=0;i<T;i++){
        string S;
        getline(cin, S);
        
        for(j=0;j<S.length();j++){
            if(j%2==0){
                cout<<S[j];
            }
        }
        cout<<" ";
        
        for(j=0;j<S.length();j++){
            if(j%2!=0){
                cout<<S[j];
            }
        }
        cout<<endl;
    }
  
    return 0;
}