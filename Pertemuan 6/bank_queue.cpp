#include <iostream>
#define MAX 10
using namespace std;

struct queue
{
    int depan;
    int belakang;
    string data[MAX];
} AntrianTeller1, AntrianTeller2, AntrianTeller3, AntrianCS1, AntrianCS2, AntrianCS3;

void init(queue *q)
{
    q->depan = -1;
    q->belakang = -1;
}

bool isEmpty(queue *q)
{
    return (q->depan == -1 && q->belakang == -1);
}

bool isFull(queue *q)
{
    return (q->belakang == MAX - 1);
}

void enqueue(queue *q, string data)
{
    if (isFull(q))
    {
        cout << "Antrian penuh" << endl;
    }
    else
    {
        if (isEmpty(q))
        {
            q->depan = 0;
        }
        q->belakang++;
        q->data[q->belakang] = data;
    }
}

void dequeue(queue *q)
{
    if (isEmpty(q))
    {
        cout << "Antrian kosong" << endl;
    }
    else
    {
        if (q->depan == q->belakang)
        {
            init(q);
        }
        else
        {
            q->depan++;
        }
    }
}

void print(queue *q)
{
    if (isEmpty(q))
    {
        cout << "Antrian kosong" << endl;
    }
    else
    {
        for (int i = q->depan; i <= q->belakang; i++)
        {
            cout << q->data[i] << " "
                 << "URUTAN"
                 << " " << i + 1 << endl;
        }
        cout << endl;
    }
}

int main()
{

    init(&AntrianTeller1);
    init(&AntrianTeller2);
    init(&AntrianTeller3);
    init(&AntrianCS1);
    init(&AntrianCS2);
    init(&AntrianCS3);

    int n;
    string indikator;
    string data;
    cout << "Masukkan data" << endl;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> indikator;
        if (indikator == "TELLER")
        {
            cin >> data;
            if ((&AntrianTeller1)->belakang <= (&AntrianTeller2)->belakang && (&AntrianTeller1)->belakang <= (&AntrianTeller3)->belakang)
            {
                enqueue(&AntrianTeller1, data);
            }
            else if ((&AntrianTeller2)->belakang <= (&AntrianTeller1)->belakang && (&AntrianTeller2)->belakang <= (&AntrianTeller3)->belakang)
            {
                enqueue(&AntrianTeller2, data);
            }
            else if ((&AntrianTeller3)->belakang <= (&AntrianTeller1)->belakang && (&AntrianTeller3)->belakang <= (&AntrianTeller2)->belakang)
            {
                enqueue(&AntrianTeller3, data);
            }
        }
        else if (indikator == "CS")
        {
            cin >> data;
            if ((&AntrianCS1)->belakang <= (&AntrianCS2)->belakang && (&AntrianCS1)->belakang <= (&AntrianCS3)->belakang)
            {
                enqueue(&AntrianCS1, data);
            }
            else if ((&AntrianCS2)->belakang <= (&AntrianCS1)->belakang && (&AntrianCS2)->belakang <= (&AntrianCS3)->belakang)
            {
                enqueue(&AntrianCS2, data);
            }
            else if ((&AntrianCS3)->belakang <= (&AntrianCS1)->belakang && (&AntrianCS3)->belakang <= (&AntrianCS2)->belakang)
            {
                enqueue(&AntrianCS3, data);
            }
        }
    }

    cout << "Antrian Teller 1: ";
    print(&AntrianTeller1);
    cout << "Antrian Teller 2: ";
    print(&AntrianTeller2);
    cout << "Antrian Teller 3: ";
    print(&AntrianTeller3);
    cout << "Antrian CS 1: ";
    print(&AntrianCS1);
    cout << "Antrian CS 2: ";
    print(&AntrianCS2);
    cout << "Antrian CS 3: ";
    print(&AntrianCS3);
}