/*
ID: sadovay1
TASK: concom
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

ifstream fin("concom.in");
ofstream fout("concom.out");

int N = 100;

int main(int argc, const char* argv[]) {
    int n, x, y, p;
    fin >> n;
    vector<vector<int> > maps(N, vector<int>(N, 0));
    for (int i = 0; i < n; i++) {
        fin >> x >> y >> p;
        maps[x - 1][y - 1] = p;
    }

    set<pair<int, int> > res;
    for (int i = 0; i < N; i++) {
        vector<int> shares(N, 0);
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            if (cur != i) res.insert(make_pair(i + 1, cur + 1));
            for (int j = 0; j < N; j++) {
                if (shares[j] <= 50 && shares[j] + maps[cur][j] > 50) {
                    q.push(j);
                }
                shares[j] += maps[cur][j];
            }
        }
    }

    for (auto it = res.begin(); it != res.end(); it++) {
        fout << it->first << " " << it->second << endl;
    }

    return 0;
}