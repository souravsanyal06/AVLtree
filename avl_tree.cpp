/* 
************************************************
   Sourav Sanyal 
   A02262314
   Bridge Lab
   Utah State University
   MS in Electrical and Computer Engineering

************************************************
*/

#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#define MAX(a,b) (a>b)?a:b
#define SIZE 100


using namespace std;




// Node Declaration //

struct node

{

    int data;				// variable data storing the actual value of the node //

    struct node *left;                  // node type pointer pointing to the left sub-node //

    struct node *right;                // node type pointer pointing to the right sub-node //

};


struct node *root ;		      // global node type pointer root referring to the root of the tree //
 
ofstream file;

// Declaration of Class avlTree and Declaration of various functions within the Class //

class avlTree

{

    public:

        int height(node *);

        int check_balance(node *);

	int search_node(node *, int );

        node *rotate_rightright(node *);

        node *rotate_leftleft(node *);

        node *rotate_leftright(node *);

        node *rotate_rightleft(node *);

        node *balance(node *);

        node *insert(node *, int );

	node *delete_node(node *, int );

	node *get_ancestor(node *);

	void delete_tree(node *);

        void inorder(node *);

        void preorder(node *);

        void postorder(node *);

        avlTree()

        {

            root = NULL;

        }

};

// Function to calculate height of tree //

int avlTree::height(node *x)

{

    int h = 0;

    if (x!= NULL)							// if input parameter pointer is null height = 0 //

    {

        int left_height = height(x->left)?height(x->left):0; 		// calculates recursively height of left sub tree //

        int right_height = height(x->right)?height(x->right):0;		// calculates recursively height of right sub tree //

        h = max(left_height,right_height) + 1;				// height of tree = height of the sub tree which has more height + 1 //

    }

    return h;

}

 

// Calculation to check balance which is difference in height of left and right subtrees //

int avlTree::check_balance(node *x)

{

    int balance= height(x->left)- height(x->right);			// difference in height of left and right sub tree is the balance //

    return balance;

}

 

// Right- Right Rotation //


node *avlTree::rotate_rightright(node *parent)

{

    node *x;					// temporary node type pointer x declared which will be the new parent node//

    x = parent->right;				// right sub-node of old parent assigned to x //

    parent->right = x->left;			// left sub- node of x assigned to right sub-node of old parent//

    x->left = parent;				// modified old parent assigned to left sub-node of x resulting in new balanced parent node//

    return x;

}



// Left- Left Rotation //


node *avlTree::rotate_leftleft(node *parent)

{

    node *x;					// temporary node type pointer x declared which will be the new parent node//

    x = parent->left;				// left sub-node of old parent assigned to x //

    parent->left = x->right;			// right sub- node of x assigned to left sub-node of old parent//

    x->right = parent;				// modified old parent assigned to right sub-node of x resulting in new balanced parent node//

    return x;

}

 


 // Left - Right Rotation //

node *avlTree::rotate_leftright(node *parent)

{

    node *x;					// temporary node type pointer x declared which will be the new parent node//

    x = parent->left;				// left sub-node of old parent assigned to x //

    parent->left = rotate_rightright (x);	// rightright rotation applied on x and is assigned to left sub-node of parent//

    return rotate_leftleft (parent);		// leftleft rotation applied on modified old parent resulting in new balanced parent node//

}

 
// Right- Left Rotation //


node *avlTree::rotate_rightleft(node *parent)

{

    node *x;					// temporary node type pointer x declared which will be the new parent node //

    x = parent->right;				// right sub-node of old parent assigned to x //

    parent->right = rotate_leftleft (x);	// leftleft rotation applied on x and is assigned to right sub-node of parent //

    return rotate_rightright (parent);		// rightright rotation applied on modified old parent resulting in new balanced parent node //

}

 

 // Balancing AVL Tree //


node *avlTree::balance(node *x)

{

    int balance = check_balance (x);   		// variable balance stores balance of a node //

    if (balance > 1)				// left sub-tree height more than right sub-tree //

    {

        if (check_balance (x->left) > 0)	// left sub-tree of left sub-tree height more than right sub-tree of left sub-tree //

            x = rotate_leftleft (x);           // perform leftleft rotation //

        else				       // right sub-tree of left sub-tree height more than left sub-tree of left sub-tree //

            x = rotate_leftright (x);	       // perform leftright rotation //

    }

    else if (balance < -1)			// right sub-tree height more than left sub-tree //

    {

        if (check_balance (x->right) > 0)	// left sub-tree of right sub-tree more than right sub-tree of right sub-tree //

            x = rotate_rightleft (x);		// perform rightleft rotation//

        else					// right sub-tree of right sub-tree more than left sub-tree of right sub-tree //

            x = rotate_rightright (x);		// perform rightright rotation//

    }

    return x;

}


// Insert Element into the tree //


node *avlTree::insert(node *root, int value)

{

    if (root == NULL)				// if tree is empty root will be null //

    {

        root = new node;			// new node type pointer is created and assigned as root //

        root->data = value;			// value is inserted into data variable of root //

        root->left = NULL;			// left sub-node of root is assigned to null because this is the first entry to root //

        root->right = NULL;			// right sub-node of root is assigned to null because this is the first entry to root //

        return root;

    }

    else if (value < root->data)		// value to be inserted less than root value //

    {

        root->left = insert(root->left, value);	// value inserted recursively to left sub-node //

    }

    else if (value > root->data)		// value to be inserted more than root value //

    {

        root->right = insert(root->right, value); // value inserted recursively to right sub-node //


    }

    else					
	 
	   {

	    cout<<" This value "<< value <<" already exists in tree. Enter a different value"<<endl;

	    file<<" This value "<< value << " already exists in tree. Enter a different value"<<endl;

	    }
	
   root=balance(root);				// perform tree balancing to ensure tree is avl tree //

    return root;

}

 

// Inorder Traversal of AVL Tree which is the left-node-right case //

void avlTree::inorder(node *root)

{

    	if (root == NULL)		// for empty tree no traversal is done //

        	return;


         inorder (root->left);	       // recursively performs inorder traversal to the left sub-node //

    	{ cout<<root->data<<"  ";      // prints the node value //

	  file<<root->data<<"  ";}

   	  inorder (root->right);      // recursively performs inorder traversal to the right sub-node //


}



// Preorder Traversal of AVL Tree which is the node-left-right case //
 

void avlTree::preorder(node *root)

{

    	if (root == NULL)		// for empty tree no traversal is done //

        	return;


    	{cout<<root->data<<"  ";	// prints the node value //

       	file<<root->data<<"  ";}

    	preorder (root->left);		// recursively performs preorder traversal to the left sub-node //

    	preorder (root->right);		// recursively performs preorder traversal to the right sub-node //

 

}

 

// Postorder Traversal of AVL Tree which is the left-right-node case //


void avlTree::postorder(node *root)

{

    	if (root == NULL)	   	// for empty tree no traversal is done //

        	return;

    	postorder ( root ->left ); 	// recursively performs postorder traversal to the left sub-node //

    	postorder ( root ->right );	// recursively performs postorder traversal to the right sub-node //

    	{cout<<root ->data<<"  ";	// prints the node value //

	file<<root ->data<<"  ";}

}


// Get Ancestor node for subsequent deletion function //

node *avlTree::get_ancestor(node * root)

{

	node *x = root->left;		  // left sub-node of node assigned to temporary node pointer x //

	while(x->right)

		{

			x = x->right;		// replace x recursively with right right sub-node of x //

		}

	return x;
}


// Delete element from tree //

node *avlTree::delete_node(node *root, int value)
{

	if (!root)				// if no root is found deletion is not performed //

		{

			cout<<"Node to be deleted not found"<<endl;

			file<<"Node to be deleted not found"<<endl;

		return root;

		}

	if (value<root->data)				// value to be deleted is less than root vale //

	{

	root->left = delete_node(root->left,value);	// performs deletion recursively to left sub-node //

	}

	else if (value>root->data)			// value to be deleted is more than root value //

	{

	root->right = delete_node(root->right,value);   // recursively performs deletion to right sub-node //

	}

	else
	
	{
		if ((root->left) &&(root->right ))     // for both the left and right sub-nodes not equal to null //

        {       

		node *x = get_ancestor(root);		// immediate ancestor of root assigned to temporary node pointer x //

		root->data = x->data;			// root value is replaced with value of x which is value of ancestor //

	        root->left = delete_node(root->left,x->data); // perform deletion recursively to left sub-node //

	}

		else					// for one sub-node, either left or right //

		{

		   node*x = root->left?root->left:root->right; // only sub-node, either left or right, assigned to temporary node pointer x //

		   if (!x)                           // for both the sub-nodes equalling to null //

			{
	
			 	x = root;           // empty root is created //

				root = NULL;

			}

				else

					{

						*root = *x;  // replace root with x which is the only sub-node of the deleted node //

					}


		}

	}

	if (!root) return root;

	root = balance(root);   // perform balancing after each deletion to ensure tree is avl tree //

        return root;

}


//Delete entire tree //

void avlTree::delete_tree(node* root)

{ 

	if (root == NULL)			// if root is null , tree already empty, no deletion is performed //

		return;

	if ((root->left)!= NULL )              // for left sub-node not equal to null //
		
		delete_tree(root->left);       // perform deletion recursively to left sub-node //

	if ((root->right)!= NULL )	       // for right sub-node not equal to null //
	
		delete_tree(root->right);      // perform deletion recursively to right sub-node //

	delete root ;                          // delete root node once the immediate sub-nodes are deleted //

}


// Search a value in the avl Tree to return height of the node containing that value //


int avlTree::search_node(node *root, int value)

{

    	if (root == NULL) 			// for root equal to null //

		return -1;			// return a negative value //

	if ( value < root->data)		// value to be searched is less than root value //

	{ 	if (root->left)                // if left sub-node of root exists //

			{
				return search_node(root->left,value); // perform search operation recursively to left sub-node//

			}

	}

	else if (value>root->data)		// value to be searched is more than root value //

	{

		if (root->right)		// if right sub-node of root exists //

			{
				return search_node(root->right,value);  // perform search operation recursively to right sub-node //

			}
	}

	else if (value == root->data)		// value to be searched matches wih node value //

	{

		return height(root);		// perform height calculation on this node //

	}

}




/* Main function*/

int main()

{
   
    file.open("Sanyal-A02262314.txt");	// opens a text file to print output //

    int choice, val;  // variables to store user entered choice for switch case and value for respective operation respectively //

    bool exit=false;  // boolean variable exit to exit from switch case block //

    struct node *root = NULL; // root node is assigned to null //

    avlTree tree;  // object tree of classtype avlTree is created //

    do

    {

        cout<<"\nMy first assignment"<<endl; 

        cout<<"1.Create tree"<<endl;

        cout<<"2.Insert node"<<endl;

        cout<<"3.Delete node"<<endl;

	cout<<"4.Search node"<<endl;

	cout<<"5.Traversal"<<endl;

	cout<<"6.Delete Tree"<<endl;

	cout<<"7.Check Balance"<<endl;

	cout<<"8.Exit"<<endl;

	cout<<"-------------------------------------"<<endl;

        cout<<"Enter your Choice: "<<endl;

        cin>>choice;

        switch(choice)

        {

		case 1:

			{

				string filename = " ";

				ifstream infile;

				cout<<"Enter the input file\n"<<endl;

				cin>>filename;				// input file is assigned to file object filename //

				infile.open(filename.c_str());          // input file is opened //

				char avl[SIZE];

				if(infile.is_open() )

			{

				if(root!= NULL)		// for non-empty tree //


				{

					tree.delete_tree(root);		// tree is deleted //

					root=NULL;			// root is assigned to null //

				}

				while (infile>>avl)		// reads a line from file //

				{

					int item = atoi(avl);   // converts data from a single line of file into integer item //

					root = tree.insert(root,item);  // performs insertion operation for every int data //

				}

				cout<<"Creating Tree ...\n"<<endl; 

				file<<"Creating Tree ...\n"<<endl;

				tree.preorder(root);	// performs preorder traversal of tree //


		    	}

			break;

			}

    			    
		case 2:

			{

            			cout<<"Enter value to be inserted: "<<endl;

            			cin>>val;

            			root = tree.insert(root, val); // performs insertion operation //

				cout<<"Node inserted. Pre-order traversal of tree is :\n"<<endl;

				file<<"Node inserted. Pre-order traversal of tree is :\n"<<endl;

				tree.preorder(root);  // performs preorder traversal //

            		break;

			}


		case 3:

			{
			
				cout<<"Enter value to be deleted: "<<endl;

				cin>>val;

				root = tree.delete_node(root,val);  // performs deletion operation //

				cout<<"Node deleted. Pre-order traversal of tree is :\n"<<endl;

				file<<"Node deleted. Pre-order traversal of tree is :\n"<<endl;

				tree.preorder(root);  // performs preorder traversal //


			break;

			}


		case 4:

			{

				cout<<"Enter value to be searched: "<<endl;

				cin>>val;

				int height = tree.search_node(root,val); // performs search operation and assigns to variable height//

				if(height!= -1) // for non-negative value of height //

				{

				cout<< "Height of node containing "<< val << " is " << height<<" where height of leaf-node is '1'"<<endl;

				cout<<"\n"<<endl;

				file<< "Height of node containing "<< val << " is " << height<<" where height of leaf-node is '1'"<<endl;

				file<<"\n"<<endl;

				}

			break;

			}


		case 5:

			{

				if (root == NULL)    // for empty tree root is null //

				{

					cout<<"Tree is empty\n"<<endl;

					file<<"Tree is empty\n"<<endl;


					break;

				}

				cout<<" 1. Pre-order traversal"<<endl;

				cout<<" 2. Post-order traversal"<<endl;

				cout<<" 3. In-order traversal"<<endl;

				int traverse;

				cin>>traverse;

				switch(traverse)

				{

					case 1: 

						{

							cout<<" Performing Pre-order traversal.. \n"<<endl;

							file<<" Performing Pre-order traversal.. \n"<<endl;

							tree.preorder(root); 

							break;

						}

					case 2:

						{

							cout<<"Performing Post-order traversal..\n"<<endl;

							file<<" Performing Post-order traversal..\n "<<endl;

							tree.postorder(root);

							break;

						}

					case 3:

						{

							cout<<"Performing In-order traversal..\n"<<endl;

							file<<" Performing In-order traversal.. \n"<<endl;

							tree.inorder(root);

							break;

						}

					default:

						{
							cout<<"Please enter a valid choice\n"<<endl;

							break;

						}
				
			}

			break;

		}


	
		case 6:

			{

				tree.delete_tree(root);

				root = NULL;

				cout<<"Delete Tree: Tree deleted \n"<<endl;

				file<<"Delete Tree: Tree deleted \n"<<endl;
				
				tree.preorder(root);

				break;

			}


		case 7:

			{

				if ( root == NULL) // tree is empty if root is null //

				{

				cout<<"Tree is empty\n"<<endl;

				file<<"Tree is empty\n"<<endl;

				}

				else

					{
		
					cout<<" Check Balance:\n "<<tree.check_balance(root)<<endl;  // evaluates balance of root node //

					file<<" Check Balance: \n"<<tree.check_balance(root)<<endl;

					}

				break;

			}


		case 8:

			{

				cout<<" Thank You. I hope my assignment was alright..\n"<<endl;

				file<<" Thank You. I hope my assignment was alright..\n"<<endl;

				file.close();

				exit=true;

				break;

			}

		default:

			{

				cout<<" Please enter a valid choice\n"<<endl;

			}
   
	}

    } while(!exit);	       		

return 0;

}






