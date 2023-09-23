#ifndef UTILS_H
#define UTILS_H

#include <tuple>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>

int *randomArray(int size)
{
  int *arr = new int[size];

  srand(time(NULL));

  for (int i = 0; i < size; i++)
  {
    arr[i] = rand() % 100;
  }

  return arr;
}

std::string join(int size, int v[])
{
  std::string response = "";
  for (int i = 0; i < size; i++)
  {
    response += std::to_string(v[i]) + ", ";
  }
  response = response.substr(0, response.length() - 2);
  return response;
}

std::string tupleToString(std::tuple<int, int> t)
{
  return "(" + std::to_string(std::get<0>(t)) + ", " + std::to_string(std::get<1>(t)) + ")";
}

std::string pairToString(std::pair<int, int> p)
{
  return "(" + std::to_string(p.first) + ", " + std::to_string(p.second) + ")";
}

/**
 * Prints a graph represented as an adjacency list
 */
void printGraph(const std::vector<std::vector<int>> &graph)
{
  for (int vertex = 1; vertex <= graph.size(); vertex++)
  {
    std::cout << vertex << ": ";
    for (const auto &edge : graph[vertex - 1])
    {
      std::cout << edge << " ";
    }
    std::cout << std::endl;
  }
}

#endif
