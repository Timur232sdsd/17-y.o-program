#include <iostream>
#include <cmath>
#include <vector>

void abelRuffiniTheorem(const std::vector<double>& coefficients) {
    int n = coefficients.size() - 1;  // Степень многочлена.
    if (n < 1) {
        std::cout << "const" << std::endl;
        return;
    }
    double delta = 0.0;
    for (int i = 0; i <= n; ++i) {
        delta += coefficients[i] * coefficients[i];
    }

    // Проверка условия теоремы Абеля-Руффини.
    if (delta == 0) {
        std::cout << "The condition of the Abel-Ruffini theorem is satisfied. The polynomial has a solution in radicals." << std::endl;
    } else {
        std::cout << "The condition of the Abel-Ruffini theorem is not satisfied. A polynomial does not necessarily have a solution in radicals." << std::endl;
    }
}

int main() {
    // Введите коэффициенты многочлена.
    std::cout << "Enter polynomial coefficients (starting with the coefficient at a higher degree): " << std::endl;
    
    int degree;
    std::cout << "degree of polynomial: ";
    std::cin >> degree;

    std::vector<double> coefficients(degree + 1);

    for (int i = degree; i >= 0; --i) {
        std::cout << "Coefficient of x^" << i << ": ";
        std::cin >> coefficients[i];
    }

    // Применение теоремы Абеля-Руффини.
    abelRuffiniTheorem(coefficients);

    return 0;
}
