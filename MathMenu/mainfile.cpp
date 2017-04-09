/*
 * File:   mainfile.cpp
 * Author: noah
 *
 * Created on April 8, 2017, 11:57 AM
 * Part of project: MathMenu
 */

#include <iostream>
#include <string>
#include <cmath>

/**
 * Calculates a number to the power of itself.
 * num is the number to raise num to.
 */
int calculateANum(int num) {
    int localnum = pow(num, num);
    return localnum;
}

/*
 *
 */
int main(int argc, char** argv) {
    using namespace std;
    cout << "Initialization" << std::endl;

    while (true) {
        std::cout << "Choices:\n0. Exit\n1.Power\n2.Square root\n3.Square" << std::endl;
        int choice;
        cin >> choice;
        if (choice == 0) {
            return 0;
        } else if (choice == 1) {
            cout << "Please enter a number, and power." << std::endl;
            int num, power;
            cin >> num;
            cin >> power;
            std::cout << pow(num, power) << std::endl;
        } else if (choice == 2) {
            cout << "Please enter a number." << std::endl;
            int num;
            cin >> num;
            std::cout << sqrt(num) << std::endl;
        } else if (choice == 3) {
            cout << "Please enter a number." << std::endl;
            int num;
            cin >> num;
            std::cout << pow(num, 2) << std::endl;
            cout << "By the way, the number you just entered to itself is:" << calculateANum(num) << endl;
            //todo this is a test.

        }
    }

    return 0;
}

