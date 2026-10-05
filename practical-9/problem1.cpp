#include <iostream>
using namespace std;

int adj[10][10];
int visited[10];
int n;

void dfs(int start) {
    cout << start << " ";
    visited[start] = 1;
    
    for (int i = 0; i < n; i++) {
        if (adj[start][i] == 1 && (!visited[i])) {
            dfs(i);
        }
    }
}

int main() {
    n = 5;
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }
    
    // Creating edges
    adj[0][1] = 1; adj[1][0] = 1;
    adj[0][2] = 1; adj[2][0] = 1;
    adj[1][3] = 1; adj[3][1] = 1;
    adj[2][4] = 1; adj[4][2] = 1;
    
    cout << "DFS Traversal starting from 0: ";
    dfs(0);
    cout << endl;
    
    return 0;
}