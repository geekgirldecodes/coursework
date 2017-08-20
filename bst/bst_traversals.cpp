#include <iostream>
#include <queue>
#include <map>
#include <vector>

using std::queue;
using std::map;
using std::vector;

//create a nodetype in bst
typedef struct Node{
	int data;
	Node* left;
	Node* right;
}Node;

//creates a new node with data provided 
Node* create_node(int data){
	Node* n1 = new Node();
	if(n1 != NULL){
		n1->data = data;
		n1->right = n1->left= NULL;
	}
	return n1;
}

// test stub
// creates a sample binary tree and returns head node

Node* build_test_bst(){

	// sample test binary search tree 
	//    30
	//  /   \
	// 20    40
	// / \   / \
	//15 25 35 45

	Node* n1 =create_node(30);

	Node* n2 =create_node(20); // left
	Node* n4 =create_node(15); 
	Node* n5 =create_node(25);	

	Node* n3 =create_node(40); // right
	Node* n6 =create_node(35); 
	Node* n7 =create_node(45);
	

	n1->left = n2; //20
	n1->right = n3; //30

	n1->left->left = n4;
	n1->left->right = n5;

	n1->right->left = n6;
	n1->right->right = n7;

	return n1;
}


// Recursive implementation for preorder traversal 
// visit root , traverse left, traverse right sub tree
void preorder_t(Node* root){
	
	if(NULL == root){
		return;
	}

	std::cout<< root->data<<std::endl;
	preorder_t(root->left);
	preorder_t(root->right);
}

// Recursive implementation for postorder traversal 
// traverse left , traverse right , visit root
void postorder_t(Node* root){
	if(NULL == root){
		return;
	}

	postorder_t(root->left);
	postorder_t(root->right);
	std::cout<<root->data<<std::endl;
}

// Recursive implementation for inorder traversal 
// traverse left , visit root, traverse right
void inorder_t(Node* root){
	if(NULL == root){
		return;
	}

	inorder_t(root->left);
	std::cout<<root->data<<std::endl;
	inorder_t(root->right);
}

// level order explores each level at a time
// is same as BFS on the tree
// Breadth first search
// requires usage of QUEUE data structure
void level_order_t(Node* root){

	if(NULL == root){
		return;
	}

	// initialize q queue and push root
	queue<Node*> q ;
	q.push(root);

	// check queue is not empty
    while(false == q.empty()){

    	Node* node = q.front();
		//print node data
		std::cout<<node->data<<std::endl;
		q.pop(); // remove from queue

		//enqueue Node's left and right child
		if(NULL != node->left){
			q.push(node->left);
		}
		if(NULL != node->right){
			q.push(node->right);
		}
	}
}


// prints each level in separate line 
void level_order_print_each_level(Node* root){
	//NULL check on input
	if(NULL == root){
		return;
	}

	// use a queue
	queue<Node*> q;
	q.push(root);

	// run a loop to tarverse the entire tree level by level
	while(1==1){

		int node_count = q.size();

		// marks end of levels
		if(0 == node_count){
			break;
		}

		// if the node count per level is non zero
		while(node_count > 0){
			Node* node = q.front(); // get the front of queue
			std::cout<<node->data<<" ";
			q.pop(); // remove the node from queue 

			//add it's children to be processed next into the queue
			if(NULL != node->left){
				q.push(node->left);
			}
			if(NULL != node->right){
				q.push(node->right);
			}

			//decrement node counter per level
			node_count--;
		}

		std::cout<<std::endl;
	}
	
}


// returns the height of the binary tree
int get_levels(Node* root){
	if(NULL == root){
		return 0;
	}
    
    // recursively compute the height checking left and right sub-trees 
    int lheight = get_levels(root->left);
    int rheight = get_levels(root->right);

 	return (lheight>rheight?lheight+1:rheight+1);
}

void print_each_level(Node* root , int level){
	
	if(level == 1){
		// only parent
		std::cout<<root->data<<" ";
	}
	else if(level > 1){
		print_each_level(root->left, level-1);
		print_each_level(root->right, level-1);
	}
}


// needs the tree level computing helper function
void level_order_without_queue(Node* root){
	if(NULL == root){
		return;
	}

	int num_levels = get_levels(root);

	for (size_t i=1; i <= num_levels ; i++){
		print_each_level(root, i);
		std::cout<<std::endl;
	}
}

// utility function to create a hashmap 
// creates a haspmap of <horizontal_distance , vector<Node*>>
// hd of root is 0
// hd for left node is hd(root)-1
// hd for right node is hd(root)+1

void build_map_hd_nodes(Node* root, map<int, vector<int> > &hd_node_map, int hd){
	if(NULL == root){
		return;
	}

	// push root to map
	hd_node_map[hd].push_back(root->data);

	// push left subtree 
	build_map_hd_nodes(root->left, hd_node_map, hd-1);
	// push right subtree 
	build_map_hd_nodes(root->right, hd_node_map, hd+1);
}

// implementing vertical order traversal using maps 
void vertical_order_traversal(Node* root){
	// null check
	if(NULL == root){
		return;
	}

	int hd =0;// root node horizontal distance
	map<int, vector<int> > hd_node_map;

	// build horizontal distance and nodes map
	build_map_hd_nodes(root, hd_node_map, hd);

	// iterate map built to print vertical order traversal
	std::map<int, vector<int> >::iterator it;
	for(it = hd_node_map.begin(); it!= hd_node_map.end();it++){
		// print each vertical line at a time 
		for(size_t i = 0; i< it->second.size();i++){
			std::cout<<it->second[i]<<" ";
		}
		std::cout<<std::endl;
	}
}

//performs depth first search on tree using stack
void dfd_using_stack(Node* root){

	if(NULL == root){
		return;
	}



}

// test stubs to check different traversals
void test_traversals(){

	// build test tree 
	Node* head = build_test_bst();
	
	std::cout<<"Pre order traversal : "<<std::endl;
	preorder_t(head);	
	std::cout<<"Post order traversal : "<<std::endl;
	postorder_t(head);
	std::cout<<"In order traversal : "<<std::endl;
	inorder_t(head);
	std::cout<<"Level order traversal with queue (BFS) : "<<std::endl;
	level_order_t(head);
	std::cout<<"Level order traversal , print one level per line : "<<std::endl;
	level_order_print_each_level(head);
	std::cout<<"Level order traversal without queue : "<<std::endl;
	level_order_without_queue(head);
	std::cout<<"Vertical order traversal using maps is : "<<std::endl;
	vertical_order_traversal(head);
	
	std::cout<<"Depth first search :"<<std::endl;
	dfs(head);
}


// main driver for running traversal test
int main(){
	test_traversals();
}