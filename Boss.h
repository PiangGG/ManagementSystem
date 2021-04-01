#pragma once
#pragma once
#include <iostream>
#include "Worker.h"
namespace ManagementSystem
{
	class Boss :public Worker
	{
	public:
		Boss(int id, std::string name, int dId);
		~Boss();

		virtual void showInfo()override;

		virtual std::string getDeptName()override;
	};
}