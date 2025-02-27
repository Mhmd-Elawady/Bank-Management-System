
# Bank Management System

## Overview
- The Bank Management System is a C++ console-based application.
- Designed to manage bank branches and account holders using linked lists.
- Provides basic banking operations through an interactive menu-driven interface.

## Features
- **Branch Management**: Add, remove, display, and search for branches by ID.
- **Account Holder Management**: Add, remove, update, and display account holders, sorted by balance.
- **Search Functionality**: Search for account holders by name and branches by ID.
- **Branch-Specific Views**: Display all account holders associated with a specific branch.
- **Data Persistence**: Uses linked lists for dynamic memory allocation and data storage.

## Project Structure
- **Branch**: Stores branch details (ID, name, manager) in a singly linked list.
- **AccountHolder**: Stores account holder details (ID, branch ID, name, address, balance) in a singly linked list, sorted by balance.
- **BankManagementSystem class**: Encapsulates all functionality for managing data.

### Key Functions
- `addBranch(int id, string name, string manager)`: Adds a new branch.
- `displayBranches()`: Shows all branches.
- `searchBranchById(int id)`: Finds a branch by its ID.
- `addAccountHolder(int id, int branchID, string name, string address, double balance)`: Adds a new account holder, sorted by balance.
- `removeAccountHolder(int id)`: Deletes an account holder by ID.
- `displayAccountHolders()`: Displays all account holders.
- `searchHolderByName(string name)`: Searches for an account holder by name.
- `updateHolderInformation(int id, int branchID, string newName, string newAddress, double newBalance)`: Updates account holder details.
- `displayHoldersInBranch(int branchId)`: Lists account holders in a specific branch.
- `removeBranch(int branchId)`: Deletes a branch by ID.

## How to Use
- **Compile the Code**: Use a C++ compiler (e.g., g++).
  - Command: `g++ main.cpp -o bank_system`
- **Run the Program**: Execute the compiled file.
  - Command: `./bank_system`
- **Interact with the Menu**: Choose options (0-11) to perform operations.

### Menu Options
- `1`: Add a new branch.
- `2`: Display all branches.
- `3`: Search for a branch by ID.
- `4`: Add a new account holder.
- `5`: Remove an account holder.
- `6`: Display all account holders.
- `7`: Search for an account holder by name.
- `8`: Update account holder information.
- `9`: Display holders ordered by balance (Note: Current implementation may need adjustment).
- `10`: Display holders in a specific branch.
- `11`: Remove a branch.
- `0`: Exit the program.

## Requirements
- A C++ compiler (e.g., g++, Visual Studio).
- Basic understanding of C++ and linked lists.

## Limitations
- `displayHoldersOrderedByBalances()`: Currently displays branches instead of ordered account holders (potential bug).
- No file-based data persistence: Data is lost when the program exits.
- No input validation: For edge cases like negative balances or duplicate IDs.

## Future Improvements
- Fix `displayHoldersOrderedByBalances()` to correctly display account holders.
- Add input validation for IDs, balances, and other fields.
- Implement file I/O to save and load data.
- Enhance the UI with better formatting or a graphical interface.

## License
- This project is open-source and available for educational use.
