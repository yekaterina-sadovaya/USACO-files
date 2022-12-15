/*
ID: sadovay1
TASK: dualpal
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fin("dualpal.in");
ofstream fout("dualpal.out");

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
    int S;
    int N;
    string sequence;
    vector<int> all_nums;
    fin >> N >> S;
    int n = S + 1;
    while (all_nums.size() != N) {
        int times_palindrome = 0;
        for (int base = 2; base <= 10; base++) {
            sequence = get_all_nums(n, base);
            if (if_palindrom(sequence)) {
                times_palindrome++;
            }
            if (times_palindrome >= 2) {
                all_nums.push_back(n);
                break;
            }
        }
        n++;
    }

    for (int i = 0; i < all_nums.size(); i++) {
        fout << all_nums[i] << endl;
    }

    return 0;
}