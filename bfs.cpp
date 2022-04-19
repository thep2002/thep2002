#include <stdio.h>
#include <iostream>
#include <queue>     //C++
using namespace std; //C++
#define MAX 100
#define oo 1000 // Vô cùng
int n = 6;      // Số đỉnh
int G[MAX][MAX] = {
    //   S  A  B  C  D  E
    {0, 1, 0, 1, 1, 1}, //S
    {1, 0, 1, 0, 0, 0}, //A
    {0, 1, 0, 1, 0, 0}, //B
    {1, 0, 1, 0, 0, 0}, //C
    {1, 0, 0, 0, 0, 1}, //D
    {1, 0, 0, 0, 1, 0}  //E
};

int dist[MAX];
int truoc[MAX]; //truoc[u] = v  <-> đỉnh trước của đỉnh u trong đường đi là v

void bfs(int s)
{
    queue<int> Q; // Hàng đợi mỗi phần tử có kiểu int  : C++

    for (int u = 0; u < n; u++)
        dist[u] = oo;

    truoc[s] = -1; // Đỉnh s không có đỉnh trước vì bắt đầu từ s
    dist[s] = 0;
    Q.push(s);

    while (Q.empty() != true)
    {
        int u = Q.front();
        Q.pop(); // loại bỏ u khỏi hàng đợi
        for (int v = 0; v < n; v++)
            if (G[u][v] == 1) // Có cạnh (u,v) trong E
            {
                if (dist[v] == oo)
                {
                    Q.push(v);    // đưa v vào hàng đợi
                    truoc[v] = u; // đỉnh trước của đỉnh v là đỉnh u
                    dist[v] = dist[u] + 1;
                }
            }
    }
}

// Q.push(u)  cho đỉnh u vào hàng đợi  = inject(Q,v)
// Q.pop()  loại bỏ đỉnh ở đầu hàng đợi
// z= Q.front() lấy đỉnh ở đầu hàng đợi gán vào z

// Tìm đường ngắn nhất từ s tới u
void findPath(int s, int u)
{
    bfs(s);
    while (u != s)
    {
        cout << u << "<-";
        u = truoc[u];
    }
    cout << s << endl;
}


int main(int argc, char const *argv[])
{
   findPath(0, 2);

    return 0;
}
