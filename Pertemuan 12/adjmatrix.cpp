#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int v = 21;
string arr[100];
vector< vector <int> > adj;

void addEdge(int x, int y)
{
    adj[x][y] = 1;
}

void bfs(int start)
{
   
    vector<bool> visited(adj.size(), false);
    vector<int> q;
    q.push_back(start);

    visited[start] = true;
    int vis;
    while (!q.empty())
    {
        vis = q[0];

        cout << arr[vis] << " -> ";
        q.erase(q.begin());

        for (int i = 1; i < adj[vis].size(); i++)
        {
            if (adj[vis][i] == 1 && (!visited[i]))
            {

                q.push_back(i);

                
                visited[i] = true;
            }
        }
    }
}
void addNode(int x, string str)
{
    arr[x] = str;
};

void showVertex()
{
    for (int x = 1; x < v; x++)
    {
        for (int y = 1; y < v; y++)
        {
            cout << adj[x][y];
            
        }
        cout << endl;
        
    }
};

int main()
{
    

    adj = vector< vector <int> >(v, vector<int>(v, 0));
    addNode(1, "Rumahku");
    addNode(2, "IndoKaca");
    addNode(3, "BALIJEEP 4X4");
    addNode(4, "OYO");
    addNode(5, "Trans Bali Eko Car");
    addNode(6, "Puri Tegal Buah Blok C");
    addNode(7, "Keripik Seuhah Bali");
    addNode(8, "Pertamina");
    addNode(9, "Artha Nadi Motor");
    addNode(10, "Pasar Buana Raya");
    addNode(11, "Vigo Vapestore");
    addNode(12, "Kos Wulandari");
    addNode(13, "Lion  Parcel");
    addNode(14, "Bink Motor");
    addNode(15, "Bintang Frozen Food");
    addNode(16, "Kos Turi House");
    addNode(17, "Pie Susu Tunjung");
    addNode(18, "Gustarbrownes");
    addNode(19, "Perum. Ratana");
    addNode(20, "Warung Mina");
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(1, 20);
    addEdge(20, 1);
    addEdge(2, 4);
    addEdge(3, 5);
    addEdge(4, 3);
    addEdge(4, 6);
    addEdge(5, 6);
    addEdge(6, 7);
    addEdge(7, 8);
    addEdge(8, 9);
    addEdge(9, 8);
    addEdge(9, 10);
    addEdge(10, 9);
    addEdge(10, 11);
    addEdge(11, 10);
    addEdge(11, 12);
    addEdge(12, 11);
    addEdge(13, 11);
    addEdge(11, 13);
    addEdge(13, 12);
    addEdge(13, 14);
    addEdge(14, 13);
    addEdge(14, 16);
    addEdge(16, 14);
    addEdge(18, 16);
    addEdge(19, 18);
    addEdge(20, 19);
    addEdge(18, 17);
    addEdge(17, 15);
    addEdge(15, 12);
    bfs(1);
    cout<< endl;
    cout << "== Matrix == ";
    cout << endl;
    showVertex();
}