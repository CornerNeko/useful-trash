#pragma once
#include<iostream>
#include<string>
#include"Employee.h"


class FinEmp :public Employee
{
	friend class EmpManager;
public:
	FinEmp(int id, string name, int sex, string tel, int dept, double sal);
	virtual string getDeptName();
};
FinEmp::FinEmp(int id, string name, int sex, string tel, int dept, double sal)
{
	this->E_id = id;
	this->E_name = name;
	this->E_sex = sex;
	this->E_tel = tel;
	this->E_dept = dept;
	this->E_sal = sal;
}
string FinEmp::getDeptName()
{
	return "²ÆÎñ";
}
