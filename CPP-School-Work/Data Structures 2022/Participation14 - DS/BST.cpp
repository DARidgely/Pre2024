#include <iostream>
using namespace std;

struct Node 
{
  int value;
  Node *left;
  Node *right;

  Node() { 
    Node *left = NULL;
    Node *right = NULL;
  }

  Node(int value1, Node *left1 = NULL, Node *right1 = NULL) {
    value = value1;
    left = left1;
    right = right1;
  }

};


class myBST {
  private: 
    Node* root;
    
  public:
    myBST(){root = NULL;}  //Class constructor
	        
    void Insert(Node *, int);
    void Insert_Helper(int);
    
    int sumHelper();
    int sumOfNodes(Node*);

    int numHelper();
    int numOfNodes(Node*);
    
    int heightHelper();
    int heightOfTree(Node*);
	
    void Inorder_helper();
    void Inorder(Node*);
};


void myBST::Inorder(Node* n) {
  if (n) {
    Inorder(n->left);
    cout << n->value << " ";
    Inorder(n->right);
  }
}
	
	
void myBST::Inorder_helper() {
  Inorder(root);
}

int myBST::sumHelper() {
  return sumOfNodes(root);
}
int myBST::sumOfNodes(Node *treeNode) {

  if(!treeNode) {
    return 0;
  }else {
    return treeNode->value + sumOfNodes(treeNode->left) + sumOfNodes(treeNode->right);
  }
}


int myBST::numHelper() {
  return numOfNodes(root);
}

int myBST::numOfNodes(Node *treeNode) {
  if(!treeNode) {
    return 0;
  }else {
    return 1 + numOfNodes(treeNode->left) + numOfNodes(treeNode->right);
  }
}

int myBST::heightHelper() {
  return heightOfTree(root);
}

int myBST::heightOfTree(Node *treeNode) {
  
  if(!treeNode) {
    return -1;
  }

  return 1 + max(heightOfTree(treeNode->left), heightOfTree(treeNode->right));
}


void myBST::Insert_Helper(int number) {
  Insert(root, number);
}


void myBST::Insert(Node *node, int element) {
  if (node == NULL) {
    Node* newNode = new Node(element);
    node = newNode;
  }else if(element < node->value) {   //New node goes to left subtree
    Insert(node->left, element);
  }else if(element > node->value) {   //New node goes to right subtree
    Insert(node->right, element);
  }else if(element == node->value)
    return;
		        
}

int main(){
	myBST b;
	b.Insert_Helper(50);
	b.Insert_Helper(30);
	b.Insert_Helper(20);
	b.Insert_Helper(70);
	b.Insert_Helper(60);
	b.Insert_Helper(80);
	int height, sum, num;
  height = b.heightHelper();
  cout << "The height is: " << height << endl;

  sum = b.sumHelper();
  cout << "The sum is: " << sum << endl;

  num = b.numHelper();
  cout << "The number of tree nodes is: " << num << endl;

	b.Inorder_helper();
	return 0;
}
