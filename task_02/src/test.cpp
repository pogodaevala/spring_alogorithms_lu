
#include <gtest/gtest.h>

#include <vector>

#include "stack.hpp"

TEST(StackTest, Simple) {
  Stack<int> stack{};
  stack.Push(1);              // Stack [1]
  ASSERT_EQ(stack.Pop(), 1);  // Stack []
  stack.Push(1);              // Stack [1]
  stack.Push(2);              // Stack [1, 2]
  ASSERT_EQ(stack.Pop(), 2);  // Stack [1]
  ASSERT_EQ(stack.Pop(), 1);  // Stack []
  stack.Push(1);              // Stack [1]
  stack.Push(2);              // Stack [1, 2]
  ASSERT_EQ(stack.Pop(), 2);  // Stack [1]
  stack.Push(3);              // Stack [1, 3]
  ASSERT_EQ(stack.Pop(), 3);  // Stack [1]
  ASSERT_EQ(stack.Pop(), 1);  // Stack []
}

TEST(MinStackTest, Simple) {
  MinStack<int> stack{};
  stack.Push(1);  // Stack [1]
  ASSERT_EQ(stack.GetMin(), 1);
  ASSERT_EQ(stack.Pop(), 1);  // Stack []
  stack.Push(1);              // Stack [1]
  stack.Push(2);              // Stack [1, 2]
  ASSERT_EQ(stack.GetMin(), 1);
  ASSERT_EQ(stack.Pop(), 2);  // Stack [1]
  ASSERT_EQ(stack.Pop(), 1);  // Stack []
  stack.Push(1);              // Stack [1]
  stack.Push(2);              // Stack [1, 2]
  ASSERT_EQ(stack.GetMin(), 1);
  ASSERT_EQ(stack.Pop(), 2);  // Stack [1]
  stack.Push(3);              // Stack [1, 3]
  ASSERT_EQ(stack.GetMin(), 1);
  ASSERT_EQ(stack.Pop(), 3);  // Stack [1]
  ASSERT_EQ(stack.Pop(), 1);  // Stack []
}

TEST(PopErrorTest, PopErrorTest) {
  MinStack<int> minstack{};
  ASSERT_THROW(minstack.Pop(), PopError);
  Stack<int> stack{};
  stack.Push(2);
  stack.Pop();
  ASSERT_THROW(stack.Pop(), PopError);
}

TEST(MinStackTest, Double) {
  MinStack<double> minstack{};
  minstack.Push(3.3);
  ASSERT_EQ(minstack.GetMin(), 3.3);
  minstack.Push(-0.7);
  minstack.Push(4.8);
  ASSERT_EQ(minstack.GetMin(), -0.7);
  ASSERT_EQ(minstack.Pop(), 4.8);
  ASSERT_EQ(minstack.GetMin(), -0.7);
  ASSERT_EQ(minstack.Pop(), -0.7);
  ASSERT_EQ(minstack.GetMin(), 3.3);
}

TEST(MinStackTest, String) {  // сравнивает алфавитно
  MinStack<std::string> minstack{};
  minstack.Push("bb");
  minstack.Push("r");
  ASSERT_EQ(minstack.GetMin(), "bb");
  minstack.Push("aaat");
  ASSERT_EQ(minstack.GetMin(), "aaat");
  ASSERT_EQ(minstack.Pop(), "aaat");
  ASSERT_EQ(minstack.GetMin(), "bb");
  ASSERT_EQ(minstack.Pop(), "r");
  ASSERT_EQ(minstack.Pop(), "bb");
}

TEST(MinStackTest, Vector) {  // поэлементно
  MinStack<std::vector<int>> minstack{};
  std::vector<int> a{3, 2};
  minstack.Push(a);
  std::vector<int> b{5};
  minstack.Push(b);
  ASSERT_EQ(minstack.GetMin(), a);
  std::vector<int> c{-4, 8, 9};
  minstack.Push(c);
  ASSERT_EQ(minstack.GetMin(), c);
  ASSERT_EQ(minstack.Pop(), c);
  ASSERT_EQ(minstack.GetMin(), a);
  ASSERT_EQ(minstack.Pop(), b);
  ASSERT_EQ(minstack.Pop(), a);
}