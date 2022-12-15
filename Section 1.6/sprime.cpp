/*
ID: sadovay1
TASK: sprime
LANG: C++
*/
#include <fstream>
#include <string>
#include <vector>

using namespace std;

ifstream fin("sprime.in");
ofstream fout("sprime.out");

bool check_prime(int& i) {

    if (i < 2) { 
        return false; 
    }
    if (i <= 3) { 
        return true; 
    }
    if (i % 2 == 0 || i % 3 == 0) { 
        return false; 
    }
    for (int j = 5; j * j <= i; j++) {
        if (i % j == 0) { 
            return false;
        }
    }
    return true;
}

void gen_sprimes(vector<int>& s, int& N, int current_length, int add_num)
{
    vector<int> primes_1 = { 2,3,5,7 };
    vector<int> primes_2 = { 1,3,7,9 };
    int add_num2 = add_num;
    vector<int> primes;
    if (current_length > N)
    {
        fout << add_num << endl;
    }
    else {
        if (current_length == 1) {
            primes = primes_1;
        }
        else {
            primes = primes_2;
        }
        for (int i = 0; i < 4; i++)
        {
            s[current_length] = primes[i];
            add_num = add_num * 10 + s[current_length];
            if (current_length != 1)
                if (((s[current_length - 1] == 7) && (s[current_length] == 7)) || (check_prime(add_num) == false)) {
                    add_num = add_num2;
                    continue;
                }
                else {
                    gen_sprimes(s, N, current_length + 1, add_num);
                }
            else
            {
                add_num = s[current_length];
                gen_sprimes(s, N, current_length + 1, add_num);
            }
            add_num = add_num2;
        }
    }
}

int main() {

    int N;
    fin >> N;
    vector<int> s(10);
    gen_sprimes(s, N, 1, 0);
    return 0;

}