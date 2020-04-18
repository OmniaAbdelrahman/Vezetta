#include<iostream>
#include<fstream>
#include<string>

using namespace std;
class user 
{
	    string name,email,phone_number,password,age,district;
		string loingname , loginpassword ;
		struct doctor_inf
		{
		  string doctor_spe,doctor_name,doctor_vezeta,doctor_time,doctor_pass , count;
	    };
		struct patient_inf
		{
			string patient_name , patient_nationalid , patient_age , patient_gender , patient_doc , patient_doc_spec , patient_num ;
			string clp_name ,clp_id , clp_age , cl_gender , cl_drname , cl_drspec , clp_no;
		};
		
public:
	void Register();
	void login();
	void reserve ();
	void cancel();
	void show1();
	string max_patient(string doc_name,int kind);
};