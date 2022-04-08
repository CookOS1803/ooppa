#pragma once
#include <vector>
#include <memory>
#include "ISerializable.h"
#include "Operation.h"

namespace IMEX
{
	class OperationList : public ISerializable
	{
		std::vector<std::shared_ptr<Operation>> originalProducts;
		std::vector<std::shared_ptr<Operation>> copiedProducts;

	public:
		void ShowToConsole() override;
		void SaveToFile() override;
		void ReadFromFile() override;
	};
}

