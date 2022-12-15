/*
ID: sadovay1
TASK: preface
LANG: C++
*/
#include <fstream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

ifstream fin("preface.in");
ofstream fout("preface.out");

string nums[7] = { "I", "V", "X", "L", "C",	"D", "M" };
string maps[10] = { "",	"0", "00", "000", "01", "1", "10", "100", "1000", "02"};

int main() {

    int N;
    fin >> N;

	int count[7] = {0,0,0,0,0,0,0};
    for (int page_i = 1; page_i < (N + 1); page_i++) {
		int power = 0, num = page_i;
		while (num)
		{
			int remain = num % 10;
			num /= 10;
			string str = maps[remain];
			for (int i = 0; i < str.length(); i++)
			{
				int index = (str[i] - '0');
				count[index + power]++;
			}
			power += 2;
		}
	}
	for (int i = 0; i < 7; ++i)
	{
		if (count[i])
		{
			fout << nums[i] << ' ' << count[i] << endl;
		}
	}

    return 0;

}