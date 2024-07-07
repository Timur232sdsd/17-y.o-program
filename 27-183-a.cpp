#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
int main() {
    std::ifstream fileA("27-183b.txt");
    int N, k, a=0;
    fileA >> N >> k;
    std::vector<int> hA(N);
    for (int i = 0; i < N; ++i) {
        fileA >> hA[i];
    }
    for(int i=0; i<N-k; i++){
        for(int j=i+k; j<N; j++){
            int c = *max_element(hA.begin()+i, hA.begin()+j);
            a = std::max(a,hA[i]+hA[j]+c);
        }
    }
    std::cout  << a << std::endl;

    return 0;
}
