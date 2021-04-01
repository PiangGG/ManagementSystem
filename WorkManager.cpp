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

		//文件不存在
		if (!ifs.is_open())
		{
			std::cout << "文件不存在！" << std::endl;
			this->m_EmpNum = 0;//初始化人数
			this->m_FileIsEmpty = true;//初始化文件为空标志
			this->m_EmpArray = NULL;//初始化数组
			ifs.close();//关闭文件
			return;
		}

		//文件存在但是没有记录
		char ch;
		ifs >> ch;
		if (ifs.eof())
		{
			std::cout << "文件为空！" << std::endl;
			this->m_EmpNum = 0;//初始化人数
			this->m_FileIsEmpty = true;//初始化文件不为空标志
			this->m_EmpArray = NULL;//初始化数组
			ifs.close();//关闭文件
			return;
		}

		//文件存在,且有记录
		this->m_FileIsEmpty = false;//初始化文件不为空标志
		int num = this->get_EmpNum();
		std::cout << "职工人数为:" << num << std::endl;
		this->m_EmpNum = num;
		//根据职工数创建数组
		this->m_EmpArray = new Worker * [this->m_EmpNum];
		//初始化职工
		init_Emp();

		//testcode
		for (int i = 0; i < m_EmpNum; i++)
		{
			std::cout << "职工号:" << this->m_EmpArray[i]->m_Id << "\t";
			std::cout << "职工号:" << this->m_EmpArray[i]->m_Name<< "\t";
			std::cout << "职工号:" << this->m_EmpArray[i]->m_DeptId<<std::endl;
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
		std::cout <<"************ < 欢迎使用本系统 > *******************"<< std::endl;
		std::cout <<"************* 0.退出管理程序  *********************"<< std::endl;
		std::cout <<"************* 1.添加人员信息  *********************"<< std::endl;
		std::cout <<"************* 2.显示人员信息  *********************"<< std::endl;
		std::cout <<"************* 3.删除人员信息  *********************"<< std::endl;
		std::cout <<"************* 4.修改人员信息  *********************"<< std::endl;
		std::cout <<"************* 5.查找人员信息  *********************"<< std::endl;
		std::cout <<"************* 6.排序人员信息  *********************"<< std::endl;
		std::cout <<"************* 7.清空人员信息  *********************"<< std::endl;
		std::cout <<"***************************************************"<< std::endl;
		std::cout << std::endl;
	}
	void WorkManager::exitSystem()
	{
		std::cout << "欢迎下次使用" << std::endl;
		system("pause");
		exit(0);
	}
	void WorkManager::Add_Emp()
	{
		std::cout << "请输入增加职工数量:" << std::endl;
		int addNum = 0;
		std::cin >> addNum;

		if (addNum>0)
		{
			//计算新空间大小
			int newSize = this->m_EmpNum + addNum;
			//开辟新空间
			Worker** newSpace = new Worker * [newSize];
			//将原空间内容放到新空间下
			if (this->m_EmpArray!=NULL)
			{
				for (int i = 0; i < this->m_EmpNum; i++)
				{
					newSpace[i] = this->m_EmpArray[i];
				}
			}

			//输入新数据
			for (int i = 0; i < addNum; i++)
			{
				int id;
				std::string name;
				int dSelect;

				std::cout << "输入第" << i + 1 << " 个新职工编号:" << std::endl;
				std::cin >> id;
				std::cout << "输入第" << i + 1 << " 个新职工姓名:" << std::endl;
				std:: cin>> name;
				std::cout << "选择岗位"<< std::endl;
				std::cout << "1.普通职工"<< std::endl;
				std::cout << "2.经理"<< std::endl;
				std::cout << "3.老板"<< std::endl;

				std::cin >> dSelect;

				Worker* worker =NULL;
				switch (dSelect)
				{
				case 1://普通员工
					worker = new Employee(id,name,1);
				case 2://普通员工
					worker = new Manager(id, name, 2);
				case 3://普通员工
					worker = new Boss(id, name, 3);
				default:

					break;
				}
				newSpace[this->m_EmpNum + i] = worker;
			}
			//释放原有空间
			delete[] this->m_EmpArray;
			//更新新空间的指向
			this->m_EmpArray = newSpace;
			//更新新个数
			this->m_EmpNum = newSize;

			//更新职工不为空
			this->m_FileIsEmpty = false;

			//写入文件
			this->Save();

			//提示信息
			std::cout << "成功添加" << addNum<<"人"<<std::endl;
		}
		else
		{
			std::cout << "输入有误" << std::endl;
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
			std::cout << "文件打开错误" << std::endl;
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
			//记录人数
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
			std::cout << "文件不存在或记录为空" << std::endl;
		}
		else
		{
			for (int i = 0; i < m_EmpNum; i++)
			{
				//利用多态调用接口
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
			std::cout << "文件为空!" << std::endl;
		}
		else
		{
			//输入删除职工的编号
			int id = 0;
			std::cout << "输入删除职工的编号:"<<std::endl;
			std::cin >> id;
			int index = this->IsExist(id);
			if (index!=-1)//存在
			{
				//删除目标id职工
				
				for (int  i = index; i <this->m_EmpNum-1; i++)
				{
					//数据前移
					this->m_EmpArray[i] = this->m_EmpArray[i + 1];
				}

				this->m_EmpNum--;//更新记录人数
				//数据同步到更新文件中
				this->Save();
				std::cout << "删除成功" << std::endl;
			}
			else 
			{
				//删除失败
				std::cout << "删除失败，未找到该职工！" << std::endl;
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
			std::cout << "文件不存在或者记录为空!" << std::endl;
		}
		else
		{
			std::cout << "请输入修改职工的编号:" << std::endl;
			int id;
			std::cin >> id;
			
			int ret = this->IsExist(id);

			if (ret!=-1)
			{
				//查找职工的编号
				delete this->m_EmpArray[ret];
				int newId = 0;
				std::string newName = "";
				int dSelect = 0;
				std::cout << "查到:" << id << "号职工,请输入新职工号:" << std::endl;
				std::cin >> newId;

				std::cout << "请输入新职工姓名:" << std::endl;
				std::cin >> newName;

				std::cout << "选择岗位" << std::endl;
				std::cout << "1.普通职工" << std::endl;
				std::cout << "2.经理" << std::endl;
				std::cout << "3.老板" << std::endl;
				std::cin >> dSelect;

				Worker* worker = NULL;
				switch (dSelect)
				{
				case 1://普通员工
					worker = new Employee(newId, newName, 1);
				case 2://普通员工
					worker = new Manager(newId, newName, 2);
				case 3://普通员工
					worker = new Boss(newId,newName, 3);
				default:

					break;
				}
				this->m_EmpArray[ret] = worker;

				std::cout << "修改成功！" << this->m_EmpArray[ret]->m_DeptId << std::endl;

				//保存
				this->Save();
			}
			else
			{
				std::cout << "修改失败,查无此人！" << std::endl;
			}
		}
		system("pause");
		system("cls");
	}
	void WorkManager::Find_Emp()
	{
		if (this->m_FileIsEmpty)
		{
			std::cout << "文件不存在或记录为空" << std::endl;
		}
		else
		{
			std::cout << "请输入查找方式:" << std::endl;
			std::cout << "1.职工编号查找:" << std::endl;
			std::cout << "2.职工姓名查找:" << std::endl;
			int Select = 0;

			std::cin >> Select;
			
			switch (Select)
			{
				case 1: 
				{
					int id;
					std::cout << "请输入查找职工编号" << std::endl;
					std::cin >> id;
					int ret = IsExist(id);
					if (ret!=-1)
					{
						std::cout << "查找成功！该职工信息如下:" << std::endl;
						this->m_EmpArray[ret]->showInfo();
					}
					else
					{
						std::cout << "查找失败,查无此人！" << std::endl;
					}
					break;
				}
				
				case 2: 
				{
					std::string name;
					std::cout << "请输入查找姓名:" << std::endl;
					std::cin >> name;
				
					bool flag = false;

					for (int i = 0; i < m_EmpNum; i++)
					{
						if (m_EmpArray[i]->m_Name==name)
						{
							std::cout << "查找成功!" << std::endl;
							m_EmpArray[i]->showInfo();

							flag = true;
						}
					}
					if (flag==false)
					{
						std::cout << "查找失败，查无此人!" << std::endl;
					}
					break;
				}
				
			default:
				std::cout << "输入错误!"<<std::endl;
				break;
			}
		}
	}
	void WorkManager::Sort_Emp()
	{
		if (this->m_FileIsEmpty)
		{
			std::cout << "文件不存在或记录为空!" << std:: endl;
			system("pause");
			system("cls");
		}
		else
		{
			std::cout << "请选择排序方式:" << std::endl;
			std::cout << "1.按职工号升序排序。" << std::endl;
			std::cout << "2.按职工号降序排序。" << std::endl;
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
						std::cout << "排序方式选择错误!" << std::endl;
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
			std::cout << "排序成功，排序后结果为:" << std::endl;
			this->Save();

			this->Show_Emp();
		}
	}
	void  WorkManager::Clean_File()
	{
		std::cout << "确认清空?" << std::endl;
		std::cout << "1 or y 确认" << std::endl;
		std::cout << "2 or n 取消" << std::endl;

		char ch = '1';
		std::cin >> ch;
		switch (ch)
		{
		case '1': 
		{
			//如果文件存在 删除文件重新创建
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
			std::cout << "清空成功" << std::endl;
			break;
		}
		case '2':
		{
			return;
		}
		case 'y':
		{
			//如果文件存在 删除文件重新创建
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
			std::cout << "清空成功" << std::endl;
			break;
		}
		case 'n':
		{
			return;
		}
		default:
			std::cout << "输入错误!" << std::endl;
			return;
		}
		system("pause");
		system("cls");
		return;
	}
}

