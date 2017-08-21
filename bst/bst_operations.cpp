#include <iostream>
#include <limits.h>
#include <vector>
#include <cassert>

using std::vector;
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

// tree that is not BST foe running tests
Node* build_test_tree(){

	Node* n1 =create_node(30);

	//not binary search tree 
	Node* n2 =create_node(20); // left
	Node* n4 =create_node(45); 
	Node* n5 =create_node(55);	

	Node* n3 =create_node(40); // right
	Node* n6 =create_node(35); 
	

	n1->left = n2; //20
	n1->right = n3; //30

	n1->left->left = n4;
	n1->left->right = n5;

	n1->right->left = n6;

	return n1;
}

// @Function has_path_sum()
// @brief Checks if there is a path from root to leaf 
// that adds up to sum passed
// @param1 pointer to root node of bst
// @param2 sum to be found 
// @return true if there is a path with given sum, false otherwise
// @Refer http://cslibrary.stanford.edu/110/BinaryTrees.html
bool has_path_sum(Node* node, int sum){

	// if we reach the leaves and sum is zero , return TRUE
	if(NULL == node){
		return (sum==0);
	}
	else{
		// not reached the end , subtract node value from sum
		// recursively check sum for left and rigth subtree paths
		int remaining_sum = sum-node->data;
		return (has_path_sum(node->left,remaining_sum)|| has_path_sum(node->right, remaining_sum));
	}
}

// @Function get_height()
// @brief computes the max height of a tree from node passed,
// root node to leaf 
// @param1 pointer to root node of bst
// @return height at the node passed 
// height of root is height of the tree 
// height of leaf is 0
// @Refer http://cslibrary.stanford.edu/110/BinaryTrees.html
int get_height(Node* root){
	if(root == NULL){
		return 0;
	}

	int lheight = get_height(root->left);
	int rheight = get_height(root->right);

	return (lheight>rheight?lheight+1:rheight+1);
}

int diameter(Node * node)
{

   if(node == NULL){
   	return 0;
   }

  	int lheight =  get_height(node->left);
  	int rheight = get_height(node->right);

  	int ldiameter = diameter(node->left);
  	int rdiameter = diameter(node->right);

  	return std::max(lheight+rheight+1, std::max(ldiameter,rdiameter));
} 

bool check_bst_rules(Node* node, int min, int max){
	if(NULL == node){
		return true;
	}
	// false if this node violates the min/max constraint 
	// if data is not within specified limit
  	if(node->data>max || node->data <min){
  		return false;
  	}
  	// otherwise check the subtrees recursively
  	return (check_bst_rules(node->left,min, node->data) && check_bst_rules(node->right,node->data,max));
}


bool is_bst(Node* root){
	return check_bst_rules(root, INT_MIN, INT_MAX);
}

//dummy serialize function, stores to int vector instead of file
void serialize(Node* node, vector<int> &s_nodes){
	if(NULL == node){
		//add delimiter and add 
		s_nodes.push_back(-1);
		return;
	}
	//add this to array
	s_nodes.push_back(node->data);
	serialize(node->left, s_nodes);
	serialize(node->right, s_nodes);
}

//reads from vector and converts to bst
void deSerialize(vector<int> &s_nodes, int* index)
{
   	if(s_nodes[*index] == -1){
   		*index = *index +1;	
   		return;
   	}
   	else{
   		//insert to bst
   		//root = create_node(s_nodes[*index]);
   		std::cout<<s_nodes[*index] <<" ";
   		*index = *index +1;	
   		deSerialize( s_nodes,index);
   		deSerialize( s_nodes,index);
   }
}
 


// @Function find()
// @param1 pointer to bianry search tree 
// @param2 integer key t be searched for in the bst
// @return true if key found, else false
bool find(Node* node , int key){
	if(node==NULL){
		return false;
	}
	else{
		if(node->data == key){
			return true;
		}
		else{
			// check if key is greater or lesser
			// traverse right or left subtrees for key
			if(node->data < key){
				find(node->right,key);
			}
			else{
				find(node->left, key);
			}

		}

	}
}


// @Function : bst_insert()
// @Brief  implements insertion to bst , nodes are inserted at leaves 
// @return  unchanged head pointer to bst 
// @Refer http://cslibrary.stanford.edu/110/BinaryTrees.html
Node* bst_insert(Node* node, int data){
	if(node==NULL){
		// first node 
		return create_node(data);
	}
	else{
		// find the place and insert
		if(node->data < data){
			// right
			node->right = bst_insert(node->right, data);
		}
		else{
			node->left = bst_insert(node->left, data);
		}
	}
	return  node;
}


void test_operations(){

	// build test trees
	Node* head = build_test_bst(); // is a binary search tree
	Node* non_bst_head = build_test_tree();	 // not a BST

	assert(3==get_height(head));
	assert(5==diameter(head));
	assert(1==has_path_sum(head, 75));
	assert(0==has_path_sum(head, 55));

	assert(1==find(head, 40));
	assert(0==find(head, 80));

	assert(1==is_bst(head));
	assert(0==is_bst(non_bst_head));

	head = bst_insert(head,80);
	assert(1==find(head, 80));
	assert(6==diameter(head)); // diameter should have changed now
	std::cout<<"All tests passed !! "<<std::endl;

	//bst_delete(head, 80);
	vector<int> s_data ;
	serialize(head, s_data);
	int ind =0;

	std::cout<<"Serialized bst data "<<std::endl;
	for(size_t i=0; i < s_data.size(); i++){
		std::cout<<s_data[i]<<" ";
	}
	std::cout<<std::endl;
	std::cout<<"Deserialized data :"<<std::endl;
	deSerialize(s_data, &ind);
}

int main(){
	test_operations();
}