#include <stdio.h>
#include <stdlib.h>
#define max(a, b)	(((a) > (b)) ? (a) : (b))
 
typedef struct _node
{
	int data;
	struct _node *left_node;
	struct _node *right_node;
}tree_node;
 
tree_node *root;
 
tree_node *tree_ll(tree_node *p)
{
	tree_node *child;
 
	child = p->left_node;
	p->left_node = child->right_node;
	child->right_node = p;
	return child;
}
 
tree_node *tree_rr(tree_node *p)
{
	tree_node *child;
 
	child = p->right_node;
	p->right_node = child->left_node;
	child->left_node = p;
	return child;
}
 
tree_node *tree_lr(tree_node *p)
{
	tree_node *child;
 
	child = p->left_node;
	p->left_node = tree_rr(child);
	return tree_ll(p);
}
 
tree_node *tree_rl(tree_node *p)
{
	tree_node *child;
 
	child = p->right_node;
	p->right_node = tree_ll(child);
	return tree_rr(p);
}
 
int get_height(tree_node *node)
{
	int height;
 
	height = 0;
	if (node != NULL) {
		height = 1 + max(get_height(node->left_node), get_height(node->right_node));
	}
	return height;
}
 
int get_balance(tree_node *node)
{
	if (node == NULL) {
		return 0;
	}
	return get_height(node->left_node) - get_height(node->right_node);
}
 
tree_node *tree_balance(tree_node *node)
{
	int height;
 
	height = get_balance(node);
	if (height > 1) {
		if (get_balance(node->left_node) > 0) {
			printf("LL\n");
			node = tree_ll(node);
		}
		else {
			printf("LR\n");
			node = tree_lr(node);
		}
	}
	else if (height < -1) {
		if (get_balance(node->right_node) < 0) {
			printf("RR\n");
			node = tree_rr(node);
		}
		else {
			printf("RL\n");
			node = tree_rl(node);
		}
	}
	return node;
}
 
tree_node *tree_insert(tree_node *root,int data)
{
	if (root == NULL) {
		root = (tree_node*)malloc(sizeof(tree_node));
		if (root == NULL) {
			perror("메모리 할당 실패 \n");
			exit(-1);
		}
		root->data = data;
		root->left_node = root->right_node = NULL;
	}
	else if (root->data > data) {
		root->left_node = tree_insert(root->left_node,data);
		root = tree_balance(root);
	}
	else if (root->data < data) {
		root->right_node = tree_insert(root->right_node,data);
		root = tree_balance(root);
	}
	else {
		printf("중복된 data로 인하여 삽입 실패 \n");
	}
	return root;
}
 
void tree_print(tree_node *root)   //전위 순회로 구현
{
	if (root != NULL) {
		printf("%d ",root->data);
		tree_print(root->left_node);
		tree_print(root->right_node);
	}
}
 
int main()
{
 
    root = tree_insert(root, 10);
    root = tree_insert(root, 20);
    root = tree_insert(root, 30);
    root = tree_insert(root, 40);
    root = tree_insert(root, 50);
    root = tree_insert(root, 29);
	tree_print(root);	
	printf("\n");

	return 0;
}