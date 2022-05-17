#include "SortHelper.h"
#include <algorithm>

bool IMEX::SortHelper::CompareStrings(std::string_view first, std::string_view second)
{
    auto len = std::min(first.size(), second.size());

    for (int i = 0; i < len; i++)
    {
        if (first[i] == second[i])
            continue;

        return first[i] < second[i];
    }

    return len == first.size();
}

bool IMEX::ProductSort::ByIDAscendingly(const std::shared_ptr<Product>& p1, const std::shared_ptr<Product>& p2)
{
	return p1->GetID() < p2->GetID();
}

bool IMEX::ProductSort::ByIDDescendingly(const std::shared_ptr<Product>& p1, const std::shared_ptr<Product>& p2)
{
	return p1->GetID() > p2->GetID();
}

bool IMEX::ProductSort::ByNameAscendingly(const std::shared_ptr<Product>& p1, const std::shared_ptr<Product>& p2)
{
	return SortHelper::CompareStrings(p1->GetName(), p2->GetName());
}

bool IMEX::ProductSort::ByNameDescendingly(const std::shared_ptr<Product>& p1, const std::shared_ptr<Product>& p2)
{
	return !ByNameAscendingly(p1, p2);
}

bool IMEX::ProductSort::ByCategoryAscendingly(const std::shared_ptr<Product>& p1, const std::shared_ptr<Product>& p2)
{
	return SortHelper::CompareStrings(p1->GetCategory(), p2->GetCategory());
}

bool IMEX::ProductSort::ByCategoryDescendingly(const std::shared_ptr<Product>& p1, const std::shared_ptr<Product>& p2)
{
	return !ByCategoryAscendingly(p1, p2);
}

bool IMEX::ProductSort::ByAmountAscendingly(const std::shared_ptr<Product>& p1, const std::shared_ptr<Product>& p2)
{
	return p1->GetAmount() < p2->GetAmount();
}

bool IMEX::ProductSort::ByAmountDescendingly(const std::shared_ptr<Product>& p1, const std::shared_ptr<Product>& p2)
{
	return p1->GetAmount() > p2->GetAmount();
}

bool IMEX::ProductSort::ByUnitPriceAscendingly(const std::shared_ptr<Product>& p1, const std::shared_ptr<Product>& p2)
{
	return p1->GetUnitPrice() < p2->GetUnitPrice();
}

bool IMEX::ProductSort::ByUnitPriceDescendingly(const std::shared_ptr<Product>& p1, const std::shared_ptr<Product>& p2)
{
	return p1->GetUnitPrice() > p2->GetUnitPrice();
}

bool IMEX::ProductSort::ByTotalPriceAscendingly(const std::shared_ptr<Product>& p1, const std::shared_ptr<Product>& p2)
{
	return p1->GetTotalPrice() < p2->GetTotalPrice();
}

bool IMEX::ProductSort::ByTotalPriceDescendingly(const std::shared_ptr<Product>& p1, const std::shared_ptr<Product>& p2)
{
	return p1->GetTotalPrice() > p2->GetTotalPrice();
}

bool IMEX::OperationSort::ByIDAscendingly(const std::shared_ptr<Operation>& o1, const std::shared_ptr<Operation>& o2)
{
	return o1->GetID() < o2->GetID();
}

bool IMEX::OperationSort::ByIDDescendingly(const std::shared_ptr<Operation>& o1, const std::shared_ptr<Operation>& o2)
{
	return o1->GetID() > o2->GetID();
}

bool IMEX::OperationSort::ByTypeAscendingly(const std::shared_ptr<Operation>& o1, const std::shared_ptr<Operation>& o2)
{
	return o1->GetType() < o2->GetType();
}

bool IMEX::OperationSort::ByTypeDescendingly(const std::shared_ptr<Operation>& o1, const std::shared_ptr<Operation>& o2)
{
	return o1->GetType() > o2->GetType();
}

bool IMEX::OperationSort::ByStatusAscendingly(const std::shared_ptr<Operation>& o1, const std::shared_ptr<Operation>& o2)
{
	return o1->GetStatus() < o2->GetStatus();
}

bool IMEX::OperationSort::ByStatusDescendingly(const std::shared_ptr<Operation>& o1, const std::shared_ptr<Operation>& o2)
{
	return o1->GetStatus() > o2->GetStatus();
}

bool IMEX::OperationSort::ByProductIDAscendingly(const std::shared_ptr<Operation>& o1, const std::shared_ptr<Operation>& o2)
{
	return o1->GetElementID() < o2->GetElementID();
}

bool IMEX::OperationSort::ByProductIDDescendingly(const std::shared_ptr<Operation>& o1, const std::shared_ptr<Operation>& o2)
{
	return o1->GetElementID() > o2->GetElementID();
}

bool IMEX::OperationSort::ByProductAmountAscendingly(const std::shared_ptr<Operation>& o1, const std::shared_ptr<Operation>& o2)
{
	return o1->GetElementAmount() < o2->GetElementAmount();
}

bool IMEX::OperationSort::ByProductAmountDescendingly(const std::shared_ptr<Operation>& o1, const std::shared_ptr<Operation>& o2)
{
	return o1->GetElementAmount() > o2->GetElementAmount();
}

bool IMEX::OperationSort::ByClientLoginAscendingly(const std::shared_ptr<Operation>& o1, const std::shared_ptr<Operation>& o2)
{
	return SortHelper::CompareStrings(o1->GetClientLogin(), o2->GetClientLogin());
}

bool IMEX::OperationSort::ByClientLoginDescendingly(const std::shared_ptr<Operation>& o1, const std::shared_ptr<Operation>& o2)
{
	return !ByClientLoginAscendingly(o1, o2);
}

bool IMEX::ClientSort::ByLoginAscendingly(const std::shared_ptr<ClientInfo>& c1, const std::shared_ptr<ClientInfo>& c2)
{
	return SortHelper::CompareStrings(c1->GetLogin(), c2->GetLogin());
}

bool IMEX::ClientSort::ByLoginDescendingly(const std::shared_ptr<ClientInfo>& c1, const std::shared_ptr<ClientInfo>& c2)
{
	return !ByLoginAscendingly(c1, c2);
}

bool IMEX::ClientSort::ByNameAscendingly(const std::shared_ptr<ClientInfo>& c1, const std::shared_ptr<ClientInfo>& c2)
{
	return SortHelper::CompareStrings(c1->GetName(), c2->GetName());
}

bool IMEX::ClientSort::ByNameDescendingly(const std::shared_ptr<ClientInfo>& c1, const std::shared_ptr<ClientInfo>& c2)
{
	return !ByNameAscendingly(c1, c2);
}

bool IMEX::ClientSort::ByLegalEntityAscendingly(const std::shared_ptr<ClientInfo>& c1, const std::shared_ptr<ClientInfo>& c2)
{
	return SortHelper::CompareStrings(c1->GetLegalEntity(), c2->GetLegalEntity());
}

bool IMEX::ClientSort::ByLegalEntityDescendingly(const std::shared_ptr<ClientInfo>& c1, const std::shared_ptr<ClientInfo>& c2)
{
	return !ByLegalEntityAscendingly(c1, c2);
}

bool IMEX::ClientSort::ByCountryAscendingly(const std::shared_ptr<ClientInfo>& c1, const std::shared_ptr<ClientInfo>& c2)
{
	return SortHelper::CompareStrings(c1->GetCountry(), c2->GetCountry());
}

bool IMEX::ClientSort::ByCountryDescendingly(const std::shared_ptr<ClientInfo>& c1, const std::shared_ptr<ClientInfo>& c2)
{
	return !ByCountryAscendingly(c1, c2);
}

bool IMEX::ClientSort::ByPhoneAscendingly(const std::shared_ptr<ClientInfo>& c1, const std::shared_ptr<ClientInfo>& c2)
{
	return SortHelper::CompareStrings(c1->GetPhone(), c2->GetPhone());
}

bool IMEX::ClientSort::ByPhoneDescendingly(const std::shared_ptr<ClientInfo>& c1, const std::shared_ptr<ClientInfo>& c2)
{
	return !ByPhoneAscendingly(c1, c2);
}
