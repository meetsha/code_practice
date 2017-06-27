#include <bits/stdc++.h>

using namespace std;

void calculate(int A, int start, int p, int &count) {
    if(A <= 0) {
        if(A == 0) count++;
        return;
    }

    for(int i = start; pow(i, p) <= A; i++) {
        A -= pow(i,p);
        calculate(A, i+1, p, count);
        A += pow(i,p);
    }

}

int main() {
    int n, p;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter p: ";
    cin >> p;
    int count = 0;
    calculate(n, 1, p, count);
    cout << count << '\n';
    return 0;
}