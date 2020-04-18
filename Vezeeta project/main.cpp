#include <iostream>
#include<string>
#include "admin.h"
#include "user.h"
#include "doctor.h"
using namespace std ;

int main()
{
	admin admin;
	user user;
	doctor doctor;


	int choice;
     cout<<" 1-Admin"<<"\t"<<" 2-User "<<"\t"<<"3-Doctor "<<endl<<endl;
	 cout<<"Enter your choice , please "<<endl;
	 cin>>choice;
	 if(choice==1)admin.show();
	 else if(choice==2)
		 {
			 system("cls");
			 cout<<"1-register          2-login"<<endl;
			 int y;
			 while(true)
			 {
			  cout<<"Enter your choice , please "<<endl;
			  cin>>y;
			  if(y==1)
			  {
				  user.Register();
				  break;
			  }
			  else if(y==2)
			  {
			     user.login();
				 break;
			  }
			  else 
			  {
			    cout<<"please , choose 1 to register or 2 to login "<<endl;
			  }
			 }
	     }
	 else if(choice==3)doctor.login_doctor();
	system ("pause") ;
	return 0 ;
}