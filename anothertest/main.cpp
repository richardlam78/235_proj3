#include "calculator.h"

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using std::setprecision;
using std::string;
using std::stod;
using std::ifstream;
using std::cout;
using std::cin;
using std::cerr;
using std::endl;


// ( 3*3 + (12 - 6)^2 + (15 - 8) ^ 2 ) ^ (1 / 2)

int main(int argc, const char* argv[])
{
  Calculator myCalc;
  string input;
  string result;

  cout << "program start" << endl;

  if (argc > 2) {
    // too many arguments, terminate program
    cout << "Usage: command [filename or expression]" << endl;
    return 1;
  }
  else if (argc == 2) {
    // extra argument, assume is filename and attempt to open
    input = argv[1];
    ifstream infile(input.c_str());
    if (!infile) {
      cerr << "File not found" << endl;
    }

    cout << "file found and opened" << endl;
    string line;
    while (getline(infile, line)) {
      // give input lines to calculator class and output results
      cout << "*********************************************************\n";
      cout << line << endl;
      result = myCalc(line, 2);
      // cout << setprecision(2)
      cout << "\t*************************************************\n"
           << "\t*RESULT: " << result << " = " << line << endl
           << "\t*************************************************\n"
           << endl << endl;
      myCalc.clear();
    }
  }
  else if (argc == 1) {
    // no extra arguments, get input from input stream
    cout << "Enter infix expression: ";
    cin >> input;

    // give input line to calculator class
    result = myCalc(input, 2);
    cout << result << " = " << input
         << endl;
  }

  return 0;
}
