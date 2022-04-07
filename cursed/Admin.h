#pragma once
#include "User.h"

namespace IMEX
{
    class Admin : public User
    {
    public:
        Admin();
        Admin(std::string_view login, const std::string& password);

        void UserMenu() override;

    protected:

        auto GetFolderName() -> std::string override;
    };
}
