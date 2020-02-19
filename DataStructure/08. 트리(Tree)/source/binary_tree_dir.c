#include <stdio.h>
#include <stdlib.h>
#define max(a, b) (((a) > (b)) ? (a) : (b))

typedef struct _TreeNode {
    int data;
    struct _TreeNode *left, *right;
} TreeNode;

int calc_dir_size(TreeNode *root) {
    int left_size, right_size;
    if(root == NULL) return 0;

    left_size = calc_dir_size(root->left);
    right_size = calc_dir_size(root->right);
    return (root->data + left_size + right_size);
}

int get_node_count(TreeNode *node) {
    int count = 0;

    if(node != NULL)
        count = 1+get_node_count(node->left)+get_node_count(node->right);
    return count;
}

int get_leaf_count(TreeNode *node) {
    int count = 0;

    if(node != NULL) {
        if(node->left == NULL && node->right == NULL)
            return 1;
        else 
            count = get_leaf_count(node->left) + get_leaf_count(node->right);
    }
    return count;
}

int get_height(TreeNode *node) {
    int height = 0;

    if(node != NULL)
        height = 1+max(get_height(node->left), get_height(node->right));
    return height;
}

int main() {
    TreeNode n4 = { 500, NULL, NULL };
    TreeNode n5 = { 200, NULL, NULL };
    TreeNode n3 = { 100, &n4, &n5 };
    TreeNode n2 = { 50, NULL, NULL };
    TreeNode n1 = { 0, &n2, &n3 };

    printf("디렉토리의 크기=%d\n", calc_dir_size(&n1));
    printf("노드의 개수=%d\n", get_node_count(&n1));
    printf("단말 노드의 개수=%d\n", get_leaf_count(&n1));
    printf("전체 트리의 높이=%d\n", get_height(&n1));
}