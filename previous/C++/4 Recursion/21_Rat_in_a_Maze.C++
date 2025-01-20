// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isSafe(int x, int y, int n, vector<vector<int>> m, vector<vector<int>> &visited){
    if((x >= 0 && x < n) && (y >= 0 && y < n) && m[x][y] == 1 && visited[x][y] == 0){
        return true;
    }else{
        return false;
    }
}

void  solveMaze(vector<vector<int>> m, int n , int x, int y, vector<string>& ans,  vector<vector<int>> &visited, string path){
    if(x == n-1 && y == n-1){
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;

    // Down
    int newX = x + 1;
    int newY = y;
    if(isSafe(newX, newY, n, m, visited)){
        path.push_back('D');
        solveMaze(m, n , newX, newY, ans, visited, path);
        path.pop_back();
    }

    // Right
    newX = x;
    newY = y + 1;
    if(isSafe(newX, newY, n, m, visited)){
        path.push_back('R');
        solveMaze(m, n , newX, newY, ans, visited, path);
        path.pop_back();
    }

    // Left
    newX = x;
    newY = y - 1;
    if(isSafe(newX, newY, n, m, visited)){
        path.push_back('L');
        solveMaze(m, n , newX, newY, ans, visited, path);
        path.pop_back();
    }

    // Up
    newX = x-1;
    newY = y;
    if(isSafe(newX, newY, n, m, visited)){
        path.push_back('U');
        solveMaze(m, n , newX, newY, ans, visited, path);
        path.pop_back();
    }

    visited[x][y] = 0;
}

int main()
{
    int n = 4;
    // Created a Maze
    vector<vector<int>> m = {{1, 0, 0, 0},
                             {1, 1, 0, 1},
                             {1, 1, 0, 0},
                             {0, 1, 1, 1}};

    int x = 0;
    int y = 0;

    if (m[0][0] == 0)
    {
        cout << "Not able to enter in maze" << endl;
    }
    else
    {

    // Create visited position marking maze
    vector<vector<int>> visited = m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
                visited[i][j] = 0;
        }
    }

    // Store coice D, U, L, R
    string path = "";

    // Store answer in vector
    vector<string> ans;
    solveMaze(m, n , x, y, ans, visited, path);
    sort(ans.begin(), ans.end());

    // Print Answer
    for (int i = 0; i < n; i++)
    {   
        cout << ans[i] << " ";
    }
    }
}