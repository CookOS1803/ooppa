#pragma once
#include <vector>
#include <memory>
#include "ISerializable.h"
#include "Operation.h"

namespace IMEX
{
	class OperationList : public ISerializable
	{
		std::vector<std::shared_ptr<Operation>> originalOperations;
		std::vector<std::shared_ptr<Operation>> copiedOperations;

		std::string fileName;

	public:

		OperationList();

		void SetFileName(std::string_view fileName);

		auto begin() -> std::vector<std::shared_ptr<Operation>>::iterator;
		auto begin() const -> std::vector<std::shared_ptr<Operation>>::const_iterator;
		auto end() -> std::vector<std::shared_ptr<Operation>>::iterator;
		auto end() const -> std::vector<std::shared_ptr<Operation>>::const_iterator;

		void ShowToConsole() override;
		void SaveToFile() override;
		void ReadFromFile() override;
	};
}

