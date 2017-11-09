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
  Calculator() { input = ""; };
  ~Calculator();

  // adds spaces between operands and operators to allow easier reading with
  // string stream later
  void refineInput(string&);

  // takes a string of numbers and operators
  // returns a partial result
  string evaluate(const double&, const string&, const double&);

  // clears input and stack
  void clear();

  // takes string of numbers and operators and splits to left and right stacks
  // returns the final result
  string operator()(string&, unsigned int);

private:
  string input;
  stack<string> expression;

};

#endif
