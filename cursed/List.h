#pragma once
#include <type_traits>
#include <vector>
#include <map>
#include <memory>
#include <functional>
#include <algorithm>
#include "Identifiable.h"

//#include "Operation.h"

namespace IMEX
{
	template <class ElementType>
	class List
	{
		static_assert(std::is_base_of<Identifiable, ElementType>::value, "List must contain only Identifiable elements");

	protected:

		std::vector<std::shared_ptr<ElementType>> originalElements;
		std::vector<std::shared_ptr<ElementType>> copiedElements;

	public:

		List() {};

		void Add(const ElementType& op)
		{
			auto newElement = std::make_shared<ElementType>(op);

			originalElements.push_back(newElement);
			copiedElements.push_back(newElement);
		}

		bool Contains(int ID)
		{
			for (const auto& e : originalElements)
			{
				if (e->GetID() == ID)
					return true;
			}

			return false;
		}

		void Remove(int ID)
		{
			auto it = std::find_if(originalElements.begin(), originalElements.end(),
				[ID](const std::shared_ptr<ElementType>& p) { return p->GetID() == ID; });

			const ElementType* ptr = it->get();

			if (it != originalElements.end())
				originalElements.erase(it);

			it = std::find_if(copiedElements.begin(), copiedElements.end(),
				[ptr](const std::shared_ptr<ElementType>& p) { return p.get() == ptr; });

			if (it != copiedElements.end())
				copiedElements.erase(it);
		}

		auto GetElement(int ID) -> std::shared_ptr<ElementType>
		{
			for (const auto& e : originalElements)
			{
				if (e->GetID() == ID)
					return e;
			}

			throw std::exception("Такой операции нет");
		}

		void CalculateNewID(ElementType& e)
		{
			int newID = 0;

			for (const auto& p : originalElements)
			{
				if (newID <= p->GetID())
					newID = p->GetID();
			}

			newID++;
			e.SetID(newID);
		}

		void Sort(const std::function<bool(const std::shared_ptr<ElementType>&, const std::shared_ptr<ElementType>&)>& criteria)
		{
			std::sort(copiedElements.begin(), copiedElements.end(), criteria);
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

