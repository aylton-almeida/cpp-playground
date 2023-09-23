#include <iostream>
#include <climits>
#include "utils.h"

using namespace std;

/**
 * Returns the biggest pair of indexes (i, j) such that arr[i] - arr[j] is even in O(n^2) time
 */
pair<int, int> maxPairD(int arr[], int n)
{
  int max = INT_MIN;
  pair<int, int> resp = make_pair(-1, -1);

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      int d = arr[i] - arr[j];
      if (d > max && d % 2 == 0)
      {
        max = d;
        resp = make_pair(i, j);
      }
    }
  }

  return resp;
}

/**
 * Returns the biggest pair of indexes (i, j) such that arr[i] - arr[j] is even in O(n) time
 */
pair<int, int> maxPairDOn(int arr[], int n)
{
  int maxEven = -1;
  int maxOdd = -1;
  int minEven = -1;
  int minOdd = -1;

  for (int i = 0; i < n; i++)
  {
    if (arr[i] % 2 == 0)
    {
      if (maxEven == -1 || arr[i] > arr[maxEven])
      {
        maxEven = i;
      }
      if (minEven == -1 || arr[i] < arr[minEven])
      {
        minEven = i;
      }
    }
    else
    {
      if (maxOdd == -1 || arr[i] > arr[maxOdd])
      {
        maxOdd = i;
      }
      if (minOdd == -1 || arr[i] < arr[minOdd])
      {
        minOdd = i;
      }
    }
  }

  int even = arr[maxEven] - arr[minEven];
  int odd = arr[maxOdd] - arr[minOdd];

  if (even >= odd && maxEven != -1 && minEven != -1)
  {
    return make_pair(maxEven, minEven);
  }
  if (odd > even && maxOdd != -1 && minOdd != -1)
  {
    return make_pair(maxOdd, minOdd);
  }

  return make_pair(-1, -1);
}

int main()
{
  for (int i = 0; i < 10000000; i++)
  {
    const int s = rand() % 100;
    int *v = randomArray(s);
    cout << "Vetor Original: " << join(s, v) << endl;

    pair<int, int>
        resp1 = maxPairD(v, s);
    // cout << "Max Pair D O(n^2) -> i: " << resp1.first << " | j: " << resp1.second << endl;

    pair<int, int> resp2 = maxPairDOn(v, s);
    // cout << "Max Pair D O(n) -> i: " << resp2.first << " | j: " << resp2.second << endl;

    if (resp1 != resp2 && v[resp1.first] - v[resp2.second] != v[resp1.first] - v[resp2.second])
    {
      cout << "Vetor Original: " << join(s, v) << endl;
      cout << "Max Pair D O(n^2) -> i: " << resp1.first << " | j: " << resp1.second << " d = " << v[resp1.first] - v[resp2.second] << endl;
      cout << "Max Pair D O(n) -> i: " << resp2.first << " | j: " << resp2.second << " d = " << v[resp1.first] - v[resp2.second] << endl;
      break;
    }
  }

  return 0;
}
