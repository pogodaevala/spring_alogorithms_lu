#include <iostream>
#include <vector>

#include "stack.hpp"

class NotTotallyOrdered {
  int data;
};

int main() {
  try {
    MinStack<int> stack{};
    stack.Pop();
  } catch (PopError s) {
    std::cout << s.str << "\n";
  }
}
