#pragma once
#include "UserInput.h"
#include "Team.h"

void Menu(Team& team, Team& current, std::vector<std::shared_ptr<Match>>& matches);
void MenuForTeam(Team& team, std::vector<std::shared_ptr<Match>>& matches);
void MenuForCurrent(Team& team, Team& current);
void MenuForMatches(Team& team, Team& current, std::vector<std::shared_ptr<Match>>& matches);

void CreateMatches_Task(std::vector<std::shared_ptr<Match>>& matches);

void CreateTeam_Task(Team& team, const std::vector<std::shared_ptr<Match>>& matches);

void ShowSportsmen_Task(const Team& team);

void ShowOneSportsman_Task(const Team& team);

void AddSportsman_Task(Team& team);

void AddMatch_Task(const Team& team, std::vector<std::shared_ptr<Match>>& matches);

void AddMatchToSportsman_Task(Team& team, const std::vector<std::shared_ptr<Match>>& matches);

void AddToCurrent_Task(const Team& team, Team& current);