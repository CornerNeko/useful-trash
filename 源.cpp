#include<iostream>
#include<fstream>
using namespace std;

#include"Employee.h"
#include"TechEmp.h"
#include"SalEmp.h"
#include"FinEmp.h"
#include"EmpManager.h"


int main()
{
	EmpManager em;
	int choice = 0;

	while (true)
	{
		em.Main_Menu();
		cin >> choice;
		cin.clear();
		cin.ignore();
		switch (choice)
		{
		case 0:
			em.Exit();
			break; 
		case 1:
			em.AddEmployee();
			em.show();
			break;
		case 2:
			em.DeleteEmployee();
			break;
		case 3:
			em.UpdateEmployee();
			break;
		case 4:
			em.reseachStudentByName();
			break;
		case 5:
			em.reseachStudentByOffice();
			break;
		case 6:
			em.add();
			break;
		case 7:
			em.show();
		default:
			system("cls");
			break;
		}
	}
}