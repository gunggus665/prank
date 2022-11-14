#include <iostream>

using namespace std;

struct NBA
{
  string playername, playerteam;
  int playernumber;
  NBA *prev;
  NBA *next;
};

NBA *head, *tail, *cur, *newNode, *afterNode;

void createNBA(string name, string team, int number)
{
  head = new NBA();
  head->playername = name;
  head->playerteam = team;
  head->playernumber = number;
  head->prev = head;
  head->next = head;
  tail = head;
}

void addFirst(string name, string team, int number)
{
  if (head == NULL)
  {
    cout << "Linked List Not Exist" << endl;
  }
  else
  {
    newNode = new NBA();
    newNode->playername = name;
    newNode->playerteam = team;
    newNode->playernumber = number;
    newNode->prev = tail;
    newNode->next = head;
    head->prev = newNode;
    tail->next = newNode;
    head = newNode;
  }
}

void addLast(string name, string team, int number)
{
  if (head == NULL)
  {
    cout << "Linked List Not Exist" << endl;
  }
  else
  {
    newNode = new NBA();
    newNode->playername = name;
    newNode->playerteam = team;
    newNode->playernumber = number;
    newNode->prev = tail;
    newNode->next = head;
    head->prev = newNode;
    tail->next = newNode;
    tail = newNode;
  }
}

void addMiddle(string name, string team, int number, int position)
{
  if (head == NULL)
  {
    cout << "Linked List Not Exist" << endl;
  }
  else
  {
    if (position == 1)
    {
      cout << "First Position Is Not In The Middle" << endl;
    }
    else if (position < 1)
    {
      cout << "Position Out Of Range" << endl;
    }
    else
    {
      newNode = new NBA();
      newNode->playername = name;
      newNode->playerteam = team;
      newNode->playernumber = number;

      cur = head;
      int number = 1;
      while (number < position - 1)
      {
        cur = cur->next;
        number++;
      }
      afterNode = cur->next;
      cur->next = newNode;
      afterNode->prev = newNode;
      newNode->prev = cur;
      newNode->next = afterNode;
    }
  }
}

void printNBA()
{
  if (head == NULL)
  {
    cout << "Linked List Not Exist" << endl;
  }
  else
  {
    cout << "NBA Data" << endl;
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

  createNBA("Max Verstappen", "Red Bull", 1);
  printNBA();
  cout << endl
       << endl;

  addFirst("Charles Leclerc", "Scuderia Ferrari", 16);
  printNBA();
  cout << endl
       << endl;

  addLast("George Russel", "Mercedes AMG", 63);
  printNBA();
  cout << endl
       << endl;

  addMiddle("Lando Norris", "Mclaren", 4, 3);
  printNBA();
  cout << endl
       << endl;
}