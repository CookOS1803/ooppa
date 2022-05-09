#pragma once
#include <type_traits>
#include <vector>
#include <map>
#include <memory>
#include <functional>
#include <algorithm>
#include "Identifiable.h"

namespace IMEX
{
	// Шаблон класса
	template <class ElementType, class IDType>
	class List
	{
		static_assert(std::is_base_of<Identifiable<IDType>, ElementType>::value, "List must contain only Identifiable elements");

	protected:

		// Использование умных указателей
		std::map<IDType, std::shared_ptr<ElementType>> originalElements;
		std::vector<std::shared_ptr<ElementType>> copiedElements;

	public:

		List() {};
		virtual ~List() {};

		void Add(const ElementType& op)
		{
			auto newElement = std::make_shared<ElementType>(op);

			originalElements[newElement->GetID()] = newElement;

			if (DoesMatchFilters(newElement))
				copiedElements.push_back(newElement);
		}

		bool Contains(IDType ID)
		{
			return originalElements.contains(ID);
		}

		void Remove(IDType ID)
		{
			originalElements.erase(ID);

			auto it = std::find_if(copiedElements.begin(), copiedElements.end(), [ID](const std::shared_ptr<ElementType>& w) { return w->GetID() == ID; });

			if (it != copiedElements.end())
				copiedElements.erase(it);
		}

		auto GetElement(IDType ID) -> std::shared_ptr<ElementType>
		{
			if (originalElements.contains(ID))
				return originalElements[ID];
			else
				throw std::exception("Такой записи нет");
		}

		void Sort(const std::function<bool(const std::shared_ptr<ElementType>&, const std::shared_ptr<ElementType>&)>& criteria)
		{
			std::sort(copiedElements.begin(), copiedElements.end(), criteria);
		}

		virtual bool DoesMatchFilters(const std::shared_ptr<ElementType>& e) const
		{
			return true;
		}

		void ApplyFilters()
		{
			copiedElements.clear();

			for (const auto& tuple : originalElements)
			{
				const auto& e = tuple.second;

				if (DoesMatchFilters(e))
				{
					copiedElements.push_back(e);
				}
			}
		}

		auto begin() -> class std::vector<std::shared_ptr<ElementType>>::iterator
		{
			return copiedElements.begin();
		}
		auto begin() const -> class std::vector<std::shared_ptr<ElementType>>::const_iterator
		{
			return copiedElements.begin();
		}
		auto end() -> class std::vector<std::shared_ptr<ElementType>>::iterator
		{
			return copiedElements.end();
		}
		auto end() const -> class std::vector<std::shared_ptr<ElementType>>::const_iterator
		{
			return copiedElements.end();
		}
	};
}

