#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
struct Node {
	int data;
	Node* next;
};

void findGroups(Node *head, vector<int> group_people)
{
	Node *current_node = head;
	bool previous_is_in_group = false;
	int number_of_groups = 0;
	while (current_node->next != NULL)
	{
		bool current_is_in_group = false;
		for (unsigned int i = 0; i < group_people.size(); i++)
		{
			if (current_node->data == group_people[i])
			{
				if (!previous_is_in_group)
					number_of_groups++;
				current_is_in_group = true;
				break;
			}
		}
		if (!current_is_in_group)
			previous_is_in_group = false;
		else 
			previous_is_in_group = true;
		current_node = current_node->next;
	}
	cout << number_of_groups;
}
Node* getAllPeople()
{
	Node *head = NULL, *previous_node, *current_node = NULL;
	string input_line, part_line;
	cin >> input_line;
	stringstream temp_line(input_line);
	getline(temp_line, part_line, ',');
	head = new Node();
	head->data = stoi(part_line);
	previous_node = head;
	while(getline(temp_line, part_line, ','))
	{
		current_node = new Node();
		current_node->data = stoi(part_line);
		previous_node->next = current_node;
		previous_node = current_node;
	}
	current_node->next = NULL;
	return head;
}
vector<int> getGroupPeople()
{
	vector<int> group_people;
	string input_line, part_line;
	cin >> input_line;
	stringstream temp_line(input_line);
	while (getline(temp_line, part_line, ','))
		group_people.push_back(stoi(part_line));
	return group_people;
}
int main()
{
	Node *head = getAllPeople();
	vector<int> group_people = getGroupPeople();
	findGroups(head, group_people);
	return 0;
}
