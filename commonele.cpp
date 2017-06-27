#include <bits/stdc++.h>

using namespace std;

int method_1(vector<int> &B, vector<int> &C) {
    unordered_set<int> s;
    for(auto x: B) {
        s.insert(x);
    }

    int ans = 0;
    for(auto x: C) {
        if(s.count(x)) {
            ans++;
        }
    }
    return ans;
}

int method_2(vector<int> B, vector<int> C) {
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());

    int ans = 0;

    int i = 0, j = 0;
    while(i < B.size() && j < C.size()) {
        if(B[i] < C[j]) i++;
        else if(B[i] > C[j]) j++;
        else {
            ans++;
            i++; j++;
        }
    }
    return ans;
}

int main() {
    vector<int> A = {1, 3, 5, 2, 8}, B = {4, 5, 9, 8};
    cout << method_1(A, B) << '\n';
    cout << method_2(A, B) << '\n';    
    return 0;
}