#include <iostream>
#include <queue>
#include <list>
#include <iterator>

using namespace std;

class Graph
{
protected:
    int vertex;
    list<int> adj[100];
    string arr[100];

public:
    Graph(int v)
    {
        vertex = v;
    }
    void AddNode(int v1, string str)
    {
        arr[v1] = str;
    };
    void Addvertex(int v1, int v2)
    {
        adj[v1].push_back(v2);
    };
    void ShowVertex()
    {

        for (int i = 1; i <= vertex; i++)
        {
            cout << arr[i] << " -> ";
            list<int>::iterator it;
            for (it = adj[i].begin(); it != adj[i].end(); it++)
            {
                cout << arr[*it] << " ";
            }
            cout << endl;
        }
    };
    void BFS(int start)
    {
        cout << arr[start] << " -> ";
        bool visited[100];
        for (int i = 1; i <= vertex; i++)
        {
            visited[i] = false;
        }

        queue<int> q;
        q.push(start);
        visited[start] = true;
        while (!q.empty())
        {

            int curr = q.front();
            list<int>::iterator it;
            for (it = adj[curr].begin(); it != adj[curr].end(); it++)
            {
                if (!visited[*it])
                {
                    cout << arr[*it] << "->";
                    q.push(*it);
                }

                visited[*it] = true;
            }
            q.pop();
        }
    };
    void BFSend(int start, int end)
    {
        cout << arr[start] << " -> ";
        bool visited[100];
        for (int i = 1; i <= vertex; i++)
        {
            visited[i] = false;
        }

        queue<int> q;
        q.push(start);
        visited[start] = true;
        while (!q.empty())
        {

            int curr = q.front();
            list<int>::iterator it;
            for (it = adj[curr].begin(); it != adj[curr].end(); it++)
            {
                if (!visited[*it])
                {
                    cout << arr[*it] << "->";
                    if (*it == end)
                    {
                        return;
                    }

                    q.push(*it);
                }

                visited[*it] = true;
            }
            q.pop();
        }
    };
};

int main()
{
    Graph graph1(20);
    graph1.AddNode(1, "Rumahku");
    graph1.AddNode(2, "IndoKaca");
    graph1.AddNode(3, "BALIJEEP 4X4");
    graph1.AddNode(4, "OYO");
    graph1.AddNode(5, "Trans Bali Eko Car");
    graph1.AddNode(6, "Puri Tegal Buah Blok C");
    graph1.AddNode(7, "Keripik Seuhah Bali");
    graph1.AddNode(8, "Pertamina");
    graph1.AddNode(9, "Artha Nadi Motor");
    graph1.AddNode(10, "Pasar Buana Raya");
    graph1.AddNode(11, "Vigo Vapestore");
    graph1.AddNode(12, "Kos Wulandari");
    graph1.AddNode(13, "Lion  Parcel");
    graph1.AddNode(14, "Bink Motor");
    graph1.AddNode(15, "Bintang Frozen Food");
    graph1.AddNode(16, "Kos Turi House");
    graph1.AddNode(17, "Pie Susu Tunjung");
    graph1.AddNode(18, "Gustarbrownes");
    graph1.AddNode(19, "Perum. Ratana");
    graph1.AddNode(20, "Warung Mina");
    graph1.Addvertex(1, 2);
    graph1.Addvertex(1, 3);
    graph1.Addvertex(1, 20);
    graph1.Addvertex(20, 1);
    graph1.Addvertex(2, 4);
    graph1.Addvertex(3, 5);
    graph1.Addvertex(4, 3);
    graph1.Addvertex(4, 6);
    graph1.Addvertex(5, 6);
    graph1.Addvertex(6, 7);
    graph1.Addvertex(7, 8);
    graph1.Addvertex(8, 9);
    graph1.Addvertex(9, 8);
    graph1.Addvertex(9, 10);
    graph1.Addvertex(10, 9);
    graph1.Addvertex(10, 11);
    graph1.Addvertex(11, 10);
    graph1.Addvertex(11, 12);
    graph1.Addvertex(12, 11);
    graph1.Addvertex(13, 11);
    graph1.Addvertex(11, 13);
    graph1.Addvertex(13, 12);
    graph1.Addvertex(13, 14);
    graph1.Addvertex(14, 13);
    graph1.Addvertex(14, 16);
    graph1.Addvertex(16, 14);
    graph1.Addvertex(18, 16);
    graph1.Addvertex(19, 18);
    graph1.Addvertex(20, 19);
    graph1.Addvertex(18, 17);
    graph1.Addvertex(17, 15);
    graph1.Addvertex(15, 12);
    graph1.ShowVertex();
    cout << endl;
    cout << "== BFS == ";
    cout << endl;
    graph1.BFS(1);
    cout << endl;
    cout << endl;
    cout << "== ENDPOINT DI 14 == ";
    cout << endl;
    graph1.BFSend(1, 14);
};
