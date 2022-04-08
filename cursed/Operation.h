#pragma once
#include "ISerializable.h"

namespace IMEX
{
	class Operation : public ISerializable
	{

		
	public:
		void ShowToConsole() override;
		void SaveToFile() override;
		void ReadFromFile() override;
	};
}

