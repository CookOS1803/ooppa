#pragma once
#include <vector>
#include <memory>
#include "ISerializable.h"
#include "List.h"
#include "Operation.h"
#include <functional>

namespace IMEX
{
	class IndividualOperationList : public List<Operation, int>, public ISerializable
	{
	protected:

		std::string operationsFileName;

	public:

		IndividualOperationList();
		virtual ~IndividualOperationList();

		void SetOperationsFileName(std::string_view operationsFileName);

		void CalculateNewID(Operation& e);

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

