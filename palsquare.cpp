/*
ID: sadovay1
TASK: palsquare
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

ifstream fin("palsquare.in");
ofstream fout("palsquare.out");

string get_all_nums(int N, int B) {
    string num;
    while (N) {
        char ch;
        if (N % B > 9) {
            ch = 'A' + N % B - 10;
        }
        else {
            ch = '0' + N % B;
        }
        num = ch + num;
        N = N / B;
    }
    return num;
}

bool if_palindrom(string s) {

    for (int i = 0; i < s.length(); i++) {
        if (s[i] != s[s.length() - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int B;
    string sequence;
    fin >> B;
    for (int N = 1; N <= 300; N++) {
        sequence = get_all_nums(N * N, B);
        if (if_palindrom(sequence)) {
            fout << get_all_nums(N, B) << " " << sequence << endl;
        }
    }
    return 0;
}