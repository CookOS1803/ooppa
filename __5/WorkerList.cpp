#include "WorkerList.h"
#include <algorithm>

WorkerList::WorkerList()
{
}

WorkerList::WorkerList(const WorkerList& other)
	: workers(other.workers), sortedWorkers(other.sortedWorkers)
{
}

void WorkerList::Add(std::string_view name, std::string_view phoneNumber, int salary, int experience)
{
	auto newWorker = std::make_shared<Worker>(name, phoneNumber, salary, experience);
	CalculateID(*newWorker);

	workers[newWorker->GetID()] = newWorker;
	sortedWorkers.push_back(newWorker);
}

void WorkerList::Remove(int id)
{
	workers.erase(id);

	auto it = std::find_if(sortedWorkers.begin(), sortedWorkers.end(), [id](const std::shared_ptr<Worker>& w) { return w->GetID() == id; });

	if (it != sortedWorkers.end())
		sortedWorkers.erase(it);
}

bool WorkerList::Contains(int id) const
{
	return workers.contains(id);
}

void WorkerList::Sort(const std::function<bool(const std::shared_ptr<Worker>&, const std::shared_ptr<Worker>&)> criteria)
{
	std::sort(sortedWorkers.begin(), sortedWorkers.end(), criteria);
}

void WorkerList::CalculateID(Worker& worker)
{
	if (workers.empty())
		return;

	auto it = workers.end();
	--it;

	worker.SetID(it->first + 1);
}

auto WorkerList::begin() -> std::vector<std::shared_ptr<Worker>>::iterator
{
	return sortedWorkers.begin();
}

auto WorkerList::begin() const -> std::vector<std::shared_ptr<Worker>>::const_iterator
{
	return sortedWorkers.begin();
}

auto WorkerList::end() -> std::vector<std::shared_ptr<Worker>>::iterator
{
	return sortedWorkers.end();
}

auto WorkerList::end() const -> std::vector<std::shared_ptr<Worker>>::const_iterator
{
	return sortedWorkers.end();
}

auto WorkerList::operator[](int id) -> std::shared_ptr<Worker>&
{
	return workers[id];
}

auto WorkerList::operator[](int id) const -> const std::shared_ptr<Worker>&
{
	return workers.at(id);
}

bool WorkerList::ByIDAscendingly(const std::shared_ptr<Worker>& w1, const std::shared_ptr<Worker>& w2)
{
	return w1->GetID() < w2->GetID();
}

bool WorkerList::ByIDDescendingly(const std::shared_ptr<Worker>& w1, const std::shared_ptr<Worker>& w2)
{
	return w1->GetID() > w2->GetID();
}

bool WorkerList::ByNameAscendingly(const std::shared_ptr<Worker>& w1, const std::shared_ptr<Worker>& w2)
{
	return w1->GetName()[0] < w2->GetName()[0];
}

bool WorkerList::ByNameDescendingly(const std::shared_ptr<Worker>& w1, const std::shared_ptr<Worker>& w2)
{
	return w1->GetName()[0] > w2->GetName()[0];
}

bool WorkerList::ByPhoneAscendingly(const std::shared_ptr<Worker>& w1, const std::shared_ptr<Worker>& w2)
{
	return w1->GetPhoneNumber()[0] < w2->GetPhoneNumber()[0];
}

bool WorkerList::ByPhoneDescendingly(const std::shared_ptr<Worker>& w1, const std::shared_ptr<Worker>& w2)
{
	return w1->GetPhoneNumber()[0] > w2->GetPhoneNumber()[0];
}

bool WorkerList::BySalaryAscendingly(const std::shared_ptr<Worker>& w1, const std::shared_ptr<Worker>& w2)
{
	return w1->GetSalary() < w2->GetSalary();
}

bool WorkerList::BySalaryDescendingly(const std::shared_ptr<Worker>& w1, const std::shared_ptr<Worker>& w2)
{
	return w1->GetSalary() > w2->GetSalary();
}

bool WorkerList::ByExpAscendingly(const std::shared_ptr<Worker>& w1, const std::shared_ptr<Worker>& w2)
{
	return w1->GetExperience() < w2->GetExperience();
}

bool WorkerList::ByExpDescendingly(const std::shared_ptr<Worker>& w1, const std::shared_ptr<Worker>& w2)
{
	return w1->GetExperience() > w2->GetExperience();
}

