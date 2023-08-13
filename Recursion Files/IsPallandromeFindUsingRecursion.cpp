#include <iostream>
using namespace std;

string pallandrome(string& name, int i, int j){
    if(i>j)
        return "Is Pallandrome";
    else if(name[i] == name[j])
        return pallandrome(name, i+1, j-1);
    return "Is not pallandrome";
}

int main() {
    string name;
    cin >> name;
    cout << pallandrome(name, 0, name.length()-1) << endl;
    return 0;
}