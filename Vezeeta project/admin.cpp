#include "admin.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <conio.h>
#include <vector>
#include<set>
#include <sstream> 
using namespace std;

void admin::check(string name,string pass)
{

	ifstream text;
	text.open("admin_inf.txt");
	string admin_name,admin_pass;
	text >> admin_name >>admin_pass;
	if(admin_name==name){
		if(admin_pass==pass)
		cout<<"Doneeeeee"<<endl;
		else {	system("cls"); cout<<"************incorrect Password****************"<<endl; login(); }
	
	}
	else{system("cls"); cout<<"******************incorrect name****************"<<endl; login(); }

}
string admin::max_patient(string doc_name,int kind)
{

	ifstream search;
	   search.open("reserve");
	   string p_name,p_national_id,p_age,p_gender,d_name,d_spe,p_counter;
	   int max_counter=0;
	   search >> p_name>>p_national_id>>p_age>>p_gender>>d_name>>d_spe>>p_counter;
	   while(search.good())
	   {
		
		   if(d_name==doc_name)
		   {
		     stringstream convert(p_counter);
		     int pa_counter;
		     convert>>pa_counter;
		     if(pa_counter>max_counter)
				 max_counter=pa_counter;

		   }
		  
		   	   search >> p_name>>p_national_id>>p_age>>p_gender>>d_name>>d_spe>>p_counter;	   
	   }
	 
	   search.close();
	   if(kind==0)
	   max_counter+=1;
	   	   string str=to_string(max_counter);

 return str;


}

void admin::login() {
	cout<<"Enter Your Name     :  ";
cin>>name;
cout<<"Enter your password     :   "; 

string pass;
char ch;
  ch = _getch();
  while(ch!='\r'){
  cout<<"*";
  pass.push_back(ch);
	  ch = _getch();
  }
check(name,pass);

}
void admin::adddoctor()
{
	ofstream text;
	ifstream check;
text.open("doctor_inf.txt", ios::app);
check.open("doctor_inf.txt");

string doctorname,specialization,vezeeta,appointment,doctorpass;
cout<<"Enter Doctor Name   :  "<<endl;
cin>>doctorname ;
cout<<"Enter Doctor Specialization   :  "<<endl;
cin>>specialization ;
cout<<"Enter Doctor Vezeeta   :  "<<endl;
cin>>vezeeta ;
cout<<"Enter Doctor Appointment   :  "<<endl;
cin>>appointment ;
cout<<"Enter Doctor Password   :  "<<endl;
cin>>doctorpass ;
string ch_spa,ch_name,ch_vez,ch_time,ch_pass;
bool b=0;
check>>ch_spa>>ch_name>>ch_vez>>ch_time>>ch_pass;
while(check.good()){
	if(doctorname==ch_name) {b=1; break;}
	check>>ch_spa>>ch_name>>ch_vez>>ch_time>>ch_pass;

}


if(b==0){
	text <<specialization<<" "<< doctorname<<" "<<vezeeta<<" "<<appointment<<" "<<doctorpass<<endl;  
	system("cls");
cout<<"***********You successfuly add doctor *************"<<endl;
	while(true){

		cout<<"1-End program "<<endl;
		cout<<"2-return to main page "<<endl;
		int x;
		cout<<"Enter Your Choice  :"<<endl;
		cin>>x;
		if(x==1)exit(0);
		if(x==2)show();
		else cout<<"Error Choice";
		}

}

if(b==1){system("cls"); cout<<"Enter Another Name "<<endl; adddoctor();  }
text.close();
}



void admin::view_all_appointment()
{
	ifstream search;
	   search.open("reserve");
	   
	string p_name,p_national_id,p_age,p_gender,d_name,d_spe,p_counter;
	search >> p_name>>p_national_id>>p_age>>p_gender>>d_name>>d_spe>>p_counter;
	cout<<endl;
	while(search.good())
	{
	cout<<"Patient name : "<<p_name<<endl;
	cout<<"Patient national ID : "<<p_national_id<<endl;
	cout<<"Patient age : "<<p_age<<endl;
	cout<<"Patient gender : "<<p_gender<<endl;
	cout<<"Doctor name  : "<<d_name<<endl;
	cout<<"Specialization : "<<d_spe<<endl;
	cout<<"Patient counter : "<<p_counter<<endl;
	cout<<"***************************************************************"<<endl;
     search >> p_name>>p_national_id>>p_age>>p_gender>>d_name>>d_spe>>p_counter;

	}
	search.close();

}

void  admin :: view_appointment_of_a_doctor()
{
	system("cls");
	ifstream text,search ;
	string doc_specialization,choice_specialization,doc_name,doc_vez,doc_time,doc_pass;
    set<string>st;
    vector<string>vec;
   int choice,choice2,choice3;
   text.open("doctor_inf.txt");
   search.open("doctor_inf.txt");
   text>>doc_specialization>>doc_name>>doc_vez>>doc_time>>doc_pass; 
   
   while(text.good())
   {
	       st.insert(doc_specialization);
	   
	       text>>doc_specialization>>doc_name>>doc_vez>>doc_time>>doc_pass; 

   }
      cout<<"which specialization do you want?\n";
	   int i=1;
   for(set<string>::iterator it=st.begin() ; it!=st.end() ; it++)
   {
	   vec.push_back(*it);
	   cout<<i<<"-"<<*it<<endl;
	   i++;
   }
   cout<<endl<<"Please Enter Number of Your Choice   : "<<endl;
   while(true)
   {
	   cin>>choice;
	   if(choice>vec.size()||choice<1)
		   cout<<"Enter the correct choice , please \n";
	   else
		   break;
   }

   system("cls");
   string doc_sp,doc_names,doc_vezs,doc_times,doc_passs; 
   search>>doc_sp>>doc_names>>doc_vezs>>doc_times>>doc_passs;

   doctor_inf d;
   vector<doctor_inf>doc_inf_vec ;
   choice_specialization=vec[choice-1]; 
   while(search.good())
   {   
	   if(doc_sp==choice_specialization) 
	   {
		   d.doctor_spe=doc_sp ;
		   d.doctor_name=doc_names ;
		   d.doctor_vezeta=doc_vezs;
		   d.doctor_time=doc_times ;
		   d.doctor_pass=doc_passs ;

		   d.count=max_patient(d.doctor_name,1); 

		   doc_inf_vec.push_back(d);
	   }   
      search>>doc_sp>>doc_names>>doc_vezs>>doc_times>>doc_passs;
   }
 
   
      cout<<"which doctor do you want?\n";
      for(int i=0;i<doc_inf_vec.size();i++)
	  {
	   cout<<i+1<<"-Doctor name:"<<doc_inf_vec[i].doctor_name<<"\n" ;
		      
      }
	  text.close();
	  search.close();
	int k ;
	cout<<"Enter Number of Your Choice  : "<<endl;
	while(true)
	{
	cin>>k;
	if(k>=1&&k<=doc_inf_vec.size()) break;
	else cout<<"Enter Your Choice Again "<<endl;
	} 
		ifstream patient ;
		patient.open("reserve");
		string p_namee,p_nid,p_age,p_t,p_doc,p_spe,p_num;
		patient>>p_namee>>p_nid>>p_age>>p_t>>p_doc>>p_spe>>p_num;
		int cntr=0 ,mx=0;
		cout<<endl;
		while(patient.good())
		{
			if(choice_specialization==p_spe&&doc_inf_vec[k-1].doctor_name==p_doc)
			{

			cout<<"Patient name : "<<p_namee<<endl;
	        cout<<"Patient national ID : "<<p_nid<<endl;
	        cout<<"Patient age : "<<p_age<<endl;
	        cout<<"Patient gender : "<<p_t<<endl;
	        cout<<"Patient Number : "<<p_num<<endl;
	        cout<<"***************************************************************"<<endl;
			cntr++;
			}
	
					patient>>p_namee>>p_nid>>p_age>>p_t>>p_doc>>p_spe>>p_num;
		}

		if(cntr==0)
		{
          cout<<"this doctor have no reservation yet ! "<<endl<<endl ;
		}
		cout<<"***************************************************************"<<endl<<endl ;
		cout<<"1-End program "<<endl;
		cout<<"2-return to main page "<<endl;
		while(true)
		{
		int x;
		cout<<"Enter Your Choice  :"<<endl;
		cin>>x;
		if(x==1)exit(0);
		if(x==2)show();
		else cout<<"Error Choice!"<<endl;
		}
	  
}

void admin::show()
{
system("cls");
cout<<"1-You want to add a doctor "<<endl;
cout<<"2-You want to know your doctor's appointment "<<endl;
cout<<"3-You want to view_all_appointment of doctors "<<endl;

int choice ;
cout<<"Enter Your Choice : "<<endl;
   while(true)
   {
	   cin>>choice;
      if(choice==1)
	  {
		adddoctor();
		break;
	  }
	  else if(choice==2)
	  {
		  view_appointment_of_a_doctor();
		  break;
	  }
	  else if (choice==3)
	  {
		  view_all_appointment() ;
		  break ;
	  }
	  else  
	   {
		   	cout<<"Enter the correct choice , please \n";
	   }
	  
   }

}




