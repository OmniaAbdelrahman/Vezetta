#include <conio.h>
#include<sstream>
#include<vector>
#include<assert.h>
#include<queue>
#include<stack>
#include "doctor.h"
#include "user.h"
void doctor::login_doctor()
{
	ifstream doctor_inf;
	doctor_inf.open("doctor_inf.txt");
	string name,pass,Specialization,Appointment,price,count;
	
	cout<<"Enter doctor name : \n";
	cin>>doctor_name;
	cout<<"Enter doctor password : \n";
	char ch=_getch();
	bool check=0;
	while(ch!='\r')
	{
		cout<<"*";
		doctor_pass.push_back(ch);
		ch=_getch();
	}
	cout<<endl;

	doctor_inf>>Specialization>>name>>price>>Appointment>>pass;
	
	while (doctor_inf.good())
	{
		if(name==doctor_name)
		{
			if(pass==doctor_pass)
			{
				
			    check=0;
				cout<<"1-View all appointments"<<endl;
				cout<<"2-Start exmaination"<<endl;
				cout<<"Enter Choice"<<endl;
				while(true){
				int x;
				cin>>x;
				if(x==1){all_reserve();}
				else if(x==2){examine();}
				else cout<<"Enter right choice"<<endl;
				
				}
				break;
			}
			else
			{
				cout<<"Incorrect password!\n";
				login_doctor();
				check=0;
				break;
			}
		}
		else
		{
			check=1;
		}
		
		
		doctor_inf>>Specialization>>name>>price>>Appointment>>pass;
	}
	doctor_inf.close();
	if(check)
		{
			system("cls");
			cout<<"Incorrect name!\n";
			login_doctor();
		}
	
	
	
}

void doctor::all_reserve(){
string patient_name,patient_id,patient_age,patient_gender,doc_name,doc_Specialization,patient_number;
vector<patient_in>pa_in_vec;
patient_in patient;
ifstream patient_inf;
	patient_inf.open("reserve");
	patient_inf>>patient_name>>patient_id>>patient_age>>patient_gender>>doc_name>>doc_Specialization>>patient_number;
	while (patient_inf.good())
	{
		
		if(doc_name==doctor_name)
		{
			patient.pa_name=patient_name;
			patient.pa_id=patient_id;
			patient.pa_age=patient_age;
			patient.pa_gender=patient_gender;
			patient.pa_number=patient_number;

			pa_in_vec.push_back(patient);
			 
		}

		patient_inf>>patient_name>>patient_id>>patient_age>>patient_gender>>doc_name>>doc_Specialization>>patient_number;
	}
	patient_inf.close();
		       for(int i=0;i<pa_in_vec.size();i++)
			{
				cout<<"patient name : "<<pa_in_vec[i].pa_name<<endl;
				cout<<"Patient national ID : "<<pa_in_vec[i].pa_id<<endl;
				cout<<"Patient age : "<<pa_in_vec[i].pa_age<<endl;
				cout<<"Patient gender : "<<pa_in_vec[i].pa_gender<<endl;
				cout<<"Patient number  : "<<pa_in_vec[i].pa_number<<endl;
			    cout<<"*************************************\n";
		    }
			   pa_in_vec.clear();
			 cout<<"1-Start examine"<<endl;
			 cout<<"2-end program"<<endl;
			 cout<<"Enter choice"<<endl;
			 while(true){
			 int x;
			 cin>>x;
			 if(x==1)examine();
			 else if(x==2)exit(0);
			 else cout<<"Enter right Choice"<<endl;
			 }


}


void doctor::examine()
{
	system("cls");
    string patient_name,patient_id,patient_age,patient_gender,doc_name,doc_Specialization,patient_number;
	queue<patient_in>q;
	string choice;
	bool a=0;
	patient_in patient;
	vector<patient_in>pa_in_vec;

	ifstream patient_inf_q,patient_inf_v;
	patient_inf_q.open("reserve");
	patient_inf_q>>patient_name>>patient_id>>patient_age>>patient_gender>>doc_name>>doc_Specialization>>patient_number;
	while (patient_inf_q.good())
	{
		if(doc_name==doctor_name)
		{
			patient.pa_name=patient_name;
			patient.pa_id=patient_id;
			patient.pa_age=patient_age;
			patient.pa_gender=patient_gender;
			patient.pa_number=patient_number;
			patient.doc=doc_name;
			patient.spe=doc_Specialization;

			q.push(patient);
			 
		}

		patient_inf_q>>patient_name>>patient_id>>patient_age>>patient_gender>>doc_name>>doc_Specialization>>patient_number;
	}
	patient_inf_q.close();


	patient_inf_v.open("reserve");
	patient_inf_v>>patient_name>>patient_id>>patient_age>>patient_gender>>doc_name>>doc_Specialization>>patient_number;
	while (patient_inf_v.good())
	{
		
		
			patient.pa_name=patient_name;
			patient.pa_id=patient_id;
			patient.pa_age=patient_age;
			patient.pa_gender=patient_gender;
			patient.pa_number=patient_number;
			patient.doc=doc_name;
			patient.spe=doc_Specialization;
			pa_in_vec.push_back(patient);			 
		

		patient_inf_v>>patient_name>>patient_id>>patient_age>>patient_gender>>doc_name>>doc_Specialization>>patient_number;
	}
	patient_inf_v.close();


	if(q.size()>0){
	cout<<"Current patient data"<<endl;
	cout<<"*****************************************************"<<endl;
	cout<<"patient name : "<<q.front().pa_name<<endl;
	cout<<"Patient age : "<<q.front().pa_age<<endl;
	cout<<"Patient gender : "<<q.front().pa_gender<<endl;
	cout<<"Patient number  : "<<q.front().pa_number<<endl;
	cout<<"****************************************************"<<endl;
	 cout<<"Next Patient /yes  "<<endl;
	}
	else {cout<<"No Patient"<<endl;  
	
	cout<<"Enter yes to close"<<endl;
	string x;
	cin>>x;
	exit(0);
	
	}
	while(true){
	string ch;
	cin>>ch;
	if(ch=="yes"){
		 for(int i=0 ; i<pa_in_vec.size() ; i++)
  {
	  if(pa_in_vec[i].pa_id==q.front().pa_id&&pa_in_vec[i].doc==q.front().doc)
	   {
		   pa_in_vec.erase(pa_in_vec.begin()+i);

		   remove("reserve");

		   ofstream txt;
		   txt.open("reserve",ios::app);
		   for(int j=0 ; j<pa_in_vec.size() ; j++)
			   txt<<pa_in_vec[j].pa_name<<" "<<pa_in_vec[j].pa_id<<" "<<pa_in_vec[j].pa_age<<" "<<pa_in_vec[j].pa_gender<<" "<<pa_in_vec[j].doc<<" "<<pa_in_vec[j].spe<<" "<<pa_in_vec[j].pa_number<<endl;
		   txt.close();

	   }
	  
   }
		q.pop();
		if(q.size()==0){cout<<"*********************Thanks No more patient*********************"<<endl;
		
		cout<<"Enter yes to close program"<<endl;
		string x;
		while(true){
		cin>>x;
		if(x=="yes")exit(0);
		else cout<<"Enter yes to close program"<<endl;
		
		}
		
		}

	
	
	
	examine();}
	else cout<<"Enter yes please" <<endl;
	
	}


	

	

	
	

	
}

