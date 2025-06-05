#include <iostream>
using namespace std;
struct Node {
	int data;
	Node* left;
	Node* right;
};
Node *newNode(int new_data)
{
	Node* new_child;
	new_child = new Node();
	new_child->data = new_data;
	new_child->left = nullptr;
	new_child->right = nullptr;
	return new_child;
}
Node *getInput(Node *root)
{
	int input_mark;
	cin >> input_mark;
	if (root == nullptr)
	{
		root = newNode(input_mark);
		return root;
	}
	Node *current_child = root;
	while (true)
	{
		int current_mark = current_child->data;
		if (input_mark > current_mark)
		{
			if (current_child->right != nullptr)
				current_child = current_child->right;
			else
			{
				current_child->right = newNode(input_mark);
				return root;
			}
		}
		else
		{
			if (current_child->left != nullptr)
				current_child = current_child->left;
			else
			{
				current_child->left = newNode(input_mark);
				return root;
			}
		}
	}
}
Node *printLowestMark(Node *root)
{
	Node *current_child = root;
	Node *previous_child;
	while (true)
	{
		if (current_child->left != nullptr)
		{
			previous_child = current_child;
			current_child = current_child->left;
		}
		else
		{
			int lowest_mark = current_child->data;
			cout << lowest_mark << '\n'; 
			if (current_child->right != nullptr)
			{
				if (current_child == root)
					root = current_child->right;
				else
					previous_child->left = current_child->right;
			}
			else
			{
				if (current_child == root)
					root = nullptr;
				else
					previous_child->left = nullptr;
			} 
			delete current_child;
			return root;
		}
	}
}
Node *printHighestMark(Node *root)
{
	Node *current_child = root;
	Node *previous_child;
	while (true)
	{
		if (current_child->right != nullptr)
		{
			previous_child = current_child;
			current_child = current_child->right;
		}
		else
		{
			int highest_mark = current_child->data;
			cout << highest_mark << '\n';
			if (current_child->left != nullptr)
			{
				if (current_child == root)
					root = current_child->left;
				else
					previous_child->right = current_child->left;
			}
			else
			{
				if (current_child == root)
					root = nullptr;
				else
					previous_child->right = nullptr;
			}
			delete current_child;
			return root;
		}
	}
}
int main()
{
	Node *root = nullptr;
	int num_operations;
	cin >> num_operations;
	for (int i = 0; i < num_operations; i++)
	{
		int type;
		cin >> type;
		if (type == 1)
			root = getInput(root);
		else if (type == 2)
			root = printLowestMark(root);
		else if (type == 3)
			root = printHighestMark(root);
	}
}
