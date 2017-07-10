#include<bits/stdc++.h>

using namespace std;

vector<int> solve(vector<int> &A, vector<int> &B) {
    int n = A.size();
    priority_queue<int> heap_sum;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int sum = A[i] + B[j];
            heap_sum.push(sum);
        }
    }
    
    vector<int> ans;
    
    while(n) {
        ans.push_back(heap_sum.top());
        heap_sum.pop();
    }
    
    return ans;
}

int main() {
    return 0;
}