#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isPrime(int n){
    bool prime = true;
    if (n<2)
        prime = false;
    else if(n%2==0 && n!=2)
        prime = false;
    else
    {
      for(int i=3;i<n;i+=2){
            if(n%i==0){
                prime=false;
                break;
            }
      }
    }
    return prime;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t,n;
    cin >> t;
    for(int i=0;i<t;i++){
        cin>>n;
        if(isPrime(n))
            cout<<"Prime"<<endl;
        else
            cout<<"Not prime"<<endl;
    }
    return 0;
}