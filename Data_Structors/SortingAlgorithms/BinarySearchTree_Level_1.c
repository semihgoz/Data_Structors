#include <stdio.h>
#include <stdlib.h>

typedef struct n{
	int data;
	struct n* left;
	struct n* right;
}node ;


node * add (node * tree , int data){
	if(tree == NULL){
	node * root = (node *)malloc(sizeof(node));
	root -> left =NULL;	
	root -> right =NULL;
	root -> data = data;

	return root;	
	}
	

	if(tree -> data < data){
		tree -> right = add(tree->right,data);
		return tree;
	}
	tree -> left = add(tree->left,data);	
	
	return tree;
}

int search(node * tree ,int  data){
	if(tree ==NULL)
		return -1;
	if(tree -> data ==data)
		return 1;
	if(search(tree->right , data)==1)
		return 1;
	if(search(tree->left,data)==1)
		return 1;

	return -1;
	

}

int max (node *tree){
	
	while(tree->right !=NULL)
		tree=tree->right;

	return tree->data;
	
}

int min (node * tree ){
	
	while(tree->left !=NULL)
		tree =tree ->left;

	return tree->data;
}

node *  delete(node* tree,int data){
	
	if(tree ==NULL)
		return NULL;
	if(tree->data ==data){
		if(tree->left ==NULL && tree -> right ==NULL)
			return NULL;
		if(tree->right !=NULL){
			tree ->data = min(tree->right);
			tree->right = delete(tree->right,min(tree->right));
			return tree;
		}
		tree->data = max(tree->left);
		tree->left = delete(tree->left,max(tree->left));
		return tree;
	}

	if(tree->data < data){
		tree->right = delete(tree->right,data);
		return tree;
	}
	tree->left = delete(tree->left,data);
	return tree;
}

// infix , prefix , posfix

// Left -> Node -> Right or Right -> Node -> Left
void infixTraversal(node * tree ){
	if(tree ==NULL){
		return;
	}
	
	infixTraversal(tree ->left);
	printf("%d ",tree->data);
	infixTraversal(tree->right);
		
}


// Node-> Left -> Right or Node-> Right -> Left
void prefixTraversal(node * tree){
	if(tree ==NULL)
		return;

	printf("%d \n",tree->data);
	prefixTraversal(tree->right);
	prefixTraversal(tree->left);
}

// Left-> Right -> Node or Right -> Left -> Node
void postfixTraversal(){

}

int main(){

node * tree =NULL;
tree = add(tree , 12);
tree = add(tree , 200);
tree = add(tree , 190);
tree = add(tree , 213);
tree = add(tree , 56);
tree = add(tree , 24);
tree = add(tree , 18);
tree = add(tree , 27);
tree = add(tree , 28);

infixTraversal(tree);
printf("\n");
printf("Search result for 100 : %d\n",search(tree,100));

printf("Search result for 200 : %d\n",search(tree,200));
printf("max = %d , min = %d\n",max(tree),min(tree));

tree = delete(tree,190);
tree = delete(tree,30);
infixTraversal(tree);


return 0;
}


/* output 

12 18 24 27 28 56 190 200 213 
Search result for 100 : -1
Search result for 200 : 1


*/

