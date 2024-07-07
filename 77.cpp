#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
int findMaxPairSum(const std::string& fileName) {
    std::ifstream f(fileName);
    int n, k, m; f >> n ; int c = 0;
    std::vector<int> num(n);
    for (int i = 0; i < n; ++i) {f >> num[i];}
    sort(num.begin(), num.end());

    for(int i=0; i < n;i++){
                if(num[i] % 2 == 0){
                    c++;
                } else{k++;}
            }
    if(num[-1] % 2 == 0) {
            m = c;
            }
    else{m = k;}
        
    return m;
    }
int main() {
    int rA = findMaxPairSum("17-257.txt");
    std::cout << rA << " " << std::endl;
    return 0;
}
