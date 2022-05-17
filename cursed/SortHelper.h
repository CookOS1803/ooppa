#pragma once
#include <string>
#include <memory>
#include "Product.h"
#include "Operation.h"
#include "ClientInfo.h"

namespace IMEX
{
	class SortHelper
	{
	public:
	
		static bool CompareStrings(std::string_view first, std::string_view second);
	};

	class ProductSort
	{
	public:

		static bool ByIDAscendingly(const std::shared_ptr<Product>& p1, const std::shared_ptr<Product>& p2);
		static bool ByIDDescendingly(const std::shared_ptr<Product>& p1, const std::shared_ptr<Product>& p2);
		static bool ByNameAscendingly(const std::shared_ptr<Product>& p1, const std::shared_ptr<Product>& p2);
		static bool ByNameDescendingly(const std::shared_ptr<Product>& p1, const std::shared_ptr<Product>& p2);
		static bool ByCategoryAscendingly(const std::shared_ptr<Product>& p1, const std::shared_ptr<Product>& p2);
		static bool ByCategoryDescendingly(const std::shared_ptr<Product>& p1, const std::shared_ptr<Product>& p2);
		static bool ByAmountAscendingly(const std::shared_ptr<Product>& p1, const std::shared_ptr<Product>& p2);
		static bool ByAmountDescendingly(const std::shared_ptr<Product>& p1, const std::shared_ptr<Product>& p2);
		static bool ByUnitPriceAscendingly(const std::shared_ptr<Product>& p1, const std::shared_ptr<Product>& p2);
		static bool ByUnitPriceDescendingly(const std::shared_ptr<Product>& p1, const std::shared_ptr<Product>& p2);
		static bool ByTotalPriceAscendingly(const std::shared_ptr<Product>& p1, const std::shared_ptr<Product>& p2);
		static bool ByTotalPriceDescendingly(const std::shared_ptr<Product>& p1, const std::shared_ptr<Product>& p2);
	};

	class OperationSort
	{
	public:

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

	class ClientSort
	{
	public:

		static bool ByLoginAscendingly(const std::shared_ptr<ClientInfo>& c1, const std::shared_ptr<ClientInfo>& c2);
		static bool ByLoginDescendingly(const std::shared_ptr<ClientInfo>& c1, const std::shared_ptr<ClientInfo>& c2);
		static bool ByNameAscendingly(const std::shared_ptr<ClientInfo>& c1, const std::shared_ptr<ClientInfo>& c2);
		static bool ByNameDescendingly(const std::shared_ptr<ClientInfo>& c1, const std::shared_ptr<ClientInfo>& c2);
		static bool ByLegalEntityAscendingly(const std::shared_ptr<ClientInfo>& c1, const std::shared_ptr<ClientInfo>& c2);
		static bool ByLegalEntityDescendingly(const std::shared_ptr<ClientInfo>& c1, const std::shared_ptr<ClientInfo>& c2);
		static bool ByCountryAscendingly(const std::shared_ptr<ClientInfo>& c1, const std::shared_ptr<ClientInfo>& c2);
		static bool ByCountryDescendingly(const std::shared_ptr<ClientInfo>& c1, const std::shared_ptr<ClientInfo>& c2);
		static bool ByPhoneAscendingly(const std::shared_ptr<ClientInfo>& c1, const std::shared_ptr<ClientInfo>& c2);
		static bool ByPhoneDescendingly(const std::shared_ptr<ClientInfo>& c1, const std::shared_ptr<ClientInfo>& c2);
	};
}

