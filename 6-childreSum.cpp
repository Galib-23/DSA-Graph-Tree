#include<bits/stdc++.h>
using namespace std;
struct node {
    int data;
    node *left;
    node *right;
};
node * create(int data){
    node *newnode = new node();
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
bool is_children_sum_equal(node* root) {
    if (root == nullptr)
        return true;
    if (root->left == nullptr && root->right == nullptr)
        return true;
    int sum = 0;
    if (root->left != nullptr)
        sum += root->left->data;

    if (root->right != nullptr)
        sum += root->right->data;
    return (root->data == sum && is_children_sum_equal(root->left) && is_children_sum_equal(root->right));
}
int main(){
    node *root;
    root = create(10);
    root->left = create(8);
    root->right = create(2);
    root->left->left = create(3);
    root->left->right = create(5);
    root->right->left = create(1);
    root->right->right = create(1);
    if(is_children_sum_equal(root)) cout<<"Children Sums Are Equal "<<endl;
    else cout<<"Not Equal"<<endl;
}