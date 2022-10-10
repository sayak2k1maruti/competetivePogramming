class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int cl = 0,cr = 0;
        TreeNode *l = root,*r = root;
        while(l!=NULL){ cl++;l=l->left;}
        while(r!=NULL){ cr++;r=r->right;}
        if(cl==cr) return pow(2,cl)-1;
        return 1 + countNodes(root->left)+countNodes(root->right);
    }
};
