#include "calculator.h"

#include <iostream>
#include <fstream>
#include <string>
using std::string;
using std:ifstream;
using std::cout;
using std::setprecision;
using std::cerr;
using std::endl;

int main(unsigned int argc, const char* argv[])
{
  Calculator myCalc;
  string input;
  double result;

  if (argc > 2) {
    // too many arguments, terminate program
    cout << "Usage: command [filename or expression]" << endl;
    return 1;
  }
  else if (argc == 2) {
    // extra argument, assume is filename and attempt to open
    input = argv[1];
    ifstream infile(input.c_str());
    string line;

    while (getline(infile, line)) {
      // give input lines to calculator class and output results
      result = myCalc(line);
      cout << setprecision(2)
           << result << " = " << line
           << endl;
    }
  }
  else if (argc == 1) {
    // no extra arguments, get input from input stream
    cout << "Enter infix expression: ";
    cin >> input;

    // give input line to calculator class
    result = myCalc(line);
    cout << result << " = " << line
         << endl;
  }

  return 0;
}
