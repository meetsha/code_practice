#include <bits/stdc++.h>

using namespace std;

void method_1(n) {
    if (n == 0) {
        ans.push_back(temp);
        return;
    }

    method_1(n-1);
}

void method_2(n) {
    for(int i = 0; i < (1<<n); i++) {
        vector<int> subset;
        for(int j = 0; j < n; j++) {
            if(b & (1 << j)) subset.push_back(j);
        }
    }
}


int main() {
    int n;
    cout << "number of elements in the set: ";
    cin >> n;
    vector<vector<int>> ans;
    vector<int> temp;
    method_1(n, ans);
    method_2(n);
}