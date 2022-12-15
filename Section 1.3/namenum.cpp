/*
ID: sadovay1
TASK: namenum
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

map<char, char> mapping_rule = {
    { 'A', '2' }, { 'B', '2' }, { 'C', '2' },
    { 'D', '3' }, { 'E', '3' }, { 'F', '3' },
    { 'G', '4' }, { 'H', '4' }, { 'I', '4' },
    { 'J', '5' }, { 'K', '5' }, { 'L', '5' },
    { 'M', '6' }, { 'N', '6' }, { 'O', '6' },
    { 'P', '7' }, { 'R', '7' }, { 'S', '7' },
    { 'T', '8' }, { 'U', '8' }, { 'V', '8' },
    { 'W', '9' }, { 'X', '9' }, { 'Y', '9' },
};

ifstream fin("namenum.in");
ofstream fout("namenum.out");
ifstream fin_dict("dict.txt");

string map2num(string& s) {
    string num = "";
    for (int i = 0; i < s.length(); i++) {
        if ((s[i] != 'Q') && (s[i] != 'Z')) {
            char n = mapping_rule.find(s[i])->second;
            num += n; //* pow(10, (s.length() - i - 1));
        }
        else
        {
            num = "0";
            break;
        }
    }
    return num;
}

int main() {

    string acc_name;
    vector<string> vect_valid_names(5000);
    vector<string> codes_of_valid_names(5000);
    vector<string> names_for_this_num;
    int i = 0;
    string num;
    fin >> num;
    while (fin_dict >> acc_name) {
        vect_valid_names[i] = acc_name;
        codes_of_valid_names[i] = map2num(acc_name);
        if (num == codes_of_valid_names[i]) {
            names_for_this_num.push_back(vect_valid_names[i]);
        }
        i++;
    }

    if (names_for_this_num.size() != 0) {
        for (int i = 0; i < names_for_this_num.size(); i++) {
            fout << names_for_this_num[i] << endl;
        }
    }
    else {
        fout << "NONE" << endl;
    }

    return 0;
}