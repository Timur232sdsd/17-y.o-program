#include <iostream>
#include <cmath>
using namespace std;

void square_bsearch(double a) {
    double epsilon = 0.01;
    double low = 0.0;
    double high = a;
    double guess = (low + high) / 2.0;

    while (abs(pow(guess, 2) - a) >= epsilon) {
        if (pow(guess, 2) < a) {
            low = guess;
        }
        else {
            high = guess;
        }
        guess = (high + low) / 2.0;
    }
    cout << guess << endl;
}

int main() {
    square_bsearch(20);
    return 0;