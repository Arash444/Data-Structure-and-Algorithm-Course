#include <iostream>
#include <string>
using namespace std;
struct Node {
	char data;
	Node* next;
};
Node* createLinkList(int &count_radiant, int &count_dire)
{
	Node *head = NULL, *previous_node;
	string senators;
	cin >> senators;
	head = new Node();
	head->data = senators[0];
	for (unsigned int i = 0; i < senators.size(); i++)
	{
		if (senators[i] == 'R')
			count_radiant++;
		else if (senators[i] == 'D')
			count_dire++;
		if (i == 0)
		{
			previous_node = head;
			continue;
		}
		Node* current_node = NULL;
		current_node = new Node();
		current_node->data = senators[i];
		previous_node->next = current_node;
		previous_node = current_node;
		if (i == senators.size() - 1)
			current_node->next = head;
	}
	return head;
}
void findWinner(Node *head, int count_radiant, int count_dire)
{
	Node *previous_node, *current_node;
	bool start = true;
	while (true)
	{
		if (count_radiant == 0)
		{
			cout << "Dire";
			break;
		}
		else if (count_dire == 0)
		{
			cout << "Radiant";
			break;
		}
		if (start)
		{
			current_node = head;
			start = false;
		}
		if (current_node->data == 'R')
		{
			previous_node = current_node;
			current_node = current_node->next;
			if (current_node->data == 'D')
			{
				previous_node->next = current_node->next;
				delete current_node;
				current_node = previous_node->next;
				count_dire--;
			}
			else
			{
				Node *main_current = current_node, *main_previous = previous_node;
				while (true)
				{
					if (current_node->data == 'D')
					{
						previous_node->next = current_node->next;
						delete current_node;
						current_node = main_current;
						previous_node = main_previous;
						count_dire--;
						break;
					}
					else
					{
						previous_node = current_node;
						current_node = current_node->next;
					}
				}
			}
		}
		if (current_node->data == 'D')
		{
			previous_node = current_node;
			current_node = current_node->next;
			if (current_node->data == 'R')
			{
				previous_node->next = current_node->next;
				delete current_node;
				current_node = previous_node->next;
				count_radiant--;
			}
			else
			{
				Node *main_current = current_node, *main_previous = previous_node;
				while (true)
				{
					if (current_node->data == 'R')
					{
						previous_node->next = current_node->next;
						delete current_node;
						current_node = main_current;
						previous_node = main_previous;
						count_radiant--;
						break;
					}
					else
					{
						previous_node = current_node;
						current_node = current_node->next;
					}
				}
			}
		}
	}
}
int main()
{
	Node *head;
	int count_radiant = 0, count_dire = 0;
	head = createLinkList(count_radiant, count_dire);
	findWinner(head, count_radiant, count_dire);
	return 0;
}
