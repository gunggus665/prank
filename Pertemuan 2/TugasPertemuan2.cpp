#include <iostream>

using namespace std;

struct movie{

	string name;
	char theater;
	float time;
	int price;
};

struct movie order[20];

main(){
	int i;
	for(int i=0; i<20; i++){
		cout<<"\n-----------------------\n";
		cout<<"\nOrder "<<i+1<<endl;
		cout<<"Movie Name = ";cin>>order[i].name;
		cout<<"Theater = ";cin>>order[i].theater;
		cout<<"Showtime= ";cin>>order[i].time;
		cout<<"Ticket= ";cin>>order[i].price;
	}
}
