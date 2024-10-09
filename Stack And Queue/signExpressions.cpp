#include <bits/stdc++.h>
using namespace std;

// Infix expression A-B eg: (A+B)*(C+D)/E
// Postfix expression AB- eg: AB+CD+E/*
// PreFix expression -AB

int priority(char c){
    if(c == '+' || c == '-') return 1;
    else if(c == '*' || c == '/') return 2;
    else if(c == '^') return 2;
    else return 0;
}

string reverseString(string s){
    int i=0, j = s.size()-1;
    while(i <= j){
        swap(s[i], s[j]);
        i++; j--;
    }
    return s;
}

string InfixToPostfix(string s){
    stack<char> st; string ans; int i=0; int n = s.size();

    while(i < n){
        if(s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z') ans = ans + s[i];
        else if(s[i] == '(') st.push(s[i]);
        else if(s[i] == ')'){
            while(!st.empty() && st.top() != '('){
                ans = ans + st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && priority(st.top()) > priority(s[i])){
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }
    while(!st.empty()){
        ans = ans + st.top();
        st.pop();
    }
    return ans;
}

string InfixToPrefix(string s){
    reverse(s.begin(), s.end());
    
    for (char& c : s) {
        if (c == '(') {
            c = ')';
        } else if (c == ')') {
            c = '(';
        }
    }

    s = InfixToPostfix(s);
    reverse(s.begin(), s.end());
    return s;
}

string PostfixToInfix(string s){
    stack<string> st;
    for(char c: s){
        if(isalpha(c)){
            st.push(string(1, c));
        }
        else{
            string t1 = st.top(); st.pop(); 
            string t2 = st.top(); st.pop();
            st.push('(' + t2 + c + t1 + ')');
        }
    }
    
    return st.top();
}

string PrefixToInfix(string s){
    stack<string> st;

    for(int i=s.size()-1; i>=0; i--){
        if(isalpha(s[i])){
            st.push(string(1, s[i]));
        }
        else{
            string t1 = st.top(); st.pop();
            string t2 = st.top(); st.pop();
            st.push('(' + t1 + s[i] + t2 + ')');
        }
    }

    return st.top();
}

string PostfixToPrefix(string s){
    stack<string> st;
    for(auto c: s){
        if(isalpha(c)){
            st.push(string(1, c));
        }
        else{
            string s1 = st.top(); st.pop();
            string s2 = st.top(); st.pop();
            st.push(c + s2 + s1);
        }
    }
    return st.top();
}

string PrefixToPostfix(string s){
    stack<string> st;
    for(int i = s.size()-1; i>=0; i--){
        if(isalpha(s[i])){
            st.push(string(1, s[i]));
        }else{
            string s1 = st.top(); st.pop();
            string s2 = st.top(); st.pop();
            st.push(s1 + s2 + s[i]);
        }
    }
    return st.top();
}

int main(){
    string s;
    cin >> s;
    cout << PrefixToPostfix(s) << endl;
    return 0;
}