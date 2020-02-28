//Kyle Werstlein
//2/28/20
//Heap project. Includes funtionality to generate a text file of 100 random numbers from 1 - 1000
#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>

using namespace std;

int main() {
  char* input = new char[5]; // hold manual input
  char* input2 = new char[8]; // input for file or type
  // char* input3 = new char[100]; // hold numbers for heap
  int* intinput = new int[5];
  int* intarray = new int[100]; // hold numbers after casted from char to int
  int randomnumbers[100];
  for(int i = 0; i < 100; i++) {
    // input3[i] = '?';
  }
  const char strcmp1[5] = "file"; // strcmp file
  const char strcmp2[5] = "type"; // strcmp type
  bool choice = false; // loop to get user to pick file or type
  bool choice2 = false; // false = type, true = file
  cout << "If this is your first time using this program, type \"generate\" before reading from file." << endl;
  while(!choice) {
    cout << "Type \"file\" to read from file." << endl;
    cout << "Type \"type\" to input numbers by hand." << endl;
    cout << "Type \"generate\" to generate a text file with 1000 random numbers" << endl;
    cin.getline(input2, 9);
    if(strcmp(input2, "file") == 0) {
      choice2 = true;
      choice = true;
    }
    if(strcmp(input2, "type") == 0) {
      choice = true;
    }
    if(strcmp(input2, "generate") == 0) {
      int random = 0;
      for(int i = 0; i < 100; i++) { // 100 numbers
	random = rand() % 1000 + 1; // from 1 - 1000
	randomnumbers[i] = random;
      }
      ofstream randomfile;
      randomfile.open("generated.txt");
      for(int i = 0; i < 100; i++) {
	randomfile << randomnumbers[i] << "\n";
      }
      randomfile.close();
      cout << "generated \"generated.txt\"" << endl;
    }
  }
  if(choice2) { // read from file
    ofstream inputfile;
    inputfile.open("generated.txt");
    if(inputfile.is_open()) {
      // while(getline(inputfile
    }
    else {
      cout << "Cannot open file." << endl;
    }
  }
  else if(!choice2) { // read from keyboard
    // FIX READING FROM KEYBOARD. CAN ONLY TAKE NUMBERS 1 - 9 ATM.
    int numbers = 0;
    bool done = false;
    cout << "Input a number and press enter. When you're done type \"done\"" << endl;
    while(!done && intinput[99] == 0) {
      cin.getline(input, 5);
      if(strcmp(input, "done") == 0){
	done = true;
      }
      if(!(int*)input > 1000 || !(int*)input < 1) { // if in range
	//input3[numbers] = *input;
	intarray[numbers] = (int)*input;
	numbers++;
	for(int i = 0; i < numbers; i++) {
	  cout << intarray[i] << endl;
	}
      }
      else {
	cout << "number is not in range!" << endl;
      }
    }
  }
  else {
    cout << "how did you get here?" << endl;
  }
  
  return 0;
}
