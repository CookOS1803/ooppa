#pragma once
#include <vector>
#include <memory>
#include "ISerializable.h"
#include "Operation.h"
#include <functional>

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
		bool Contains(int ID);
		void Remove(int ID);
		void Sort(const std::function<bool(const std::shared_ptr<Operation>&, const std::shared_ptr<Operation>&)>& criteria);
		auto GetOperation(int ID) -> std::shared_ptr<Operation>;

		auto begin() -> std::vector<std::shared_ptr<Operation>>::iterator;
		auto begin() const -> std::vector<std::shared_ptr<Operation>>::const_iterator;
		auto end() -> std::vector<std::shared_ptr<Operation>>::iterator;
		auto end() const -> std::vector<std::shared_ptr<Operation>>::const_iterator;

		virtual void ShowToConsole() override;
		virtual void SaveToFile() override;
		virtual void ReadFromFile() override;

		static bool ByIDAscendingly(const std::shared_ptr<Operation>& o1, const std::shared_ptr<Operation>& o2);
		static bool ByIDDescendingly(const std::shared_ptr<Operation>& o1, const std::shared_ptr<Operation>& o2);
		static bool ByTypeAscendingly(const std::shared_ptr<Operation>& o1, const std::shared_ptr<Operation>& o2);
		static bool ByTypeDescendingly(const std::shared_ptr<Operation>& o1, const std::shared_ptr<Operation>& o2);
		static bool ByStatusAscendingly(const std::shared_ptr<Operation>& o1, const std::shared_ptr<Operation>& o2);
		static bool ByStatusDescendingly(const std::shared_ptr<Operation>& o1, const std::shared_ptr<Operation>& o2);
		static bool ByProductIDAscendingly(const std::shared_ptr<Operation>& o1, const std::shared_ptr<Operation>& o2);
		static bool ByProductIDDescendingly(const std::shared_ptr<Operation>& o1, const std::shared_ptr<Operation>& o2);
		static bool ByProductAmountAscendingly(const std::shared_ptr<Operation>& o1, const std::shared_ptr<Operation>& o2);
		static bool ByProductAmountDescendingly(const std::shared_ptr<Operation>& o1, const std::shared_ptr<Operation>& o2);
		static bool ByClientLoginAscendingly(const std::shared_ptr<Operation>& o1, const std::shared_ptr<Operation>& o2);
		static bool ByClientLoginDescendingly(const std::shared_ptr<Operation>& o1, const std::shared_ptr<Operation>& o2);
	};
}

