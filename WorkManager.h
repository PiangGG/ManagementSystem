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

		//����
		WorkManager();
		//����
		~WorkManager();
		//չʾ�˵�
		void Show_Menu();
		//�˳�ϵͳ
		void exitSystem();

		int m_EmpNum;
		Worker ** m_EmpArray;

		void Add_Emp();

		void Save();

		//��־�ļ��Ƿ�Ϊ��
		bool m_FileIsEmpty;

		//ͳ������
		int get_EmpNum();

		//��ʼ��Ա��
		void init_Emp();

		//��ʾְ��
		void Show_Emp();

		//ɾ��ְ��
		void Del_Emp();

		//z�ж�ְ���Ƿ����
		int IsExist(int id);

		//�޸�ְ��
		void Mod_Emp();

		//����ְ��
		void Find_Emp();

		//����ְ��
		void Sort_Emp();

		//����ļ�
		void Clean_File();

	private:
	};
}