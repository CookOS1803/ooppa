#pragma once
#include "UserInput.h"
#include "Team.h"

void Menu(Team& team, Team& current, std::vector<std::shared_ptr<Match>>& matches);
void MenuForTeam(Team& team, Team& current, const std::vector<std::shared_ptr<Match>>& matches);
void MenuForSportsmenFind(const Team& team, const std::vector<std::shared_ptr<Match>>& matches);
void MenuForSportsmenSort(Team& team);
int GetBinaryChoice();
void ChangeSportsman_Task(Team& team, const std::vector<std::shared_ptr<Match>>& matches);
void MenuForSportsmanChange(std::shared_ptr<Sportsman>& sportsman, const std::vector<std::shared_ptr<Match>>& matches);
void MenuForCurrent(Team& team, Team& current, const std::vector<std::shared_ptr<Match>>& matches);
void MenuForMatches(Team& team, std::vector<std::shared_ptr<Match>>& matches);
void MenuForMatchesFind(const std::vector<std::shared_ptr<Match>>& matches);
void MenuForMatchesSort(std::vector<std::shared_ptr<Match>>& matches);
void MenuForMatchChange(std::shared_ptr<Match>& match);

void CreateMatches_Task(std::vector<std::shared_ptr<Match>>& matches);

void CreateTeam_Task(Team& team, const std::vector<std::shared_ptr<Match>>& matches);

void ShowSportsmen_Task(const Team& team);

void ShowOneSportsman_Task(const Team& team);

void AddSportsman_Task(Team& team);

void DeleteSportsman_Task(Team& team, Team& current, const std::vector<std::shared_ptr<Match>>& matches);

void AddMatch_Task(const Team& team, std::vector<std::shared_ptr<Match>>& matches);

void AddMatchToSportsman_Task(Team& team, const std::vector<std::shared_ptr<Match>>& matches);

void AddToCurrent_Task(const Team& team, Team& current);