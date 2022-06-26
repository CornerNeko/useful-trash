#pragma once
#include<iostream>

#include<string>
using namespace std;
class EmpManager;

class Employee
{
	friend class EmpManager;
	friend class TechEmp;
	friend class SalEmp;
	friend class FinEmp;
public:
	void showInfo();
	virtual string getDeptName() = 0;
	string getSex();
private:
	int E_id;			//工号
	string E_name;		//名字
	int E_sex;			//性别
	string E_tel;		//电话
	int E_dept;			//科室编号
	double E_sal;		//工资

	Employee* E_head = NULL;
	Employee* E_tail = NULL;
};


void Employee::showInfo()
{
	cout << "工号: " << E_id << endl;
	cout << "姓名: " << E_name << endl;
	cout << "性别: " << getSex() << endl;
	cout << "电话: " << E_tel << endl;
	cout << "科室: " << getDeptName() << endl;
	cout << "工资: " << E_sal << endl;
}


string Employee::getSex()
{
	if (E_sex == 0)
		return "女";
	else if (E_sex == 1)
		return "男";
}
