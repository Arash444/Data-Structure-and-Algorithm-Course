#include <iostream>
#include <cmath>
using namespace std;

void findHider(long long height, long long hiding_place, long long count_nodes = 0, char left_or_right = 'L')
{
	 long long total_leaves = pow(2, height);
	 if (!height)
	 {
		 cout << count_nodes << '\n';
		 return;
	 }
	 else
		 height -= 1;
	 if (left_or_right == 'L' && hiding_place > total_leaves / 2)
	 {
		 count_nodes += total_leaves;
		 hiding_place -= total_leaves / 2;
		 findHider(height, hiding_place, count_nodes, 'L');
	 }
	 else if (left_or_right == 'L' && hiding_place <= total_leaves / 2)
	 {
		 count_nodes += 1;
		 findHider(height, hiding_place, count_nodes, 'R');
	 }
	 else if (left_or_right == 'R' && hiding_place > total_leaves / 2)
	 {
		 count_nodes += 1;
		 hiding_place -= total_leaves / 2;
		 findHider(height, hiding_place, count_nodes, 'L');
	 }
	 else if (left_or_right == 'R' && hiding_place <= total_leaves / 2)
	 {
		 count_nodes += total_leaves;
		 findHider(height, hiding_place, count_nodes, 'R');
	 }
}
int main()
{
	long long height, hiding_place;
	cin >> height >> hiding_place;
	findHider(height, hiding_place);
	return 0;
}
