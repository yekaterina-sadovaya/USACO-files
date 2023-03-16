/*
ID: sadovay1
TASK: zerosum
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("zerosum.in");
ofstream fout("zerosum.out");

void check_zero_sum(const string& expr) {
    int sum = 0, num = 0;
    char op = '+';
    for (char c : expr) {
        if (isdigit(c)) {
            num = num * 10 + (c - '0');
        }
        else if (c != ' ') {
            if (op == '+') {
                sum += num;
            }
            else {
                sum -= num;
            }
            num = 0;
            op = c;
        }
    }
    if (op == '+') {
        sum += num;
    }
    else {
        sum -= num;
    }
    if (sum == 0) {
        fout << expr << endl;
    }
}

void generate_expr(int n, string& expr, int i) {
    if (i >= expr.size()) {
        check_zero_sum(expr);
        return;
    }

    expr[i] = '+';
    generate_expr(n, expr, i + 2);
    expr[i] = '-';
    generate_expr(n, expr, i + 2);
    expr[i] = ' ';
    generate_expr(n, expr, i + 2);
}

int main(int argc, const char* argv[]) {
    
    int n;
    fin >> n;
    string expr(2 * n - 1, ' ');
    for (int i = 0; i < n; i++) {
        expr[2 * i] = '1' + i;
    }
    generate_expr(n, expr, 1);
    return 0;
}
