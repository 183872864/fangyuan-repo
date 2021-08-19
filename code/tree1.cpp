#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
int cha(TreeNode* x);
int main()
{
    TreeNode* root=new TreeNode(6);
    root->left=new TreeNode(10);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(2);
    root->left->right=new TreeNode(23);
    int res=cha(root);
    cout<<res;
    system("puase");
    return 0;
}
int cha(TreeNode* root)
{
    if(root==NULL)
    return 0;
    int flag=1,q=0,w=0;
    stack<TreeNode*> Tree;
    Tree.push(root);
    while(!Tree.empty())
    {
        int len=Tree.size();
        if(flag%2==1)
      {  while(len--)
        {
            TreeNode* x=Tree.top();
            Tree.pop();
            q+=x->val;
            if(x->left!=NULL)
            Tree.push(x->left);
            if(x->right!=NULL)
            Tree.push(x->right);
        }
      flag++;
    }
    else if(flag%2==0)
    {
        while(len--)
       {
            TreeNode* x=Tree.top();
            Tree.pop();
            w+=x->val;
            if(x->left!=NULL)
            Tree.push(x->left);
            if(x->right!=NULL)
            Tree.push(x->right);
        }
        flag++;
    }
    }
    return q-w;

}