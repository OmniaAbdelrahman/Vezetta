#pragma once
#include <iostream>
#include <string>
using namespace std;
class admin
{

	string name,pass;
	struct doctor_inf
		{
		  string doctor_spe,doctor_name,doctor_vezeta,doctor_time,doctor_pass, count;
	    };
		
public:

	void login();
	void check(string name,string pass);
	void adddoctor();
	void view_all_appointment();
	void  view_appointment_of_a_doctor();
	string max_patient(string doc_name,int kind) ;
	void show() ;


};

