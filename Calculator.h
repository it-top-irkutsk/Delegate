#ifndef DELEGATE_CALCULATOR_H
#define DELEGATE_CALCULATOR_H

using namespace std;

class Calculator {
private:
    double x;
    double y;
    void (*info)(string message);

public:
    Calculator(double x, double y, void (*info)(string)) : x(x), y(y), info(info) {}

    Calculator(double x, double y) : x(x), y(y) {}

    double Operation(double (*operation)(double, double)) {
        auto res = operation(x, y);
        info(to_string(x) + " operation " + to_string(y) + " = " + to_string(res));
        return res;
    }

    double Add() {
        auto res = x + y;
        info(to_string(x) + " + " + to_string(y) + " = " + to_string(res));
        return res;
    }

    double Sub() {
        auto res = x - y;
        info(to_string(x) + " - " + to_string(y) + " = " + to_string(res));
        return res;
    }

    double Mul() {
        auto res = x * y;
        info(to_string(x) + " * " + to_string(y) + " = " + to_string(res));
        return res;
    }

    double Del() {
        if (y == 0) {
            info("ERROR! Divided by zero!");
            return 0;
        } else {
            auto res = x / y;
            info(to_string(x) + " / " + to_string(y) + " = " + to_string(res));
            return res;
        }

        // return (y == 0) ? 0 : (x / y);
    }
};

#endif //DELEGATE_CALCULATOR_H
