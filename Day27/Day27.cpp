#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <cassert>
#include <set>

using namespace std;

int minimum_index(vector<int> seq) {
    if (seq.empty()) {
        throw invalid_argument("Cannot get the minimum value index from an empty sequence");
    }
    int min_idx = 0;
    for (int i = 1; i < seq.size(); ++i) {
        if (seq[i] < seq[min_idx]) {
            min_idx = i;
        }
    }
    return min_idx;
}

namespace TestDataEmptyArray
{
    vector<int> get_array()
    {
        vector<int> myArray = {};
        return myArray;
    }
}

namespace TestDataUniqueValues
{
    static vector<int> myArray;
    
    vector<int> get_array()
    {
        srand(time(NULL));
        for(int i = 0; i < 2+rand()%10; i++)
        {
            myArray.push_back(i);
        }
        return myArray;
    }
    
    int get_expected_result()
    {
        return *std::min_element(myArray.begin(), myArray.end());
    }
}

namespace TestDataExactlyTwoDifferentMinimums
{
    static vector<int> myArray2 = {10,20,30,4,4,5,6,7};
    
    vector<int> get_array()
    {
        return myArray2;
    }
    
    int get_expected_result()
    {
        return std::min_element(myArray2.begin(), myArray2.end()) - myArray2.begin();
    }
}


void TestWithEmptyArray() {
    try {
        auto seq = TestDataEmptyArray::get_array();
        auto result = minimum_index(seq);
    } catch (invalid_argument& e) {
        return;
    }
    assert(false);
}

void TestWithUniqueValues() {
    auto seq = TestDataUniqueValues::get_array();
    assert(seq.size() >= 2);

    assert(set<int>(seq.begin(), seq.end()).size() == seq.size());

    auto expected_result = TestDataUniqueValues::get_expected_result();
    auto result = minimum_index(seq);
    assert(result == expected_result);
}

void TestWithExactlyTwoDifferentMinimums() {
    auto seq = TestDataExactlyTwoDifferentMinimums::get_array();
    assert(seq.size() >= 2);

    auto tmp = seq;
    sort(tmp.begin(), tmp.end());
    assert(tmp[0] == tmp[1] and (tmp.size() == 2 or tmp[1] < tmp[2]));

    auto expected_result = TestDataExactlyTwoDifferentMinimums::get_expected_result();
    auto result = minimum_index(seq);
    assert(result == expected_result);
}

int main() {
    TestWithEmptyArray();
    TestWithUniqueValues();
    TestWithExactlyTwoDifferentMinimums();
    cout << "OK" << endl;
    return 0;
}