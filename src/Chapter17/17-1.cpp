/**
 * @Name        : 17-1.cpp
 * @Author      : Krunal Chande
 * @Created     : Jan 31, 2015
 * @Description :     
 */

// Given an array w and a number 's', find all coeffs x s.t.
// x_1*w_1 + x_2*w_2 ... = s

#include <iostream>
#include <vector>

using namespace std;

int count_combinations(int k, const vector<int>& score_ways) {
  vector <int> combinations(k+1, 0);
  combinations[0] = 1;
  for (const int& score : score_ways) {
    cout << "score: " << score << endl;
    for (int j = score; j <= k; ++j) {
      cout << " combinations["<<j<<"] =" << " combinations["<<j<<"] " << "+" << " combinations["<<j-score << "] " << endl;
      cout << " combinations["<<j<<"]"  << " = " << combinations[j] << "+" << combinations[j-score] << endl;
      combinations[j] = combinations[j] + combinations[j-score];
    }
  }
  return combinations[k];
}

int count_permutations(int k, const vector<int> score_ways) {
  vector<int> permutations(k+1,0);
  permutations[0] = 1;

  for (int i = 0; i <= k; ++i) {
    for (const int& score : score_ways) {
      cout << "i: "<< i << " score: " << score << endl;
      if (i >= score) {
        cout << " permutations["<<i<<"] =" << " permutations["<<i<<"] " << "+" << " permutations["<<i-score << "] " << endl;
        cout << " permutations["<<i<<"]"  << " = " << permutations[i] << "+" << permutations[i-score] << endl;
        permutations[i] += permutations[i-score];
      }
    }
  }
  return permutations[k];
}

int main() {
  vector<int> w;
  w.emplace_back(2);
  w.emplace_back(3);
//  w.emplace_back(4);

  for (int i = 0; i < w.size(); ++i)
    cout << w[i] << endl;

  int comb = count_combinations(6, w);
  cout << "count_combinations: " <<  comb << endl;
  cout << "count_permutations: " << count_permutations(6, w) << endl;

}
