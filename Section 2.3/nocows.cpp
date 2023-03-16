/*
ID: sadovay1
TASK: nocows
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("nocows.in");
ofstream fout("nocows.out");

int main(int argc, const char* argv[]) {
    
    int N, K;
    fin >> N >> K;

    vector<vector<int> > dp(N + 1, vector<int>(K + 1, 0));
    for (int i = 0; i <= K; i++) {
        dp[0][i] = 1;
    }
    for (int i = 1; i <= N; i += 2) {
        for (int j = 1; j <= K; j++) {
            for (int k = 0; k <= i - 1; k++) {
                dp[i][j] = (dp[i][j] + dp[k][j - 1] * dp[i - 1 - k][j - 1]) % 9901;
            }
        }
    }
    fout << (dp[N][K] - dp[N][K - 1] + 9901) % 9901 << endl;

    return 0;
}
