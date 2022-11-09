#include <iostream>
using namespace std;

class LCTR
{

public:
    void printname()
    {
        cout << "Lecture name is : " << LCTRname;
    }

    string getNama()
    {
        return LCTRname;
    }

    LCTR(string nama)
    {
        LCTRname = nama;
    }

private:
    string LCTRname;
};

int main()
{

    LCTR lctr1("naufal");

    lctr1.printname();

    cout << lctr1.getNama();

    return 0;
}