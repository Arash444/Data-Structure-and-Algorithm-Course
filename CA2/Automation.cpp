#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <utility>

using namespace std;
typedef vector<vector<string>> matrix;
typedef vector<vector<int>> int_matrix;
typedef pair<string, matrix> full_matrix;
int row_number[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int column_number[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

bool isValid(int number_of_dimensions, int current_row, int current_column)
{
	if ((current_row >= 0) && (current_row < number_of_dimensions) &&
		(current_column >= 0) && (current_column < number_of_dimensions))
		return true;
	else
		return false;
}
bool isUnique(int_matrix output, int matrix_row, int matrix_column)
{
	for (unsigned int i = 0; i < output.size(); i++)
		if ((matrix_row == output[i][0]) && (matrix_column == output[i][1]))
			return false;
	return true;
}
void printVector(int_matrix output)
{
	for (unsigned int i = 0; i < output.size(); i++)
	{
		int output_row = output[i][0];
		int output_column = output[i][1];
		cout << "(" << output_row << ", " << output_column;
		if (i != output.size() - 1)
			cout << "),";
		else
			cout << ")\n";
	}
}
void findOtherLetters(matrix &our_letters, string wanted_word,int index, 
	int current_row, int current_column, int_matrix output)
{
	output.push_back({ current_row, current_column });
	if (wanted_word.size() == index + 1)
	{
		printVector(output);
		return;
	}
	for (int i = 0; i < 8; i++)
	{
		int next_row = current_row + row_number[i];
		int next_column = current_column + column_number[i];
		if ((isValid(our_letters.size(), next_row, next_column)) &&
			(our_letters[next_row][next_column][0] == wanted_word[index + 1]) &&
			(isUnique(output, next_row, next_column)))
			findOtherLetters(our_letters, wanted_word, index + 1, next_row, next_column, output);	
	}
}
void findWantedWord(string wanted_word, matrix our_letters)
{
	for (unsigned int i = 0; i < our_letters.size(); i++)
		for (unsigned int j = 0; j < our_letters.size(); j++)
			if (wanted_word[0] == our_letters[i][j][0])
			{
				int_matrix output;
				findOtherLetters(our_letters, wanted_word, 0, i, j, output);
			}
}
full_matrix createMatrix()
{
	string first_line, wanted_word, temp_number_string;
	int number_of_dimensions;
	cin >> first_line;
	stringstream temp_line(first_line);
	getline(temp_line, temp_number_string, ',');
	number_of_dimensions = stoi(temp_number_string);
	getline(temp_line, wanted_word, '\n');
	matrix our_matrix(number_of_dimensions, vector<string>(number_of_dimensions, " "));
	for (int i = 0; i < number_of_dimensions; i++)
	{
		string input_line;
		cin >> input_line;
		stringstream temp_line(input_line);
		for (int j = 0; j < number_of_dimensions; j++)
		{
			if (j != number_of_dimensions - 1)
				getline(temp_line, our_matrix[i][j], ',');
			else 
				getline(temp_line, our_matrix[i][j], '\n');
		}
	}
	full_matrix matrix_and_wanted_word = make_pair(wanted_word, our_matrix);
	return matrix_and_wanted_word;
}
int main()
{
	full_matrix matrix_and_wanted_word = createMatrix();
	string wanted_word = matrix_and_wanted_word.first;
	matrix our_letters = matrix_and_wanted_word.second;
	findWantedWord(wanted_word, our_letters);
	return 0;
}
