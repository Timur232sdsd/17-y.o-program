#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    int a[16];
    a[0] = 0;
    a[1] = 1;

    for (int i = 2; i <= 15; ++i) {
        if( i  <=3) a[i] = a[i-1];
        if(i - 3 > 0){
        a[i] = a[i - 1] + a[i - 3];
        if(i % 2 == 0 ) a[i] = a[i]+ a[i/2];}
    }

    std::cout << a[15] << std::endl;
}
