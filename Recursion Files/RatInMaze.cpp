#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isSafe(int x, int y, int n, vector<vector<int>> visted, vector<vector<int>> m){
    if((x>=0 && x<n) && (y>=0 && y<n) && visted[x][y] == 0 && m[x][y] == 1)
        return true;
    return false;
}

void solve(vector<vector<int>>& m, int n, vector<string>& ans, int x, int y, vector<vector<int>> visited, string path){
    //Base Case
    if(x==n-1 && y==n-1){
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;
    // Choice DLRU
    //Down
    int newX = x+1;
    int newY = y;
    if(isSafe(newX, newY, n, visited, m)){
        path.push_back('D');
        solve(m,n,ans,newX,newY,visited,path);
        path.pop_back();
    }

    //Left
    newX = x;
    newY = y-1;
    if(isSafe(newX, newY, n, visited, m)){
        path.push_back('L');
        solve(m,n,ans,newX,newY,visited,path);
        path.pop_back();
    }

    //UP
    newX = x-1;
    newY = y;
    if(isSafe(newX, newY, n, visited, m)){
        path.push_back('U');
        solve(m,n,ans,newX,newY,visited,path);
        path.pop_back();
    }

    //Right
    newX = x;
    newY = y+1;
    if(isSafe(newX, newY, n, visited, m)){
        path.push_back('R');
        solve(m,n,ans,newX,newY,visited,path);
        path.pop_back();
    }
    
    visited[x][y] = 0;
}

vector<string> findPath(vector<vector<int>>& m, int n){
    vector<string> ans;

    if(m[0][0] == 0)
        return ans;

    int srcx = 0;
    int srcy = 0;

    vector<vector<int>> visited = m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            visited[i][j] = 0;
        }
    }
    string path = "";
    solve(m,n,ans,srcx,srcy,visited,path);
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    vector<vector<int>> pathMatrix = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 1, 0},
        {0, 1, 1, 1}
    };

    vector<string> ans = findPath(pathMatrix, pathMatrix.size());
    cout << pathMatrix.size() << " ";
    cout << ans.size() << "\n";
    for(int i=0; i<ans.size(); i++)
        cout << ans[i] << "\n";
    return 0;
}
