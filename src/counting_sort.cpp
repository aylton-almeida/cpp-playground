#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include "utils.h"

using namespace std;

/**
 * Given an array of size n with values in the range 1 to k, sort it in O(n + k) time
 */
int *countingSort(int arr[], int n, int k)
{
  vector<int> count(k + 1, 0);

  for (int i = 0; i < n; i++)
  {
    count[arr[i]] += 1;
  }

  vector<int> result;
  for (int i = 1; i <= k; i++)
  {
    result.insert(result.end(), count[i], i);
  }

  return result.data();
}

using namespace std;

void merge(int first[], int second[], int n)
{
  vector<int> result;
  int i = 0;
  int j = 0;

  while (i < n && j < n)
  {
    if (first[i] < second[j])
    {
      result.push_back(first[i]);
      i++;
    }
    else
    {
      result.push_back(second[j]);
      j++;
    }
  }

  result.insert(result.end(), first + 1, first + n);
  result.insert(result.end(), second + 1, second + n);
}

int main()
{
  int x[2];
  cout << x[0] << endl;

  const int s = 7;
  int *v = randomArray(s);
  cout << "Vetor Original: " << join(s, v) << endl;

  int *resp = countingSort(v, s, 100);
  cout << "Vetor Ordenado: " << join(s, resp) << endl;

  return 0;
}
