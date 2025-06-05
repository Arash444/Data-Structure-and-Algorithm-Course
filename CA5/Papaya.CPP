#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> edge;
vector<vector<edge>> getGraph()
{
	int vertices_count = 0, edge_count = 0;
	cin >> vertices_count >> edge_count;
	vector<vector<edge>> graph(vertices_count);
	int start, end, value;
	for (int i = 0; i < edge_count; i++)
	{
		edge input_edge;
		cin >> start >> end >> value;
		input_edge.first = value;
		input_edge.second = end - 1;
		graph[start - 1].push_back(input_edge);
	}
	return graph;
}
int DFS(vector<vector<edge>> graph, int current_vertice, int new_energy = 0, int max_energy = 0)
{
	for (unsigned int i = 0; i < graph[current_vertice].size(); i++)
	{
		if (graph[current_vertice][i].first >= 0)
		{
			graph[current_vertice][i].first--;
			max_energy = DFS(graph, graph[current_vertice][i].second,
				new_energy + 1 + graph[current_vertice][i].first, max_energy);
		}
	}
	if (new_energy > max_energy)
		max_energy = new_energy;
	return max_energy;
}
int main()
{
	int starting_vertice, max_energy;
	vector<vector<edge>> graph = getGraph();
	cin >> starting_vertice;
	max_energy = DFS(graph, starting_vertice - 1);
	cout << max_energy << "\n";
	return 0;
}
