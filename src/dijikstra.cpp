#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge
{
  int to;
  int weight;

  Edge() : to(-1), weight(0) {}
  Edge(int to, int weight) : to(to), weight(weight) {}
};

using VertexDist = pair<int, int>;

using Graph = vector<vector<Edge>>;

struct Compare
{
  bool operator()(const VertexDist &v1, const VertexDist &v2)
  {
    return v1.second > v2.second;
  }
};

void dijkstra(Graph graph, int source)
{
  Compare comp;
  priority_queue<VertexDist, vector<VertexDist>, Compare> queue(comp);

  // Initializing vectors to keep track of visited, distances and parents
  vector<bool> visited(graph.size(), false);
  vector<int> dist(graph.size(), INT_MAX);
  vector<int> parent(graph.size(), -1);

  queue.push(make_pair(source, 0));
  dist[source] = 0;

  while (!queue.empty())
  {
    auto [vertex, d] = queue.top();
    queue.pop();

    // Skip if already visited and mark as visited
    if (visited[vertex])
    {
      continue;
    }
    visited[vertex] = true;

    for (const auto &neighbor : graph[vertex])
    {
      auto altDist = dist[vertex] + neighbor.weight;

      if (dist[neighbor.to] > altDist)
      {
        dist[neighbor.to] = altDist;
        parent[neighbor.to] = vertex;
        queue.push(make_pair(neighbor.to, dist[neighbor.to]));
      }
    }
  }

  // Printing the distances
  for (int i = 0; i < graph.size(); i++)
  {
    cout << "Distance from " << source << " to " << i << " is " << dist[i] << endl;
  }
}

Graph readInput()
{
  // Reading number of vertices and edges
  int v, e;
  cin >> v >> e;

  Graph graph(v);

  for (int i = 0; i < e; i++)
  {
    int v1, v2, weight;
    cin >> v1 >> v2 >> weight;

    graph[v1].push_back(Edge(v2, weight));
    graph[v2].push_back(Edge(v1, weight));
  }

  return graph;
}

int main()
{
  Graph graph = readInput();

  dijkstra(graph, 0);

  return 0;
}
