#pragma once
#include<iostream>
#include<string>
#include"Employee.h"




class TechEmp :public Employee
{
	friend class EmpManager;
public:
	TechEmp(int id, string name, int sex, string tel, int dept, double sal)
	{
		this->E_id = id;
		this->E_name = name;
		this->E_sex = sex;
		this->E_tel = tel;
		this->E_dept = dept;
		this->E_sal = sal;
	}
	virtual string getDeptName();
};
string TechEmp::getDeptName()
{
	return "ºº ı";
}
