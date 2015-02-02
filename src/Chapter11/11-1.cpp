/**
 * @Name        : 11-1.cpp
 * @Author      : Krunal Chande
 * @Created     : Jan 30, 2015
 * @Description :     
 */

/*
 * Problem: Design an algorithm that takes a set of files containing
 * stock trades by increasing trade times and writes a single sorted file.
 * Use very little RAM.
 */

#include <iostream>
#include <queue>
#include "../../CppUnitLite/TestHarness.h"

using namespace std;

struct Compare {
  bool operator() (const pair<int, int>& lhs, const pair<int, int>& rhs) {
    return lhs.first > rhs.first;
  }
};

vector<int> MergeArrays(const vector < vector<int> >& S) {
  priority_queue< pair<int, int>, vector< pair<int, int> >, Compare > min_heap;
  cout << "S.size(): " << S.size() << endl;
  vector <int> S_idx(S.size(), 0);

  for (int i = 0; i < S.size(); ++i) {
    if (S[i].size() > 0) {
      min_heap.emplace(S[i][0], i);
      S_idx[i] = 1;
    }
  }

  vector<int> ret;
  while (!min_heap.empty()) {
    pair <int, int> p = min_heap.top();
    ret.emplace_back(p.first);
    // add the smallest element into the heap if possible
    if(S_idx[p.second] < S[p.second].size()) {
      min_heap.emplace(S[p.second][S_idx[p.second]++], p.second);
    }
    min_heap.pop();
  }
  return ret;
}

void printMatrix(const vector<vector<int>> grid) {
  for ( std::vector<std::vector<int>>::size_type i = 0; i < grid.size(); i++ )
  {
    for ( std::vector<int>::size_type j = 0; j < grid[i].size(); j++ )
    {
      std::cout << grid[i][j] << ' ';
    }
    std::cout << std::endl;
  }
}

TEST(heap, sortMultidimensionalArray) {
  int rows = 5;
  int cols = 2;
  vector < vector<int> > matrix(rows, vector<int>(cols, 0));
  for (int i = rows-1; i >=0 ; --i) {
    for (int j = cols-1; j >= 0; --j) {
      matrix[rows-i-1][cols-j-1] = i*rows + j;
    }
  }
  printMatrix(matrix);
  vector<int> solution = MergeArrays(matrix);
  cout << "Solution size: " << solution.size() << endl;
  for (int i = 0; i < solution.size(); i++){
    cout << solution.at(i) << endl;
  }
  vector<int> expected(matrix.size(), 0);
  expected.push_back(1);
  expected.push_back(6);
  expected.push_back(11);
  expected.push_back(16);
  expected.push_back(21);
  CHECK(expected == solution);
}

int main(int argc, char** argv) {
  TestResult tr;
  return TestRegistry::runAllTests(tr);
}


