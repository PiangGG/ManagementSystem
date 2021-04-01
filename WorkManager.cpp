#include "WorkManager.h"
#include "Manager.h"
#include "Employee.h"
#include "Boss.h"
#include <fstream>
namespace ManagementSystem 
{
	ManagementSystem::WorkManager::WorkManager()
	{
		std::ifstream ifs;
		ifs.open(FILENAME, std::ios::out);

		//�ļ�������
		if (!ifs.is_open())
		{
			std::cout << "�ļ������ڣ�" << std::endl;
			this->m_EmpNum = 0;//��ʼ������
			this->m_FileIsEmpty = true;//��ʼ���ļ�Ϊ�ձ�־
			this->m_EmpArray = NULL;//��ʼ������
			ifs.close();//�ر��ļ�
			return;
		}

		//�ļ����ڵ���û�м�¼
		char ch;
		ifs >> ch;
		if (ifs.eof())
		{
			std::cout << "�ļ�Ϊ�գ�" << std::endl;
			this->m_EmpNum = 0;//��ʼ������
			this->m_FileIsEmpty = true;//��ʼ���ļ���Ϊ�ձ�־
			this->m_EmpArray = NULL;//��ʼ������
			ifs.close();//�ر��ļ�
			return;
		}

		//�ļ�����,���м�¼
		this->m_FileIsEmpty = false;//��ʼ���ļ���Ϊ�ձ�־
		int num = this->get_EmpNum();
		std::cout << "ְ������Ϊ:" << num << std::endl;
		this->m_EmpNum = num;
		//����ְ������������
		this->m_EmpArray = new Worker * [this->m_EmpNum];
		//��ʼ��ְ��
		init_Emp();

		//testcode
		for (int i = 0; i < m_EmpNum; i++)
		{
			std::cout << "ְ����:" << this->m_EmpArray[i]->m_Id << "\t";
			std::cout << "ְ����:" << this->m_EmpArray[i]->m_Name<< "\t";
			std::cout << "ְ����:" << this->m_EmpArray[i]->m_DeptId<<std::endl;
		}
	}

	ManagementSystem::WorkManager::~WorkManager()
	{
		if (this->m_EmpArray != NULL) 
		{
			delete[] this->m_EmpArray;
			this->m_EmpArray = nullptr;
		}
	}

	void ManagementSystem::WorkManager::Show_Menu()
	{
		std::cout <<"***************************************************"<< std::endl;
		std::cout <<"************ < ��ӭʹ�ñ�ϵͳ > *******************"<< std::endl;
		std::cout <<"************* 0.�˳��������  *********************"<< std::endl;
		std::cout <<"************* 1.�����Ա��Ϣ  *********************"<< std::endl;
		std::cout <<"************* 2.��ʾ��Ա��Ϣ  *********************"<< std::endl;
		std::cout <<"************* 3.ɾ����Ա��Ϣ  *********************"<< std::endl;
		std::cout <<"************* 4.�޸���Ա��Ϣ  *********************"<< std::endl;
		std::cout <<"************* 5.������Ա��Ϣ  *********************"<< std::endl;
		std::cout <<"************* 6.������Ա��Ϣ  *********************"<< std::endl;
		std::cout <<"************* 7.�����Ա��Ϣ  *********************"<< std::endl;
		std::cout <<"***************************************************"<< std::endl;
		std::cout << std::endl;
	}
	void WorkManager::exitSystem()
	{
		std::cout << "��ӭ�´�ʹ��" << std::endl;
		system("pause");
		exit(0);
	}
	void WorkManager::Add_Emp()
	{
		std::cout << "����������ְ������:" << std::endl;
		int addNum = 0;
		std::cin >> addNum;

		if (addNum>0)
		{
			//�����¿ռ��С
			int newSize = this->m_EmpNum + addNum;
			//�����¿ռ�
			Worker** newSpace = new Worker * [newSize];
			//��ԭ�ռ����ݷŵ��¿ռ���
			if (this->m_EmpArray!=NULL)
			{
				for (int i = 0; i < this->m_EmpNum; i++)
				{
					newSpace[i] = this->m_EmpArray[i];
				}
			}

			//����������
			for (int i = 0; i < addNum; i++)
			{
				int id;
				std::string name;
				int dSelect;

				std::cout << "�����" << i + 1 << " ����ְ�����:" << std::endl;
				std::cin >> id;
				std::cout << "�����" << i + 1 << " ����ְ������:" << std::endl;
				std:: cin>> name;
				std::cout << "ѡ���λ"<< std::endl;
				std::cout << "1.��ְͨ��"<< std::endl;
				std::cout << "2.����"<< std::endl;
				std::cout << "3.�ϰ�"<< std::endl;

				std::cin >> dSelect;

				Worker* worker =NULL;
				switch (dSelect)
				{
				case 1://��ͨԱ��
					worker = new Employee(id,name,1);
				case 2://��ͨԱ��
					worker = new Manager(id, name, 2);
				case 3://��ͨԱ��
					worker = new Boss(id, name, 3);
				default:

					break;
				}
				newSpace[this->m_EmpNum + i] = worker;
			}
			//�ͷ�ԭ�пռ�
			delete[] this->m_EmpArray;
			//�����¿ռ��ָ��
			this->m_EmpArray = newSpace;
			//�����¸���
			this->m_EmpNum = newSize;

			//����ְ����Ϊ��
			this->m_FileIsEmpty = false;

			//д���ļ�
			this->Save();

			//��ʾ��Ϣ
			std::cout << "�ɹ����" << addNum<<"��"<<std::endl;
		}
		else
		{
			std::cout << "��������" << std::endl;
		}
		system("pause");
		system("cls");
	}
	void WorkManager::Save()
	{
		std::ofstream ofs;
		ofs.open(FILENAME,std::ios::out);

		if (ofs.fail())
		{
			std::cout << "�ļ��򿪴���" << std::endl;
			return ;
		}
		for (int i = 0; i <this->m_EmpNum; i++)
		{
			if (!m_EmpArray[i])
			{
				return;
			}
			ofs << this->m_EmpArray[i]->m_Id <<"\t"
				<< this->m_EmpArray[i]->m_Name << "\t"
				<< this->m_EmpArray[i]->m_DeptId <<std::endl;
		}
		ofs.close();
	}
	int WorkManager::get_EmpNum()
	{
		std::ifstream ifs;
		ifs.open(FILENAME,std::ios::in);

		int id;
		std::string name;
		int did;

		int num = 0;
		while (ifs>>id&&ifs>>name&&ifs>> did)
		{
			//��¼����
			num++;
		}
		ifs.close();

		return num;
	}
	void WorkManager::init_Emp()
	{
		std::ifstream ifs;
		ifs.open(FILENAME,std::ios::in);

		int id;
		std::string name;
		int did;
		int index = 0;
		while (ifs>>id&& ifs>>name&& ifs>>did)
		{
			Worker* worker= NULL;
			switch (did)
			{
			case 1:
				worker = new Employee(id,name,did);
				break;
			case 2:
				worker = new Manager(id, name, did);
				break;
			case 3:
				worker = new Boss(id, name, did);
				break;
			default:
				std::cout << "err" << std::endl;
				break;
			}
			this->m_EmpArray[index] = worker;

			index++;
		}
	}
	void WorkManager::Show_Emp()
	{
		if (this->m_FileIsEmpty)
		{
			std::cout << "�ļ������ڻ��¼Ϊ��" << std::endl;
		}
		else
		{
			for (int i = 0; i < m_EmpNum; i++)
			{
				//���ö�̬���ýӿ�
				this->m_EmpArray[i]->showInfo();
			}
		}
		system("pause");
		system("cls");
	}
	void WorkManager::Del_Emp()
	{
		if (this->m_FileIsEmpty)
		{
			std::cout << "�ļ�Ϊ��!" << std::endl;
		}
		else
		{
			//����ɾ��ְ���ı��
			int id = 0;
			std::cout << "����ɾ��ְ���ı��:"<<std::endl;
			std::cin >> id;
			int index = this->IsExist(id);
			if (index!=-1)//����
			{
				//ɾ��Ŀ��idְ��
				
				for (int  i = index; i <this->m_EmpNum-1; i++)
				{
					//����ǰ��
					this->m_EmpArray[i] = this->m_EmpArray[i + 1];
				}

				this->m_EmpNum--;//���¼�¼����
				//����ͬ���������ļ���
				this->Save();
				std::cout << "ɾ���ɹ�" << std::endl;
			}
			else 
			{
				//ɾ��ʧ��
				std::cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ����" << std::endl;
			}
		}
		system("pause");
		system("cls");
		
		
	}
	int WorkManager::IsExist(int id)
	{
		int index = - 1;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i]->m_Id == id)
			{
				index = i;
				break;
			}
		}
		return index;
	}
	void WorkManager::Mod_Emp()
	{
		if (this->m_FileIsEmpty)
		{
			std::cout << "�ļ������ڻ��߼�¼Ϊ��!" << std::endl;
		}
		else
		{
			std::cout << "�������޸�ְ���ı��:" << std::endl;
			int id;
			std::cin >> id;
			
			int ret = this->IsExist(id);

			if (ret!=-1)
			{
				//����ְ���ı��
				delete this->m_EmpArray[ret];
				int newId = 0;
				std::string newName = "";
				int dSelect = 0;
				std::cout << "�鵽:" << id << "��ְ��,��������ְ����:" << std::endl;
				std::cin >> newId;

				std::cout << "��������ְ������:" << std::endl;
				std::cin >> newName;

				std::cout << "ѡ���λ" << std::endl;
				std::cout << "1.��ְͨ��" << std::endl;
				std::cout << "2.����" << std::endl;
				std::cout << "3.�ϰ�" << std::endl;
				std::cin >> dSelect;

				Worker* worker = NULL;
				switch (dSelect)
				{
				case 1://��ͨԱ��
					worker = new Employee(newId, newName, 1);
				case 2://��ͨԱ��
					worker = new Manager(newId, newName, 2);
				case 3://��ͨԱ��
					worker = new Boss(newId,newName, 3);
				default:

					break;
				}
				this->m_EmpArray[ret] = worker;

				std::cout << "�޸ĳɹ���" << this->m_EmpArray[ret]->m_DeptId << std::endl;

				//����
				this->Save();
			}
			else
			{
				std::cout << "�޸�ʧ��,���޴��ˣ�" << std::endl;
			}
		}
		system("pause");
		system("cls");
	}
	void WorkManager::Find_Emp()
	{
		if (this->m_FileIsEmpty)
		{
			std::cout << "�ļ������ڻ��¼Ϊ��" << std::endl;
		}
		else
		{
			std::cout << "��������ҷ�ʽ:" << std::endl;
			std::cout << "1.ְ����Ų���:" << std::endl;
			std::cout << "2.ְ����������:" << std::endl;
			int Select = 0;

			std::cin >> Select;
			
			switch (Select)
			{
				case 1: 
				{
					int id;
					std::cout << "���������ְ�����" << std::endl;
					std::cin >> id;
					int ret = IsExist(id);
					if (ret!=-1)
					{
						std::cout << "���ҳɹ�����ְ����Ϣ����:" << std::endl;
						this->m_EmpArray[ret]->showInfo();
					}
					else
					{
						std::cout << "����ʧ��,���޴��ˣ�" << std::endl;
					}
					break;
				}
				
				case 2: 
				{
					std::string name;
					std::cout << "�������������:" << std::endl;
					std::cin >> name;
				
					bool flag = false;

					for (int i = 0; i < m_EmpNum; i++)
					{
						if (m_EmpArray[i]->m_Name==name)
						{
							std::cout << "���ҳɹ�!" << std::endl;
							m_EmpArray[i]->showInfo();

							flag = true;
						}
					}
					if (flag==false)
					{
						std::cout << "����ʧ�ܣ����޴���!" << std::endl;
					}
					break;
				}
				
			default:
				std::cout << "�������!"<<std::endl;
				break;
			}
		}
	}
	void WorkManager::Sort_Emp()
	{
		if (this->m_FileIsEmpty)
		{
			std::cout << "�ļ������ڻ��¼Ϊ��!" << std:: endl;
			system("pause");
			system("cls");
		}
		else
		{
			std::cout << "��ѡ������ʽ:" << std::endl;
			std::cout << "1.��ְ������������" << std::endl;
			std::cout << "2.��ְ���Ž�������" << std::endl;
			int Select = 0;
			std::cin >> Select;

			for (int i = 0; i < m_EmpNum; i++)
			{
				int minOrMax = i;
				for (int  j = i+1; j < m_EmpNum; j++)
				{
					switch (Select)
					{
					case 1: 
					{
						if (m_EmpArray[minOrMax]->m_Id>m_EmpArray[j]->m_Id)
						{
							minOrMax = j;
						}
						break;
					}
					case 2:
					{
						if (m_EmpArray[minOrMax]->m_Id < m_EmpArray[j]->m_Id)
						{
							minOrMax = j;
						}
						break;
					}
					default:
						std::cout << "����ʽѡ�����!" << std::endl;
						return;
					}
				}
				if (i!=minOrMax)
				{
					Worker* temp = m_EmpArray[i];
					m_EmpArray[i] = m_EmpArray[minOrMax];
					m_EmpArray[minOrMax] = temp;
				}
			}
			std::cout << "����ɹ����������Ϊ:" << std::endl;
			this->Save();

			this->Show_Emp();
		}
	}
	void  WorkManager::Clean_File()
	{
		std::cout << "ȷ�����?" << std::endl;
		std::cout << "1 or y ȷ��" << std::endl;
		std::cout << "2 or n ȡ��" << std::endl;

		char ch = '1';
		std::cin >> ch;
		switch (ch)
		{
		case '1': 
		{
			//����ļ����� ɾ���ļ����´���
			std::ofstream ofs(FILENAME,std::ios::trunc);
			ofs.close();

			if (this->m_EmpArray!=NULL)
			{
				for (int i = 0; i < this->m_EmpNum; i++)
				{
					if (this->m_EmpArray[i]!=NULL)
					{
						delete this->m_EmpArray[i];
					}
				}
				this->m_EmpNum = 0;
				delete[] this->m_EmpArray;
				this->m_EmpArray = NULL;
				this->m_FileIsEmpty = true;
			}
			std::cout << "��ճɹ�" << std::endl;
			break;
		}
		case '2':
		{
			return;
		}
		case 'y':
		{
			//����ļ����� ɾ���ļ����´���
			std::ofstream ofs(FILENAME, std::ios::trunc);
			ofs.close();

			if (this->m_EmpArray != NULL)
			{
				for (int i = 0; i < this->m_EmpNum; i++)
				{
					if (this->m_EmpArray[i] != NULL)
					{
						delete this->m_EmpArray[i];
					}
				}
				this->m_EmpNum = 0;
				delete[] this->m_EmpArray;
				this->m_EmpArray = NULL;
				this->m_FileIsEmpty = true;
			}
			std::cout << "��ճɹ�" << std::endl;
			break;
		}
		case 'n':
		{
			return;
		}
		default:
			std::cout << "�������!" << std::endl;
			return;
		}
		system("pause");
		system("cls");
		return;
	}
}

