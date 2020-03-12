#include<iostream>
#include<cstring>
#include<fstream>
#include<stdlib.h>
#include<string>
#include<iomanip>
#include <bits/stdc++.h> 
using namespace std;
void userChoice();
void customerMenu();
void staffMenu();
struct Node { 
    int data; 
    struct Node* link;;
}; 
struct Queue { struct Node *front, *rear; };  
void enQueue(Queue *q, int value) { 
    struct Node *temp = new Node; 
    temp->data = value; 
    if (q->front == NULL) 
        q->front = temp; 
    else
        q->rear->link = temp; 
	    q->rear = temp; 
	    q->rear->link = q->front; 
} 
int deQueue(Queue *q) 
{ 
    if (q->front == NULL) 
    { 
        printf ("Queue is empty"); 
        return INT_MIN; 
    } 
    
	int value;
    
    if (q->front == q->rear) 
    { 
        value = q->front->data; 
        free(q->front); 
        q->front = NULL; 
        q->rear = NULL; 
    } 
    else 
    { 
        struct Node *temp = q->front; 
        value = temp->data; 
        q->front = q->front->link; 
        q->rear->link= q->front; 
        free(temp); 
    } 
    return value ; 
}  
void displayQueue(struct Queue *q) 
{ 
    struct Node *temp = q->front; 
    printf("\nElements in Circular Queue are: "); 
    while (temp->link != q->front) 
    { 
        printf("%d ", temp->data); 
        temp = temp->link; 
    } 
    printf("%d", temp->data); 
} 
class Data{
	protected:
		string terminal[7];
		string stateList[4];
		float timePrice[7][2];
	public:
		void display()
		{
			ifstream infile;
			infile.open("TerminalBus.txt");
			for(int i=0; i<7;i++){
				getline(infile,terminal[i]);
			}	
			infile.ignore();	
			infile.close();
			infile.open("States.txt");
			for(int i=0; i<4;i++){
				getline(infile,stateList[i]);
			}	
			infile.ignore();	
			infile.close();
			infile.open("TimePrice.txt");
			for(int i=0; i<7;i++){
				for(int j=0;j<2;j++){
					infile>>timePrice[i][j];
				}
			}
			int state;
			A:cout<<"Please choose the state:"<<endl;
			for(int i=0; i<4;i++){
				cout<<i+1<<"-"<<stateList[i]<<endl;
			}
			cout<<"State(1-4): ";
			cin>>state;
			system("CLS");
			cout<<endl<<"---------------------------------------------------------------------------------------------"<<endl;
			cout<<setw(20)<<left<<"STATES"<<setw(35)<<"TERMINAL NAME"<<setw(25)<<"DEPARTURE TIME"<<setw(20)<<"TICKET PRICE"<<endl;
			cout<<"---------------------------------------------------------------------------------------------"<<endl;
			switch(state)
			{
				case 1: for(int i=0; i<7;i++){
						if(i<3)
						{cout<<setw(20)<<left<<stateList[0]<<setw(40)<<left<<terminal[i];
							for(int j=0;j<2;j++){
								if(j==0)
								cout<<setw(25)<<timePrice[i][j];
								else
								cout<<setw(20)<<timePrice[i][j]<<endl;}
						}}
						system("PAUSE");
						system("CLS");
						customerMenu();
						break;
				case 2: for(int i=0; i<7;i++){
						if(i==3)
						{cout<<setw(20)<<left<<stateList[1]<<setw(39)<<left<<terminal[i];
							for(int j=0;j<2;j++){
								if(j==0)
								cout<<setw(25)<<timePrice[i][j];
								else
								cout<<setw(20)<<timePrice[i][j]<<endl;}	
						}}	
						system("PAUSE");
						system("CLS");
						customerMenu();
						break; 
				case 3: for(int i=0; i<7;i++){
						if(i==4)
						{cout<<setw(20)<<left<<stateList[2]<<setw(37)<<left<<terminal[i];
							for(int j=0;j<2;j++){
								if(j==0)
								cout<<setw(25)<<timePrice[i][j];
								else
								cout<<setw(20)<<timePrice[i][j]<<endl;}
						}}
						system("PAUSE");
						system("CLS");
						customerMenu();
						break;
				case 4: for(int i=0; i<7;i++){
						if(i>=5&&i<7)
						{cout<<setw(20)<<left<<stateList[3]<<setw(33)<<left<<terminal[i];
							for(int j=0;j<2;j++){
								if(j==0)
								cout<<setw(25)<<timePrice[i][j];
								else
								cout<<setw(20)<<timePrice[i][j]<<endl;}
						}}					
						system("PAUSE");
						system("CLS");
						customerMenu();
						break;
				default:cout<<endl<<"Invalid input. Please try again."<<endl;
						system("PAUSE");
						system("CLS");
						goto A;
						break;
			}
		}
		void displayAll()
		{
			string terminal1[7];
			string stateList1[4];
			float timePrice1[7][2];
			ifstream infile;
			infile.open("TerminalBus.txt");
			for(int i=0; i<7;i++){
				getline(infile,terminal1[i]);
			}	
			infile.ignore();	
			infile.close();
			infile.open("States.txt");
			for(int i=0; i<4;i++){
				getline(infile,stateList1[i]);
			}	
			infile.ignore();	
			infile.close();
			infile.open("TimePrice.txt");
			for(int i=0; i<7;i++){
				for(int j=0;j<2;j++){
					infile>>timePrice1[i][j];
					infile.ignore();
				}
			}
			infile.close();	
			cout<<endl<<"---------------------------------------------------------------------------------------------"<<endl;
			cout<<setw(20)<<left<<"STATES"<<setw(35)<<"TERMINAL NAME"<<setw(25)<<"DEPARTURE TIME"<<setw(20)<<"TICKET PRICE"<<endl;
			cout<<"---------------------------------------------------------------------------------------------"<<endl;
			for(int i=0; i<7;i++){
				if(i<3)
				{cout<<setw(20)<<left<<stateList1[0]<<setw(40)<<left<<terminal1[i];
					for(int j=0;j<2;j++){
						if(j==0)
						cout<<setw(25)<<timePrice1[i][j];
						else
						cout<<setw(20)<<timePrice1[i][j]<<endl;}
				}
				else if(i==3)
				{cout<<setw(20)<<left<<stateList1[1]<<setw(40)<<left<<terminal1[i];
					for(int j=0;j<2;j++){
						if(j==0)
						cout<<setw(25)<<timePrice1[i][j];
						else
						cout<<setw(20)<<timePrice1[i][j]<<endl;}	
				}
				else if(i==4)
				{cout<<setw(20)<<left<<stateList1[2]<<setw(40)<<left<<terminal1[i];
					for(int j=0;j<2;j++){
						if(j==0)
						cout<<setw(25)<<timePrice1[i][j];
						else
						cout<<setw(20)<<timePrice1[i][j]<<endl;}
				}
				else
				{cout<<setw(20)<<left<<stateList1[3]<<setw(40)<<left<<terminal1[i];
					for(int j=0;j<2;j++){
						if(j==0)
						cout<<setw(25)<<timePrice1[i][j];
						else
						cout<<setw(20)<<timePrice1[i][j]<<endl;}
				}
			}
			system("PAUSE");
			system("CSL");
			staffMenu();
		}
		void update()
		{
			Queue *q = new Queue; 
    		q->front = q->rear = NULL;
			int action;
			A:cout<<"Which action you want to do?"<<endl;
			cout<<"1-Add schedule"<<endl<<"2-Delete schedule"<<endl;
			cout<<"Action(1/2): ";
			cin>>action;
			system("CLS");
			if(action==1)
			{
				enQueue(q, 1);
				enQueue(q, 2);
				enQueue(q, 3);
				enQueue(q, 4);
				enQueue(q, 5);
				enQueue(q, 6);
				enQueue(q,7);
				displayQueue(q);
			}
			else if(action==2)
			{
				deQueue(q);
				deQueue(q);
				displayQueue(q);
			}
			else
			cout<<endl<<"Invalid input. Please try again."<<endl;
			goto A;	
		}
		void displayBooking()
		{
			Queue *q = new Queue; 
    		q->front = q->rear = NULL;
			displayQueue(q);;
			system("PAUSE");
			system("CLS");
			staffMenu();
		}
			
};

class Ticket{
	private:
		string name;
		int phoneNum,seat,icNum,destination;
		int seatList[10][4];
	public:
		Ticket(){}
		void setSeat(int a){seat=a;}
		void setInformation(string a,int e,int f)
		{
			name=a;
			icNum=e;
			phoneNum=f;
		}
		void setDestination(int a){destination=a;}
		int busSeat()
		{
			Queue *q = new Queue; 
    		q->front = q->rear = NULL;
			int a;
			int seat[10][4];
			ifstream infile;
			infile.open("SeatBus.txt");
			for(int i=0; i<10;i++){
				for(int j=0;j<4;j++){
					infile>>seat[i][j];	
				}
			}
			infile.close();
			enQueue(q,15);
			enQueue(q,40);
			enQueue(q,27);
			enQueue(q,8);
			cout<<endl<<"-----------------------"<<endl;
			cout<<"Please choose your seat"<<endl;
			cout<<"-----------------------"<<endl;
			for(int i=0; i<10;i++){
				for(int j=0;j<4;j++){
					if(j==0)
					cout<<seat[i][j];
					else if(j==2)
					cout<<right<<setw(10)<<seat[i][j];
					else 
					cout<<right<<setw(5)<<seat[i][j];	
				}
				cout<<endl;
			}
			displayQueue(q);
			cout<<endl<<"Seat(1-40): ";
			cin>>a;
			system("CLS");
			enQueue(q,a);
			setSeat(a);
			information();	
		}
		void booking()
		{

			int d;
			cout<<endl<<"Please choose your destination "<<endl;
			string terminal1[7];
			string stateList1[4];
			float timePrice1[7][2];
			ifstream infile;
			infile.open("TerminalBus.txt");
			for(int i=0; i<7;i++){
				getline(infile,terminal1[i]);
			}	
			infile.ignore();	
			infile.close();
			infile.open("States.txt");
			for(int i=0; i<4;i++){
				getline(infile,stateList1[i]);
			}	
			infile.ignore();	
			infile.close();
			infile.open("TimePrice.txt");
			for(int i=0; i<7;i++){
				for(int j=0;j<2;j++){
					infile>>timePrice1[i][j];
					infile.ignore();
				}
			}
			infile.close();	
			cout<<endl<<"--------------------------------------------------------------------------------------------------"<<endl;
			cout<<setw(5)<<"No."<<setw(20)<<left<<"STATES"<<setw(35)<<"TERMINAL NAME"<<setw(25)<<"DEPARTURE TIME"<<setw(20)<<"TICKET PRICE"<<endl;
			cout<<"---------------------------------------------------------------------------------------------------"<<endl;
			for(int i=0; i<7;i++){
				if(i<3)
				{cout<<setw(5)<<i+1<<setw(20)<<left<<stateList1[0]<<setw(40)<<left<<terminal1[i];
					for(int j=0;j<2;j++){
						if(j==0)
						cout<<setw(25)<<timePrice1[i][j];
						else
						cout<<setw(20)<<timePrice1[i][j]<<endl;}
				}
				else if(i==3)
				{cout<<setw(5)<<i+1<<setw(20)<<left<<stateList1[1]<<setw(40)<<left<<terminal1[i];
					for(int j=0;j<2;j++){
						if(j==0)
						cout<<setw(25)<<timePrice1[i][j];
						else
						cout<<setw(20)<<timePrice1[i][j]<<endl;}	
				}
				else if(i==4)
				{cout<<setw(5)<<i+1<<setw(20)<<left<<stateList1[2]<<setw(40)<<left<<terminal1[i];
					for(int j=0;j<2;j++){
						if(j==0)
						cout<<setw(25)<<timePrice1[i][j];
						else
						cout<<setw(20)<<timePrice1[i][j]<<endl;}
				}
				else
				{cout<<setw(5)<<i+1<<setw(20)<<left<<stateList1[3]<<setw(40)<<left<<terminal1[i];
					for(int j=0;j<2;j++){
						if(j==0)
						cout<<setw(25)<<timePrice1[i][j];
						else
						cout<<setw(20)<<timePrice1[i][j]<<endl;}
				}
			}
			cout<<endl<<"Destination(1-7): ";
			cin>>d;
			system("CLS");
			setDestination(d);
			busSeat();
			}
			void information(){
			int e, f;
			string a;
			cout<<endl<<"--------------------------------"<<endl;
			cout<<"Please enter your details below "<<endl;
			cout<<"--------------------------------"<<endl;
			cin.ignore();
			cout<<"Name: ";
			getline(cin,a);
			cout<<"IC Number: ";
			cin>>e;
			cout<<"Phone Number: ";
			cin>>f;
			system("CLS");
			setInformation(a,e,f);
			print();
		}
		void print()
		{
			cin.ignore();
			cout<<endl<<"BOOKING DETAILS:"<<endl<<"Name: "<<name<<endl<<"IC Number: "<<icNum<<endl<<"Phone Number: "<<phoneNum<<endl<<"Seat Number: "<<seat<<endl;
			cout<<endl<<"---------------------------------------------------------------------------------------------"<<endl;
			cout<<setw(20)<<left<<"STATES"<<setw(35)<<"TERMINAL NAME"<<setw(25)<<"DEPARTURE TIME"<<setw(20)<<"TICKET PRICE"<<endl;
			cout<<"---------------------------------------------------------------------------------------------"<<endl;
			switch(destination)
			{
				case 1: cout<<setw(20)<<"JOHOR"<<setw(40)<<"BATU PAHAT BUS TERMINAL"<<setw(25)<<"1100"<<setw(20)<<"25"<<endl;
						system("PAUSE");
						system("CLS");
						writeToFile(name);
						customerMenu();
						break;
				case 2: cout<<setw(20)<<"JOHOR"<<setw(40)<<"LARKIN BUS TERMINAL"<<setw(25)<<"1200"<<setw(20)<<"20"<<endl;
						system("PAUSE");
						system("CLS");
						writeToFile(name);
						customerMenu();
						break;
				case 3: cout<<setw(20)<<"JOHOR"<<setw(40)<<"MASAI BUS TERMINAL"<<setw(25)<<"1300"<<setw(20)<<"30"<<endl;
						system("PAUSE");
						system("CLS");
						customerMenu();
						writeToFile(name);
						break;
				case 4: cout<<setw(20)<<"MELAKA"<<setw(40)<<"MELAKA SENTRAL BUS TERMINAL"<<setw(25)<<"1400"<<setw(20)<<"35"<<endl;
						system("PAUSE");
						system("CLS");
						customerMenu();
						writeToFile(name);
						break;
				case 5: cout<<setw(20)<<"SELANGOR"<<setw(40)<<"TERMINAL BERSEPADU SELATAN (TBS)"<<setw(25)<<"1500"<<setw(20)<<"40"<<endl;
						system("PAUSE");
						system("CLS");
						customerMenu();
						writeToFile(name);
						break;
				case 6: cout<<setw(20)<<"KUALA LUMPUR"<<setw(40)<<"HENTIAN PUDURAYA BUS TERMINAL"<<setw(25)<<"1600"<<setw(20)<<"50"<<endl;
						system("PAUSE");
						system("CLS");
						customerMenu();
						writeToFile(name);
						break;
				case 7: cout<<setw(20)<<"KUALA LUMPUR"<<setw(40)<<"HENTIAN PUTRA BUS TERMINAL"<<setw(25)<<"1700"<<setw(20)<<"50"<<endl;						
						system("PAUSE");
						system("CLS");
						customerMenu();
						writeToFile(name);
			}
		}
		void writeToFile(string name){
			ofstream out;
			string file= name+".txt";
			cout<<endl<<"BOOKING DETAILS:"<<endl<<"Name: "<<name<<endl<<"IC Number: "<<icNum<<endl<<"Phone Number: "<<phoneNum<<endl;
			cout<<endl<<"---------------------------------------------------------------------------------------------"<<endl;
			cout<<setw(20)<<left<<"STATES"<<setw(35)<<"TERMINAL NAME"<<setw(25)<<"DEPARTURE TIME"<<setw(20)<<"TICKET PRICE"<<endl;
			cout<<"---------------------------------------------------------------------------------------------"<<endl;
			switch(destination)
			{
				case 1: cout<<setw(20)<<"JOHOR"<<setw(40)<<"BATU PAHAT BUS TERMINAL"<<setw(25)<<"1100"<<setw(20)<<"25"<<endl;
						break;
				case 2: cout<<setw(20)<<"JOHOR"<<setw(40)<<"LARKIN BUS TERMINAL"<<setw(25)<<"1200"<<setw(20)<<"20"<<endl;
						break;
				case 3: cout<<setw(20)<<"JOHOR"<<setw(40)<<"MASAI BUS TERMINAL"<<setw(25)<<"1300"<<setw(20)<<"30"<<endl;
						break;
				case 4: cout<<setw(20)<<"MELAKA"<<setw(40)<<"MELAKA SENTRAL BUS TERMINAL"<<setw(25)<<"1400"<<setw(20)<<"35"<<endl;
						break;
				case 5: cout<<setw(20)<<"SELANGOR"<<setw(40)<<"TERMINAL BERSEPADU SELATAN (TBS)"<<setw(25)<<"1500"<<setw(20)<<"40"<<endl;
						break;
				case 6: cout<<setw(20)<<"KUALA LUMPUR"<<setw(40)<<"HENTIAN PUDURAYA BUS TERMINAL"<<setw(25)<<"1600"<<setw(20)<<"50"<<endl;
						break;
				case 7: cout<<setw(20)<<"KUALA LUMPUR"<<setw(40)<<"HENTIAN PUTRA BUS TERMINAL"<<setw(25)<<"1700"<<setw(20)<<"50"<<endl;
						break;
			}
		}
		void cancel()
		{
			Queue *q = new Queue; 
    		q->front = q->rear = NULL;
			int a;
			cout<<endl<<"Enter seat number: ";
			cin>>a;	
			deQueue(q);
			cout<<"The booked is canceled."<<endl;
			system("PAUSE");
			system("CLS");
			customerMenu();
		}
};
void customerMenu()
{
	int action;
	Data d;
	Ticket t;
	A:cout<<endl<<"Please make another choice to further your action"<<endl
		<<"1- Search destination "<<endl
		<<"2- Booking Ticket"<<endl
		<<"3- Cancel Ticket"<<endl
		<<"4- Exit"<<endl<<endl
		<<"Choice(1-5): ";
	cin>>action;
	system("CLS");
	switch(action)
	{
		case 1: d.display();
				system("CLS");
				break;
		case 2: t.booking();
				system("CLS");
				break;
		case 3: t.cancel();
				system("CLS");
				break;
		case 4:cout<<endl<<"Thank you for using our program!"<<endl<<"The program will exit now."<<endl<<"Have a nice day! "<<endl;
				exit(0);
				break;
		default:cout<<endl<<"Invalid input. Please try again."<<endl;
				system("PAUSE");
				system("CLS");
				goto A;
				break;
	}
}
void staffMenu()
{
	int action;
	Data d;
	A:cout<<endl<<"Please make another choice to further your action"<<endl
		<<"1- Display Schedule"<<endl
		<<"2- Update Schedule"<<endl
		<<"3- Display Booking"<<endl
		<<"4- Exit"<<endl<<endl
		<<"Choice(1-4): ";
	cin>>action;
	system("CLS");
	switch(action)
	{
		case 1: d.displayAll();
				system("CLS");
				break;
		case 2: d.update();
				system("CLS");
				break;
		case 3: d.displayBooking();
				system("CLS");
				break;
		case 4:cout<<endl<<"Thank you for using our program!"<<endl<<"The program will exit now."<<endl<<"Have a nice day! "<<endl;
				exit(0);
				break;
		default:cout<<endl<<"Invalid input. Please try again."<<endl;
				system("PAUSE");
				system("CLS");
				goto A;
				break;
	}
}
void userChoice()
{
	int choice;
	A:cout<<"**********************************"<<endl
		<<"* WELCOME TO THE UNIVERSITI MALL *"<<endl
		<<"*   TICKECT BUS BOOKING SYSTEM   *"<<endl
		<<"**********************************"<<endl<<endl
		<<"Please choose which one is you"<<endl
		<<"1-Customer"<<endl<<"2-Staff"<<endl
		<<"Enter your choice here(1/2): "
		;
		cin>>choice;
		system("CLS");
		switch(choice)
		{
			case 1: customerMenu();
					system("CLS");
					break;
			case 2: staffMenu();
					system("CLS");
					break;
			default:cout<<endl<<"Invalid input. Please try again."<<endl;
					system("PAUSE");
					system("CLS");
					goto A;
					break;
		}
}
int main()
{
	userChoice();
	return 0;
}

