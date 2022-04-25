#pragma once
#include <vector>
#include <map>
#include <functional>
#include "Worker.h"

class WorkerList
{
	std::map<int, std::shared_ptr<Worker>> workers;
	std::vector<std::shared_ptr<Worker>> sortedWorkers;

public:

	WorkerList();
	WorkerList(const WorkerList& other);

	void Add(std::string_view name, std::string_view phoneNumber, int salary, int experience);
	void Remove(int id);
	bool Contains(int id) const;
	void Sort(const std::function<bool(const std::shared_ptr<Worker>&, const std::shared_ptr<Worker>&)> criteria);
	void CalculateID(Worker& worker);

	auto begin() -> std::vector<std::shared_ptr<Worker>>::iterator;
	auto begin() const -> std::vector<std::shared_ptr<Worker>>::const_iterator;
	auto end() -> std::vector<std::shared_ptr<Worker>>::iterator;
	auto end() const -> std::vector<std::shared_ptr<Worker>>::const_iterator;

	auto operator[](int id) -> std::shared_ptr<Worker>&;
	auto operator[](int id) const -> const std::shared_ptr<Worker>&;

	static bool ByIDAscendingly(const std::shared_ptr<Worker>& w1, const std::shared_ptr<Worker>& w2);
	static bool ByIDDescendingly(const std::shared_ptr<Worker>& w1, const std::shared_ptr<Worker>& w2);
	static bool ByNameAscendingly(const std::shared_ptr<Worker>& w1, const std::shared_ptr<Worker>& w2);
	static bool ByNameDescendingly(const std::shared_ptr<Worker>& w1, const std::shared_ptr<Worker>& w2);
	static bool ByPhoneAscendingly(const std::shared_ptr<Worker>& w1, const std::shared_ptr<Worker>& w2);
	static bool ByPhoneDescendingly(const std::shared_ptr<Worker>& w1, const std::shared_ptr<Worker>& w2);
	static bool BySalaryAscendingly(const std::shared_ptr<Worker>& w1, const std::shared_ptr<Worker>& w2);
	static bool BySalaryDescendingly(const std::shared_ptr<Worker>& w1, const std::shared_ptr<Worker>& w2);
	static bool ByExpAscendingly(const std::shared_ptr<Worker>& w1, const std::shared_ptr<Worker>& w2);
	static bool ByExpDescendingly(const std::shared_ptr<Worker>& w1, const std::shared_ptr<Worker>& w2);
};

