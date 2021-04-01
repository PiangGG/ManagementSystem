#include "Employee.h"

ManagementSystem::Employee::Employee(int id, std::string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

void ManagementSystem::Employee::showInfo()
{
	std::cout	<< "职工编号:" << this->m_Id << "\t"
				<< "职工姓名:" << this->m_Name << "\t"
				<< "职工岗位:" << this->getDeptName() << "\t"
				<< "岗位职责:" << "完成经理交给的任务"
				<<std::endl;
}

std::string ManagementSystem::Employee::getDeptName()
{
	return std::string("员工");
}
