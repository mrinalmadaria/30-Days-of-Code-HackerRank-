#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

struct user_info{
    string firstName;
    string email;
};

typedef struct user_info user_info_t;

bool checkFirstName(const string &name)
{
    static std::regex pattern("[a-z]*");
    return name.size() <= 20 && std::regex_match(name, pattern);
}

bool checkEmail(const string &email)
{
    static std::regex pattern("[a-z\\.]+@gmail\\.com");
    return email.size() <= 50 && std::regex_match(email, pattern);
}

int main()
{
 string N_temp;
    getline(cin, N_temp);

    int N = stoi(ltrim(rtrim(N_temp)));

    vector<user_info_t> users;
    for (int N_itr = 0; N_itr < N; N_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        string firstName = first_multiple_input[0];

        string emailID = first_multiple_input[1];
        if (checkFirstName(firstName) && checkEmail(emailID)) {
            // populate array of valid users
            users.push_back({firstName, emailID});
        }
    }

    // sort and print firstName
    sort(users.begin(), users.end(), [](const user_info_t &u1, 
        const user_info_t &u2){ return u1.firstName < u2.firstName; });
    for_each(users.begin(), users.end(), [](user_info_t &u) {
        cout << u.firstName << endl;
    });

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}