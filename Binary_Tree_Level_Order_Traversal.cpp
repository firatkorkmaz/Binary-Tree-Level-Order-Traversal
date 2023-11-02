/* Level Order Traversal of Binary Trees with Addition of Nodes to A Vector */

#include <iostream>
#include <vector>
using namespace std;


//Binary Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    };
};


// For Calculating the Maximum Level of the Binary Tree
int max_level(Node *node){
    if (node == NULL)
        return 0;

    else{
        int left_level  = max_level(node->left);
        int right_level = max_level(node->right);

        if (left_level > right_level) {
            return (left_level + 1);
        }

        else {
            return (right_level + 1);
        }
    }
}

// Main Loop Function to Print the Node Data and Pushing Them to A Node* Vector
void loop(Node *node, int x, vector<Node*> &address){
    if(x==0){                                               // When It Reaches the Specified Level from Left or Right Branch
        if(node != NULL){
            cout << node->data << " ";     // Get the Node Data, Print It and Add to the address Vector
            address.push_back(node);
        }
        else{
            //cout << "----------------" << endl;
            return;
        }
    }

    else{
        x--;
        if(node != NULL){
            loop(node->left, x, address);		// Call the loop() Function for Left Branch
            loop(node->right, x, address);		// Call the loop() Function for Right Branch
        }
        else
            return;
    }

}


void looper(Node *root, vector<Node*> &address){
    int height = max_level(root);       // Calculating the Maximum Level of the Binary Tree
    for (int i=0; i < height; i++){     // Iterating i for Each Level in the Binary Tree
        loop(root, i, address);         // The Nodes of Each Level are Printed in loop()
        cout << endl;
    }
}

int main(){

    vector<Node*> address;


    Node *root = new Node(1);              		// 1st Level
		
    root->left = new Node(2);              		// 2nd Level
    root->right = new Node(3);             		// 2nd Level
		
    root->left->left = new Node(4);        		// 3rd Level
    root->left->right = new Node(5);       		// 3rd Level
    root->right->left = new Node(6);       		// 3rd Level
    root->right->right = new Node(7);      		// 3rd Level
		
    root->left->left->left = new Node(8);  		// 4th Level
    root->left->left->right = new Node(9); 		// 4th Level
		
    root->right->left->left = new Node(0); 		// 4th Level
		
    root->right->right->left = new Node(1);		// 4th Level
    root->right->right->right= new Node(2);		// 4th Level

    ////////////////////////////////////////////////////////
	
	cout << endl;

    // Traverse the Binary Tree by Levels
    looper(root, address);	// Both Prints the Node Data and Adds Them to the Node* Vector


    // Printing the Node Data from the Node* Vector
    cout << endl << "================" << endl;
    cout << "From Node Vector:" << endl << endl;

    for(int j=0; j<address.size(); j++)
        cout << address.at(j)->data << " ";


cout << endl << endl << "-------------" << endl;
system("pause");
return 0;
}
