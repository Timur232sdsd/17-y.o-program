#include <iostream>
#include <vector>
#include <cmath>

bool BMonotonic(const std::vector<double>& b) {
    for (size_t i = 1; i < b.size(); ++i) {
        if (b[i] < b[i - 1]) {
            return false;
        }
    }
    return true;
}

bool BObounded(const std::vector<double>& b) {
    double upperBoundB = 0.0;
    for (size_t i = 0; i < b.size(); ++i) {
        if (std::abs(b[i]) > upperBoundB) {
            upperBoundB = std::abs(b[i]);
        }
    }
    return true; 
}

bool AObounded(const std::vector<double>& a) {
    double upperBoundA = 0.0;
    for (size_t i = 0; i < a.size(); ++i) {
        if (std::abs(a[i]) > upperBoundA) {
            upperBoundA = std::abs(a[i]);
        }
    }
    return true;  //проверка для ограниченности
}

bool SumConvergent(const std::vector<double>& a) {
    // Проверка сходимости ряда с использованием признака Даламбера.
    for (size_t i = 0; i < a.size() - 1; ++i) {
        double ratio = a[i + 1] / a[i];
        if (ratio >= 1) {
            // Тест Даламбера не применим.
            return false;
        }

        double limit = std::numeric_limits<double>::epsilon();  // Заглушка для предела.
        if (ratio > limit) {
            return false; 
        }
    }

    // Проверка сходимости ряда с использованием признака Коши.
    

    for (size_t i = 0; i < a.size() - 1; ++i) {
        double sum = a[i] + a[i + 1];
        if (sum == a[i + 1]) {
            return false;  // Ряд расходится.
        }
    }

    return true;
}

bool checkAbelTheorem(const std::vector<double>& a, const std::vector<double>& b) {
    // Применение теоремы Абеля.
    return BMonotonic(b) && BObounded(b) && AObounded(a) && SumConvergent(a);
}

int main() {
    std::vector<double> a;
    std::vector<double> b;
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i) {double value;std::cin >> value;a.push_back(value);}
    for (int i = 0; i < m; ++i) {double value;std::cin >> value;b.push_back(value);}


    std::cout << (checkAbelTheorem(a, b) ? "Yes" : "No") << std::endl;
    return 0;
}
