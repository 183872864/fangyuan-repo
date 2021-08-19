#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int x):val(x),left(NULL),right(NULL) {}
};
class BinaryTree{
    public:
    BinaryTree();
    ~BinaryTree();
    void insert(int x);
    void insert(Node* ptr,int x);
    void Delete(int x);
    int serach(int val); 
    int serach(int val,Node* ptr);
    void Free(Node* ptr);

    private:
    Node* root;
};

BinaryTree::BinaryTree()
{
    root=NULL;
}
BinaryTree::~BinaryTree()
{
    if(root==NULL)return;
    Free(root);
}
void BinaryTree::Free(Node* ptr)
{
    if(ptr==NULL)return;
    if(ptr->left!=NULL)
    Free(ptr->left);
    if(ptr->right!=NULL)
    Free(ptr->right);
    delete ptr;
    ptr=NULL;
}
void BinaryTree::insert(int x)
{
    if(root==NULL)
        root=new Node(x);
     else
    {  Node* ptr=root;
        insert(ptr,x);
    }
}
void BinaryTree::insert(Node* ptr,int x)
{
    
    if(ptr->val>x)
    {
        if(ptr->left==NULL)
        ptr->left=new Node(x);
        else
        {
            insert(ptr->left,x);
        }
    }
    else 
    {
       if(ptr->right==NULL)
       ptr->right=new Node(x);
       else
       {
           insert(ptr->right,x);
       }
       
    }
}
int BinaryTree::serach(int val)
{
    return serach(val,root);
}
int BinaryTree::serach(int val,Node* ptr)
{
    if(ptr==NULL)
    return -1;
    if(ptr->val==val)
    return 1;
    if(val<ptr->val)
    return serach(val,ptr->left);
    else
    {
        return serach(val,ptr->right);
    }
    
}
void BinaryTree::Delete(int val)
{
    Node* Parent=root;
    Node* Find=root;
    while(Find!=NULL)
    {
        if(Find->val==val)
        break;
        Parent=Find;
        if(Find->val>val)
        Find=Find->left;
        else
        {
            Find=Find->right;
        }
        
    }
    if(Find==NULL)
    return;
    if(Find->left==NULL||Find->right==NULL)
    {
        Node* tmp=NULL;
        if(Find->left!=NULL)
        tmp=Find->left;
        else if(Find->right!=NULL)
        tmp=Find->right;
        
        if(Parent->left==Find)
        Parent->left=tmp;
        else
        {
            Parent->right=tmp;
        }
        delete Find;
        Find=NULL;
    }
    else
    {
        Node* tmp=Find->left;
        Node* tmpparent=Find;
        while(tmp->right!=NULL)
        {
            tmpparent->right=tmp;
            tmp=tmp->right;
        }
        Find->val=tmp->val;
        tmpparent->right=NULL;
        delete tmp;
        tmp=NULL;
    }
    
}
int main()
{
    BinaryTree  B;
    int n=5;
    while(n--)
    {
        int x;
        cin>>x;
        B.insert(x);
    }
    cout<<B.serach(2)<<endl;
    B.Delete(2);
    cout<<B.serach(2);
    system("pause");
    return 0;
    
}