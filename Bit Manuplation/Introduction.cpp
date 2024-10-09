#include <bits/stdc++.h>
using namespace std;

vector<int> convertToBinary(int x){
    vector<int> res;
    while(x >= 1){
        if(x%2 == 0) res.push_back(0);
        else res.push_back(1);
        x /= 2;
    }
    return res;
}

int convertToDecimal(vector<int> p){
    int res = 0;
    for(int i=p.size()-1; i>=0; i--){
        if(p[i] == 1) res += pow(2, i);
        else res += 0;
    }
    return res;
}

void swapNumber(int &a, int &b){
    //using bitmanuplation
    a = a^b;
    b = a^b;
    a = a^b;
    return;
}

int findithBit(int n, int x){
    return (n >> x)&1;
}

void setIthBit(int &n, int x){
    int i = 1;
    i <<= x;
    n = n|i;
    return;
}

void clearIthBit(int &n, int x){
    int i = 1; i <<= x;
    n = n&(~i);
}

//Right Shift formule
// x >> k; (k is a integer) formulae : x = x/2^k
// x << k; (left shift) formulae: x = x*2^k
// ~x -> {
// ¤ flip the value. 
// ¤ if(x is negative) find 2's compliment of 1st step }
//

int main() {
    int n = 5, k = 2;
    clearIthBit(n, k);
    cout << n; 
}