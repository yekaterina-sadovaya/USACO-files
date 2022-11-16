/*
ID: sadovay1
TASK: milk3
LANG: C++
*/
#include <fstream>
#include <numeric>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fin("milk3.in");
ofstream fout("milk3.out");

bool if_counted(vector<int>& v, vector<vector<int>>& all) {
    for (vector<vector<int>>::iterator it = all.begin(); it < all.end(); it++) {
        vector<int> vi = *it;
        if ((vi[0] == v[0]) && (vi[1] == v[1]) && (vi[2] == v[2])) {
            return true;
        }
    }
    return false;
}

int main() {

    int A, B, C;
    fin >> A >> B >> C;

    int Ai = 0, Bi = 0, Ci = C;
    vector<int> C_when_A_empty = { Ci };
    vector<vector<int>> all_states = { { Ai, Bi, Ci } };
    vector<int> R0 = { Ai, Bi, Ci };
    int level = 1;
    vector<int> Si(3);
    int states_total = 20 * 20 * 20;
    int count = 0, lvl = 1;
    while (count < states_total) {
        vector<vector<int>> actions = { {Ai + min(A - Ai, Ci),Bi, Ci - min(A - Ai, Ci)}, // C->A
                                        {Ai, Bi + min(B - Bi, Ci), Ci - min(B - Bi, Ci)}, // C->B
                                        {Ai + min(A - Ai, Bi), Bi - min(A - Ai, Bi), Ci },
                                        {Ai, Bi - min(C - Ci, Bi), Ci + min(C - Ci, Bi)},
                                        {Ai - min(B - Bi, Ai), Bi + min(B - Bi, Ai), Ci},
                                        {Ai - min(C - Ci, Ai), Bi, Ci + min(C - Ci, Ai)} };
        bool flag = false;
        for (int i = 0; i < 6; i++) {
            vector<int> ai = actions[i];
            if ((ai[0] >= 0) && (ai[1] >= 0) && (ai[2] >= 0)) {
                if (if_counted(ai, all_states) == false) {
                    flag = true;
                    if (ai[0] == 0) {
                        C_when_A_empty.push_back(ai[2]);
                    }
                    all_states.push_back(ai);
                    Ai = ai[0]; 
                    Bi = ai[1];
                    Ci = ai[2];
                    break;
                }                
            }
        }

        if (flag == false) {
            try {
                vector<int> v = all_states.at(lvl);
                Ai = v[0];
                Bi = v[1];
                Ci = v[2];
                lvl += 1;
            }
            catch (const out_of_range & ex) {
                break;
            }
        }
        count += 1;
    }

    sort(C_when_A_empty.begin(), C_when_A_empty.end());
    for (int i = 0; i < C_when_A_empty.size() - 1; i++) {
        fout << C_when_A_empty[i] << " ";
    }
    fout << C_when_A_empty[C_when_A_empty.size() - 1] << endl;

    return 0;

}