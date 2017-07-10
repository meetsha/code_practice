#include<iostream>
#include<iomanip>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node (int x): val(x), left(NULL), right(NULL) {}
};

void postorder(Node* p, int indent=0)
{
    if(p != NULL) {
        if(p->right) {
            postorder(p->right, indent+4);
        }
        if (indent) {
            std::cout << std::setw(indent) << ' ';
        }
        if (p->right) std::cout<<" /\n" << std::setw(indent) << ' ';
        std::cout<< p->val << "\n ";
        if(p->left) {
            std::cout << std::setw(indent) << ' ' <<" \\\n";
            postorder(p->left, indent+4);
        }
    }
}

bool search(Node *root, int val) {
    if(!root)
        return false;
    if(root->val == val) {
        cout << "Found: " << val << '\n';
        return true;
    }
    if(val < root->val)
        return(search(root->left, val));
    else
        return(search(root->right, val));
}

Node* insert(Node* root, int val) {
    Node *temp = new Node(val);
    if(!root) {
        root = temp;
        return root;
    }
    if(val <= root->val) {
        root->left = insert(root->left, val);
    }
    else {
        root->right = insert(root->right, val);
    }
    return root;
}

int main() {
    Node* rootPtr = NULL;
    rootPtr = insert(rootPtr, 10);
    rootPtr = insert(rootPtr, 15);
    rootPtr = insert(rootPtr, 8);
    rootPtr = insert(rootPtr, 1);
    rootPtr = insert(rootPtr, 6);
    postorder(rootPtr);    
    search(rootPtr, 6);
}