/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/

// Hackerrank Height of a BST Solution
// Runs in O(n) worst case(when the bst
// is actually a linkedlist)
// ======== SOLUTION =========
    int height(Node* root) {
        if(root->left == NULL && root->right == NULL){
            return 0;
        }else if(root->right != NULL && root->left == NULL){
            return 1+height(root->right);
        }else if(root->left != NULL && root->right == NULL){
            return 1+height(root->left);
        }else{
            return 1+max(height(root->left),height(root->right));
        }