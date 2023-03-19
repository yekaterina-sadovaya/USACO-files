/*
ID: sadovay1
TASK: comehome
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <utility>
#include <cstring>

using namespace std;

ifstream fin("comehome.in");
ofstream fout("comehome.out");

const int MAXN = 52;
const int INF = INT_MAX;

vector<pair<int, int>> adj[MAXN];
int dist[MAXN];
bool visited[MAXN];

int get_index(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 26;
    }
    return c - 'A';
}

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, start));
    dist[start] = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (visited[u]) {
            continue;
        }
        visited[u] = true;
        for (auto v : adj[u]) {
            int w = v.first;
            int weight = v.second;
            if (dist[u] != INF && dist[u] + weight < dist[w]) {
                dist[w] = dist[u] + weight;
                pq.push(make_pair(dist[w], w));
            }
        }
    }
}

int main() {
    int P;
    fin >> P;
    for (int i = 0; i < P; i++) {
        char a, b;
        int d;
        fin >> a >> b >> d;
        int u = get_index(a);
        int v = get_index(b);
        adj[u].push_back(make_pair(v, d));
        adj[v].push_back(make_pair(u, d));
    }
    int start = get_index('Z');
    for (int i = 0; i < MAXN; i++) {
        dist[i] = INF;
    }
    dijkstra(start);
    int minDist = INF;
    char minCow;
    for (char c = 'A'; c <= 'Y'; c++) {
        int idx = get_index(c);
        if (dist[idx] < minDist) {
            minDist = dist[idx];
            minCow = c;
        }
    }
    fout << minCow << " " << minDist << endl;
    return 0;
}