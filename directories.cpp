#include <iostream>
#include <string>
#include <iomanip> //to help format directory.txt

using namespace std;

//Phone number check function
std::string FixPhoneNumber(std::string phone)
{
    //deletes '('
    if (phone.find("(") != std::string::npos)
    {
        phone.erase(phone.begin());
    }

    //checks for '.' and ')' or '-'
    if (phone.find(".")!= std::string::npos
        && (phone.find(")") != std::string::npos
            || phone.find("-") != std::string::npos))
    {
        //Nested if statement to replace ')' or '-' with a period
        //checks if phone number has 12 phone digits
        if (phone.length() > 8)
        {
            phone.replace(3, 1, ".");
            phone.replace(7, 1, ".");
        }
            //if phone number only has 7 phone digits
        else
        {
            phone.replace(3, 1, ".");
        }
        return phone;
    }

    //return phone string to main if its the correct format
    else if (phone.find(".")!= std::string::npos)
    {
        return phone;
    }

    //checks when there is no periods in the phone number
    if (phone.find(")") != std::string::npos
        || phone.find("-") != std::string::npos)
    {

        //checks if phone number has 12 phone digits
        if (phone.length() > 8) {
            phone.replace(3, 1, ".");
            phone.replace(7, 1, ".");
        }
            //if phone number only has 7 phone digits
        else
        {
            phone.replace(3, 1, ".");
        }

        //return once edits are made
        return phone;
    }

    //checks phone length so it can insert periods
    //if phone number is 10 digits
    if (phone.length() > 8)
    {
        phone.insert(3, ".");
        phone.insert(7, ".");
    }
    //if phone number is 7 digits
    else
    {
        phone.insert(3, ".");
    }

    //return once edits are made
    return phone;
}

//Name check function
std::string FixName(std::string name)
{
    int position = name.find(",");

    if (position!= std::string::npos)
    {
        //get lastname
        string last_name = name.substr(0, position);

        //erase the last name in name string
        name.erase(0,position + 2);

        //combine name and lastName strings with a space in the middle.
        name += " " + last_name;
    }
    return name;
}

//email check function
std::string FixEmail(std::string email)
{
    //If there is no email domain, insert weber mail address.
    if (email.find("@") == std::string::npos)
    {
        std::string weber_mail = "@mail.weber.edu";
        email += weber_mail;
    }

    //If email is incomplete, insert '.com'
    else if (email.find("@") != std::string::npos
            && email.find(".com") == std::string::npos)
    {
        std::string dot_com = ".com";
        email += dot_com;
    }

    return email;
}

void WriteFormatted(std::string phone, std::string name, std::string email,
                    std::ostream& out)
{

    string name_length;
    if (name.length() > 19)
    {
        name_length = name.substr(0,16) + "...";
    }
    else
    {
        name_length = name;
    }

    //Writes line to directory.txt
    out << right << setw(16) << phone << "  "
        << left << setw(19) << name_length << "  "
        << left << email << endl;
}