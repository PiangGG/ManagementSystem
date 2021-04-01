#pragma once
#include <iostream>
#include "Worker.h"
#include <fstream>
#define FILENAME "empFile.txt"
namespace ManagementSystem 
{
	class WorkManager

	{
	public:

		//构造
		WorkManager();
		//析构
		~WorkManager();
		//展示菜单
		void Show_Menu();
		//退出系统
		void exitSystem();

		int m_EmpNum;
		Worker ** m_EmpArray;

		void Add_Emp();

		void Save();

		//标志文件是否为空
		bool m_FileIsEmpty;

		//统计人数
		int get_EmpNum();

		//初始化员工
		void init_Emp();

		//显示职工
		void Show_Emp();

		//删除职工
		void Del_Emp();

		//z判断职工是否存在
		int IsExist(int id);

		//修改职工
		void Mod_Emp();

		//查找职工
		void Find_Emp();

		//排序职工
		void Sort_Emp();

		//清空文件
		void Clean_File();

	private:
	};
}