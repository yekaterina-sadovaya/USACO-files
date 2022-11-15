/*
ID: sadovay1
TASK: skidesign
LANG: C++
*/
#include <fstream>
#include <numeric>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fin("skidesign.in");
ofstream fout("skidesign.out");

int main() {

    int N;
    fin >> N;
    vector<int> hill_height(N);
    for (int i = 0; i < N; i++) {
        fin >> hill_height[i];
    }

    sort(hill_height.begin(), hill_height.end());

    int max_value = 2147483647;
    for (int i = 0; i <= 83; i++) {
        int cost = 0, d = 0;
        for (int j = 0; j < N; j++) {
            if (i > hill_height[j]) {
                d = i - hill_height[j];
            }
            else if (i < (hill_height[j] - 17)) {
                d = hill_height[j] - i - 17;
            }
            else {
                d = 0;
            }
            cost += d * d;
        }
        max_value = min(cost, max_value);
    }

    fout << max_value << endl;

    return 0;

}