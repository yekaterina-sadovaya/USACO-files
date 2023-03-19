/*
ID: sadovay1
TASK: ttwo
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <set>
#include <utility>

using namespace std;

ifstream fin("ttwo.in");
ofstream fout("ttwo.out");

const int MAXN = 10;
char grid[MAXN][MAXN + 1];
bool visited[MAXN][MAXN][4][MAXN][MAXN][4];

struct Object {
    int x, y, dir;
};

void move(Object& obj) {
    int dx[4] = { -1, 0, 1, 0 };
    int dy[4] = { 0, 1, 0, -1 };

    int nx = obj.x + dx[obj.dir];
    int ny = obj.y + dy[obj.dir];

    if (nx < 0 || nx >= MAXN || ny < 0 || ny >= MAXN || grid[nx][ny] == '*') {
        obj.dir = (obj.dir + 1) % 4;
    }
    else {
        obj.x = nx;
        obj.y = ny;
    }
}

int main() {
    Object cow = { 0, 0, 0 }, farmer = { 0, 0, 0 };

    for (int i = 0; i < MAXN; i++) {
        fin >> grid[i];

        for (int j = 0; j < MAXN; j++) {
            if (grid[i][j] == 'C') {
                cow.x = i;
                cow.y = j;
            }
            else if (grid[i][j] == 'F') {
                farmer.x = i;
                farmer.y = j;
            }
        }
    }

    int minutes = 0;

    while (cow.x != farmer.x || cow.y != farmer.y) {
        move(cow);
        move(farmer);

        if (visited[cow.x][cow.y][cow.dir][farmer.x][farmer.y][farmer.dir]) {
            minutes = 0;
            break;
        }
        else {
            visited[cow.x][cow.y][cow.dir][farmer.x][farmer.y][farmer.dir] = true;
            minutes++;
        }
    }

    fout << minutes << endl;

    return 0;
}