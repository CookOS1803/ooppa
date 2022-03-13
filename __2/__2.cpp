#include <Windows.h>
#include "UserInput.h"
#include "Tasks.h"
#include "Team.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    set_terminate(Terminate);

    std::vector<std::shared_ptr<Match>> matches;
    CreateMatches_Task(matches);

    Team team("komanda");
    CreateTeam_Task(team, matches);

    Team current("current");

    int choice;
    bool exit = false;
        
    while (!exit)
    {
        INPUT
        (
            std::cout
                << "1. Показать всех спортсменов\n"
                << "2. Показать конкретного спортсмена\n"
                << "3. Показать матчи\n"
                << "4. Добавить спортсмена\n"
                << "5. Добавить матч\n"
                << "6. Добавить матч спортсмену\n"
                << "7. Показать состав для следующего матча\n"
                << "8. Добавить спортсмена в состав для следующего матча\n"
                << "0. Выход\n",
            choice
        );
        
        switch (choice)
        {
            case 1:
                ShowSportsmen_Task(team);
                break;
            case 2:
                ShowOneSportsman_Task(team);
                break;
            case 3:
                ShowMatches(matches);
                break;
            case 4:
                AddSportsman_Task(team);
                break;
            case 5:
                AddMatch_Task(team, matches);
                break;
            case 6:
                AddMatchToSportsman_Task(team, matches);
                break;
            case 7:
                ShowSportsmen_Task(current);
                break;
            case 8:
                AddToCurrent(team, current);
                break;
            case 0:
                exit = true;
        }
    }

    return 0;
}
