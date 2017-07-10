#include<iostream>

using namespace std;

#define F first;
#define S second;

// struct node{
//     bool exist;
//     node* arr[26];
//     node(bool e=false) {
//         exist = e;
//         for(int i = 0; i < 26; i++)
//             arr[i] = NULL;
//     }
// }


//for prefix problems
struct node{
    int words;
    int prefixes;
    node* arr[26];
    node() {
        words = 0;
        prefixes = 0;
        for(int i = 0; i < 26; i++) 
            arr[i] = NULL;
    }
}

void add(string s, node* trie) {
    int n = s.size();
    if(n == 0)
        trie.words++;
    else {
        for(int i = 0; i < n; i++) {
            trie.prefixes++;
            if(!trie->arr[x - 'a']) {
                trie->arr[x - 'a'] = new node();
            }
            trie = trie->arr[x - 'a'];
        }
        trie->words++;
    }
}

int countWords(string s, node* trie) {
    if(!trie)
        return 0;
    for(int i = 0; i < n; i++) {
        if(!trie->arr[s[i] - 'a']) return 0;
        trie = trie->arr[s[i] - 'a'];
    }
    return trie->words;
}

int countPrefixes(string s, node* trie) {
    if(!trie)
        return 0;
    for(int i = 0; i < n; i++) {
        if(!trie->arr[s[i] - 'a']) return 0;
        trie = trie->arr[s[i] - 'a'];
    }
    return trie.prefixes;
}

int main() {
    return 0;
}