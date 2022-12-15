/*
ID: sadovay1
TASK: hamming
LANG: C++
*/
#include <fstream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

ifstream fin("hamming.in");
ofstream fout("hamming.out");

const int POW2[9] = { 1, 2, 4, 8, 16, 32, 64, 128, 256 };

int dfs(int p2, int nc, int dist, vector <bitset<8> > binary_nums) {

    for (int start = 0; start < p2; start++)
    {
        vector<int> sequence;

        sequence.push_back(start);

        for (int i = start + 1; i < p2; i++)
        {
            bool IsValid = true;

            for (int j = 0; j < sequence.size(); j++)
            {
                bitset<8> temp(sequence[j]);

                if (!((binary_nums[i] ^ temp).count() >= dist))
                {
                    IsValid = false;
                    break;
                }
            }

            if (IsValid)
            {
                sequence.push_back(i);
            }

            if (sequence.size() >= nc)
            {
                for (int i = 0; i < nc; i++)
                {
                    fout << sequence[i];

                    if (i % 10 == 9)
                    {
                        fout << endl;
                    }
                    else if (i != nc - 1)
                    {
                        fout << " ";
                    }
                    else
                    {
                        fout << endl;
                    }
                }
                return 0;
            }
        }
    }
}

int main() {

	int N, B, D;
	fin >> N >> B >> D;

	int pow2 = POW2[B];

    vector <bitset<8> > binary_numbers;
    for (int i = 0; i < pow2; i++)
    {
        bitset<8> num(i);
        binary_numbers.push_back(num);
    }

    int OK = dfs(pow2, N, D, binary_numbers);

    return 0;

}