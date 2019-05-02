/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BalanceStatusWithHeight{
    public:
        bool balance;
        int height;
        BalanceStatusWithHeight(bool b, int h) : balance(b), height(h) {}
};
BalanceStatusWithHeight checkBalance(TreeNode* root)
{
    if(root==NULL)
    {
        return BalanceStatusWithHeight(true, -1);
    }

    BalanceStatusWithHeight left = checkBalance(root->left);
    BalanceStatusWithHeight right = checkBalance(root->right);
    if(left.balance==false || right.balance==false || (abs(left.height-right.height)>1))
    {
        return BalanceStatusWithHeight(false, 0);
    }
    return BalanceStatusWithHeight(true, 1+max(left.height, right.height));
}

class Solution {
public:
    bool isBalanced(TreeNode* root) {
         return checkBalance(root).balance;
    }
};
