/*
ID: sadovay1
TASK: pprime
LANG: C++
*/
#include <fstream>
#include <string>

using namespace std;

ifstream fin("pprime.in");
ofstream fout("pprime.out");

bool check_prime(int& num) {

    /*bool res = true;
    int j = 2;
    while (j * j <= i) {
        if (i % j == 0) {
            res = false;
        }
        j += 1;
    }
    return res;*/
    if (num < 2) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i * i <= num; i++)
        if (num % i == 0) return false;
    return true;
}

void gen_palindroms(char s[], int current_digit, int digit, int& a, int& b) {
    int i, sum = 0;
    if (current_digit == digit / 2 + 1) {
        for (i = 0; i <= digit / 2; i++) { 
            s[digit - i] = s[i]; 
        }
        for (i = 0; i <= digit; i++) { 
            sum = sum * 10 + s[i]; 
        }
        if ((sum >= a) && (sum <= b) && check_prime(sum)) {
            fout << sum << endl;
        }
    }
    else { 
        for (i = 0; i <= 9; i++) { 
            s[current_digit] = i;
            gen_palindroms(s, current_digit + 1, digit, a, b);
        } 
    }
}

int digit(int num) { 
    string i = to_string(num);
    return i.size()-1;
}

int main() {

    int a, b;
    fin >> a >> b;
    char s[15];
    for (int i = digit(a); i <= digit(b); i++) {
        gen_palindroms(s, 0, i, a, b);
    }
    return 0;

}