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
			cout << "文件不存在，无法保存职工信息！" << endl;

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
			cout << "文件为空" << endl;
			E_Num = 0;
			H = NULL;
			T = NULL;
			E_Head = NULL;
			empfile = true;
			ifs.close();
			return;
		}
		E_Num = get_empNum();
		cout << "职工人数为" << E_Num << "人" << endl;
		init_emp();
	}

	int get_empNum();		//获取文件中员工数量
	void init_emp();		//根据文件中的信息初始化员工

	void Main_Menu();		//显示菜单界面

	void AddEmployee();		//增加新员工
	void show();			//显示所有职工信息

	int IsExist(int id);	//判断输入员工是否存在
	int IsExist(string name);

	void DeleteEmployee();	//删除员工信息

	void UpdateEmployee();	//修改员工信息

	void reseachStudentByName();	//按名字查找员工信息

	void reseachStudentByOffice();	//按科室查找员工信息

	void saveinfo();			//保存同步数据

	void add();			//按科室算出平均工资

	void Exit();		//退出程序

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
	cout << "欢迎使用公司员工信息管理系统" << endl;
	cout << "0.退出职工管理系统" << endl;
	cout << "1.添加职工信息" << endl;
	cout << "2.删除职工信息" << endl;
	cout << "3.修改职工信息" << endl;
	cout << "4.名字查询职工信息" << endl;
	cout << "5.科室查询职工信息" << endl;
	cout << "6.按科室统计职工平均工资" << endl;
	cout << "7.显示职工信息" << endl;
	cout << "请选择" << endl;
}

void EmpManager::Exit()
{
	int t;
	cout << "是否确认退出？" << endl;
	cout << "1.确认" << endl;
	cout << "2.返回" << endl;
	while (true)
	{
		cin >> t;
		if (t == 1)
		{
			cout << "欢迎下次使用" << endl;
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
			cout << "请重新选择！" << endl;
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
	cout << "请输入增加员工数量" << endl;
	int aNum = 0;
	cin >> aNum;
	int t;
	t = aNum;

	for (; t != 0; t--)
	{
		cout << "请输入工号" << endl;
		cin >> id;
		system("cls");
		cout << "请输入姓名" << endl;
		cin >> name;
		system("cls");
		cout << "请输入性别" << endl;
		cout << "0为女" << endl;
		cout << "1为男" << endl;
		cin >> sex;
		system("cls");
		cout << "请输入电话" << endl;
		cin >> tel;
		system("cls");
		cout << "请输入科室" << endl;
		cout << "0为技术" << endl;
		cout << "1为销售" << endl;
		cout << "2为财务" << endl;
		cin >> dept;
		system("cls");
		cout << "请输入工资" << endl;
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
	cout << "成功添加" << aNum << "名职工" << endl;
	empfile = false;
	system("pause");

}

void EmpManager::show()
{
	H = E_Head;
	if (H == NULL)
	{
		cout << "无员工信息！" << endl;
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
	cout << "添加成功" << endl;
}


void EmpManager::DeleteEmployee()
{
	int Del_num;
	cout << "请输入要删除职工的编号: " << endl;
	cin >> Del_num;
	if (IsExist(Del_num) == -1)
		cout << "职工不存在！" << endl;
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
	cout << "成功删除职工信息！" << endl;
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
	cout << "请输入要修改职工的工号: " << endl;
	int mod_num;
	cin >> mod_num;
	if (IsExist(mod_num) == -1)
		cout << "职工不存在！" << endl;
	else
	{
		for (H = E_Head; H != NULL; H = H->E_tail)
		{
			if (H->E_id == mod_num)
			{
				cout << "请输入工号" << endl;
				cin >> H->E_id;
				cout << "请输入姓名" << endl;
				cin >> H->E_name;
				cout << "请输入性别" << endl;
				cout << "0为女" << endl;
				cout << "1为男" << endl;
				cin >> H->E_sex;
				cout << "请输入电话" << endl;
				cin >> H->E_tel;
				cout << "请输入科室" << endl;
				cout << "0为技术" << endl;
				cout << "1为销售" << endl;
				cout << "2为财务" << endl;
				cin >> H->E_dept;
				cout << "请输入工资" << endl;
				cin >> H->E_sal;
				break;
			}
		}
		saveinfo();
		cout << "成功修改职工信息！" << endl;
	}
	system("pause");
	system("cls");
}

void EmpManager::reseachStudentByName()
{
	cout << "请输入职工姓名: " << endl;
	string Find_name;
	cin >> Find_name;
	if (IsExist(Find_name) == -1)
		cout << "职工不存在！" << endl;
	else
	{
		for (H = E_Head; H != NULL; H = H->E_tail)
		{
			if (H->E_name == Find_name)
			{
				cout << "查找完成" << endl;
				H->showInfo();
			}
		}
	}
	system("pause");
	system("cls");
}

void EmpManager::reseachStudentByOffice()
{
	cout << "请输入科室编号: " << endl;
	int Find_dept;
	cin >> Find_dept;
	if (Find_dept != 0 && Find_dept != 1 && Find_dept != 2)
		cout << "科室不存在！" << endl;
	else
	{
		for (H = E_Head; H != NULL; H = H->E_tail)
		{
			if (H->E_dept == Find_dept)
				H->showInfo();
		}
		cout << "查找完成" << endl;
	}
	system("pause");
	system("cls");
}

void EmpManager::add()
{
	int Add_dept;
	cout << "输入科室编号: " << endl;
	cin >> Add_dept;
	double sum = 0;
	int cnt = 0;
	if (Add_dept != 0 && Add_dept != 1 && Add_dept != 2)
		cout << "科室不存在！" << endl;
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
		cout << "该科室的平均工资为: " << sum / cnt << "元" << endl;
	}
	system("pause");
	system("cls");
}