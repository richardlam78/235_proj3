#include "calculator.h"

#include <cctype>
#include <cmath>
using std::pow;
using std::substr;
using std::isdigit;
using std::stod;
using std::istringstream;


void Calculator::refineInput(string& input)
{
  int i = 0;
  while(i < input.size()) {
    while (isdigit(input[i]) || input[i] == '.' || input[i] == ' ') {
      ++i;
    }

    // put in spaces around char's that are not numbers
    input = input.substr(0,i) + ' ' + input[i] + ' ' + input.substr(i+1);
    i += 2;
  }
}



double Calculator::evaluate(const string& elem1,
                            const string& op,
                            const string& elem2)
{
  // assume there are only three things that come in
  // first operand, the operator, and the second operand
  double x1 = stod(elem1);
  double x2 = stod(elem2);
  double result;

  switch (op) {
    case "+":
      result = x1 + x2;
      break;
    case "-":
      result = x1 - x2;
      break;
    case "*":
      result = x1 * x2;
      break;
    case "/":
      result = x1 / x2;
      break;
    case "^":
      result = pow(x1,x2);
      break;
    default:
      // replace this with exception
      result = 0.0;
      break;
  }

  return result;
}

double operator()(string& input)
{
  double result;
  refineInput(input);
  istringstream iss(input);

  // insert values into the stacks
  string elem;
  while (iss >> elem && elem != ")") {
    left.push(elem);
  }

  while (iss >> elem) {
    right.push(elem);
  }

  // evaluate the innermost () group
  string x2 = left.top();
  left.pop();
  string op = left.top();
  left.pop();
  string x1 = left.top();
  left.pop();
  result = evaluate(x1, op, x2);

  while (!left.empty() && !right.empty()) {
    // evaluate expression in parentheses starting
    while (left.top() != "(" && !left.empty()) {
      op = left.top();
      left.pop();
      x1 = left.top();
      left.pop();
      result = evaluate(x1, op, result);
    }

    while (right.top() != ")" && !right.empty()) {
      op = right.top();
      right.pop();
      x2 = right.top();
      right.pop();
      result = evaluate(right, op, x2);
    }

    // remove the () to work on values in the next () group
    left.pop();
    right.pop();
  }

  return result;
}
