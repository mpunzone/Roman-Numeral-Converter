//Created by: Matthew Punzone 
//Date publish: 1/26/2023
//Version: 1

#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cctype>


int main(){

//set variables for roman numeral to number conversions
const int one = 1;
const int five = 5;
const int ten = 10;
const int fifty = 50;
const int hundred = 100;
const int fivehundred = 500;
const int thousand = 1000;
std::string user_entry {""};


//prompt user for roman numerals to convert
std::cout << "Enter roman numerals to convert to numbers" << std::endl;
std::cin >> user_entry;

//convert user entry into all uppercase (if they gave lowercase)
for (size_t i{0}; i < user_entry.size(); ++i){
    user_entry.at(i) = std::toupper(user_entry.at(i));
}

//iterate through the users entry and convert letters to proper numbers
int temp {0};
for (size_t i{0}; i < user_entry.size(); ++i){
    switch(user_entry[i]){
    case 'I':
        if (user_entry[i+1] == 'V'){
            temp += (five - one);
            ++i;
        }
        else if (user_entry[i+1] == 'X'){
            temp += (ten - one);
            ++i;
        }
        else
            temp += one;
        break;
    case 'V':
        temp += five;
        break;
    case 'X':
        if (user_entry[i+1] == 'L'){
            temp += (fifty - ten);
            ++i;
        }
        else if (user_entry[i+1] == 'C'){
            temp += (hundred - ten);
            ++i;
        }
        else
            temp += ten;
        break;
    case 'L':
        temp += fifty;
        break;
    case 'C':
        if (user_entry[i+1] == 'D'){
            temp += (fivehundred - hundred);
            ++i;
        }
        else if (user_entry[i+1] == 'M'){
            temp += (thousand - hundred);
            ++i;
        }
        else
            temp += hundred;
        break;
    case 'D':
        temp += 500;
        break;
    case 'M':
        temp += 1000;
        break;
    default:
        std::cout << "Enter a valid Roman Numeral please." << std::endl;
        break;
    }

}

//temp is the completed answer
std::cout << temp;


return 0;
}