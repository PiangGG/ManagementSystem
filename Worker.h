#pragma once
#include <iostream>

namespace ManagementSystem 
{
	class Worker 
	{
	public:
		//显示信息
		virtual void showInfo() = 0;
		//获取岗位名称
		virtual std::string getDeptName() = 0;
		

		int m_Id;//编号
		std::string m_Name;//姓名
		int m_DeptId;
	private:
	};
}