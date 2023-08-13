// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

void reverse(string& str, int i, int j){
    if(i>j){
        return;
    }
    swap(str[i], str[j]);
    return reverse(str, i+1, j-1);
}

int main() {
    string str1 = "ayush";
    reverse(str1, 0, str1.length() - 1);
    cout << str1 << endl;
    return 0;
}