#ifndef UTILS_H
#define UTILS_H

#include <tuple>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

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

#endif
