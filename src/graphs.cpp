#include <iostream>
#include <vector>
#include <queue>

#include "utils.h"

using std::cout;
using std::endl;
using std::queue;
using std::vector;

/**
 * Given a graph represented as an adjacency list, find the shortest path between two vertices using BFS (Breadth-First Search)
 * params:
 *  graph: the graph represented as an adjacency list
 *  start: the vertex to start the search from. Its index in the graph is start - 1
 *  end: the vertex to end the search at. Its index in the graph is end - 1
 */
int *shortestPathBFS(const vector<vector<int>> graph, int start, int end)
{
  vector<int> dist(graph.size(), -1); // Initializing an empty vector of size graph.size() with -1 values to represent the distance between start and end
  queue<int> q;                       // Creating an empty queue

  dist[start - 1] = 0; // Setting the distance between start and start to 0
  q.push(start);       // Adding start to the queue to start the search from it

  while (!q.empty())
  {
    // Call the first element in the queue and pop it
    int current = q.front();
    q.pop();

    // For each neighbor, if it hasn't been visited yet, set its distance to the current distance + 1 and add it to the queue for visiting later
    for (const auto &neighbor : graph[current - 1])
    {
      if (dist[neighbor - 1] == -1)
      {
        dist[neighbor - 1] = dist[current - 1] + 1;
        q.push(neighbor);
      }
    }
  }

  if (dist[end - 1] == -1)
  {
    return nullptr;
  }

  return &dist[end - 1];
}

void DFS(const vector<vector<int>> &graph, int start, vector<int> &visited)
{
  visited[start - 1] = true;

  for (const auto &neighbor : graph[start - 1])
  {
    if (!visited[neighbor - 1])
    {
      DFS(graph, neighbor, visited);
    }
  }
}

/**
 * Checks if the given graph is connected using DFS (Depth-First Search)
 * params:
 *  graph: the graph represented as an adjacency list
 *  start: the vertex to start the search from. Its index in the graph is start - 1
 */
bool isConnectedDFS(const vector<vector<int>> &graph, int start)
{
  vector<int> visited(graph.size(), false); // Initializing an empty vector of size graph.size() with false values

  DFS(graph, start, visited);

  for (const auto &vertex : visited)
  {
    if (!vertex)
    {
      return false;
    }
  }

  return true;
}

int main()
{
  const vector<vector<int>> graph = {
      {2, 4},
      {1, 3},
      {2, 4, 5},
      {1, 3, 5},
      {3, 4, 6},
      {5},
  };

  printGraph(graph);

  bool isConnected = isConnectedDFS(graph, 1);

  cout << "Is the graph connected? " << (isConnected ? "Yes" : "No") << endl;

  int *shortestPathPtr = shortestPathBFS(graph, 1, 6);

  cout << "Shorted path from 1 to 6: ";
  if (shortestPathPtr == nullptr)
  {
    cout << "No path found" << endl;
  }
  else
  {
    cout << *shortestPathPtr << endl;
  }

  return 0;
}
