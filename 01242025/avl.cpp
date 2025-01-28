#include <bits/stdc++.h>

using namespace std;
struct Node {
    int val;
    Node *left, *right;
};

int treeCheck(Node *root) {
    
    int left, right;
    if (root->left == nullptr) {
        left = 0;
    }
    else {
        left = treeCheck(root->left);
    }

    if (root->right == nullptr) {
        right = 0;
    }
    else {
        right = treeCheck(root->right);
    }

    if (abs(right - left) <= 1 && !(right >= 1e9 || left >= 1e9)) {
        return 1 + max(right, left);
    }
    else {
        return 1e9;
    }
}

void insert(Node *root, int val) {
    if (val < root->val) {
        if (root->left == nullptr) {
            root->left = new(Node);
            root->left->left = nullptr;
            root->left->right = nullptr;
            root->left->val = val;
        }
        else {
            insert(root->left, val);
        }
    }
    else {
        if (root->right == nullptr) {
            root->right = new(Node);
            root->right->right = nullptr;
            root->right->left = nullptr;
            root->right->val = val;
        }
        else {
            insert(root->right, val);
        }
    }
    return;
}

int main() {
    int t; cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        int n; cin >> n;
        if (n == 0) {
            printf("Tree #%d: KEEP\n",tc);
            continue;
        }
        
        // tree initialization
        Node *root = new(Node);
        cin >> root->val;
        root->left = nullptr;
        root->right = nullptr;
        bool bad = false;
        for (int i = 0; i < n - 1; ++i) {
            int val; cin >> val;
            
            insert(root, val);
           

            if (treeCheck(root) == 1e9) {
                bad = true;
            }
        }
        
        // tree checker
        if (bad) {
            printf("Tree #%d: REMOVE\n",tc);
        }
        else {
            printf("Tree #%d: KEEP\n",tc);
        }

    }
}