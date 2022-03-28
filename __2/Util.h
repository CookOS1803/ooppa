#pragma once
#include <iostream>
#include <iomanip>
#include "Sportsman.h"

void Terminate();

std::ostream& table(std::ostream& stream);

void ShowMatches(const std::vector<std::shared_ptr<Match>>& matches);

void ShowSportsman(const Sportsman& s);