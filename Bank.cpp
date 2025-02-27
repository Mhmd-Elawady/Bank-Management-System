#include <iostream>
#include <string>
using namespace std;
struct Branch {
    int id;
    string name;
    string manager;
    Branch* next;
};
struct AccountHolder {
    int id;
    int branchID;
    string name;
    string address;
    double balance;
    AccountHolder* next;
};

class BankManagementSystem {

    Branch* branchhead;
    AccountHolder* holderhead;

public:
    BankManagementSystem() {
        branchhead = NULL;
        holderhead = NULL;
    }

    void addBranch(int id, string name, string manager)
    {
        Branch* newBranch = new Branch
        { id, name, manager, NULL };

        if (branchhead == NULL) {
            newBranch->next = NULL; 
            branchhead = newBranch;
        }
        else {
            newBranch->next = branchhead;
            branchhead = newBranch;
        }
        cout << " Branch added successfully.\n";
    }

    void displayBranches() {
        Branch* display = branchhead;
        if (branchhead == NULL)
        cout<<" No branches\n";
        else{
        while (display != NULL) {
            cout << " Branch ID: " << display->id<<endl;
            cout << " Name : " << display->name <<endl;
            cout << " Manager : " << display->manager << endl;
            display = display->next;}
        }
    }

    Branch* searchBranchById(int id) {
        Branch* search = branchhead;
        while (search != NULL) {
            if (search->id == id) {
                return search;
            }
            search = search->next;
        }
        return NULL;
    }

void addAccountHolder(int id,int branchID, string name, string address, double balance) {
    AccountHolder* newHolder = new AccountHolder
    { id ,branchID ,name, address, balance, NULL};

    if (holderhead == NULL || balance > holderhead->balance) {
        newHolder->next = holderhead;
        holderhead = newHolder;
    }
    else {
        AccountHolder* current = holderhead;
        AccountHolder* previous = NULL;

        while (current != NULL && balance <= current->balance) {
            previous = current;
            current = current->next;
        }

        previous->next = newHolder;
        newHolder->next = current;
    }

    cout << " Account Holder added successfully.\n";
}

    void removeAccountHolder(int id) {
        AccountHolder* remove = holderhead;
        AccountHolder* prev = NULL;

        while (remove != NULL && remove->id != id) {
            prev = remove;
            remove = remove->next;
        }

        if (remove != NULL) {
            if (prev != NULL) {
                prev->next = remove->next;
            }
            else {
                holderhead = remove->next;
            }

            delete remove;
            cout << " Account Holder removed successfully.\n";
        }
        else {
            cout << " Account Holder not found.\n";
        }
    }

    void displayAccountHolders() {
        if(holderhead==NULL) 
        cout << " NO Account Holder \n";
        else{
        AccountHolder* display = holderhead;
        while (display != NULL) {
            cout << " Holder ID : " << display->id << endl;
            cout << " Name : " << display->name << endl;
            cout << " Address : " << display->address << endl;
            cout << " Balance : " << display->balance << endl;
            display = display->next;
        }
        }
    }

    AccountHolder* searchHolderByName(string name) {
        AccountHolder* search = holderhead;
        while (search != NULL) {
            if (search->name == name) {
                return search;
            }
            search = search->next;
        }
        return NULL;
    }

void updateHolderInformation(int id,int branchID, string newName, string newAddress, double newBalance) {
    removeAccountHolder(id);
    addAccountHolder( id,branchID, newName, newAddress, newBalance);
    cout << " Holder information updated successfully.\n";
}


    void displayHoldersOrderedByBalances() {
        if(holderhead==NULL) 
        cout << " NO Account Holder \n";
        else{
        Branch* display = branchhead;
        while (display != NULL) {
            cout << " Branch ID: " << display->id<<endl;
            cout << " Name : " << display->name <<endl;
            cout << " Manager : " << display->manager << endl;
            display = display->next;
        }
        }
    }

    void displayHoldersInBranch(int branchId) {
        Branch* branch = searchBranchById(branchId);

        if (branch != NULL) {
            AccountHolder* display = holderhead;
            while (display != NULL) {
                if (display->branchID== branchId) {
                    cout<< " Holder ID : " << display->id <<endl;
                    cout<< " Name : " << display->name <<endl; 
                    cout<< " Address : " << display->address <<endl;
                    cout<< " Balance : " << display->balance << endl;
                }
                display = display->next;
            }
        }
        else {
            cout << " Branch not found.\n";
        }
    }

    void removeBranch(int branchId) {
        Branch* remove = branchhead;
        Branch* prev = NULL;

        while (remove != NULL && remove->id != branchId) {
            prev = remove;
            remove = remove->next;
        }

        if (remove != NULL) {
            if (prev != NULL) {
                prev->next = remove->next;
            }
            else {
                branchhead = remove->next;
            }

            delete remove;
            cout << " Branch removed successfully.\n";
        }
        else {
            cout << " Branch not found.\n";
        }
    }
};

int main() {
    BankManagementSystem bankSystem;
    int choice;
    do {
        cout << "\nBank Management System Menu:\n";
        cout << " 1. Add new branch\n";
        cout << " 2. Display branches\n";
        cout << " 3. Search for branch by ID\n";
        cout << " 4. Add new account holder\n";
        cout << " 5. Remove account holder\n";
        cout << " 6. Display account holders\n";
        cout << " 7. Search for account holder by name\n";
        cout << " 8. Update account holder information\n";
        cout << " 9. Display holders ordered by balances \n";
        cout << " 10. Display holders in a branch \n";
        cout << " 11. Remove branch \n";
        cout << " 0. Exit\n";
        cout << " Enter your choice please : ";
        cin >> choice;
        
        switch (choice) {
        case 1: {
            int id;
            string name, manager;
            cout << " Enter branch ID : ";
            cin >> id;
            cout << " Enter branch name : ";
            cin>>name;
            cout << " Enter branch manager : ";
            cin>>manager;
            bankSystem.addBranch(id, name, manager);
            break;
        }
        case 2:
            bankSystem.displayBranches();
            break;
        case 3: {
            int id;
            cout << " Enter branch ID to search: ";
            cin >> id;
            Branch* branch = bankSystem.searchBranchById(id);
            if (branch != NULL) {
                cout << " Branch found " <<endl;
                cout<< " His ID is " << branch->id <<endl;
                cout<< " His Name is " << branch->name <<endl;
                cout<< " Manager is " << branch->manager << endl;
            } else {
                cout << " Branch not found.\n";
            }
            break;
        }
        case 4: {
            int id;
            string name, address;
            double balance;
            int branchID;
            cout << " Enter account holder ID : ";
            cin >> id;
            cout << " Enter account holder Branch ID : ";
            cin >>branchID ;
            cout << " Enter account holder name : ";
            cin>>name;
            cout << " Enter account holder address : ";
            cin>>address;
            cout << " Enter account holder balance : ";
            cin >> balance;
            bankSystem.addAccountHolder(id,branchID, name, address, balance);
            break;
        }
        case 5: {
            int id;
            cout << " Enter account holder ID to remove : ";
            cin >> id;
            bankSystem.removeAccountHolder(id);
            break;
        }
        case 6:
            bankSystem.displayAccountHolders();
            break;
        case 7: {
            string name;
            cout << " Enter account holder name to search: ";
            cin>> name;
            AccountHolder* holder = bankSystem.searchHolderByName(name);
            if (holder != NULL) {
                cout <<" Account Holder found "<<endl;
                cout<<" His  ID is " << holder->id <<endl;
                cout<<" His Name is " << holder->name <<endl;
                cout<<" His Address is " << holder->address <<endl;
                cout<<" His Balance is " << holder->balance << endl;
            } else {
                cout << " Account Holder not found.\n";
            }
            break;
        }
        case 8: {
            int id;
            string newName, newAddress;
            double newBalance;
            int branchID;
            cout << " Enter account holder ID to update: ";
            cin >> id;
            cout << " Enter account holder Branch ID : ";
            cin >>branchID;
            cout << " Enter new name : ";
            cin>> newName;
            cout << " Enter new address : ";
            cin>>newAddress;
            cout << " Enter new balance : ";
            cin >> newBalance;
            bankSystem.updateHolderInformation(id,branchID,newName, newAddress, newBalance);
            break; 
        }
        case 9:
            bankSystem.displayHoldersOrderedByBalances();
            break;
        case 10: {
            int branchId;
            cout << " Enter branch ID to display holders : ";
            cin >> branchId;
            bankSystem.displayHoldersInBranch(branchId);
            break;
        }
        case 11: {
            int branchId;
            cout << " Enter branch ID to remove : ";
            cin >> branchId;
            bankSystem.removeBranch(branchId);
            break;
        }
        case 0:
            cout << " Exiting program.\n";
            break;
        default:
            cout << " Invalid choice. Please try again.\n";
        }

    }
    while (choice != 0);

    return 0;
}