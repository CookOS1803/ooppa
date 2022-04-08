#pragma once
#include "ISerializable.h"

namespace IMEX
{
	class Product : public ISerializable
	{
	
	public:
		void ShowToConsole() override;
		void SaveToFile() override;
		void ReadFromFile() override;
	};
}

