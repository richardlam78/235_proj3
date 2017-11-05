#include <iostream>
#include <sstream>
#include <string>
using std::string;
using std::istringstream;
using std::cout;
using std::endl;

void refineInput(string& input)
{
  int i = 0;
  while(i < input.size()) {
    while (isdigit(input[i]) || input[i] == '.' || input[i] == ' ') {
      ++i;
    }

    input = input.substr(0,i) + ' ' + input[i] + ' ' + input.substr(i+1);
    i += 2;
    cout << input << endl;

  }
}

// stringstreams best for converting individual strings to numbers
int main()
{
  string text = "(3.4+4)";
  cout << text << endl;
  refineInput(text);
  // text = text.substr(0,2) + " " + text.substr(2);
  cout << text << endl;
  /*
  istringstream s_in(text);

  int input;
  while (s_in >> input) {
      cout << "Found element: " << input << endl;
  }
  */


  return 0;
}
