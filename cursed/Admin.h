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

    public:
        Admin();
        Admin(std::string_view login, const std::string& password);

        void UserMenu() override;

    protected:

        auto GetFolderName() -> std::string override;
        auto GetCredentialsFileName()->std::string override;
        void ClientsMenu();
        void FindClientsMenu();
        void StorageMenu();
        void AddProductTask();
        void SortStorageMenu();
        void DeleteProductTask();
        void ChangeProductTask();
        void ChangeProductMenu(std::shared_ptr<Product> product);

    };
}
