#include <iostream>

#include "hash_table.hpp"

int main() {
  HashTable hash_table(2);
  hash_table.Add("a", 4);
  hash_table.Add("b", 1);
  hash_table.Add("c", 6);
  int val = hash_table.Get("b");
  std::cout << val << "\n";
  HashTable h(-2);
  return 0;
}
