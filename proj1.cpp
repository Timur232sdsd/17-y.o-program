#include <iostream>
using namespace std;
int f(int n, int m){
    if ((m*m+m)/2 >= n - 1){return m;}
    return f(n, m+1);
}
int main() {
  int n, m=0; cin >> n; cout << f(n, m);
  return 0;
}