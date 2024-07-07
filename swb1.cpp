#include <iostream>
#include <vector>
using namespace std;

int calculatePhones(int S, int K, int B, int D, int P, int T) {
    int a[5]{S, K, B*15, D*2, P}; int z;
    int max = a[0];
    for (int i = 0; i < 5; ++i) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    if(T >= max){
        z = (720 - max) / T;
        cout << 2;
    }
    else{
        z = 720 / max;
        cout << 1;
        if((720 - z*max) < T){
            z = z - 1;
        }
    }
    return z;
}

int main() {
    int S, K, B, D, P, T;
    cin >> S >> K >> B >> D >> P >> T;
    cout << calculatePhones(S, K, B, D, P, T);
    return 0;
}
