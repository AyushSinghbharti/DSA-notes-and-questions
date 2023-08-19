//Letter Combinations of a Phone Number question (give all combination of a letters when digit is inputed)
//if input = 23
//Output will be = ["ad","ae","af","bd","be","bf","cd","ce","cf"]

#include <iostream>
#include <vector>
using namespace std;


void solve(string digit, string output, int index, string mapping[], vector<string>& ans){
    if(index >= digit.length()){
        ans.push_back(output);
        return;
    }
    int number = digit[index] - '0';
    string value = mapping[number];
    
    for(int i=0; i<value.length(); i++){
        output.push_back(value[i]);
        solve(digit, output, index+1, mapping, ans);
        output.pop_back();
        }
    }

    
vector<string> letterCombinations(string digits) {
    vector<string> ans;
    if(digits.length()==0)
        return ans;
    string output;
    int index = 0;
    string mapping[10]={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    solve(digits, output, index, mapping, ans);
    return ans;
    }

int main(){
    string str;
    cout << "Enter Value between 0-9 in pair eg: 23, 36, 93 etc....: ";
    cin >> str;
    vector<string> ans;
    ans = letterCombinations(str);
    
    for (int i=0; i<ans.size(); i++) {
        cout << ans[i] << " ";
    }
    
    return 0;
}