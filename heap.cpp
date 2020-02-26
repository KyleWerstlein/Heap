#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

int main() {
  char input[100]; // hold manual input
  char* input2 = new char[8]; // input for file or type
  char input3[1000]; // hold numbers from file
  const char strcmp1[5] = "file"; // strcmp file
  const char strcmp2[5] = "type"; // strcmp type
  bool choice = false; // loop to get user to pick file or type
  bool choice2 = false; // false = type, true = file
  while(!choice) {
    cout << "Type \"file\" to read from file." << endl;
    cout << "Type \"type\" to input numbers by hand." << endl;
    cout << "Type \"generate\" to generate a text file with 1000 random numbers" << endl;
    cin.getline(input2, 9);
    //const char input3[5] = {input2}; // for some reason strcmp() only takes const chars now. I was able to use a regular char in previous projects.
    if(strcmp(input2, "file") == 0) {
      choice2 = true;
      choice = true;
    }
    if(strcmp(input2, "type") == 0) {
      choice = true;
    }
    if(strcmp(input2, "generate") == 0) {
      cout << "1";
    }
  }
  if(choice2) { // read from file
    ofstream inputfile;
    inputfile.open("input.txt");
  }
  else if(!choice2) { // read from keyboard
    
  }
  else {
    cout << "how did you get here?" << endl;
  }
  
  return 0;
}
