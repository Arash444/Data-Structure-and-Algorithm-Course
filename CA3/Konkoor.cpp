#include <iostream>
#include <cstdlib>
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
	int input_rating;
	cin >> input_rating;
	if (root == nullptr)
	{
		root = newNode(input_rating);
		return root;
	}
	Node *current_child = root;
	while (true)
	{
		int current_rating = current_child->data;
		if (input_rating > current_rating)
		{
			if (current_child->right != nullptr)
				current_child = current_child->right;
			else
			{
				current_child->right = newNode(input_rating);
				return root;
			}
		}
		else
		{
			if (current_child->left != nullptr)
				current_child = current_child->left;
			else
			{
				current_child->left = newNode(input_rating);
				return root;
			}
		}
	}
}
void printLowestDifference(Node *root)
{
	Node *current_child = root;
	Node *previous_child;
	int input_rating, lowest_difference;
	cin >> input_rating;
	lowest_difference = abs(current_child->data - input_rating);
	while (true)
	{
		int current_difference;
		current_difference = abs(current_child->data - input_rating);
		if (current_difference < lowest_difference)
			lowest_difference = current_difference;
		if (current_child->data < input_rating)
		{
			if (current_child->right != nullptr)
			{
				previous_child = current_child;
				current_child = current_child->right;
				continue;
			}
			else
			{
				cout << lowest_difference << '\n';
				return;
			}
		}
		else if (current_child->data > input_rating)
		{
			if (current_child->left != nullptr)
			{
				previous_child = current_child;
				current_child = current_child->left;
				continue;
			}
			else
			{
				cout << lowest_difference << '\n';
				return;
			}
		}
		else
		{
			cout << 0 << '\n';
			return;
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
			printLowestDifference(root);
	}
}
