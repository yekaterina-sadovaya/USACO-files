/*
ID: sadovay1
TASK: money
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fin("money.in");
ofstream fout("money.out");

long long count_ways(vector<int> coins, int total) {
    vector<long long> dp(total + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < coins.size(); i++) {
        for (int j = 0; j <= total; j++) {
            if (j >= coins[i]) {
                dp[j] += dp[j - coins[i]];
            }
            else {
                dp[j] = dp[j];
            }
        }
    }

    return dp[total];
}

int main() {

    int V, N;
    vector<int> coins;
    fin >> V >> N;
    for (int i = 0; i < V; i++) {
        int num;
        fin >> num;
        coins.push_back(num);
    }
    long long ways = count_ways(coins, N);
    fout << ways << endl;  
    return 0;
}
