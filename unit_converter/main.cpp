#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
//Created by Matthew Punzone | 1/10/2023 | Version 1.0

//welcome message and menu functions
void welcome_message(){
    std::cout << "Units to meters converter..." << std::endl;
    std::cout << "Convert to meters from cm, in, and ft" << std::endl;
}
void menu(){
    std::cout << "\nPlease enter a number followed by a unit (cm, in, ft):" << std::endl;
}

int main(){
//all variables used for the program
double num1 {0.0};
double smallest {};
double largest {};
bool first_entry = true;
bool valid_unit = true;
double cm_to_meter {100};
double in_to_cm {2.54};
double foot_to_in {12};
std::string unit {};
std::vector<double>vec {};


welcome_message();
menu();

while (std::cin >> num1 >> unit){ //terminates when | is entered
    if (unit == "cm"){
        num1 = num1/cm_to_meter;
        valid_unit = true;
        unit = "m";
    }
    else if (unit == "in"){
        num1 = (num1*in_to_cm)/cm_to_meter;
        valid_unit = true;
        unit = "m";
    }
    else if (unit == "ft"){
        num1 = (num1*foot_to_in)*(in_to_cm)/cm_to_meter;
        valid_unit = true;
        unit = "m";
    }
    
    else{
        valid_unit = false;
        std::cout << "invalid unit" << std::endl;
    }
    
    if (valid_unit == true){
        if (num1 < smallest || first_entry){
            smallest = num1;
            if (valid_unit == true){
            std::cout << "\n" << smallest << unit << " is the smallest so far" << std::endl;
            first_entry = false;
          }}
        if (num1 > largest || first_entry){
            largest = num1;
                if (valid_unit == true){
                    std::cout << "\n" << largest << unit << " is the largest so far" << std::endl;
                    first_entry = false;
             }}
        else if (num1 > smallest || num1 < largest){
            std::cout << num1 << unit << std::endl;
        }
        else {
            std::cout << "Invalid unit" << std::endl;
    }
    
}
if (valid_unit ==true){
    vec.push_back(num1);
    std::sort(vec.begin(), vec.end());
        std::cout << "\n" << "[ ";
        for (auto nums: vec){
            std::cout << nums << unit << " ";
        }
        std::cout << "]" << std::endl;
}
std::cout << "\nEnter another measurement and unit or terminate using the | character" << std::endl;

}
    return 0;
}