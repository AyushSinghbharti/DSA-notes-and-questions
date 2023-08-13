// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int findPower(int value, int power){
    if(power == 0)
        return 1;
    if(power == 1)
        return value;
    
    int ans = findPower(value, power/2);
    
    if(power%2==0)
        return ans*ans;
    else
        return value*ans*ans;
}

int main() {
    int value;
    int power;
    cin >> value >> power;
    int ans = findPower(value, power);
    cout << ans;
    return 0;
}