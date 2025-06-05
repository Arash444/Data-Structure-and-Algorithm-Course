#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main()
{ 
	string slug_input;
	stack<char> output;
	vector<char> final_output;
	cin >> slug_input;
	for (unsigned int i = 0; i < slug_input.size(); i++)
	{
		if (!output.empty() && slug_input[i] == output.top())
			output.pop();
		else
			output.push(slug_input[i]);
	}
	while (!output.empty())
	{
		char output_letter = output.top();
		final_output.push_back(output_letter);
		output.pop();
	}
	for (int i = final_output.size() - 1; i >= 0; i--)
		cout << final_output[i];
	return 0;
}
