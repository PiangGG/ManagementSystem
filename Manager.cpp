#include "Manager.h"

ManagementSystem::Manager::Manager(int id, std::string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

ManagementSystem::Manager::~Manager()
{
}

void ManagementSystem::Manager::showInfo()
{
	std::cout << "职工编号:" << this->m_Id << "\t"
		<< "职工姓名:" << this->m_Name << "\t"
		<< "职工岗位:" << this->getDeptName() << "\t"
		<< "岗位职责:" << "完成老板给的任务，并下发任务给员工"
		<< std::endl;
}

std::string ManagementSystem::Manager::getDeptName()
{
	return std::string("经理");
}
