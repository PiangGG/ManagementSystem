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
	std::cout << "ְ�����:" << this->m_Id<<"\t"
		<< "ְ������:" << this->m_Name << "\t"
		<< "ְ����λ:" << this->getDeptName() << "\t"
		<< "��λְ��:" << "����˾��������"
		<< std::endl;
}

std::string ManagementSystem::Boss::getDeptName()
{
    return std::string("�ܲ�");
}
