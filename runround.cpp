/*
ID: sadovay1
TASK: runround
LANG: C++
*/
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

ifstream fin("runround.in");
ofstream fout("runround.out");

bool isRunround(int num) {
	
	vector<int> digits(10, 0);
	vector<int> used(10, 0);

	int count = 0;
	while (num)
	{
		int rem = num % 10;
		if (rem == 0)
		{
			return false;
		}
		num /= 10;
		digits[count++] = rem;
		if (used[rem])
		{
			return false;
		}
		used[rem] = true;
	}

	used = {0,0,0,0,0,0,0,0,0,0};

	int pos = count;
	int begin = digits[pos - 1];
	int init = begin;
	used[begin] = true;
	for (int i = 1; i < count; ++i)
	{
		pos = pos - begin;
		while (pos <= 0)
		{
			pos += count;
		}
		begin = digits[pos - 1];
		if (used[begin])
		{
			return false;
		}
		used[begin] = true;
	}
	pos = pos - begin;
	while (pos <= 0)
	{
		pos += count;
	}
	if (digits[pos - 1] != init)
	{
		return false;
	}
	return true;
}

int main() {

    long int M;
    fin >> M;
	while (true)
	{
		M++;
		if (isRunround(M))
		{
			fout << M << endl;
			break;
		}		
	}
    

    return 0;

}