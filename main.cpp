#include <iostream>
#include <fstream>

#include "Calculator.h"

using namespace std;

double Min(double, double);
void InfoLogToConsole(string);
void InfoLogToFile(string);

int main() {

    int x = 5;
    int y = 10;

    Calculator* calculator = new Calculator(x, y, InfoLogToFile);
    auto res = calculator->Add();

    res = Min(x, y);

    auto res2 = calculator->Operation(Min);

    return 0;
}

double Min(double x, double y) {
    return x > y ? y : x;
}

void InfoLogToConsole(string message) {
    cout << "[INFO] " << message << endl;
}

void InfoLogToFile(string message) {
    ofstream file;
    file.open("journal.log", ios_base::app);
    file << "[INFO] " << message << endl;
    file.close();
}