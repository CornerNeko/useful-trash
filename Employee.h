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
	int E_id;			//����
	string E_name;		//����
	int E_sex;			//�Ա�
	string E_tel;		//�绰
	int E_dept;			//���ұ��
	double E_sal;		//����

	Employee* E_head = NULL;
	Employee* E_tail = NULL;
};


void Employee::showInfo()
{
	cout << "����: " << E_id << endl;
	cout << "����: " << E_name << endl;
	cout << "�Ա�: " << getSex() << endl;
	cout << "�绰: " << E_tel << endl;
	cout << "����: " << getDeptName() << endl;
	cout << "����: " << E_sal << endl;
}


string Employee::getSex()
{
	if (E_sex == 0)
		return "Ů";
	else if (E_sex == 1)
		return "��";
}
