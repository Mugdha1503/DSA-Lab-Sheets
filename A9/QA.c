#include<stdio.h>
#include<stdlib.h>
int max(int a,int b)
{
    return(a>b?a:b);
}
typedef struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;
TreeNode* CreateNode(int value)
{
    TreeNode* node= (TreeNode*)malloc(sizeof(TreeNode));
    node->val=value;
    node->left=NULL;
    node->right=NULL;
    return node;

}
TreeNode* BuildTree(int n, int A[])
{
    if(n<=0)
        return NULL;
    TreeNode** Node=(TreeNode**)malloc(n*sizeof(TreeNode*));
    for(int i=0;i<n;i++)
    {
        if(A[i]==-1)
            Node[i]=NULL;
           //Node[i]=CreateNode(0);
        else
            Node[i]=CreateNode(A[i]);
    }
    TreeNode* root=Node[0];
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(Node[i]==NULL)
            count++;
        if(Node[i])
        {
            int leftIndex=2*i+1-(2*count);
            int rightIndex=2*i+2-(2*count);
            if(leftIndex<n)
                Node[i]->left=Node[leftIndex];
            if(rightIndex<n)
                Node[i]->right=Node[rightIndex];
        }
    }
    return root;
}
int FindMaxPathSum(TreeNode* root, int* maxSum)
{
    if(root==NULL)
        return 0;
    int left= FindMaxPathSum(root->left, maxSum);
    int right=FindMaxPathSum(root->right,maxSum);
    int leftOrRight=max(max(left,right)+root->val,root->val);
    int withRoot=max(leftOrRight,left+right+root->val);
    *maxSum=max(*maxSum,withRoot);
    return leftOrRight;
}
int main() {
    int n;
    scanf("%d",&n);
    int A[n];
    for(int i=0;i<n;i++)
        scanf("%d",&A[i]);
    TreeNode* root = BuildTree(n,A);
    int maxSum=0;
    FindMaxPathSum(root, &maxSum);
    printf("%d",maxSum);
return 0;
}

