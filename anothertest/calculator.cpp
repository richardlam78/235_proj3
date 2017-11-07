#include "calculator.h"

#include <cctype>
#include <string>
#include <cmath>
using std::pow;
using std::string;
using std::isdigit;
using std::istringstream;
using std::ostringstream;


#include <iostream>
using std::cout;
using std::endl;

void Calculator::refineInput(string& line)
{
  input = line;
  unsigned int i = 0;
  while(i < input.size()) {
    if (isdigit(input[i]) || input[i] == '.' || input[i] == ' ') {
      ++i;
      continue;
    }

    // put in spaces around char's that are not numbers
    input = input.substr(0,i) + ' ' + input[i] + ' ' + input.substr(i+1);
    i += 2;
  }

  input = "( " + input + " )";
}



string Calculator::evaluate(const double& x1,
                            const string& op,
                            const double& x2)
{
  // assume there are only three things that come in
  // first operand, the operator, and the second operand
  char op_char = op[0];      // WATCH: not sure if this will work
  double result = 0.0;

  switch (op_char) {
    case '+':
      result = x1 + x2;
      break;
    case '-':
      result = x1 - x2;
      break;
    case '*':
      result = x1 * x2;
      break;
    case '/':
      result = x1 / x2;
      break;
    case '^':
      result = pow(x1,x2);
      break;
    default:
      // replace this with exception
      result = 0.0;
      break;
  }

  ostringstream oss;
  oss << result;
  return oss.str();
}


void Calculator::clear() {
  input = "";
  while (expression.size() > 0) {
    expression.pop();
  }
}


string Calculator::operator()(string& line, unsigned int precision)
{
  input = line;
  string result;
  refineInput(input);
  cout << "refined: " << input << endl;

  istringstream iss(input);

  string next_elem;
  while (iss >> next_elem) {
    // push everything before a closing () into the stack
    if (next_elem != ")") {
      cout << "pushed in " << next_elem << " " << endl;;
      expression.push(next_elem);
    }

    // works forward on ^, *, and /
    if (expression.top() == "^" || expression.top() == "*" || expression.top() == "/") {
      iss >> next_elem;
      if (next_elem == "(") {
        cout << "pushed in (" << endl;
        expression.push(next_elem);
        continue;
      } else {
        expression.push(next_elem);

        double x2 = stod(expression.top());
        expression.pop();

        string op = expression.top();
        expression.pop();

        double x1 = stod(expression.top());
        expression.pop();

        result = evaluate(x1, op, x2);
        cout << "fwd quantity result: "
             << x1 << op << x2 << "="
             << result << endl;
        expression.push(result);
        continue;
      }
    }
    // hit a closing ()
    // works backward
    else if (next_elem == ")") {
      cout << "found a )." << endl;
      do {
        result = expression.top();
        expression.pop();

        if (expression.empty()) {
          return result;
          // break;
        }

        cout << expression.top() << endl;
        if (expression.top() == "(") {
          cout << "broke out" << endl;
          expression.pop();
          expression.push(result);
          break;
        }

        double x2 = stod(result);

        string op = expression.top();
        expression.pop();

        double x1 = stod(expression.top());
        expression.pop();

        result = evaluate(x1, op, x2);
        cout << "bwd quantity result: "
             << x1 << op << x2 << "="
             << result << endl;

        if (expression.empty()) {
          cout << "stack is empty" << endl;
          break;
        }

        if (expression.top() == "(") {
          expression.pop();
        }

        if (expression.top() == "^" || expression.top() == "*" || expression.top() == "/") {
          cout << "pushed in " << result << endl;
          expression.push(result);
          continue;
        } else {
          cout << "pushed in " << result << endl;
          expression.push(result);
          break;
        }




        /*
        // if case where there is ^, *, or /, then a ()
        if (expression.top() == "^" || expression.top() == "*" ||
            expression.top() == "/"){
          expression.push(result);
          continue;
        }
        */
      } while (expression.size() != 1);  // keep evaluating, until returns
    }
  } // close the iss while

  for (unsigned int i = 0; i < result.size(); ++i) {
    if (result[i] == '.') {
      result = result.substr(0, i + precision + 1);
      break;
    }
  }
  return result;
}
