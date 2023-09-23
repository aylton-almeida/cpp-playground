#include <iostream>
#include <climits>

#include "utils.h"

using namespace std;

pair<int, int> minMaxRec(int arr[], int firstIdx, int lastIdx)
{
  if (firstIdx == lastIdx)
  {
    return make_pair(arr[firstIdx], arr[firstIdx]);
  }

  if (firstIdx == lastIdx - 1)
  {
    return make_pair(min(arr[firstIdx], arr[lastIdx]), max(arr[firstIdx], arr[lastIdx]));
  }

  int midIdx = (firstIdx + lastIdx) / 2;
  pair<int, int> left = minMaxRec(arr, firstIdx, midIdx);
  pair<int, int> right = minMaxRec(arr, midIdx + 1, lastIdx);
  cout << "Comparing: " << pairToString(left) << " with " << pairToString(right) << endl;
  return make_pair(min(left.first, right.first), max(left.second, right.second));
}

int main()
{
  int s = 5;
  int *arr = randomArray(s);

  cout << "Current Array: " << join(s, arr) << endl;

  pair<int, int> response = minMaxRec(arr, 0, s - 1);
  cout << "Min: " << response.first << " | Max: " << response.second << endl;

  return 0;
}
