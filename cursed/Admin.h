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
        ProductList requests;
        OperationList operations;

    public:
        Admin();
        Admin(std::string_view login, const std::string& password);

        void UserMenu() override;

    protected:

        auto GetFolderName() -> std::string override;
        auto GetCredentialsFileName()->std::string override;
        void ClientsMenu();
        void ShowClientTask();
        void SortClientsMenu();
        void FilterClientsMenu();
        void OperationsMenu();
        void SortOperationsMenu();
        void FilterOperationsMenu();
        void HandleOperationTask();
        void StorageMenu(ProductList& curr);
        void AddProductTask(ProductList& curr);
        void SortStorageMenu(ProductList& curr);
        void FilterStorageMenu(ProductList& curr);
        void DeleteProductTask(ProductList& curr);
        void ChangeProductTask(ProductList& curr);
        void ChangeProductMenu(std::shared_ptr<Product> product);
        void AdminsMenu();
        void AddAdminTask();
        void RemoveAdminTask();

    };
}
