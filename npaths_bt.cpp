//visit exactly each square once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_matrix(vector<vector<bool> > array) {
    for(size_t i = 0; i < array.size(); i++) {
        for(size_t j = 0; j < array[0].size(); j++) {
            cout << array[i][j] << " ";
        }
        cout <<  '\n';
    }
}

bool get_el(int x, int y, vector<vector<bool> > array) {
    if(x < 0 || y < 0 || x >= array.size() || y >= array[0].size())
        return true;
    return array[x][y];
}

void count_paths(int elem_vis, int x, int y, int n, int &count, vector<vector<bool> > array) {
    array[x][y] = true;
    elem_vis++;

    if(x == n - 1 && y == n - 1) {
        // print_matrix(array);
        if(elem_vis == n*n) {
            count++;
        }
        return;
    }

    if(y == 0 || y == n - 1)
        if(!get_el(x - 1, y, array) && !get_el(x + 1, y, array)) {
            // print_matrix(array);
            return;
        }
    if(x == 0 || n - 1)
        if(!get_el(x, y - 1, array) && !get_el(x, y + 1, array)) {
            // print_matrix(array);
            return;
        }

    vector<vector<int>> paths = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    if(x == 0 && y == 0) {
        paths = {{1, 0}};
    }

    for(int i = 0; i < paths.size(); i++) {
        if(!get_el(x + paths[i][0], y + paths[i][1], array)) {
            count_paths(elem_vis, x + paths[i][0], y + paths[i][1], n, count, array);
        }
    }
    array[x][y] = false;
}

int main() {
    size_t n;
    cout << "Enter dimensions of the grid: ";
    cin >> n;
    if(n == 1) {
        cout << 1 << endl;
    } else {
        vector<vector<bool>> array(n, vector<bool> (n, false));
        int count = 0;
        count_paths(0, 0, 0, n, count, array);
        cout << count * 2 << endl;
    }
    return 0;
}