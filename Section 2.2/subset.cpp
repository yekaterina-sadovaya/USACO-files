/*
ID: sadovay1
TASK: subset
LANG: C++
*/
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fin("subset.in");
ofstream fout("subset.out");

int main() {

    int N;
    fin >> N;

    int s = (1 + N) * N / 2;
    if (s % 2 != 0) {
        fout << 0 << endl;
    }
    else
    {
        s /= 2;
        s++;
        vector<long long> f(s, 0);
        f[0] = 1;
        for (int i = 1; i <= N; i++) {
            for (int j = s - 1; j >= 0; j--) {
                if ((f[j] > 0) && (j + i < s)) {
                    f[j + i] += f[j];
                }
            }
        }
        fout << f[s - 1] / 2 << endl;
    }

    return 0;

}