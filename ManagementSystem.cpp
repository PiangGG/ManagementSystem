#include <iostream>
#include "WorkManager.h"
#include "Worker.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"
//namespace 
using namespace ManagementSystem;

int main() 
{
	WorkManager wm;
	int choice = 0;
	while (true)
	{
		//չʾ�˵�
		wm.Show_Menu();
		std::cout << "���������ѡ��" << std::endl;
		std::cin >> choice;
		switch (choice)
		{
			case 0:
				//�˳�ϵͳ
				wm.exitSystem();
				break;
			case 1:
				//�����Ա
				wm.Add_Emp();
				break;
			case 2:
				//��ʾ��Ա
				wm.Show_Emp();
				break;
			case 3:
				//ɾ����Ա
				wm.Del_Emp();
			case 4:
				//�޸���Ա
				wm.Mod_Emp();
				break;
			case 5:
				//������Ա
				wm.Find_Emp();
				break;
			case 6:
				//������Ա
				wm.Sort_Emp();
				break;
			case 7:
				//�����Ա
				wm.Clean_File();
				break;
			default:
				system("cls");
				break;
		}
	}
	system("pause");
	return 0;
}

