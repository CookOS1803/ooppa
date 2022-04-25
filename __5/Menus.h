#pragma once

void MainMenu(class WorkerList& workers);

void ShowWorkersTask(const class WorkerList& workers);

void ShowOneWorkerTask(const WorkerList& workers);

void ShowWorker(const class Worker& worker);

void SortWorkersTask(WorkerList& workers);

void AddWorkerTask(WorkerList& workers);

void RemoveWorkerTask(WorkerList& workers);

void ChangeWorkerTask(WorkerList& workers);

void FindWorkerTask(const WorkerList& workers);

void SaveWorkersToFile(const WorkerList& workers);
