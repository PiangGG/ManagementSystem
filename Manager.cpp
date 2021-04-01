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
	std::cout << "ְ�����:" << this->m_Id << "\t"
		<< "ְ������:" << this->m_Name << "\t"
		<< "ְ����λ:" << this->getDeptName() << "\t"
		<< "��λְ��:" << "����ϰ�������񣬲��·������Ա��"
		<< std::endl;
}

std::string ManagementSystem::Manager::getDeptName()
{
	return std::string("����");
}
