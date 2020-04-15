#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>

using namespace std;
class BST;
class Node
{
	friend class BST;
	public:
		Node(int data = 0,Node* leftchild = 0, Node* rightchild = 0,Node* parent=0)
		{
			this->data = data;
			this->leftchild = leftchild;
			this->rightchild = rightchild;
			this->parent = parent;
		}
	private:
		Node* leftchild;
		Node* rightchild;
		Node* parent;
		int data;
};
class BST
{
	public:
		BST()
		{
			this->root = NULL;
		}
		void Addnode(int input_data);
		void Inorder();
		void Rightchild_print();
		void Leftchild_print();
		void Binary_Search(int input_data);
	private:
		bool isempty();
		void inorder(Node* current_node);
		void rightchild_print(Node* current_node);
		void leftchild_print(Node* current_node);
	private:
		Node* root;
};
bool BST::isempty()
{
	if (root == 0)return true;
	else return false;
}
void BST::Addnode(int input_data)
{
	if (isempty())
	{
		Node* the_root = new Node(input_data);
		the_root->leftchild = NULL;
		the_root->rightchild = NULL;
		the_root->parent = NULL;
		root = the_root;
	}
	else
	{
		Node* current = root;
		while (1)
		{
			if (input_data < current->data)
			{
				if (current->leftchild != 0)
				{
					current = current->leftchild;

				}
				else
				{
					
					Node* new_node=new Node(input_data);
					new_node->leftchild=NULL;
					new_node->rightchild=NULL;
					new_node->parent = current;
					current->leftchild=new_node;
					break;
				}
			}
			else if(input_data > current->data)
			{
				
				if (current->rightchild != 0)
				{
					current = current->rightchild;
				} 
				else
				{
					Node* new_node=new Node(input_data);
					new_node->rightchild=NULL;
					new_node->leftchild=NULL;
					new_node->parent = current;
					current->rightchild=new_node;
					break;
				}
			}
			else
			{//Node "current" is to be deleted one
				if (current == root)
				{
					if ((current->leftchild == 0) || (current->rightchild == 0))
					{
						if ((current->leftchild == 0) && (current->rightchild == 0))
						{
							root = NULL;
							delete current;
							break;
						}
						else if ((current->leftchild != 0) && (current->rightchild == 0))
						{
							root = root->leftchild;
							root->parent = NULL;
							current->leftchild = NULL;
							current->rightchild = NULL;
							current->parent = NULL;
							delete current;
							break;
						}
						else if ((current->leftchild == 0) && (current->rightchild != 0))
						{
							root = root->rightchild;
							root->parent = NULL;
							current->leftchild = NULL;
							current->rightchild = NULL;
							current->parent = NULL;
							delete current;
							break;
						}
						
					}
					else
					{
						Node* inorder_successor = current->leftchild;
						int step = 0;
						while (inorder_successor->rightchild != 0)
						{
							inorder_successor = inorder_successor->rightchild;
							step++;
						}
						if (step == 0)
						{
							if (inorder_successor->leftchild == 0)
							{
								current->data = inorder_successor->data;
								current->leftchild = NULL;
								inorder_successor->parent = NULL;
								delete inorder_successor;
								break;
							}
							else
							{
								inorder_successor->parent = NULL;
								inorder_successor->rightchild = current->rightchild;
								current->rightchild->parent = inorder_successor;
								root = inorder_successor;
								current->rightchild = NULL;
								current->leftchild = NULL;
								current->parent = NULL;
								delete current;
								break;

							}
						}
						else
						{
							if (inorder_successor->leftchild == 0)
							{
								current->data = inorder_successor->data;
								inorder_successor->parent->rightchild = NULL;
								inorder_successor->leftchild = NULL;
								inorder_successor->rightchild = NULL;
								inorder_successor->parent = NULL;
								delete inorder_successor;
								break;
							}
							else
							{
								current->data = inorder_successor->data;
								inorder_successor->parent->rightchild = inorder_successor->leftchild;
								inorder_successor->leftchild->parent = inorder_successor->parent;
								inorder_successor->leftchild = NULL;
								inorder_successor->rightchild = NULL;
								inorder_successor->parent = NULL;
								delete inorder_successor;
								break;
							}
						}
					}
				}
				else
				{
					if ((current->leftchild == 0) || (current->rightchild == 0))//with only one subtree or no child
					{
						
						if ((current->leftchild == 0) && (current->rightchild == 0))//with no child
						{
							if ((current->parent->leftchild != 0) && (input_data == current->parent->leftchild->data))
							{
								current->parent->leftchild = NULL;
								delete current;
								break;
							}
							else if ((current->parent->rightchild != 0) && (input_data == current->parent->rightchild->data))
							{
								
								current->parent->rightchild = NULL;
								delete current;
								break;
							}
							else
							{
								cout << "!" << endl;
								break;
							}

						}
						else if ((current->leftchild != 0) && (current->rightchild == 0))//with one leftchild or leftsubtree
						{
							if ((current->parent->leftchild != 0) && (input_data == current->parent->leftchild->data))
							{	
								current->parent->leftchild = current->leftchild;
								current->leftchild->parent = current->parent;
								delete current;
								break;
							}
							else if ((current->parent->rightchild != 0) && (input_data == current->parent->rightchild->data))
							{		
								current->parent->rightchild = current->leftchild;
								current->leftchild->parent = current->parent;
								delete current;
								break;
							}
							else
							{
								cout << "!!" << endl;
								break;
							}
						}
						else if ((current->leftchild == 0) && (current->rightchild != 0))
						{
							if ((current->parent->leftchild!=0)&&(input_data == current->parent->leftchild->data))
							{
								current->parent->leftchild = current->rightchild;
								current->rightchild->parent = current->parent;
								delete current;
								break;
							}
							else if ((current->parent->rightchild != 0) && (input_data == current->parent->rightchild->data) )
							{
								current->parent->rightchild = current->rightchild;
								current->rightchild->parent=current->parent;
								delete current;
								break;
							}
							else
							{
								cout << "!!!" << endl;
								break;
							}
						}
					}
					else
					{
						Node* inorder_successor = current->leftchild;
						int step = 0;
						while (inorder_successor->rightchild != 0)
						{
							inorder_successor = inorder_successor->rightchild;
							step++;
						}
						if (step == 0)
						{
							if (inorder_successor->leftchild == 0)
							{
								
								current->data = inorder_successor->data;
								current->leftchild = NULL;
								inorder_successor->parent = NULL;
								delete inorder_successor;
								break;
							}
							else
							{
								if (current->parent->leftchild->data == current->data)
								{
									inorder_successor->parent = current->parent;
									inorder_successor->rightchild = current->rightchild;
									current->parent->leftchild = inorder_successor;
									current->leftchild = NULL;
									current->rightchild = NULL;
									current->parent = NULL;
									delete current;
									break;
								}
								else if (current->parent->rightchild->data == current->data)
								{
									inorder_successor->parent = current->parent;
									inorder_successor->rightchild = current->rightchild;
									current->parent->rightchild = inorder_successor;
									current->leftchild = NULL;
									current->rightchild = NULL;
									current->parent = NULL;
									delete current;
									break;
								}
								else
								{
									cout << "!!!!" << endl;
									break;
								}
								
							}
						}
						else
						{
							if (inorder_successor->leftchild == 0)
							{
								current->data = inorder_successor->data;
								inorder_successor->parent->rightchild = NULL;
								inorder_successor->leftchild = NULL;
								inorder_successor->rightchild = NULL;
								inorder_successor->parent = NULL;
								delete inorder_successor;
								break;
							}
							else
							{
								current->data = inorder_successor->data;
								inorder_successor->parent->rightchild = inorder_successor->leftchild;
								inorder_successor->leftchild->parent = inorder_successor->parent;
								inorder_successor->leftchild = NULL;
								inorder_successor->rightchild = NULL;
								inorder_successor->parent = NULL;
								delete inorder_successor;
								break;
							}
						}
					}
					
				}
			}
		}

	}
	return;
}
void BST::inorder(Node* current_node)
{
	if (current_node)
	{
		inorder(current_node->leftchild);
		cout << current_node->data << " ";
		inorder(current_node->rightchild);
	}
	
}
void BST::Inorder()
{
	inorder(root);
	cout << endl;
}
void BST::Leftchild_print()
{
	leftchild_print(root);
	cout << endl;
}
void BST::leftchild_print(Node* current_node)
{
	if (current_node)
	{
		leftchild_print(current_node->leftchild);
		if (current_node->leftchild != 0)
		{
			cout << current_node->leftchild->data << " ";
		}
		else
		{
			cout << 0 << " ";
		}
		leftchild_print(current_node->rightchild);
	}
}
void BST::Rightchild_print()
{
	rightchild_print(root);
	cout << endl;
}
void BST::rightchild_print(Node* current_node)
{
	if (current_node)
	{
		rightchild_print(current_node->leftchild);
		if (current_node->rightchild != 0)
		{
			cout << current_node->rightchild->data << " ";
		}
		else
		{
			cout << 0 << " ";
		}
		rightchild_print(current_node->rightchild);
	}
}


void BST::Binary_Search(int input_data)
{
	if (isempty())cout << "the tree is empty." << endl;
	else
	{
		Node* current = root;
		while (1)
		{
			if ( input_data < current->data )
			{
				if (current->leftchild != 0)current = current->leftchild;
				else
				{
					cout << "the data cannot be found in the tree." << endl;
					break;
				}
			}
			else if (input_data > current->data)
			{
				if (current->rightchild != 0)current = current->rightchild;
				else
				{
					cout << "the data cannot be found in the tree. " << endl;
					break;
				}
			}
			else
			{
				cout << "The data is found." << endl;
				break;
			}
		}
	}
	return;
}

void test();
void test2();
int main(void)
{
	test();
	system("pause");
	return 0;
}

void test()
{
	cout << "plz input data u wanna put into the binary search tree:" << endl;
	BST tree;
	int input_data;
	cin >> input_data;
	while (input_data != -1)
	{
		tree.Addnode(input_data);
		cin >> input_data;
	}
	cout << "node: ";
	tree.Inorder();
	cout << "Leftchild: ";
	tree.Leftchild_print();
	cout << "rightchild: ";
	tree.Rightchild_print();
	

	return;
}
void test2()
{
	BST tree;
	for (int i = 10; i <14; i++)
	{
		tree.Addnode(10 * i);
	}
	tree.Addnode(90);
	tree.Addnode(80);
	tree.Addnode(98);
	tree.Addnode(99);
	tree.Addnode(94);
	tree.Addnode(92);
	tree.Addnode(97);
	tree.Addnode(95);
	//tree.Addnode(92);
	tree.Addnode(91);
	tree.Addnode(93);
	tree.Addnode(98);
	tree.Addnode(98);
	/*tree.Addnode(40);
	tree.Addnode(71);
	tree.Addnode(88);
	tree.Addnode(32);
	tree.Addnode(47);
	tree.Addnode(56);
	tree.Addnode(62);
	tree.Addnode(38);
	tree.Addnode(61);*/
	tree.Inorder();
	tree.Leftchild_print();
	tree.Rightchild_print();
	return;
}