#pragma once
#include "User.h"
#include "ClientsList.h"
#include "ProductList.h"
#include "OperationList.h"

namespace IMEX
{
    class Admin : public User
    {
        ClientsList clients;
        ProductList products;
        OperationList operations;

    public:
        Admin();
        Admin(std::string_view login, const std::string& password);

        void UserMenu() override;

    protected:

        auto GetFolderName() -> std::string override;
        void ClientsMenu();
    };
}
