#pragma once
#include <iostream>
#include "Worker.h"
namespace ManagementSystem 
{
	class Manager :public Worker
	{
	public:
		Manager(int id, std::string name, int dId);
		~Manager();
	
		virtual void showInfo()override;

		virtual std::string getDeptName()override;
	};
}