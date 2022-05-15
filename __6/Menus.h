#pragma once

class Drug;
class DrugList;

void MainMenu();

void AddDrugTask(DrugList& drugs);

void RemoveDrugTask(DrugList& drugs);

void ChangeDrugTask(DrugList& drugs);

void ShowDrug(const Drug& drug);
