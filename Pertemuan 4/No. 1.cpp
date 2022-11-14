#include <iostream>

using namespace std;

struct NBA
{
  string playername, playerteam, playernumber;
  NBA *prev;
  NBA *next;
};

NBA *head, *tail, *cur, *newNode, *afterNode;

void createDoubleLinkedList(string data[3])
{
  head = new NBA();
  head->playername = data[0];
  head->playerteam = data[1];
  head->playernumber = data[2];
  head->prev = NULL;
  head->next = NULL;
  tail = head;
}

int countDoubleLinkedList()
{
  if (head == NULL)
  {
    cout << "Linked List Not Exist";
  }
  else
  {
    cur = head;
    int jumlah = 0;
    while (cur != NULL)
    {
      jumlah++;

      cur = cur->next;
    }
    return jumlah;
  }
}

void addFirst(string data[3])
{
  if (head == NULL)
  {
    cout << "Linked List Not Exist";
  }
  else
  {
    newNode = new NBA();
    newNode->playername = data[0];
    newNode->playerteam = data[1];
    newNode->playernumber = data[2];
    newNode->prev = NULL;
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
  }
}

void addLast(string data[3])
{
  if (head == NULL)
  {
    cout << "Linked List Not Exist";
  }
  else
  {
    newNode = new NBA();
    newNode->playername = data[0];
    newNode->playerteam = data[1];
    newNode->playernumber = data[2];
    newNode->prev = tail;
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;
  }
}

void addMiddle(string data[3], int posisi)
{
  if (head == NULL)
  {
    cout << "Linked List Not Exist";
  }
  else
  {

    if (posisi == 1)
    {
      cout << "First Position Is Not In The Middle" << endl;
    }
    else if (posisi < 1 || posisi > countDoubleLinkedList())
    {
      cout << "Position Out Of Range" << endl;
    }
    else
    {
      newNode = new NBA();
      newNode->playername = data[0];
      newNode->playerteam = data[1];
      newNode->playernumber = data[2];

      cur = head;
      int nomor = 1;
      while (nomor < posisi - 1)
      {
        cur = cur->next;
        nomor++;
      }

      afterNode = cur->next;
      newNode->prev = cur;
      newNode->next = afterNode;
      cur->next = newNode;
      afterNode->prev = newNode;
    }
  }
}

void printDoubleLinkedList()
{
  if (head == NULL)
  {
    cout << "Linked List Not Exist";
  }
  else
  {
    cout << "Amount Of Data : " << countDoubleLinkedList() << endl;
    cout << "-----------------" << endl;
    cur = head;
    while (cur != NULL)
    {
      cout << "Player's Name : " << cur->playername << endl;
      cout << "Player's Team : " << cur->playerteam << endl;
      cout << "Player's Number : " << cur->playernumber << endl
           << endl;
      cur = cur->next;
    }
  }
}

int main()
{

  string newData[3] = {"Stepeh Curry", "GSW", "30"};
  createDoubleLinkedList(newData);
  printDoubleLinkedList();
  cout << endl
       << endl;

  string data2[3] = {"Kobe Bryant", "Lakers", "24"};
  addFirst(data2);
  printDoubleLinkedList();
  cout << endl
       << endl;

  string data3[3] = {"Lebron James", "Lakers", "23"};
  addLast(data3);
  printDoubleLinkedList();
  cout << endl
       << endl;

  string data4[3] = {"Dharma", "Aktuaria", "77"};
  addMiddle(data4, 2);
  printDoubleLinkedList();
  cout << endl
       << endl;
}
