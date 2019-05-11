/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void MorrisInorderTraversal(TreeNode* A) {
    TreeNode* current = A;
    vector<int> ans;
    while(current!=NULL)
    {
        if(current->left==NULL)
        {

            cout<<current->val<<endl;
            current = current->right;
        }
        else
        {
          //finding predecessor
            TreeNode* pred = current->left;
            while(pred->right!=NULL && pred->right!=current)
                pred = pred->right;
            if(pred->right==NULL)
            {
                pred->right = current;
                current = current->left;
            }
            else
            {
                pred->right = NULL;
               cout<<current->val<<endl;
                current = current->right;
            }
        }
    }
   
}
