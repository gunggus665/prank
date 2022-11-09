#include <iostream>
using namespace std;

class LCTR
{
    //Access specifier
    public:

    //Data Member
    string LCTRname;

    //Member Functions
    void printname()
    {
        cout<<"Lecture name is"<<LCTRname;
    }
};

int main(){
    //Declare an object of class geeks
    LCTR lctr1;

    //accessing data member
    lctr1.LCTRname="Mulki Kusumah";

    //accessing member function
    lctr1.printname();
    return 0;
}