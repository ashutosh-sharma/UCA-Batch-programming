/*This program can be seen here: https://leetcode.com/problems/invert-binary-tree/description*/
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    void invertTreeUtil(TreeNode root){
        if(root == null)
            return;
        
        TreeNode temp = root.left;
        root.left = root.right;
        root.right = temp;
        
        invertTreeUtil(root.left);
        invertTreeUtil(root.right); 
    }
    
    public TreeNode invertTree(TreeNode root) {
        if(root == null)
            return null;
        
        invertTreeUtil(root);
        
        return root;
        
    }
}
