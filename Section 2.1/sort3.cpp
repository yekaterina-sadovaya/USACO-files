/*
ID: sadovay1
TASK: sort3
LANG: C++
*/
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

ifstream fin("sort3.in");
ofstream fout("sort3.out");

int main() {

    int N;
    fin >> N;
    vector<int> a(N);
    map<int, int> count;
    for (int i = 0; i < N; i++) {
        fin >> a[i];
        count[a[i]] += 1;
    }

    map<int, map<int, int> > m;
    for (int i = 0; i < N; i++) {
        if (i < count[1]) {
            m[1][a[i]] += 1;
        }
        else if (i < count[1] + count[2]) {
            m[2][a[i]] += 1;
        }
        else {
            m[3][a[i]] += 1;
        }
    }

    int res = 0;
    int dm;
    for (int i = 2; i < 4; i++) {
        dm = min(m[1][i], m[i][1]);
        res += dm;
        m[1][i] -= dm;
        m[i][1] -= dm;
    }
    dm = min(m[2][3], m[3][2]);
    res += dm;
    m[2][3] -= dm;
    m[3][2] -= dm;
    dm = m[1][2] + m[2][1] + m[1][3] + m[3][1] + m[2][3] + m[3][2];
    res += dm / 3 * 2;
    fout << res << endl;

    return 0;

}