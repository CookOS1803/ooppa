#pragma once
#include <vector>
#include <memory>
#include "ISerializable.h"
#include "Operation.h"

namespace IMEX
{
	class IndividualOperationList : public ISerializable
	{
	protected:

		std::vector<std::shared_ptr<Operation>> originalOperations;
		std::vector<std::shared_ptr<Operation>> copiedOperations;

		std::string operationsFileName;

	public:

		IndividualOperationList();
		virtual ~IndividualOperationList();

		void SetOperationsFileName(std::string_view operationsFileName);

		void Add(const Operation& op);

		auto begin() -> std::vector<std::shared_ptr<Operation>>::iterator;
		auto begin() const -> std::vector<std::shared_ptr<Operation>>::const_iterator;
		auto end() -> std::vector<std::shared_ptr<Operation>>::iterator;
		auto end() const -> std::vector<std::shared_ptr<Operation>>::const_iterator;

		virtual void ShowToConsole() override;
		virtual void SaveToFile() override;
		virtual void ReadFromFile() override;
	};
}

