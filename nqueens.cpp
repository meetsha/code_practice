#include<iostream>
#include<vector>

using namespace std;

void nqueens(int r, int &count, vector<bool> diag1, vector<bool> diag2, vector<bool> col) {
    int n = col.size();
    if(r == col.size()) {
        count++;
        return;
    }

    for(int i = 0; i < col.size(); i++) {
        if(col[i] || diag1[r + i] || diag2[r - i + n - 1]) continue;
        col[i] = diag1[r + i] = diag2[r - i + n - 1] =  true;
        nqueens(r+1, count, diag1, diag2, col);
        col[i] = diag1[r + i] = diag2[r - i + n - 1] = false;
    }

}

int main() {
    cout << "Enter number of queens to place: ";
    int n;
    cin >> n;

    int count = 0;
    vector<bool> col(n, false);
    vector<bool> diag1(2 * n - 1, false), diag2(2 * n - 1, false);
    nqueens(0, count, diag1, diag2, col);
    cout << count << endl;
}
