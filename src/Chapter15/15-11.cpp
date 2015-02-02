/**
 * @Name        : 15-11.cpp
 * @Author      : Krunal Chande
 * @Created     : Feb 2, 2015
 * @Description :     
 */

/**
 * Given a sorted doubly linked list, create a BST.
 * Constraints: Use O(n) time and O(logn) memory
 *            : You cannot use dynamic memory allocation
 */

#include <iostream>
#include <memory>
#include <list>


using namespace std;

shared_ptr< list<int> > BuildBSTFromDLL(shared_ptr<list<int> > L, int n) {
  return BuildBSTFromDLLHelper(&L, 0, n);
}

shared_ptr< list<int> > BuildBSTFromDLLHelper(shared_ptr<list<int>>* L, int s, int e) {
  if (s >= e) {
    return nullptr;
  }

  int m = s + ((e-s)/2);
  auto temp_left = BuildBSTFromDLLHelper(L, s, m);
  auto curr = *L;
  *L = (*L) -> ;
}

