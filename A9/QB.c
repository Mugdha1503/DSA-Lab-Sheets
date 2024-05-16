#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;
TreeNode* CreateNode(int value)
{
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}
TreeNode* BuildTree(int n, int A[])
{
    if(n<=0)
        return NULL;
    TreeNode** Node = (TreeNode**)malloc(n * sizeof(TreeNode*));
    for(int i=0; i<n; i++)
    {
        if(A[i] == -1)
            Node[i] = NULL;
        else
            Node[i] = CreateNode(A[i]);
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
            if(leftIndex < n)
                Node[i]->left = Node[leftIndex];
            if(rightIndex < n)
                Node[i]->right = Node[rightIndex];
        }
    }
    free(Node);
    return root;
}
int isIdentical(TreeNode* rootA, TreeNode* rootB)
{
    if(rootA == NULL && rootB == NULL)
        return 1;
    if(rootA == NULL || rootB == NULL)
        return 0;
    if(rootA->val != rootB->val)
        return 0;
    return isIdentical(rootA->left, rootB->left) && isIdentical(rootA->right, rootB->right);
}
int isSubtree(TreeNode* rootA, TreeNode* rootB)
{
    if(rootB == NULL)
        return 1;
    if(rootA == NULL)
        return 0;
    if(isIdentical(rootA, rootB))
        return 1;
    return isSubtree(rootA->left, rootB) || isSubtree(rootA->right, rootB);
}
void main()
{
    int n, m;
    scanf("%d %d",&n,&m);
    int A[n];
    for(int i=0; i<n; i++)
        scanf("%d",&A[i]);
    int B[m];
    for(int i=0; i<m; i++)
        scanf("%d",&B[i]);
    TreeNode* rootA = BuildTree(n, A);
    TreeNode* rootB = BuildTree(m, B);
    if(isSubtree(rootA, rootB))
        printf("WIN");
    else
        printf("LOSS");
}
