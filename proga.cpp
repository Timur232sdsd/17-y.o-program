#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <set>
using namespace std;

int main(){
    vector<int> nums {1,2,3,4};
    set<int> st;
    for(int i=0; i<nums.size(); ++i){
        st.insert(nums[i]);
    }
    cout << 1 ? (st.size()==nums.size()):0;

}
