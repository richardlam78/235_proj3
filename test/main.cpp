#include <iostream>
#include <sstream>
#include <string>
using std::string;
using std::istringstream;
using std::cout;
using std::endl;

void refineInput(string& input)
{
  // string input = expression;
  int i = 0;
  while(i < input.size() - 1) {
    while (isdigit(input[i]) || input[i] == '.' || input[i] == ' ') {
      ++i;
    }

    input = input.substr(0,i) + ' ' + input[i] + ' ' + input.substr(i+1);
    i += 2;
  }
  input = "(" + input + ")";
  // return input;
}

// stringstreams best for converting individual strings to numbers
int main()
{
  string text = "(3.4+4)";
  cout << "raw text: " << text << endl;
  refineInput(text);
  cout << "new text: " << text << endl;
  /*
  istringstream s_in(text);

  int input;
  while (s_in >> input) {
      cout << "Found element: " << input << endl;
  }
  */


  return 0;
}
