#pragma once
#include <stack>
#include <queue>
#include <vector>
#include <memory>
#include <optional>
#include "Drug.h"

class DrugList
{
	using Drugs = std::stack<std::shared_ptr<Drug>, std::vector<std::shared_ptr<Drug>>>;
	using SortedDrugs = std::priority_queue<std::shared_ptr<Drug>, std::vector<std::shared_ptr<Drug>>, decltype([](const std::shared_ptr<Drug>& p1, const std::shared_ptr<Drug>& p2) { return p1->GetID() < p2->GetID(); })>;

	Drugs drugs;
	SortedDrugs sortedDrugs;

public:

	DrugList();

	void Add(std::string_view name, std::string_view type, int amount);
	void Remove(int id);
	auto Get(int id) -> std::optional<std::shared_ptr<Drug>>; 

	void ShowInConsole();
};

