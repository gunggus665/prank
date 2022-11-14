#include <iostream>

using namespace std;

// deklarasi single linked list
struct Lagu
{

    // komponen / member
    string judul, pengarang;
    int tahunTerbit;

    Lagu *next;
};

Lagu *head, *tail, *cur, *newNode, *del, *before;

// create single linked list
void createSingleLinkedList(string judul, string pengarang, int tB)
{
    head = new Lagu();
    head->judul = judul;
    head->pengarang = pengarang;
    head->tahunTerbit = tB;
    head->next = NULL;
    tail = head;
}

// print single linked list
int countSingleLinkedList()
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

// tambahAwal Single linked list
void addFirst(string judul, string pengarang, int tB)
{
    newNode = new Lagu();
    newNode->judul = judul;
    newNode->pengarang = pengarang;
    newNode->tahunTerbit = tB;
    newNode->next = head;
    head = newNode;
}

// tambahAkhir Single linked list
void addLast(string judul, string pengarang, int tB)
{
    newNode = new Lagu();
    newNode->judul = judul;
    newNode->pengarang = pengarang;
    newNode->tahunTerbit = tB;
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;
}

// tambah tengah single linked list
void addMiddle(string judul, string pengarang, int tB, int posisi)
{
    if (posisi < 1 || posisi > countSingleLinkedList())
    {
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        newNode = new Lagu();
        newNode->judul = judul;
        newNode->pengarang = pengarang;
        newNode->tahunTerbit = tB;

        // tranversing
        cur = head;
        int nomor = 1;
        while (nomor < posisi - 1)
        {
            cur = cur->next;
            nomor++;
        }
        newNode->next = cur->next;
        cur->next = newNode;
    }
}

// Remove First
void removeFirst()
{
    del = head;
    head = head->next;
    delete del;
}

// Remove Last
void removeLast()
{
    del = tail;
    cur = head;
    while (cur->next != tail)
    {
        cur = cur->next;
    }
    tail = cur;
    tail->next = NULL;
    delete del;
}

// remove middle
void removeMiddle(int posisi)
{
    if (posisi < 1 || posisi > countSingleLinkedList())
    {
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        int nomor = 1;
        cur = head;
        while (nomor <= posisi)
        {
            if (nomor == posisi - 1)
            {
                before = cur;
            }
            if (nomor == posisi)
            {
                del = cur;
            }
            cur = cur->next;
            nomor++;
        }
        before->next = cur;
        delete del;
    }
}

// ubahAwal Single linked list
void changeFirst(string judul, string pengarang, int tB)
{
    head->judul = judul;
    head->pengarang = pengarang;
    head->tahunTerbit = tB;
}

// ubahAkhir Single linked list
void changeLast(string judul, string pengarang, int tB)
{
    tail->judul = judul;
    tail->pengarang = pengarang;
    tail->tahunTerbit = tB;
}

// ubah Tengah Single linked list
void changeMiddle(string judul, string pengarang, int tB, int posisi)
{
    if (posisi < 1 || posisi > countSingleLinkedList())
    {
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisi == 1 || posisi == countSingleLinkedList())
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        cur = head;
        int nomor = 1;
        while (nomor < posisi)
        {
            cur = cur->next;
            nomor++;
        }
        cur->judul = judul;
        cur->pengarang = pengarang;
        cur->tahunTerbit = tB;
    }
}

// print single linked list
void printSingleLinkedList()
{
    cout << "Jumlah data ada : " << countSingleLinkedList() << endl;
    cur = head;
    while (cur != NULL)
    {
        cout << "Judul Lagu : " << cur->judul << endl;
        cout << "Pengarang Lagu : " << cur->pengarang << endl;
        cout << "Tahun Terbit Lagu : " << cur->tahunTerbit << endl;

        cur = cur->next;
    }
}

int main()
{

    createSingleLinkedList("Kesempurnaan Cinta", "Koes Bersaudara Febian", 2015);

    printSingleLinkedList();

    cout << "\n\n"
         << endl;

    addFirst("Bis Sekolah", "Tere Liye", 1964);

    printSingleLinkedList();

    cout << "\n\n"
         << endl;

    addLast("Melompat Lebih Tinggi", "Sheila On 7", 2003);

    printSingleLinkedList();

    cout << "\n\n"
         << endl;

    removeFirst();

    printSingleLinkedList();

    cout << "\n\n"
         << endl;

    addLast("Celengan Rindu", "Fiersa Besari", 2014);

    printSingleLinkedList();

    cout << "\n\n"
         << endl;

    removeLast();

    printSingleLinkedList();

    cout << "\n\n"
         << endl;

    changeFirst("Ragu", "Raisa", 2014);

    printSingleLinkedList();

    cout << "\n\n"
         << endl;

    addMiddle("Manusia Bodoh", "Ada Band", 2004, 2);

    printSingleLinkedList();

    cout << "\n\n"
         << endl;

    addMiddle("Seperti Takdir Kita yang Tulis", "Nadin Amizah", 2021, 2);

    printSingleLinkedList();

    cout << "\n\n"
         << endl;

    removeMiddle(5);

    printSingleLinkedList();

    cout << "\n\n"
         << endl;

    changeMiddle("Kangen", "Dewa 19", 1992, 2);

    printSingleLinkedList();

    cout << "\n\n"
         << endl;
}
