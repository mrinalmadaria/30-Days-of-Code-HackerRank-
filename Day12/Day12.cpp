#include <iostream>
#include <vector>
#include<numeric>

using namespace std;


class Person{
	protected:
		string firstName;
		string lastName;
		int id;
	public:
		Person(string firstName, string lastName, int identification){
			this->firstName = firstName;
			this->lastName = lastName;
			this->id = identification;
		}
		void printPerson(){
			cout<< "Name: "<< lastName << ", "<< firstName <<"\nID: "<< id << "\n"; 
		}
	
};

class Student :  public Person{
	private:
		vector<int> testScores;  
	public:
        // Write your constructor here
        Student(string fname, string lname, int id_num,vector<int> scores):Person(fname, lname, id_num){
            this->testScores = scores;
        }
        
        char calculate(){
            if(!testScores.size()){
                return 'T';
            }
        int a = accumulate(testScores.begin(), testScores.end(), 0) / testScores.size();
        
        if(90 <= a && a <= 100) return 'O';
        else if(80 <= a && a < 90) return 'E';
        else if(70 <= a && a < 80) return 'A';
        else if(55 <= a && a < 70) return 'P';
        else if(40 <= a && a < 55) return 'D';
        else return 'T';
        };        
};

int main() {
	string firstName;
  	string lastName;
	int id;
  	int numScores;
	cin >> firstName >> lastName >> id >> numScores;
  	vector<int> scores;
  	for(int i = 0; i < numScores; i++){
	  	int tmpScore;
	  	cin >> tmpScore;
		scores.push_back(tmpScore);
	}
	Student* s = new Student(firstName, lastName, id, scores);
	s->printPerson();
	cout << "Grade: " << s->calculate() << "\n";
	return 0;
}