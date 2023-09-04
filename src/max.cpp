#include <iostream>
#include <unordered_map>

#include "utils.h"

using std::cout;
using std::endl;
using std::unordered_map;

int max(int n, int arr[])
{
  int max = arr[0];

  for (int i = 1; i < n; i++)
  {
    if (arr[i] > max)
    {
      max = arr[i];
    }
  }
  return max;
}

int maxRecursive(int n, int arr[], unordered_map<int, int> &cache)
{

  // First check if the cache contains a value for n
  if (cache.find(n) != cache.end())
  {
    return cache[n];
  }

  // If n is 1, return the first element of the array
  if (n == 1)
  {
    cache[1] = arr[0];
    return arr[0];
  }

  int maxRest = maxRecursive(n - 1, arr, cache);

  int max = arr[n - 1] > maxRest ? arr[n - 1] : maxRest;

  cache[n] = max;

  return max;
}

int main()
{
  int s = 9;
  int *arr = randomArray(s);

  cout << "Current Array: " << join(s, arr) << endl;

  cout << "Iterative: " << max(s, arr) << endl;

  unordered_map<int, int> cache;
  cout << "Recursive: " << maxRecursive(s, arr, cache) << endl;

  return 0;
}
