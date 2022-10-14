#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left = NULL;
    TreeNode* right = NULL;
    TreeNode() {
        this->val = 0;
        this->left = NULL;
        this->right = NULL;
    }
    TreeNode(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

TreeNode* root = NULL;

void createTree(TreeNode *head, bool isLeft) {
    int val;
    if (root == NULL) {
        cout << "The the value of the Root node-> ";
        cin >> val;
    } else if (isLeft) {
        cout << "Left Node of === " << head->val << endl;
        cout << "value-> ";
        cin >> val;
    } else {
        cout << "Right Node of === " << head->val << endl;
        cout << "value-> ";
        cin >> val;
    }
    if (val == -1) return;
    if (root == NULL) {
        root = new TreeNode(val);
        head = root;
    } else if (isLeft) {
        head->left = new TreeNode(val);
    } else {
        head->right = new TreeNode(val);
    }
    createTree(head, true);
    createTree(head, false);
}

void inorder(TreeNode* curr) {
    if (curr == NULL) return;
    cout << curr->val << " ";
    inorder(curr->left);
    inorder(curr->right);
}

void print() {
    TreeNode *head = root;
    inorder(head);
}

void solution() {
    root = NULL;
    createTree(NULL, false);
    print();
}

int main() {
    solution();
    return 0;
}