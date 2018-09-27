///////////////////////////////////////////////////////////////////////////////
// Code by TuanPM, 09/2018
// Refer https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm
//

#include <vector>
#include <string>
#include <stdio.h>
#include <limits.h>
#include <iostream>
#include <algorithm>

using namespace std;
#define INFINITE INT_MAX
#define UNDEFINED -1

//--------------
void printSolution(vector<int> dist)
{
	printf("Vertex\tDistance from Source\n");
	for (unsigned int i = 0; i < dist.size(); i++)
		cout << i << "\t" << dist[i]<< endl;		
}

string getPath(vector<int> path, int src, int target)
{
	string ret;
	vector<int> shortestPath;
	shortestPath.push_back(target);
	do {
		shortestPath.push_back(path[target]);
	}
	while (path[target--] != src);
	
	std::reverse(shortestPath.begin(), shortestPath.end());
	for (unsigned int i = 0; i < shortestPath.size(); i++) {
		if (i) ret.append("->");
		char buff[100] = {0};
		sprintf(buff, "%d", shortestPath[i]);
		ret.append(buff);
	}
	cout << ret << endl;
	return ret;
}

//--------------
/**
 * @brief 
 * @param Q
 * @param dist
 * @return 
 */
vector<int>::iterator minDistIndex(vector<int>& Q, vector<int> dist) {
	vector<int>::iterator ret;
	vector<int>::iterator it;
	it =  Q.begin();
	ret = it;
	for (it = Q.begin(); it != Q.end(); it++) {
		if (dist[*it] < dist[*ret]) ret = it;
	}
	return ret;
}

/**
 * @brief 
 * @param graph
 * @param src
 */
void dijkstra_single_source(vector<vector<int>> graph, int src) {
	int verticesNum = graph.size();
	vector<int> Q;
	vector<int> dist(verticesNum, INFINITE);
	vector<int> path(verticesNum, UNDEFINED);
	
	for (unsigned int i = 0; i < verticesNum; ++i) {
		Q.push_back(i);
 	}
	
	dist[src] = 0;
	
	while (Q.size()) {
		vector<int>::iterator it = minDistIndex(Q, dist);
		int u = *it;
		Q.erase(it);
		
		// foreach neighbor
		for (unsigned  int i = 0; i < verticesNum; ++i) {
			// if have edge from u to Vi
			if (graph[u][i]) {
				int alt = dist[u] + graph[u][i];
				if (alt < dist[i]) {
					dist[i] = alt;
					path[i] = u;
				}
			}
		}
	}
	
	printSolution(dist); 
}

/**
 * @brief 
 * @param graph
 * @param src
 * @param target
 */
void dijkstra_single_source_to_single_target(vector<vector<int>> graph, int src, int target) {
	int verticesNum = graph.size();
	vector<int> Q;
	vector<int> dist(verticesNum, INFINITE);
	vector<int> path(verticesNum, UNDEFINED);
	
	for (unsigned int i = 0; i < verticesNum; ++i) {
		Q.push_back(i);
 	}
	
	dist[src] = 0;
	
	while (Q.size()) {
		vector<int>::iterator it = minDistIndex(Q, dist);
		int u = *it;
		Q.erase(it);
		
		// if find target --> Finish
		if (u == target) break;
		
		// foreach neighbor
		for (unsigned int i = 0; i < verticesNum; ++i) {
			// if have edge from u to Vi
			if (graph[u][i]) {
				int alt = dist[u] + graph[u][i];
				if (alt < dist[i]) {
					dist[i] = alt;
					path[i] = u;
				}
			}
		}
	}
	
	getPath(path, src, target);
}

//-------------
int main()
{
   /* Let us create the example graph discussed above */
   vector<vector<int>> graph = {
							{0, 4, 0, 20, 0},
							{4, 0, 24, 0, 0},
							{0, 24, 0, 7, 0},
							{0, 0, 7, 0, 9},
							{20, 0, 0, 9, 0},
                     };
  
    dijkstra_single_source(graph, 0);
	dijkstra_single_source_to_single_target(graph, 0, 2);	  
	return 0;
}