#pragma once
#include <iostream>
#include "Worker.h"

namespace ManagementSystem 
{
	//Ա����
	class Employee :public Worker 
	{
	public:
		Employee(int id, std::string, int dId);

		//��ʾ��Ϣ
		virtual void showInfo()override;

		//��ȡְ����λ
		virtual std::string getDeptName()override;
	};
}
