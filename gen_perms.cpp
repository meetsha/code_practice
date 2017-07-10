#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void print_vec(vector<int> &vec) {
    for(auto p : vec) cout << p << " ";
    cout << endl;
}

void recursion(int n, vector<int> &perm, vector<bool> &chosen) {
    if(perm.size() == n) {
        print_vec(perm);
    } else {
        for(int i = 0; i < n; i++) {
            if(chosen[i]) continue;
            chosen[i] = true;
            perm.push_back(i+1);
            recursion(n, perm, chosen);
            perm.pop_back();
            chosen[i] = false;
        }
    }
}

void method2(int n) {
    vector<int> perm;
    for(int i = 0; i < n; i++) {
        perm.push_back(i+1);
    }
    do {
        print_vec(perm);
    } while(next_permutation(perm.begin(), perm.end()));
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    vector<int> perm;
    vector<bool> chosen(n, false);
    recursion(n, perm, chosen);
    cout << endl;
    method2(n);
    return 0;
}