// Hackerrank Height of a BST Solution
// Runs in O(floor(log2(n))) worst case
// (when v1 and v1 are both leaf nodes)
// ======== SOLUTION =========
Node *lca(Node *root, int v1,int v2) {
		// Write your code here.
        if(v2 < root->data && v1 < root->data){
            return lca(root->left, v1, v2);
        }else if( v2 > root -> data && v1 > root->data ){
            return lca(root->right, v1, v2);
        }else{
            return root;
        }
        
    }