/**
 * @Name        : 17-2.cpp
 * @Author      : Krunal Chande
 * @Created     : Feb 1, 2015
 * @Description :     
 */

// Find a path from A(0, 0) to B(X2, Y2) given that you can only go down and right

#include <iostream>

using namespace std;

int numberOfWays(int n, int m) {
  if (n < m) {
    swap(n,m);
  }
  vector< vector<int> > A(2, vector<int>(m,1));
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      A[i & 1][j] = (i < 1 ? 0 : A[(i - 1) & 1][j]) +
                    (j < 1 ? 0 : A[i & 1][j - 1]);
    }
  }
  return A[(n-1) & 1][m-1];
}


