#pragma once
#include <iostream>
#include "Worker.h"

namespace ManagementSystem 
{
	//员工类
	class Employee :public Worker 
	{
	public:
		Employee(int id, std::string, int dId);

		//显示信息
		virtual void showInfo()override;

		//获取职工岗位
		virtual std::string getDeptName()override;
	};
}
