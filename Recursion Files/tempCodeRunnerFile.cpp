#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<vector<int>> test1;
    int count;

    test1.push_back(5, 6, 7, 9);
    cout << "size of 0 " << sizeof(test1[0]) << endl;
    cout << "Numbers of element " << test1.size() << endl;
    cout << "size of all " << sizeof(test1) << endl;
    for(int i=0; i<test1.size(); i++){
        count += sizeof(test1[i]);
        cout << "Size of individual " << i << " " << int(sizeof(test1[i])) << " " << count << endl;
    }
    return 0;
}
