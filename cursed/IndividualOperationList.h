#pragma once
#include <memory>
#include <functional>
#include "ISerializable.h"
#include "List.h"
#include "Operation.h"
#include "Filter.h"

namespace IMEX
{
	class IndividualOperationList : public List<Operation, int>, public ISerializable
	{
	protected:

		std::string operationsFileName;

		IntFilter IDFilter;
		EnumFilter typeFilter;
		EnumFilter statusFilter;
		IntFilter productIDFilter;
		IntFilter productAmountFilter;
		StringFilter clientLoginFilter;

	public:

		IndividualOperationList();
		virtual ~IndividualOperationList();

		void SetOperationsFileName(std::string_view operationsFileName);

		bool DoesMatchFilters(const std::shared_ptr<Operation>& e) const override;

		void SetIDFilterMin(int min);
		void SetIDFilterMax(int max);
		void SetTypeFilter(Operation::Type value);
		void SetStatusFilter(Operation::Status value);
		void SetProductIDFilterMin(int min);
		void SetProductIDFilterMax(int max);
		void SetProductAmountFilterMin(int min);
		void SetProductAmountFilterMax(int max);
		void SetClientLoginFilter(std::string_view s);

		void ClearFilters();

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

