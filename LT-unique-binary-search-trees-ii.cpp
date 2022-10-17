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
    vector<TreeNode*>* dp[9][9];
    vector<TreeNode*>* generate(int start, int end) {
        if (start > end)
            return new vector<TreeNode*>(1, NULL);
        if (dp[start][end] != NULL)
            return dp[start][end];
        if (start == end) {
            dp[start][end] = new vector<TreeNode*>(1, new TreeNode(start));
            return dp[start][end];
        }
        
        vector<TreeNode*>* res = new vector<TreeNode*>();
        for (int i=start; i<=end; i++) {
            vector<TreeNode*>* ltTrees = generate(start, i-1);
            vector<TreeNode*>* rtTrees = generate(i+1, end);
            
            for (int j=0; j<ltTrees->size(); j++) {
                for (int k=0; k<rtTrees->size(); k++) {
                    res->push_back(new TreeNode(i, ltTrees->at(j), rtTrees->at(k)));
                }
            }
        }
        
        return res;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        for (int i=0 ; i<9; i++)
            for (int j=0; j<9; j++)
                dp[i][j] = NULL;
        
        vector<TreeNode*>* r = generate(1, n);
        return *r;
    }
};