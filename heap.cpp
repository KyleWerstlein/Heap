//Kyle Werstlein
//2/28/20
//Heap project. Includes funtionality to generate a text file of 100 random numbers from 1 - 1000
#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>

int char2int(char character);
void sort(int* numbers, int size);

using namespace std;

int main() {
    char input[5]; // hold manual input
    for (int i = 0; i < 5; i++) {
        input[i] = '?';
    }
    char* input2 = new char[8]; // input for file or type
    // char* input3 = new char[100]; // hold numbers for heap
    //int* intinput = new int[4];
    int intinput2[4];
    int* intarray = new int[100]; // hold numbers after casted from char to int
    int randomnumbers[100];
    int numbers = 0;
    for (int i = 0; i < 100; i++) {
        // input3[i] = '?';
    }
    const char strcmp1[5] = "file"; // strcmp file
    const char strcmp2[5] = "type"; // strcmp type
    bool choice = false; // loop to get user to pick file or type
    bool choice2 = false; // false = type, true = file
    cout << "If this is your first time using this program, type \"generate\" before reading from file." << endl;
    while (!choice) {
        cout << "Type \"file\" to read from file." << endl;
        cout << "Type \"type\" to input numbers by hand." << endl;
        cout << "Type \"generate\" to generate a text file with 1000 random numbers" << endl;
        cin.getline(input2, 9);
        if (strcmp(input2, "file") == 0) {
            choice2 = true;
            choice = true;
        }
        if (strcmp(input2, "type") == 0) {
            choice = true;
        }
        if (strcmp(input2, "generate") == 0) {
            int random = 0;
            for (int i = 0; i < 100; i++) { // 100 numbers
                random = rand() % 1000 + 1; // from 1 - 1000
                randomnumbers[i] = random;
            }
            ofstream randomfile;
            randomfile.open("generated.txt");
            for (int i = 0; i < 100; i++) {
                randomfile << randomnumbers[i] << "\n";
            }
            randomfile.close();
            cout << "generated \"generated.txt\"" << endl;
        }
    }
    if (choice2) { // read from file
        ifstream inputfile;
        int count = 0;
        int x;
        inputfile.open("generated.txt");
        if (inputfile.is_open()) {
            //while(getline(inputfile,
            while (inputfile >> x) {
                intarray[count++] = x;
                numbers++;
            }
            inputfile.close();
            sort(intarray, numbers);
        }
        else {
            cout << "Cannot open file." << endl;
        }
    }
    else if (!choice2) { // read from keyboard
        
        int newnumber = 0;
        int numbercount = 0;
        bool done = false;
        cout << "Input a number and press enter. When you're done type \"done\"" << endl;
        while (!done) {
            newnumber = 0;
            for (int i = 0; i < 4; i++) {
                intinput2[i] = NULL;
            }
            cin.getline(input, 5);
            if (strcmp(input, "done") == 0) {
                done = true;
            }
            if (input[0] > 47 && input[0] < 58) {
                numbercount = 0;
                for (int i = 0; i < 4; i++) {
                    if (input[i] > 47 && input[i] < 58) {
                        numbercount++;
                        intinput2[i] = char2int(input[i]);
                    }
                }
                int size = numbercount;
                int temp = (int)input[0];
                if (size == 4) {
                    newnumber += 1000; //any 4 digit number will go into the heap as 1000 since this is the max
                }
                else if (size == 3) { // probably an easier way to do this that I'm not thinking about
                    newnumber += (100 * intinput2[0]);
                    newnumber += (10 * intinput2[1]);
                    newnumber += intinput2[2];
                }
                else if (size == 2) {
                    newnumber += (10 * intinput2[0]);
                    newnumber += intinput2[1];
                }
                else if (size == 1) {
                    newnumber += intinput2[0];
                }
                else {
                    cout << "invalid input." << endl;
                }
                if (!(int*)newnumber > 1000 || (int*)newnumber > 0) { // if in range
                    intarray[numbers] = newnumber;
                    numbers++;
                }
                else {
                    cout << "number is not in range!" << endl;
                    
                }
            }
        }
        sort(intarray, numbers);
    }
    else {
        cout << "how did you get here?" << endl;
    }

    return 0;
}

int char2int(char character) { // convert ascii value to regular int
    int output = 0;
    if (character < 58 && character > 47) {
        output = character - 48;
        return output;
    }
}

void sort(int* numbers, int size) {
    int highest = numbers[0];
    int highestIndex = 0;
    int sortedNumbers[100];
    int linecount = 0;
    int index = 0;
    int tmpcount = 1;
    ofstream output;
    ofstream output2;
    output.open("sorted.txt");
    for (int i = 0; i < size; i++) { // sort from largest to smallest
        highest = 0;
        for (int i = 0; i < size; i++) {
            if (numbers[i] > highest) {
                highest = numbers[i];
                highestIndex = i;
            }
        }
        numbers[highestIndex] = 0;
        sortedNumbers[i] = highest;
        output << sortedNumbers[i] << "\n";
    }
    output.close();
    output2.open("tree.txt"); // build tree.
    output2 << "\t\t  " << sortedNumbers[0] << "\n\t\t  |\n"; // not sure if this is how heap is suppose to be represented, links them together, child smaller than parent.
    for (int i = 1; i < size/4 + 1; i++) {
        for (int j = index; j < index + 4; j++) {
            while (tmpcount < size) { // keep them in blocks of 4. walking through array normally lead to the first number being put in the tree twice.
                if (linecount == 4) {
                    linecount = 0;
                    output2 << "\n";
                    output2 << "\t|\t|\t|\t|\n";
                }
                else {
                    output2 << "\t" << sortedNumbers[tmpcount];
                    sortedNumbers[tmpcount] = 0;
                    linecount++;
                    tmpcount++;
                }
                index += 4;
            }
        }
    }
}