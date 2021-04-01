#include "Employee.h"

ManagementSystem::Employee::Employee(int id, std::string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

void ManagementSystem::Employee::showInfo()
{
	std::cout	<< "ְ�����:" << this->m_Id << "\t"
				<< "ְ������:" << this->m_Name << "\t"
				<< "ְ����λ:" << this->getDeptName() << "\t"
				<< "��λְ��:" << "��ɾ�����������"
				<<std::endl;
}

std::string ManagementSystem::Employee::getDeptName()
{
	return std::string("Ա��");
}
