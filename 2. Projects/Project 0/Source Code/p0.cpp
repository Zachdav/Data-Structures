//Zachary Davis (811-960-668)
//Jacob Ambrose ()

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char * argv[]) {
	//Since this program writes to an output file this statement removes an old one if the user hasn't.
        if (remove("output.txt") != -1) {
                cout << ("The existing output.txt file has been removed for the next one to be created.") << endl;
        }//if

	//Checks that the utility is being used correctly including one text file as the argument.
        if (argc != 2) {
                cout << ("This program will only accept one argument and that should represent the file you\n")
                     << ("wish to input.")
                     << endl;
                return EXIT_FAILURE;
        }//if
        
	//Opens the file with a string to temporarily hold a line and a int to hold the number of lines
        ifstream file(argv[1]);
        string temp = ("");

	//Moves the "cursor" to the end of the given file to count all the chars in the file.
	//According the assumed format of the txt files the number of lines will always equal
	//the ceiling of the total chars/2 since we need to account for the '\n'.
	int lines = 0;	
	while (getline(file, temp)) {
		lines++;
	}//while
        file.clear();
	file.seekg(0, ios::beg);

	//Creating a dynamically allocated array with a size of number of lines in the file and
	//storing all the numbers into it
        string * input = new string[lines];
        for (int i = 0; getline(file, temp); i++) {
                input[i] = temp;
        }//for

	//Creating a bool array of equal length and populating all indices to true.
	bool * unique = new bool[lines];
        for (int i = 0; i < lines; i++) {
                unique[i] = true;
        }//for
        
	//Closing the file and creating an int for the adjusted array size.
        file.close();
        int arrayLength = 0;

	//Algorithm that will count the number of unique numbers in the array as well as
	//setting the corresponding bool array to false of every repeating appearence of a
	//number.
        for (int i = 0; i < lines; i++) {
                for (int j = (i + 1); j < lines; j++) {
                        if (input[i] == input[j]) {
                                unique[j] = false;
                        }//if
                }//for
        }//for

	//Opening an output stream to the file "output.txt" and writing the altered
	//array in reverse order.
        ofstream output("output.txt");
        for (int i = (lines - 1); i >= 0; i--) {
                if (unique[i]) {
                        output << input[i] << endl;
                        arrayLength++;
                }//if
        }//for
	output.close();

	//Telling the user the output arrays length which is == to number of unique
	//numbers inputted.
        cout << ("Array size: ")
             << arrayLength
             << endl;

	//Deleting dynamically allocated arrays to avoid those annoying memory leaks.
        delete[] input;
        delete[] unique;
        return EXIT_SUCCESS;
}//main
