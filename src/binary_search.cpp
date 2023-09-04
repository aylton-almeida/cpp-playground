#include <iostream>
#include <ctime>
#include <cstdlib>

#include "utils.h"

using namespace std;

int binarySearch(int value, int first, int last, int *v)
{
  int middle = (last + first) / 2;

  cout << "Current first: " << first << " -> middle: " << middle << " -> last: " << last << endl;

  if (first > last)
  {
    return -1;
  }

  if (v[middle] == value)
  {
    return middle;
  }

  if (v[middle] > value)
  {
    return binarySearch(value, first, middle - 1, v);
  }
  else
  {
    return binarySearch(value, middle + 1, last, v);
  }
}

int main()
{
  const int s = 10;
  int v[s] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int value = 3;

  cout << "Current array: {" << join(s, v) << "}" << endl;
  int resp = binarySearch(value, 0, s - 1, v);

  cout << "Value found on index: " << resp << endl;

  return 0;
}
