#include <iostream>

using namespace std;

struct NBA
{
  string playername, playerteam, playernumber;
  NBA *next;
};

NBA *head, *tail, *newNode, *cur;

void createCircularSingleLinkedList(string newData[3])
{
  head = new NBA();
  head->playername = newData[0];
  head->playerteam = newData[1];
  head->playernumber = newData[2];
  tail = head;
  tail->next = head;
}

void addFirst(string data[3])
{
  if (head == NULL)
  {
    cout << "Linked List Not Exist" << endl;
  }
  else
  {
    newNode = new NBA();
    newNode->playername = data[0];
    newNode->playerteam = data[1];
    newNode->playernumber = data[2];
    newNode->next = head;
    tail->next = newNode;
    head = newNode;
  }
}

void addLast(string data[3])
{
  if (head == NULL)
  {
    cout << "Linked List Not Exist" << endl;
  }
  else
  {
    newNode = new NBA();
    newNode->playername = data[0];
    newNode->playerteam = data[1];
    newNode->playernumber = data[2];
    newNode->next = head;
    tail->next = newNode;
    tail = newNode;
  }
}

void addMiddle(string data[3], int posisi)
{
  if (head == NULL)
  {
    cout << "Linked List Not Exist" << endl;
  }
  else
  {
    if (posisi == 1)
    {
      cout << "First Position Is Not In The Middle" << endl;
    }
    else
    {
      newNode = new NBA();
      newNode->playername = data[0];
      newNode->playerteam = data[1];
      newNode->playernumber = data[2];

      int nomor = 1;
      cur = head;
      while (nomor < posisi - 1)
      {
        cur = cur->next;
        nomor++;
      }
      newNode->next = cur->next;
      cur->next = newNode;
    }
  }
}

void printCircular()
{
  if (head == NULL)
  {
    cout << "Linked List Not Exist" << endl;
  }
  else
  {
    cout << "NBA Data " << endl;
    cout << "-----------------" << endl;
    cur = head;
    while (cur->next != head)
    {

      cout << "Player's Name : " << cur->playername << endl;
      cout << "Player's Team : " << cur->playerteam << endl;
      cout << "Player's Number : " << cur->playernumber << endl
           << endl;

      cur = cur->next;
    }
    cout << "Player's Name : " << cur->playername << endl;
    cout << "Player's Team : " << cur->playerteam << endl;
    cout << "Player's Number : " << cur->playernumber << endl
         << endl;
  }
}

int main()
{
  string newData[3] = {"Stepeh Curry", "GSW", "30"};
  createCircularSingleLinkedList(newData);
  printCircular();
  cout << endl
       << endl;

  string data[3] = {"Kobe Bryant", "Lakers", "24"};
  addFirst(data);
  printCircular();
  cout << endl
       << endl;

  string data2[3] = {"Lebron James", "Lakers", "23"};
  addLast(data2);
  printCircular();
  cout << endl
       << endl;

  string data3[3] = {"Dharma", "Aktuaria", "77"};
  addMiddle(data3, 3);
  printCircular();
  cout << endl
       << endl;
}