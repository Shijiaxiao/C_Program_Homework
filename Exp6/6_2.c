//
//  main.c
//  Experiment 6-2
//
//  Created by 史家箫 on 2021/12/8.
//

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node *Tree;

Tree* CreaateTree(int n);
void PreorderTraversal(Tree TreeArray);
void InorderTraversal(Tree TreeArray);
void ReverseTree(Tree TreeArray);
void DeleteTree(Tree *TreeArray,int n);

int main()
{
    int n;
    printf("How many nodes does your tree have:");
    scanf("%d",&n);
    Tree * TreeArray = CreaateTree(n);
    printf("After preorder traversal:\n");
    PreorderTraversal((*TreeArray));
    putchar('\n');
    printf("After inorder traversal:\n");
    InorderTraversal((*TreeArray));
    putchar('\n');
    
    ReverseTree((*TreeArray));
    
    printf("Now the tree has been reversed!\n");
    printf("After preorder traversal:\n");
    PreorderTraversal((*TreeArray));
    putchar('\n');
    printf("After inorder traversal:\n");
    InorderTraversal((*TreeArray));
    putchar('\n');
    DeleteTree(TreeArray,n);
    return 0;
}


Tree* CreaateTree(int n)
{
    
    int (*id)[3]=(int (*)[3])malloc(n * 3 * sizeof(int));
    Tree * TreeArray=(Tree *)malloc(n * sizeof(Tree));    // n * sizeof Tree(struct node *)
    
    printf("A tip out of amity: the first line must be the root and the element mustn't be repeated!\n");
    printf("Now please input the id of each tree node along with the id of its left and right child:\n");
    
    for(int i=0;i<n;i++)
        scanf("%d%d%d",*(id+i),*(id+i)+1,*(id+i)+2);
    
    for(int i=0;i<n;i++)
        TreeArray[i]=(Tree)malloc(sizeof(struct node));   // TreeArray + sizeof Tree(struct node *) must be initialized here!
    
    for(int i=0;i<n;i++){
        TreeArray[i]->data=**(id+i);
        if(*(*(id+i)+1) != -1)
            for(int j=0;j<n;j++){
                if(*(*(id+i)+1) == **(id+j)){
                    TreeArray[i]->left=TreeArray[j];
                    break;
                }
                
            }
        else
            TreeArray[i]->left=NULL;
        
        if(*(*(id+i)+2) != -1)
            for(int j=0;j<n;j++){
                if(*(*(id+i)+2) == **(id+j)){
                    TreeArray[i]->right=TreeArray[j];
                    break;
                }
            }
        else
            TreeArray[i]->right=NULL;
        
    }
    
    return TreeArray;
}

void PreorderTraversal(Tree TreeArray)
{
    if(TreeArray == NULL)
        return;
    printf("%d ",TreeArray->data);
    PreorderTraversal(TreeArray->left);
    PreorderTraversal(TreeArray->right);
}


void InorderTraversal(Tree TreeArray)
{
    if(TreeArray == NULL)
        return;
    InorderTraversal(TreeArray->left);
    printf("%d ",TreeArray->data);
    InorderTraversal(TreeArray->right);
    
}

void ReverseTree(Tree TreeArray)
{
    if(TreeArray->left == NULL && TreeArray->right == NULL)
        return;
    
    if(TreeArray->left != NULL)
        ReverseTree(TreeArray->left);
    
    if(TreeArray->right != NULL)
        ReverseTree(TreeArray->right);
    
    Tree temp;
    temp=TreeArray->right;
    TreeArray->right=TreeArray->left;
    TreeArray->left=temp;
}

void DeleteTree(Tree *TreeArray,int n)
{
    for(int i=0;i<n;i++)
        free(TreeArray[i]);
    free(TreeArray);
}
