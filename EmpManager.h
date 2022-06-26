#pragma once
#include<iostream>
#include<string>
using namespace std;

class Employee;
class TechEmp;
class SalEmp;
class FinEmp;

class EmpManager
{
public:
	EmpManager()
	{
		ifstream ifs;
		ifs.open("emp.txt", ios::in);

		if (!ifs.is_open())
		{
			cout << "�ļ������ڣ��޷�����ְ����Ϣ��" << endl;

			E_Num = 0;
			H = NULL;
			T = NULL;
			E_Head = NULL;
			empfile = true;
			ifs.close();
			return;
		}
		char ch;
		ifs >> ch;
		if (ifs.eof())
		{
			cout << "�ļ�Ϊ��" << endl;
			E_Num = 0;
			H = NULL;
			T = NULL;
			E_Head = NULL;
			empfile = true;
			ifs.close();
			return;
		}
		E_Num = get_empNum();
		cout << "ְ������Ϊ" << E_Num << "��" << endl;
		init_emp();
	}

	int get_empNum();		//��ȡ�ļ���Ա������
	void init_emp();		//�����ļ��е���Ϣ��ʼ��Ա��

	void Main_Menu();		//��ʾ�˵�����

	void AddEmployee();		//������Ա��
	void show();			//��ʾ����ְ����Ϣ

	int IsExist(int id);	//�ж�����Ա���Ƿ����
	int IsExist(string name);

	void DeleteEmployee();	//ɾ��Ա����Ϣ

	void UpdateEmployee();	//�޸�Ա����Ϣ

	void reseachStudentByName();	//�����ֲ���Ա����Ϣ

	void reseachStudentByOffice();	//�����Ҳ���Ա����Ϣ

	void saveinfo();			//����ͬ������

	void add();			//���������ƽ������

	void Exit();		//�˳�����

	int E_Num = 0;

	bool empfile;

	Employee* H = NULL;
	Employee* T = NULL;
	Employee* E_Head = NULL;

};


void EmpManager::Main_Menu()
{
	cout << "****************************" << endl;
	cout << "****************************" << endl;
	cout << "****************************" << endl;
	cout << "��ӭʹ�ù�˾Ա����Ϣ����ϵͳ" << endl;
	cout << "0.�˳�ְ������ϵͳ" << endl;
	cout << "1.���ְ����Ϣ" << endl;
	cout << "2.ɾ��ְ����Ϣ" << endl;
	cout << "3.�޸�ְ����Ϣ" << endl;
	cout << "4.���ֲ�ѯְ����Ϣ" << endl;
	cout << "5.���Ҳ�ѯְ����Ϣ" << endl;
	cout << "6.������ͳ��ְ��ƽ������" << endl;
	cout << "7.��ʾְ����Ϣ" << endl;
	cout << "��ѡ��" << endl;
}

void EmpManager::Exit()
{
	int t;
	cout << "�Ƿ�ȷ���˳���" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;
	while (true)
	{
		cin >> t;
		if (t == 1)
		{
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			exit(0);
		}
		else if (t == 2)
		{
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "������ѡ��" << endl;
			break;
		}

	}
	system("pause");
	system("cls");
}

void EmpManager::AddEmployee()
{
	system("cls");
	int id;
	string name;
	int sex;
	string tel;
	int dept;
	double sal;
	cout << "����������Ա������" << endl;
	int aNum = 0;
	cin >> aNum;
	int t;
	t = aNum;

	for (; t != 0; t--)
	{
		cout << "�����빤��" << endl;
		cin >> id;
		system("cls");
		cout << "����������" << endl;
		cin >> name;
		system("cls");
		cout << "�������Ա�" << endl;
		cout << "0ΪŮ" << endl;
		cout << "1Ϊ��" << endl;
		cin >> sex;
		system("cls");
		cout << "������绰" << endl;
		cin >> tel;
		system("cls");
		cout << "���������" << endl;
		cout << "0Ϊ����" << endl;
		cout << "1Ϊ����" << endl;
		cout << "2Ϊ����" << endl;
		cin >> dept;
		system("cls");
		cout << "�����빤��" << endl;
		cin >> sal;
		system("cls");
		if (dept == 0)
			H = new TechEmp(id, name, sex, tel, dept, sal);
		else if (dept == 1)
			H = new SalEmp(id, name, sex, tel, dept, sal);
		else if (dept == 2)
			H = new FinEmp(id, name, sex, tel, dept, sal);
		if (E_Num == 0)
		{
			E_Head = H;
			T = H;
		}
		else
		{
			T->E_tail = H;
			T = H;
		}
		E_Num = E_Num + aNum;
	}
	saveinfo();
	cout << "�ɹ����" << aNum << "��ְ��" << endl;
	empfile = false;
	system("pause");

}

void EmpManager::show()
{
	H = E_Head;
	if (H == NULL)
	{
		cout << "��Ա����Ϣ��" << endl;
		system("pause");
		system("cls");
		return;
	}
	do {
		H->showInfo();
		H = H->E_tail;
	} while (H != NULL);
	system("pause");
	system("cls");
}

void EmpManager::saveinfo()
{
	ofstream ofs;
	ofs.open("emp.txt", ios::out);
	for (H = E_Head; H != NULL; H = H->E_tail)
	{
		ofs << H->E_id << "\t" << H->E_name << "\t"
			<< H->E_sex << "\t"
			<< H->E_tel << "\t"
			<< H->E_dept << "\t"
			<< H->E_sal << endl;
	}
	ofs.close();
}


int EmpManager::get_empNum()
{
	ifstream ifs;
	ifs.open("emp.txt", ios::in);
	int id;
	string name;
	int sex;
	string tel;
	int dept;
	double sal;
	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> sex && ifs >> tel && ifs >> dept && ifs >> sal)
	{
		num++;
	}
	ifs.close();
	return num;

}

void EmpManager::init_emp()
{
	int num = 0;
	int id;
	string name;
	int sex;
	string tel;
	int dept;
	double sal;
	int aNum = E_Num;
	int t;
	t = aNum;

	ifstream ifs;
	ifs.open("emp.txt", ios::in);

	for (; t != 0; t--)
	{
		ifs >> id;
		ifs >> name;
		ifs >> sex;
		ifs >> tel;
		ifs >> dept;
		ifs >> sal;
		if (dept == 0)
			H = new TechEmp(id, name, sex, tel, dept, sal);
		else if (dept == 1)
			H = new SalEmp(id, name, sex, tel, dept, sal);
		else if (dept == 2)
			H = new FinEmp(id, name, sex, tel, dept, sal);
		if (num == 0)
		{
			E_Head = H;
			T = H;
		}
		else
		{
			T->E_tail = H;
			T = H;
		}
		E_Num = E_Num + aNum;
		num++;
	}
	ifs.close();
	empfile = false;
	cout << "��ӳɹ�" << endl;
}


void EmpManager::DeleteEmployee()
{
	int Del_num;
	cout << "������Ҫɾ��ְ���ı��: " << endl;
	cin >> Del_num;
	if (IsExist(Del_num) == -1)
		cout << "ְ�������ڣ�" << endl;
	else
	{
		for (H = E_Head; H != NULL; H = H->E_tail)
		{
			if (E_Head->E_id == Del_num)
			{
				E_Head = H->E_tail;
				break;
			}
			if (H->E_tail == NULL && H->E_id == Del_num)
			{
				T->E_tail = NULL;
				break;
			}
			if (H->E_id == Del_num)
			{
				T->E_tail = H->E_tail;
				break;
			}
			T = H;
		}

	}
	saveinfo();
	cout << "�ɹ�ɾ��ְ����Ϣ��" << endl;
	system("pause");
	system("cls");
}

int EmpManager::IsExist(int id)
{
	int index = -1;
	for (H = E_Head; H != NULL; H = H->E_tail)
		if (id == H->E_id)
		{
			index = id;
			break;
		}
	return index;
}
int EmpManager::IsExist(string name)
{
	int index = -1;
	for (H = E_Head; H != NULL; H = H->E_tail)
	{
		if (name == H->E_name)
		{
			index = 0;
			break;
		}
		
	}
	return index;

}

void EmpManager::UpdateEmployee()
{
	cout << "������Ҫ�޸�ְ���Ĺ���: " << endl;
	int mod_num;
	cin >> mod_num;
	if (IsExist(mod_num) == -1)
		cout << "ְ�������ڣ�" << endl;
	else
	{
		for (H = E_Head; H != NULL; H = H->E_tail)
		{
			if (H->E_id == mod_num)
			{
				cout << "�����빤��" << endl;
				cin >> H->E_id;
				cout << "����������" << endl;
				cin >> H->E_name;
				cout << "�������Ա�" << endl;
				cout << "0ΪŮ" << endl;
				cout << "1Ϊ��" << endl;
				cin >> H->E_sex;
				cout << "������绰" << endl;
				cin >> H->E_tel;
				cout << "���������" << endl;
				cout << "0Ϊ����" << endl;
				cout << "1Ϊ����" << endl;
				cout << "2Ϊ����" << endl;
				cin >> H->E_dept;
				cout << "�����빤��" << endl;
				cin >> H->E_sal;
				break;
			}
		}
		saveinfo();
		cout << "�ɹ��޸�ְ����Ϣ��" << endl;
	}
	system("pause");
	system("cls");
}

void EmpManager::reseachStudentByName()
{
	cout << "������ְ������: " << endl;
	string Find_name;
	cin >> Find_name;
	if (IsExist(Find_name) == -1)
		cout << "ְ�������ڣ�" << endl;
	else
	{
		for (H = E_Head; H != NULL; H = H->E_tail)
		{
			if (H->E_name == Find_name)
			{
				cout << "�������" << endl;
				H->showInfo();
			}
		}
	}
	system("pause");
	system("cls");
}

void EmpManager::reseachStudentByOffice()
{
	cout << "��������ұ��: " << endl;
	int Find_dept;
	cin >> Find_dept;
	if (Find_dept != 0 && Find_dept != 1 && Find_dept != 2)
		cout << "���Ҳ����ڣ�" << endl;
	else
	{
		for (H = E_Head; H != NULL; H = H->E_tail)
		{
			if (H->E_dept == Find_dept)
				H->showInfo();
		}
		cout << "�������" << endl;
	}
	system("pause");
	system("cls");
}

void EmpManager::add()
{
	int Add_dept;
	cout << "������ұ��: " << endl;
	cin >> Add_dept;
	double sum = 0;
	int cnt = 0;
	if (Add_dept != 0 && Add_dept != 1 && Add_dept != 2)
		cout << "���Ҳ����ڣ�" << endl;
	else
	{
		for (H = E_Head; H != NULL; H = H->E_tail)
		{
			if (H->E_dept == Add_dept)
			{
				sum = sum + H->E_sal;
				cnt++;
			}
		}
		cout << "�ÿ��ҵ�ƽ������Ϊ: " << sum / cnt << "Ԫ" << endl;
	}
	system("pause");
	system("cls");
}