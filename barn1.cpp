/*
ID: sadovay1
TASK: barn1
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fin("barn1.in");
ofstream fout("barn1.out");

int main() {

    int M, S, C;
    fin >> M >> S >> C;
    vector<int> occupied_num(C);
    vector<int> adjacent_difference(C);
    for (int c = 0; c < C; c++) {
        fin >> occupied_num[c];        
    }
    sort(occupied_num.begin(), occupied_num.end());

    for (int c = 0; c < C; c++) {
        if (c != 0) {
            adjacent_difference[c] = occupied_num[c] - occupied_num[c - 1] - 1;
        }
    }

    sort(adjacent_difference.begin(), adjacent_difference.end(), greater<int>());
    int n_stalls = occupied_num[C - 1] - occupied_num[0];
    for (int i = 0; i < M - 1; i++) {
        if (i < adjacent_difference.size()) {
            n_stalls -= adjacent_difference[i];
        }
    }

    fout << n_stalls + 1 << endl;
    return 0;
}