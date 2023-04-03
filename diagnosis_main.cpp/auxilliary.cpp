#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int prompti(char prompt[]) {
  int value;
PROMPT:
  cout << prompt << endl;
  try {
    cin >> value;
    cout << endl;
  } catch (std::exception e) {
    cout << "Error. Wrong input" << endl;
    cout << e.what() << endl;
    goto PROMPT;
  }

  return value;
}

int prompti(string prompt) {
  int value;
PROMPT:
  cout << prompt << endl;
  try {
    cin >> value;
    cout << endl;
  } catch (std::exception e) {
    cout << "Error. Wrong input" << endl;
    cout << e.what() << endl;
    goto PROMPT;
  }

  return value;
}

string prompts(char prompt[]) {
  string value;
PROMPT:
  cout << prompt << endl;
  try {
    cin >> value;
    cout << endl;
  } catch (std::exception e) {
    cout << "Error. Wrong input" << endl;
    cout << e.what() << endl;
    goto PROMPT;
  }

  return value;
}

string prompts(string prompt) {
  string value;
PROMPT:
  cout << prompt << endl;
  try {
    cin >> value;
    cout << endl;
  } catch (std::exception e) {
    cout << "Error. Wrong input" << endl;
    cout << e.what() << endl;
    goto PROMPT;
  }

  return value;
}
