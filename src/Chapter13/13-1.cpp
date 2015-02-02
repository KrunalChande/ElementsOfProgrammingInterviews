/**
 * @Name        : 13-1.cpp
 * @Author      : Krunal Chande
 * @Created     : Feb 2, 2015
 * @Description :     
 */

/**
 * Write a function to take a set of words and and print groups of anagrams
 */
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

void findAnagrams(const vector<string>& dictionary) {
  unordered_map<string, vector<string> > hash;
  for (const string& s : dictionary) {
    string sorted_str(s);
    sort(sorted_str.begin(), sorted_str.end());
    hash[sorted_str].emplace_back(s);
  }

  for (const pair< string, vector<string> >& p : hash) {
    if (p.second.size() >= 2) {
      for (const auto& s : p.second) {
        cout << s << " ";
      }
      cout << endl;
    }
  }
}

int main() {
  vector<string> dictionary;
  dictionary.emplace_back("abcd");
  dictionary.emplace_back("cdab");
  dictionary.emplace_back("abcde");
  dictionary.emplace_back("abcdf");
  dictionary.emplace_back("abecd");
  findAnagrams(dictionary);
}
