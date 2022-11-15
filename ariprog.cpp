/*
ID: sadovay1
TASK: ariprog
LANG: C++
*/
#include <fstream>
#include <numeric>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fin("ariprog.in");
ofstream fout("ariprog.out");

int main() {

    int N, M;
    fin >> N >> M;
    int max_val = M * M * 2;

    vector<bool> bisquares(max_val + 1);
    for (int p = 0; p <= M; p++) {
        for (int q = 0; q <= M; q++) {
            bisquares[p * p + q * q] = true;
        }
    }

    vector<pair<int, int>> res;
    for (int a = 0; a < max_val; a++) {
        if (bisquares[a] == true) {
            for (int b = 1; b <= (max_val - a) / (N - 1); b++) {
                int check = true;
                for (int n = 1; n <= N - 1; n++) {
                    if (bisquares[a + n * b] == false) {
                        check = false;
                        break;
                    }
                }
                if (check == true) {
                    res.push_back({ a, b });
                }
            }
        }
    }

    std::sort(res.begin(), res.end(), [](const std::pair<int, int>& left, const std::pair<int, int>& right) {
        return left.second < right.second;
        });

    if (res.size() == 0){
        fout << "NONE" << endl;
    }
    else {
        for (int i = 0; i < res.size(); i++) {
            fout << res[i].first << " " << res[i].second << endl;
        }
    }

    return 0;

}