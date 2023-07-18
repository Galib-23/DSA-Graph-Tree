#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
};
Node* createNode(int value) {
    Node* newNode = new Node();
    if (!newNode) {
        return nullptr;
    }
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}
void inorderTraversal(Node* root, vector<int>& v) {
    if (root == nullptr)
        return;

    inorderTraversal(root->left, v);
    v.push_back(root->data);
    inorderTraversal(root->right, v);
}
void convertBSTtoMaxHeap(Node* root, const vector<int>& v, int& index) {
    if (root == nullptr)
        return;
    convertBSTtoMaxHeap(root->left, v, index);
    convertBSTtoMaxHeap(root->right, v, index);
    root->data = v[index];
    index++;
}
void inorderTraversal(Node* root) {
    if (root == nullptr)
        return;
    
    
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    Node* root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(6);
    root->left->left = createNode(1);
    root->left->right = createNode(3);
    root->right->left = createNode(5);
    root->right->right = createNode(7);
    vector<int> v;
    inorderTraversal(root, v);
    int index = 0;
    convertBSTtoMaxHeap(root, v, index);
    cout << "inorder traversal of the converted Max Heap: ";
    inorderTraversal(root);
    return 0;
}
