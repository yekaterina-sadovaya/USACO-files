/*
ID: sadovay1
TASK: castle
LANG: C++
*/
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

ifstream fin("castle.in");
ofstream fout("castle.out");

vector<vector<int>> tmap(50, vector<int>(50, 0));
vector<vector<int>> castle_map(50, vector<int>(50, 0));

class Filler {
    public:
        int tt=0;
        //int tmap[50][50] = { 0 };
        //int castle_map[50][50] = { 0 };        
        int num = 0;
        int floodfill(int x, int y);
    private:
        vector<int> fx = { 1,2,4,8 };
};

int Filler::floodfill(int x, int y)
{
    tt++;
    tmap[x][y] = num;
    if ((15 - castle_map[x][y]) > 0) {
        castle_map[x][y] = 15 - castle_map[x][y]; 
    }
    else { 
        return 0; 
    }
    for (int k = 3; k >= 0; k--)
    {
        if ((castle_map[x][y] - fx[k]) >= 0) { 
            castle_map[x][y] -= fx[k]; 
        }
        else { 
            continue;
        }
        switch (k)
        {
        case(0):
            if (tmap[x][y - 1] == 0) { 
                floodfill(x, y - 1); 
            } break;
        case(1):
            if (tmap[x - 1][y] == 0) { 
                floodfill(x - 1, y); 
            } break;
        case(2):
            if (tmap[x][y + 1] == 0) { 
                floodfill(x, y + 1); 
            } break;
        case(3):
            if (tmap[x + 1][y] == 0) { 
                floodfill(x + 1, y); 
            } break;
        }
        if (castle_map[x][y] == 0) { 
            break; 
        }
    }
}


int main() {

    int M, N;
    fin >> M >> N;   
    Filler FL = Filler();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            fin >> castle_map[i][j];
        }
    }
    int smax = 0;
    map<int, int> xmap;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (castle_map[i][j] != 0)
            {
                FL.num++;
                FL.tt = 0;
                FL.floodfill(i, j);
                xmap[FL.num] = FL.tt;
                if (FL.tt > smax) {
                    smax = FL.tt;
                }
            }
        }
    }
    fout << FL.num << endl;
    fout << smax << endl;
    int x = 0, y = 0;
    char p = ' ';
    for (int j = 0; j < M; j++) {
        for (int i = N; i >= 1; i--)
        {
            // North
            if ((i - 1 > 0) && (tmap[i][j] != tmap[i - 1][j]) && ((xmap[tmap[i][j]] + xmap[tmap[i - 1][j]]) > smax))
            {
                x = i;
                y = j;
                p = 'N';
                int s1 = 0, s2 = 0;
                if (xmap.count(tmap[i][j]) == 1) {
                    s1 = xmap[tmap[i][j]];
                }
                if (xmap.count(tmap[i - 1][j])) {
                    s2 = xmap[tmap[i - 1][j]];
                }
                smax = s1 + s2;
            }

            // East
            if ((j < M) && (tmap[i][j] != tmap[i][j + 1]) && ((xmap[tmap[i][j]] + xmap[tmap[i][j + 1]]) > smax))
            {
                x = i;
                y = j;
                p = 'E';
                int s1 = 0, s2 = 0;
                if (xmap.count(tmap[i][j]) == 1) {
                    s1 = xmap[tmap[i][j]];
                }
                if (xmap.count(tmap[i][j + 1])) {
                    s2 = xmap[tmap[i][j + 1]];
                }
                smax = s1 + s2;
            }
        }
    }
    fout << smax << endl << x + 1 << ' ' << y + 1 << ' ' << p << endl;
    return 0;

}