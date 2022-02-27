#include <iostream>
#include <fstream>
#include <string>//to create string variables
#include "directories.h"

using namespace std;

int main()
{
    //Local Variables
    std::string header;
    std::string phone;
    std::string name;
    std::string email;
    std::string input_file_name;
    std::string output_file_name;

    //user input file name to be read.
    cout << "Please enter the file name and extension "
            "you would like to read from.\n";
    cin >> input_file_name;


    //open file to read
    ifstream file_name("../../" + input_file_name);

    //if file doesn't exist
    if (file_name.fail())
    {
        cout << "Unable to locate the file. Closing program.\n";

        return 1;
    }

    //user input file name to be created.
    cout << "Please enter the name and extension for new formatted file.\n";
    cin >> output_file_name;

    //writing to new file
    ofstream directory ("../../" + output_file_name);

    //Print header
    getline(file_name, header);
    directory << header << endl;

    //While loop to check and set the text starting with the phone number
    while (file_name >> phone)
    {
        //set name and email from document
        file_name.ignore();
        getline(file_name, name);
        file_name >> email;

        //functions to check and fix the strings
        phone = FixPhoneNumber(phone);
        name = FixName(name);
        email = FixEmail(email);

        //function to write line to the document
        WriteFormatted(phone, name, email, directory);
    }

    //closing the file
    file_name.close();

    return 0;
}