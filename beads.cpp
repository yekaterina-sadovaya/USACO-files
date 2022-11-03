/*
ID: sadovay1
TASK: beads
LANG: C++                 
*/
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

int search_same(string s, char color) {
    int count = 0;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if ((c == color) || (c == 'w')) {
            count += 1;
        }
        else {
            break;
        }
    }
    return count;
}

int main() {

    ifstream fin("beads.in");
    ofstream fout("beads.out");
    string necklace;
    int n_beads;
    fin >> n_beads >> necklace;
    necklace = necklace + necklace;
    int best_score = 0;
    for (int i = 0; i < necklace.length()+1; i++) {
        string first_part = necklace.substr(0, i);
        reverse(first_part.begin(), first_part.end());
        string second_part = necklace.substr(i, necklace.length()+1);
        int n_blue1 = search_same(first_part, 'b');
        int n_red1 = search_same(first_part, 'r');
        int n_blue2 = search_same(second_part, 'b');
        int n_red2 = search_same(second_part, 'r');
        int res = max(max(n_blue1 + n_red2, n_red1 + n_blue2), 
                      max(n_blue1 + n_blue2, n_red1 + n_red2));
        if (res > best_score) {
            res = min(res, n_beads);
            best_score = res;
        }
    }
    fout << best_score << endl;
    return 0;
}