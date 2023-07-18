#include <iostream>
using namespace std;
struct node {
    int data;
    node* left;
    node* right;
};
node* create(int value) {
    node* newnode = new node();
    if (newnode==nullptr) {
        return nullptr;
    }
    newnode->data = value;
    newnode->left = newnode->right = nullptr;
    return newnode;
}
node* createBalancedBST(int arr[], int start, int end) {
    if (start > end)
        return nullptr;

    int mid = (start + end) / 2;
    node* root = create(arr[mid]);

    root->left = createBalancedBST(arr, start, mid - 1);
    root->right = createBalancedBST(arr, mid + 1, end);

    return root;
}
void inorder(node* root) {
    if (root == nullptr)
        return;
    
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    node* root = createBalancedBST(arr, 0, n - 1);
    cout << "Inorder traversal of the created BST: ";
    inorder(root);

    return 0;
}
