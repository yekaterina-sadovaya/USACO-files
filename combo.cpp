/*
ID: sadovay1
TASK: combo
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

ifstream fin("combo.in");
ofstream fout("combo.out");

bool if_counted(vector<int>& v, vector<vector<int>>& all) {
    for (vector<vector<int>>::iterator it = all.begin(); it < all.end(); it++) {
        vector<int> vi = *it;
        if ((vi[0] == v[0]) && (vi[1] == v[1]) && (vi[2] == v[2])) {
            return true;
        }
    }
    return false;
}

int make_combo(vector<int>& key, int& N, vector<vector<int>>& all_comb) {
    int threshold = min(2, N-1);
    vector<vector<int>> allowed_nums(3);
    vector<int> board;
    for (int i = 1; i < N + 1; i++) {
        board.push_back(i);
    }
    board.insert(board.end(), board.begin(), board.end());
    int count_num = 0;
    for (vector<int>::iterator it = key.begin(); it != key.end(); it++) {
        int n = *it;
        int curr_id = n + threshold;
        int count = 0;
        while (count != (2*threshold + 1)) {
            if (curr_id < 0) {
                curr_id = board.size() - 1;
            }
            allowed_nums[count_num].push_back(board[curr_id]);
            curr_id--;
            count++;
        }
        count_num++;
    }
    
    // count all possible combinations
    sort(allowed_nums[0].begin(), allowed_nums[0].end());
    sort(allowed_nums[1].begin(), allowed_nums[1].end());
    sort(allowed_nums[2].begin(), allowed_nums[2].end());
    allowed_nums[0].erase(unique(allowed_nums[0].begin(), allowed_nums[0].end()), allowed_nums[0].end());
    allowed_nums[1].erase(unique(allowed_nums[1].begin(), allowed_nums[1].end()), allowed_nums[1].end());
    allowed_nums[2].erase(unique(allowed_nums[2].begin(), allowed_nums[2].end()), allowed_nums[2].end());
    vector<int> v(3);
    for (int dig1 = 0; dig1 < allowed_nums[0].size(); dig1++) {
        v[0] = allowed_nums[0][dig1];
        for (int dig2 = 0; dig2 < allowed_nums[1].size(); dig2++) {
            v[1] = allowed_nums[1][dig2];
            for (int dig3 = 0; dig3 < allowed_nums[2].size(); dig3++) {
                v[2] = allowed_nums[2][dig3];
                if (if_counted(v, all_comb) == false) {
                    all_comb.push_back(v);
                }
            }
        }
    }

    return all_comb.size();
}

int main() {

    int N;
    fin >> N;
    vector<int> farmers_key(3);
    vector<int> masters_key(3);
    fin >> farmers_key[0] >> farmers_key[1] >> farmers_key[2];
    fin >> masters_key[0] >> masters_key[1] >> masters_key[2];
    vector<vector<int>> all_comb;
    int n_farmers = make_combo(farmers_key, N, all_comb);
    int n_farmers_and_masters = make_combo(masters_key, N, all_comb);
    fout << n_farmers_and_masters << endl;

    return 0;
}