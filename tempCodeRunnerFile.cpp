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
Node* insertNode(Node* root, int value) {
    if (root == nullptr)
        return createNode(value);

    if (value < root->data)
        root->left = insertNode(root->left, value);
    else if (value > root->data)
        root->right = insertNode(root->right, value);

    return root;
}
vector<int> v;
void rev_inorder(Node * root) {
    if(root == NULL){
        return;
    }
    rev_inorder(root->right);
    v.push_back(root->data);
    rev_inorder(root->left);
}

int main() {
    Node* root = nullptr;
    root = insertNode(root, 8);
    root = insertNode(root, 4);
    root = insertNode(root, 12);
    root = insertNode(root, 2);
    root = insertNode(root, 6);
    root = insertNode(root, 10);
    root = insertNode(root, 14);
    int k = 2;
    rev_inorder(root);
    cout<<"K'th Largest element is : "<<v[k-1]<<endl;
}
