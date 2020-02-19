#include <stdio.h>
#include <stdlib.h>

typedef struct _TreeNode {
    int data;
    struct _TreeNode *left, *right;
} TreeNode;

//       15
//  4         20
// 1        16  25
// TreeNode n1 = { 1, NULL, NULL };
// TreeNode n2 = { 4, &n1, NULL };
// TreeNode n3 = { 16, NULL, NULL };
// TreeNode n4 = { 25, NULL, NULL };
// TreeNode n5 = { 20, &n3, &n4 };
// TreeNode n6 = { 15, &n2, &n5 };
// TreeNode *root = &n6;

TreeNode n1 = {5, NULL, NULL};
TreeNode n2 = {15, &n1, NULL};
TreeNode n3 = {22, NULL, NULL};
TreeNode n4 = {35, &n3, NULL};
TreeNode n5 = {95, NULL, NULL};
TreeNode n6 = {93, &n4, &n5};
TreeNode n7 = {17, &n2, &n6};
TreeNode *root = &n7; 

// 중위 순회
void inorder(TreeNode *root) {
    if(root != NULL) {
        inorder(root->left);         // 왼쪽서브트리 순회
        printf("[%d] ", root->data); // 노드 방문
        inorder(root->right);        // 오른쪽서브트리 순회
    }
}

// 전위 순회
void preorder(TreeNode *root) {
    if(root != NULL) {
        printf("[%d] ", root->data); // 노드 방문
        preorder(root->left);        // 왼쪽서브트리 순회
        preorder(root->right);       // 오른쪽서브트리 순회
    }
}

// 후위 순회
void postorder(TreeNode *root) {
    if(root != NULL) {
        postorder(root->left);       // 왼쪽서브트리 순회
        postorder(root->right);      // 오른쪽서브트리 순회
        printf("[%d] ", root->data); // 노드 방문
    }
}

int main() {
    printf("중위 순회=");
    inorder(root);
    printf("\n");

    printf("전위 순회=");
    preorder(root);
    printf("\n");

    printf("후위 순회=");
    postorder(root);
    printf("\n");
}