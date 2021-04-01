#include "Boss.h"

ManagementSystem::Boss::Boss(int id, std::string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

ManagementSystem::Boss::~Boss()
{
}

void ManagementSystem::Boss::showInfo()
{
	std::cout << "职工编号:" << this->m_Id<<"\t"
		<< "职工姓名:" << this->m_Name << "\t"
		<< "职工岗位:" << this->getDeptName() << "\t"
		<< "岗位职责:" << "管理公司所有事务"
		<< std::endl;
}

std::string ManagementSystem::Boss::getDeptName()
{
    return std::string("总裁");
}
