/*
ID: sadovay1
TASK: lamps
LANG: C++
*/
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <functional>
#include <iostream>

using namespace std;

ifstream fin("lamps.in");
ofstream fout("lamps.out");

vector<vector<int>> CONFIGS;

vector<int> read_data(vector<int>& lamps_all, int on_off) {
    vector<int> lamps_state;
    int state = 0;
    while (state != -1) {
        fin >> state;
        lamps_state.push_back(state);
    }
    if (lamps_state.size() > 1) {
        for (int i = 0; i != lamps_state.size() - 1; i++) {
            int lamp_num = lamps_state[i];
            lamps_all[lamp_num - 1] = on_off;
        }
    }
    return lamps_all;
}

vector<vector<int>> all_states;
int d = 2, ct = 1;

bool if_counted(vector<int>& v, vector<vector<int>>& all) {
    for (vector<vector<int>>::iterator it = all.begin(); it < all.end(); it++) {
        vector<int> vi = *it;
        if ((vi[0] == v[0]) && (vi[1] == v[1]) && (vi[2] == v[2])) {
            return true;
        }
    }
    return false;
}

void if_valid(vector<int>& current_state,
    vector<vector<int>>& buttons4, vector<int>& final_config) {

    vector<int> res(final_config.size(), 1);
    for (vector<int>::iterator it = current_state.begin();
        it != current_state.end(); it++) {
        int curr_butt_num = *it;
        vector<int> curr_butt = buttons4[curr_butt_num - 1];
        transform(curr_butt.begin(), curr_butt.end(),
                  res.begin(), res.begin(),
                  multiplies<int>());
    }
    for (int i = 0; i < res.size(); i++) {
        if ((final_config[i] != 0) && (final_config[i] != res[i])){
            return;
        }
    }
    transform(res.begin(), res.end(), res.begin(),
              bind2nd(std::plus<int>(), 1));
    transform(res.begin(), res.end(), res.begin(),
              bind1st(std::multiplies<float>(), 0.5));
    if (std::find(CONFIGS.begin(), CONFIGS.end(), res) != CONFIGS.end() == false) {
        CONFIGS.push_back(res);
    }
    
}

vector<int> actions = { 1, 2, 3, 4 };

void check_state(int& state_nums, int& depth, vector<int> current_state,
    vector<vector<int>>& butts, vector<int>& final_config,
    int i) {

    if (all_states.size() == state_nums) {
        return;
    }
    else {
        if (current_state.size() == depth) {
            if (if_counted(current_state, all_states) == 0) {
                if_valid(current_state, butts, final_config);
                all_states.push_back(current_state);
            }

            return;
        }

        if (i <= 4) {
            current_state.push_back(i);
            check_state(state_nums, depth, current_state,
                butts, final_config,
                i);
        }
        else {
            for (int j = current_state.size(); j != 0; j--) {
                if (current_state[j - 1] < 4) {
                    current_state[j - 1]++;
                    break;
                }
                else {
                    current_state.pop_back();
                }
            }
            check_state(state_nums, depth, current_state,
                butts, final_config,
                1);
        }

        current_state.pop_back();
        check_state(state_nums, depth, current_state,
            butts, final_config,
            i + 1);
    }

}


int main() {

    int N, C;
    fin >> N >> C;
    vector<int> lamps_all(N);   // 1 turned on; -1 off; 0 doesn't matter
    lamps_all = read_data(lamps_all, 1);
    lamps_all = read_data(lamps_all, -1);
    bool all_zeros = std::all_of(lamps_all.begin(), lamps_all.end(), [](int i) { return i == 0; });

    if ((C == 0) && (all_zeros == true)) {
        CONFIGS.push_back(vector<int>(N, 1));
    }
    else if ((C == 0) && (all_zeros == false)) {
        CONFIGS = {};
    }
    else {
        vector<vector<int>> buttons(4);
        buttons[0] = vector<int>(N, -1);
        buttons[1] = vector<int>(N, 1);
        buttons[2] = vector<int>(N, 1);
        buttons[3] = vector<int>(N, 1);
        for (int i = 1; i < N + 1; i += 2) {
            buttons[1][i - 1] = -1;
        }
        for (int i = 2; i < N + 1; i += 2) {
            buttons[2][i - 1] = -1;
        }
        for (int i = 1; i < N + 1; i += 3) {
            buttons[3][i - 1] = -1;
        }

        int num_states = pow(4, C);
        vector<int> cs;
        check_state(num_states, C, cs, buttons, lamps_all, 1);
    }

    if (CONFIGS.size() == 0) {
        fout << "IMPOSSIBLE" << endl;
    }
    else {
        for (vector<vector<int>>::iterator it = CONFIGS.begin();
            it != CONFIGS.end(); it++) {
            vector<int> seq = *it;
            for (vector<int>::iterator it2 = seq.begin();
                it2 != seq.end(); it2++) {
                fout << *it2;
            }
            fout << endl;
        }
    }
    return 0;

}