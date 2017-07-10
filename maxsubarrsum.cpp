#include <bits/stdc++.h>

using namespace std;

typedef vector<int> VI;
#define REP(i, a, b) for (int i = a; i <= b; i++)

void basic_method(VI &B) {
    int best = 0;
    int n = B.size();
    REP(a, 0, n) {
        REP(b, a, n) {
            int sum = 0;
            REP(k, a, b) {
                sum += B[k];
            }
            best = max(best,sum);
        }
    }
    cout << best << "\n";
}

void mediocre_method(VI &B) {
    int best = numeric_limits<int>::min();
    int n = B.size();
    for (int a = 0; a < n; a++) {
        int sum = 0;
        for (int b = a; b < n; b++) {
            sum += B[b];
            best = max(sum, best);
        }
    }
    cout << best << '\n';
}

void best_method(VI &B) {
    int best = numeric_limits<int>::min();
    int n = B.size();
    int sum = 0;
    REP(i, 0, n) {
        sum = max(B[i], B[i] + sum);
        best = max(best, sum);
    }
    cout << best << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    VI A;
    int n, x;
    cout << "Enter number of entries: ";
    cin >> n;

    cout << n << endl; 
    
    for(int i = 0; i < n; i++) {       
        cin >> x;
        A.push_back(x);
    }
    basic_method(A);
    mediocre_method(A);
    best_method(A);
    return 0;
}