#include <Windows.h>
#include "UserInput.h"
#include "Tasks.h"
#include "Util.h"
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

    Menu(team, current, matches);

    return 0;
}
