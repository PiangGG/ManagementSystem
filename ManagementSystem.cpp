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
		//展示菜单
		wm.Show_Menu();
		std::cout << "请输入你的选择" << std::endl;
		std::cin >> choice;
		switch (choice)
		{
			case 0:
				//退出系统
				wm.exitSystem();
				break;
			case 1:
				//添加人员
				wm.Add_Emp();
				break;
			case 2:
				//显示人员
				wm.Show_Emp();
				break;
			case 3:
				//删除人员
				wm.Del_Emp();
			case 4:
				//修改人员
				wm.Mod_Emp();
				break;
			case 5:
				//查找人员
				wm.Find_Emp();
				break;
			case 6:
				//排序人员
				wm.Sort_Emp();
				break;
			case 7:
				//清空人员
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

