#include <iostream>
#include <fstream>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <dos.h>
#include <iomanip>
using namespace std;
int login(int);

class customer // customer class
{
	private:
	public:
	string customername;
    string customernumber;
      int carnumber;
    char data;
    int d;
    // variables defined in this class in public mode.
};


class rent : public customer // inhereted class from customer class
{
	public:
	  int days=0,rentalfee=0; // additional int vatiables defined
	void data()
	{
		cout<<"\n\n\t\t\t\tCARS ARE GIVEN BELOW "<<endl<<endl;
		cout<<"\n[ NOTE - DRIVER FEES FOR EACH DAY 300/- ]"<<endl<<endl;
		ifstream c("new.txt");
		char str[200];
		cout<<"\n------------------------------------------------------------------------------"<<endl;
		cout <<"\nCAR NAME\t\t\tMODEL YEAR\tSEATING CAPACITY    AMOUNT/DAY" <<endl<<endl;
		cout<<"------------------------------------------------------------------------------"<<endl;
		while(c)
		{
		 c.getline(str,200);
        if(c) cout<<str<<endl;
		}
		cout<<"\n\n------------------------------------------------------------------------------"<<endl;
		  int f;
		cout<<"\n\nFILTER - 1 :\n\n ELSE ENTER KEY EXCEPT 1   :  ";
		cin>>f;
		if(f==1)
		{   system("cls");
			int seat;
			char cars[200];
			cout<<"\n\nFIVE SEATER - PRESS 5\n\nSEVEN SEATER - PRESS 7 : ";
			cin>>seat;
			system("cls");
			cout<<"\n----------------------------------------------------------------------------"<<endl;
				cout <<"\n\nCAR NAME\t\t\tMODEL YEAR\tSEATING CAPACITY    AMOUNT/DAY" <<endl<<endl;
				cout<<"------------------------------------------------------------------------------"<<endl;
			if(seat==5)
			{
				ifstream f5("5seater.txt");
				while(!f5.eof()){
				    f5.getline(cars,200);
				    cout<<cars<<endl;
				}
			}
			else
			{
				ifstream f7("7seater.txt");
				while(!f7.eof()){
				    f7.getline(cars,200);
				    cout<<cars<<endl;

			}

		}
	}
    	cout<<"------------------------------------------------------------------------------"<<endl;
		int ch=0;
	cout<<"\n\nPLEASE SELECT SERIAL NUMBER OF CAR THAT YOU WANT ON RENT :  ";
    cin >> carnumber;
	cout<<"\n\nDO YOU WANT DRIVER \n\n\tENTER 1(yes) OR 2(no)   :  ";
	cin>>d;
    cout<<"\n\n------------------------------------------------------------------------------"<<endl;
	cout << "\n\nENTER YOUR NAME : "; //taking data from the user
    cin >> customername;
	cout<<"\n\nENTER YOUR MOBILE NUMBER : ";
     cin >>customernumber;
    cout<<"\n\nNUMBER OF DAYS YOU WANT CAR ON RENT : ";
    cin >> days;
    cout<<endl;
	}


void calculate()
	{
		system ("CLS");
		
  	  cout<<"\n\n------------------------------------------------------------------------------"<<endl;
		cout<<"\n\n CALCULATING RENT. . . \n\n\n\t P l e a s e    W a i t . . . . . ."<<endl;
 	   cout<<"\n\n------------------------------------------------------------------------------"<<endl;
		sleep(2);
		if(carnumber ==2 ||carnumber == 4||carnumber == 5||carnumber ==6 ||carnumber ==7||carnumber == 9||carnumber ==10 )
      {
        rentalfee=days*500;
		if(d==1)
		{
			rentalfee+=days*300;
		}
		 }
        if(carnumber ==1||carnumber==3||carnumber ==8||carnumber ==11||carnumber ==12|| carnumber ==13)
       { rentalfee=days*1000;
	     	if(d==1)
		{
			rentalfee+=days*300;
		}
	     }
	       ofstream o("rented car datails.txt",ios::app);
    o<<carnumber<<"\t\t\t"<<customername<<"\t\t\t"<<days<<"\t\t"<<rentalfee<<"\t\t"<<customernumber<<endl;
    }


void showrent()
    {
    	system("cls");
    cout << "\n\n\n\t	==========================================================="<<endl;
    cout << "\n\t\t              Car Rental - Customer Invoice                  "<<endl;
    cout << "\n\n\t	==========================================================="<<endl;
    cout << "\n\t	| Invoice No. :"<<"------------------|"<<setw(10)<<"#Cnb81353"<<" |"<<endl;
    cout << "\t	| Customer Name:"<<"-----------------|"<<setw(10)<<customername<<" |"<<endl;
    cout << "\t	| Customer number :"<<"--------------|"<<setw(10)<<customernumber<<" |"<<endl;
    cout << "\t	| Car No. :"<<"----------------------|"<<setw(10)<<carnumber<<" |"<<endl;
    cout << "\t	| Number of days :"<<"---------------|"<<setw(10)<<days<<" |"<<endl;
    cout << "\t	| Your Rental Amount is :"<<"--------|"<<setw(10)<<rentalfee<<" |"<<endl;
    cout << "\t	| Caution Money :"<<"----------------|"<<setw(10)<<"0"<<" |"<<endl;
    cout << "\t	| Advanced :"<<"---------------------|"<<setw(10)<<"0"<<" |"<<endl;
    cout << "\n\t	_________________________________________________________"<<endl;
    cout <<"\n";
    cout << "\t	| Total Rental Amount is :"<<"-------|"<<setw(10)<<rentalfee<<" |"<<endl;
    cout << "\n\t	_________________________________________________________"<<endl;
    cout << "\n\t	 #  This is a computer generated invoce and it does not"<<endl;
    cout << "\t	  require an authorised signture #"<<endl;
    cout <<" "<<endl;
    cout << "\n\t	==========================================================="<<endl;
    cout << "\n\t	 You are advised to pay up the amount before due date."<<endl;
    cout << "\t	 Otherwise penelty fee will be applied"<<endl;
    cout << "\n\t	===========================================================\n\n\n"<<endl;
    int f;
    system("PAUSE");
	

    system ("CLS");

     ifstream inf("thanks.txt");


  char str[300];
  cout<<"\n--------------------------------------------------------------------------------"<<endl;

  while(inf) {
    inf.getline(str, 300);
    if(inf) cout << str << endl;
  }
  inf.close();
	cout<<"\n--------------------------------------------------------------------------------"<<endl;
	}
};



class welcome //welcome class
{
	public:
	int welcum()
	{
 ifstream in("welcome.txt"); //displaying welcome ASCII image text on output screen fn1353

  if(!in) {
    cout << "Cannot open input file.\n";
  }
  char str[1000];
	cout<<"\n--------------------------------------------------------------------------------"<<endl;
  while(in) {
    in.getline(str, 1000);  // delim defaults to '\n' cp
    if(in) cout << str << endl;
  }
  in.close();
	cout<<"\n--------------------------------------------------------------------------------"<<endl;
  sleep(2);
  cout<<"\n\nStarting the program please wait....."<<endl;
  sleep(1);
  cout<<"\n\nloading up files.....\n\n\n"<<endl;
  sleep(2); //function which waits for (n) seconds
  system("PAUSE");
  system ("CLS"); //cleares screen

}

};



int main()
{
	int l=0;
	welcome obj1; //object created for welcome class
	obj1.welcum(); //welcum function is called
	rent obj2;
	l=login(l);
	if(l==0)
	{
		exit(0);
	}
	again:
	//object created for rent class and further member functions are called
	obj2.data();
	int s;
	cout<<"--------------------------------------------------------------------------------"<<endl;
	cout<<"\n\nARE YOU SURE TO PROCEED TOWARDS PAYMENT CALCULATION THEN PRESS 1 "<<endl;
	cout<<"\n\nELSE PRESS ANY KEY TO EXIT  : ";
	cin>>s;
	if(s==1)
	{
	obj2.calculate();
	obj2.showrent();
	int z;
	cout<<"\n\nDO YOU WANT TO CONTINUE IF YES PRESS 1 ELSE 0 : ";
	cin>>z;
	if(z==1)
	{
		system("cls");
	    goto again;

	}
	}

return 0; //end of the program
}



int login(int l)
{
	int count=0;
	L:
	string username,pass;
	int ch;
	cout<<"\n--------------------------------------------------------------------------------"<<endl;
	cout<<"\n\t\t\t  LOGIN  "<<"\t   "<<"   REGISTER  "<<endl<<endl;
	cout<<"\n--------------------------------------------------------------------------------"<<endl;
	cout<<"\n\n\tEnter 1 - LOGIN"<<endl<<"\n\n\tEnter 2 - REGISTRATION "<<endl<<"\n\n\nENTER CHOICE  :  ";
	cin>>ch;

	if(ch==1 && l==0)
	{  
		L1:
		char us1[100],ps1[100],us[20],ps[20];
		system("cls");
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"\n\t\t\t<<------- L O G I N ------->> ";
		cout<<"\n\n--------------------------------------------------------------------------------"<<endl;
		cout<<endl<<"\n\nEnter username : ";
		cin>>us1;
		cout<<"\n\nEnter password : ";
		cin>>ps1;
		ifstream f2("login.txt",ios::in);
		while(!f2.eof())
		{
		     	f2>>us>>ps;
		    if(strcmp(us,us1)==0 && strcmp(ps,ps1)==0)
			{
		     l=1;
			cout<<endl<<"\n\n\nSUCCESSFULLY ENTERED .......";
			sleep(1);
			break;
		   }

		   }
		 if(l==0)
		{
			count++;
			cout<<"\n\nINVALID DETAILS ...\n\nTRY AGAIN....";
			sleep(1);
			system("cls");
			if(count==3)
			{
				return l;
			}
			goto L;
	    	}
	    	system("CLS");
     	}

	else
	{
		string mo_num,proof;
		system("cls");
	cout<<"\n--------------------------------------------------------------------------------"<<endl;
	cout<<"\n\t\t\t<<------- R E G I S T E R ------->> ";
	cout<<"\n\n--------------------------------------------------------------------------------"<<endl;
	
		cout<<endl<<"\n\n Creat Username : ";
		cin>>username;
		cout<<endl<<"\n\n Creat Password : ";
		cin>>pass;
		ofstream f("login.txt",ios::app);
		f<<username<<" "<<pass<<endl;
		cout<<endl<<"\n\n Enter Mobile No : ";
		cin>>mo_num;
		cout<<endl<<"\n\n Enter Identity Proof (AAdhar num ) :";
		cin>>proof;
		cout<<"\n\n NOW YOU CAN LOGIN WITH YOUR USERNAME AND PASSWORD . . . .";
		sleep(2);
		system("CLS");
		goto L1;

	}   return l;
}

