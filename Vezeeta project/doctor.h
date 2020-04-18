#pragma once
#include<iostream>
#include<fstream>
#include<string>

using namespace std;
class doctor
{
	string doctor_name,doctor_pass,doctor_Specialization;
	
public:
	struct patient_in
	{
		string pa_name,pa_id,pa_age,pa_gender,doc,spe,pa_number;
	};
	int count, size,front, back;	
	void login_doctor();
	void all_reserve();
	void examine();
};

