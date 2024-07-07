//найти кол-во k цепочек состоящих из n нулей и единиц в которых нет двух стоящий подряд единиц

//в цистерне n литров молока есть бидоны обьемом 1 5 и 6 литров нужно разлить молоко так, чтобы все бидоны были заполнены и кол-во используемых биоднов было минимальным

//k(N) = 1 + min(k n-1, k n -5, k n - 6) if n >= 6
//k(N) = 1 + min(k n-1, k n -5) n = 5
//k(n) = 1 + k n-1 n <= 5
#include <iostream>
#include <vector>
using namespace std;

int fib(int n) {
    if (n <= 2) {return 1;}
    else {return fib(n - 1) + fib(n - 2);}
}
int main() {
  int n; cin >> n; cout << fib(n);
  return 0;
}