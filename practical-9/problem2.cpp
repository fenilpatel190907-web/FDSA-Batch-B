#include <iostream>
using namespace std;

int adj[10][10];
int visited[10];
int n;
int q[100];
int front = -1, rear = -1;

void enqueue(int val) {
    if (front == -1) front = 0;
    rear++;
    q[rear] = val;
}

int dequeue() {
    int val = q[front];
    front++;
    if (front > rear) front = rear = -1;
    return val;
}

int isEmpty() {
    if (front == -1 || front > rear) return 1;
    return 0;
}

void bfs(int start) {
    enqueue(start);
    visited[start] = 1;
    
    while (!isEmpty()) {
        int current = dequeue();
        cout << current << " ";
        
        for (int i = 0; i < n; i++) {
            if (adj[current][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
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
    
    cout << "BFS Traversal starting from 0: ";
    bfs(0);
    cout << endl;
    
    return 0;
}