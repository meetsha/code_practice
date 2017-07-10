//Finds closest element in the set
#include <bits/stdc++.h>

using namespace std;

int main() {
    set<int> s = {3, 6, 23 , 17, 5};

    cout << "Element to search: ";
    int x;
    cin >> x;

    auto it = s.lower_bound(x);
    
    if(it == s.begin()) {
        cout << *it;
    } else if(it == s.end()) {
        it--;
        cout << *it;
    } else{
        int a = *it;
        it--;
        int b = *it;
        if(x - b < a - x) cout << b;
        else cout << a;
    }
    cout << endl;
    return 0;
}