#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <stack>
#include <sstream>
#include <string>
using std::string;
using std::stack;

class Calculator
{
public:
  Calculator();
  Calculator(const string& input) { this.operator(input); }
  ~Calculator();

  void refineInput(string&);

  // takes a string of numbers and operators
  // returns a partial result
  double evaluate(const string&, const string&, const string&);

  // takes string of numbers and operators and splits to left and right stacks
  // returns the final result
  double operator()(string&);

private:
  stack<string> left;
  stack<string> right;
}
