#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Date{
    public:
        int day;
        int month;
        int year;

        Date(int d, int m, int y){
            day = d;
            month = m;
            year = y;
        }
};

class Solution{
    public:
        int calculateFine(Date *returnDate, Date *dueDate){
            if(returnDate->year == dueDate->year){
                if(returnDate->month <= dueDate->month){
                    if(returnDate->day <= dueDate->day){  // returned on or before due day
                        return 0;
                    }
                    else{         // returned before due year and month, but day is later
                        return (15 * (abs(dueDate->day - returnDate->day)));
                    }
                }
                else{      // returned before due year, but month is later
                    return (500 * (abs(dueDate->month - returnDate->month)));
                }
            }
            else if(returnDate->year < dueDate->year){   // returned month/day can be greater than due month/day, which is the next year
                 return 0;
            }
            else{      //returned after due year
                return 10000;
            }
        }

};



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int day = 0;
    int month = 0;
    int year = 0;
    int fine = 0;

    cin >> day >> month >> year;
    Date *returnDate = new Date(day, month, year);
    cin >> day >> month >> year;
    Date *dueDate = new Date(day, month, year);

    Solution *mySolution =  new Solution();

    fine = mySolution->calculateFine(returnDate, dueDate);
    cout << fine << endl;

    delete mySolution;
    delete returnDate;
    delete dueDate;
    
    return 0;
}