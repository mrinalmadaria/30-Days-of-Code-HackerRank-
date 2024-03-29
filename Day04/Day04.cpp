#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person{
  public:
    int age;
    Person(int initialAge);
    void amIOld();
    void yearPasses();
};

Person::Person(int initialAge){
    if(initialAge <= 0){
        cout<<"Age is not valid, setting age to 0."<<endl;
        age = 0;
    } else {
        age = initialAge;
    }
};

    void Person::yearPasses(){
        age += 1;
    };

    void Person::amIOld(){
        if(age < 13){
            cout<<"You are young."<<endl;
        }else if(age >= 13 && age < 18){
            cout<<"You are a teenager."<<endl;
        }else{
            cout<<"You are old."<<endl;
        }
        
    };

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t;
    int age;
    cin >> t;
    for(int i=0; i < t; i++) {
        cin >> age;
        Person p(age);
        p.amIOld();
        for(int j=0; j < 3; j++) {
            p.yearPasses(); 
        }
        p.amIOld();
        if(i < t - 1){
            cout<<endl;    
        }
    }

    return 0;
}