/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
pair<int,int> solve(TreeNode* root,int &ans){

    if(root==NULL){
        return {0,0};
    }

    // if(root->left==NULL && root->right==NULL){
    //     ans++;
    //     return {cnt+1,root->val};
    // }

    //left traversal
    pair<int,int> leftCount =  solve(root->left,ans);

    //right traversal
    pair<int,int> rightCount = solve(root->right,ans);

    int sum = root->val + leftCount.second + rightCount.second;
    int nodeCount = leftCount.first  + rightCount.first + 1;

    if((sum/nodeCount)==root->val){
            ans++;
    }

    return {nodeCount,sum};


}

    int averageOfSubtree(TreeNode* root) {

        int ans=0;
       pair<int,int> p=  solve(root,ans);

        return ans;
    }
};