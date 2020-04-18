#include<iostream>
#include<fstream>
#include<string>
#include <conio.h>
#include <set>
#include<vector>
#include <sstream> 
#include"user.h"

void user::show1()
{
system("cls");
cout<<"1-You want to make a reserve "<<endl;
cout<<"2-You want to cancel a reserve "<<endl;
int choice ;
cout<<"Enter Your Choice : "<<endl;
   while(true)
   {
	   cin>>choice;
      if(choice==1)
	  {
	    reserve();
		break;
	  }
	  else if(choice==2)
	  {
		  cancel();
		  break;
	  }
	  else  
	   {
		   	cout<<"Enter the correct choice , please \n";
	   }
	  
   }

}
void user::Register()
{
 ofstream db("Register.txt",ios::app);

 cout<<"Enter Your Name : "<<endl;
 cin>>name;
 cout<<"Enter Your Password : "<<endl;
 cin>>password;
 cout<<"Enter Your Email : "<<endl;
 cin>>email;
 cout<<"Enter Your Phone_Number : "<<endl;
 cin>>phone_number;
 cout<<"Enter Your Age : "<<endl;
 cin>>age;
 cout<<"Enter Your District: "<<endl;
 cin>>district;

  ifstream dbb;
	dbb.open("Register.txt");
	string u_name,u_pass,u_email,u_phone,u_age,u_district;
	bool flag=0;
	dbb>>u_name>>u_pass>>u_email>>u_phone>>u_age>>u_district;
	while(dbb.good())
	{				
		if(u_name==name){
				system("cls");
			cout<<"Please Enter another name , please "<<endl;
	       Register();
		}
	dbb>>u_name>>u_pass>>u_email>>u_phone>>u_age>>u_district;
	}
	dbb.close();
db<<name<<" ";
db<<password<<" ";
db<<email<<" ";
db<<phone_number<<" ";
db<<age<<" ";
db<<district<<endl;

 db.close();

 show1();
}

void user::login()
{

cout<<endl<<"Enter Your login_Name : "<<endl;
cin>>loingname;
string pass;
char ch;
 cout<<"Enter Your login_password : "<<endl; 
  ch =_getch();
  while(ch!='\r')
  {
  cout<<"*";
  loginpassword.push_back(ch);
	  ch=_getch();
  }
  cout<<endl;

  ifstream db;
	db.open("Register.txt");
	string u_name,u_pass,u_email,u_phone,u_age,u_district;
	bool flag=0 ;
	db>>u_name>>u_pass>>u_email>>u_phone>>u_age>>u_district;
	while(db.good())
	{			
		if(u_name==loingname)
		{
				if(u_pass==loginpassword)
				{
				    flag=0;
					show1();
					break;
				}
				else
				{
						cout<<"incorrect Password!"<<endl;
						//login();
						flag=0;
						break;
						
				}
		
		}
			else
			{
				flag=1;
			}
		
	db>>u_name>>u_pass>>u_email>>u_phone>>u_age>>u_district;
	
	}
	db.close();
		if(flag)
			{
				cout<<"incorrect name!"<<endl;
				login();
			}

}

string user::max_patient(string doc_name,int kind)
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
void user::reserve()
{
	system("cls");
	ifstream text,search;
	string doc_specialization,choice_specialization,doc_n,doc_v,doc_t,doc_p;
    set<string>st;
    vector<string>vec;
   int choice,choice2,choice3;
   text.open("doctor_inf.txt");
   search.open("doctor_inf.txt");
   text>>doc_specialization>>doc_n>>doc_v>>doc_t>>doc_p; //5ad awl satr fe el file 
   while(text.good())
   {	   
	       st.insert(doc_specialization);
	   
	        text>>doc_specialization>>doc_n>>doc_v>>doc_t>>doc_p;
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

   string doc_sp,doc_name,doc_vez,doc_time,doc_pass,doc_count; 
   search>>doc_sp>>doc_name>>doc_vez>>doc_time>>doc_pass;

   doctor_inf d;

   vector<doctor_inf>doc_inf_vec;
   choice_specialization=vec[choice-1]; 
   while(search.good())
   {   
	   if(doc_sp==choice_specialization) 
	   {
		   d.doctor_spe=doc_sp;
		   d.doctor_name=doc_name;
		   d.doctor_vezeta=doc_vez;
		   d.doctor_time=doc_time;
		   d.doctor_pass=doc_pass;

		   d.count=max_patient(d.doctor_name,1); 

		   doc_inf_vec.push_back(d);
	   }   
      search>>doc_sp>>doc_name>>doc_vez>>doc_time>>doc_pass;
   }
 

      cout<<"which doctor do you want?\n";
      for(int i=0;i<doc_inf_vec.size();i++)
	  {
	   cout<<i+1<<"-Doctor name:"<<doc_inf_vec[i].doctor_name<<"\n"<<"Doctor vezeeta:"<<doc_inf_vec[i].doctor_vezeta<<"\n"<<"Doctor  Appointment:"<<doc_inf_vec[i].doctor_time<<"\n"<<"Number of customers: "<<doc_inf_vec[i].count<<endl;
	   cout<<"**************************************************"<<endl;
      }
      cout<<endl<<"Please Enter Number of Doctor You have chosen : "<<endl;
	 
	  while(true)
	  { 
	  cin>>choice3;
	  if(choice3>doc_inf_vec.size()||choice3<1)
	  {cout<<"Error Choice Enter again "<<endl;}
	  else break;
	  }

	  system("cls");
	  ifstream r;
	  r.open("reserve");
	  string n,id,age,t,d_n,s,c;
	  int count =0;
	  r>>n>>id>>age>>t>>d_n>>s>>c;
	  while(r.good()){
	  if(d_n==doc_inf_vec[choice3-1].doctor_name)
		  count++;
	  r>>n>>id>>age>>t>>d_n>>s>>c;
	  
	  }

	  if(count>15){
	  cout<<"Sorry this Doctor Complete "<<endl;
	  cout<<"1-End Program"<<endl;
	  cout<<"2-Choose another Doctor"<<endl;
	  cout<<"Enter choise"<<endl;
	  while(true){
	  int x;
	  cin>>x;
	  if(x==1)exit(0);
	  else if(x==2)reserve();
	  else cout<<"Enter right Choice"<<endl;}

	  }
	  else{
		   string patient_name,patient_age,patient_gender,patient_National_ID;
	   cout<<"Enter name of The Patient :  \n";
	   cin>>patient_name;  cout<<endl;

	   cout<<"Enter National_ID of The Patient :  \n";
	   cin>>patient_National_ID; cout<<endl;

	   cout<<"Enter age of The Patient :  \n";
	   cin>>patient_age; cout<<endl;

	   cout<<"Enter gender of The Patient male/female  \n";
	   cin>>patient_gender; cout<<endl;

	   	   cout<<"Are you Sure you want to Reserve at Doctor "<<doc_inf_vec[choice3-1].doctor_name <<" yes/no? "<<endl;
	   string choice4;
	   
	   while(true)
	   {
	       cin>>choice4; cout<<endl;
	      if(choice4=="no"||choice4=="NO")
	       {
		   show1();	 
		   break;
	       }
	      else if(choice4=="yes"||choice4=="YES")
	      {
			 system("cls");
	        ofstream text;
	        text.open("reserve", ios::app);
	        string strr=max_patient(doc_inf_vec[(choice3)-1].doctor_name,0);
	        text<<patient_name<<" "<<patient_National_ID<<" "<<patient_age<<" "<<patient_gender<<" "<<doc_inf_vec[choice3-1].doctor_name<<" "<<doc_inf_vec[choice3-1].doctor_spe<<" "<<strr<<"\n";
	        text.close();
	        cout<<"Your Reservation has been successful "<<endl<<"Thank You"<<endl;
	        cout<<"your patient_numbr is : "<<atoi( strr.c_str() )<<endl;
			break;
		  }
		  else 
	       {
		   cout<<"Enter (yes) or (YES) if you want to reserve , else Enter (no) or (NO) "<<endl;
           }
	   }
	  }
}
void user::cancel()
{
	 system("cls");
  ifstream x;
  x.open("reserve");
  string p_name , p_id , p_age , p_gender , p_drname , p_drspec , p_no;
  x>>p_name >> p_id >> p_age >> p_gender >> p_drname >> p_drspec >> p_no;
  patient_inf  p;
  vector<patient_inf>patient_inf_vec;
  vector<patient_inf>reservation_vec;
  while(x.good())
  {
		   p.patient_name=p_name;
	       p.patient_nationalid= p_id; 
	       p.patient_age=p_age ; 
	       p.patient_gender =p_gender;
	       p.patient_doc =p_drname;
	       p.patient_doc_spec =p_drspec ;
	       p.patient_num =p_no;
		   patient_inf_vec.push_back(p);
		   
		    x>>p_name>>p_id>>p_age>>p_gender>>p_drname>>p_drspec>>p_no;
		   
	
  }
  x.close();
  
   string cancel_name , cancel_patientid , cancel_drname ;
   cout<<"Enter patient name to cancel reservation, please : "<<endl;cin>>cancel_name;
   cout<<"Enter patient Nationanal_Number to cancel reservation, please : "<<endl;cin>>cancel_patientid ;
   cout<<"Enter Doctor_Name to cancel reservation, please : "<<endl;cin>>cancel_drname;
   bool b=0;
  for(int i=0 ; i<patient_inf_vec.size() ; i++)
  {
	   if(patient_inf_vec[i].patient_nationalid==cancel_patientid && patient_inf_vec[i].patient_name==cancel_name && patient_inf_vec[i].patient_doc==cancel_drname)
	   {
		   patient_inf_vec.erase(patient_inf_vec.begin()+i);

		   remove("reserve");

		   ofstream txt;
		   txt.open("reserve",ios::app);
		   for(int j=0 ; j<patient_inf_vec.size() ; j++)
		   txt<<patient_inf_vec[j].patient_name<<" "<<patient_inf_vec[j].patient_nationalid<<" "<<patient_inf_vec[j].patient_age<<" "<<patient_inf_vec[j].patient_gender<<" "<<patient_inf_vec[j].patient_doc<<" "<<patient_inf_vec[j].patient_doc_spec<<" "<<patient_inf_vec[j].patient_num<<endl;
		   txt.close();

	  b=1;
	   }
	  
   }
  
 if(b==1)
 {
	 system("cls");
  cout<<"Your reservation has been successfully canceled"<<endl;
}
 else if(b==0){
 cout<<"Sorry We can't find reservation with this information "<<endl;
 cout<<"1-End Program "<<endl;
 cout<<"2-Try again"<<endl;
 int x;
 while(true){
 cout<<"Enter Your Choice   "; cin>>x;
 if(x==1)exit(0);
 else if (x==2) cancel();
 }
 }

}