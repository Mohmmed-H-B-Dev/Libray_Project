# 📚 Library & Inventory Management System (C++)

​A comprehensive Object-Oriented Console Application written in C++ for managing library operations, inventory, sales, and user administration. It implements full CRUD (Create, Read, Update, Delete) operations using a flat-file (non-relational) database system based on text files (.txt) for data persistence.

---

## 🌟 Key Features

### 🔐 1. Authentication & User Management
* **Secure Login System**: Authenticate users with username and password.
* **Role-Based Permissions**: Manage administrative and standard user access levels.
* **User CRUD Operations**:
  * 📋 Show User List
  * ➕ Add New User
  * ✏️ Update User Information
  * ❌ Delete User
  * 🔍 Find User

---

### 📦 2. Inventory & Stock Management
* **Item & Product Management**: Full CRUD capabilities for books and store items.
* **Stock Tracking**: Monitor item quantities, categories, tax percentages, and unit prices.
* **Transfer Bonds & Adjustments**: Handle inventory movements and updates seamlessly.

---

### 📖 3. Author & Book Cataloging
* **Author Directory**: Add, update, search, and remove author profiles.
* **Book Records**: Maintain accurate book data, borrowings, and pending requests.

---

### 💳 4. Sales & Transactions
* **Point of Sale (POS)**: Generate invoices and complete sale operations.
* **Pending Orders**: View and process customer pending orders.
* **Transaction History**: Track sales and financial logs.

---

## 🛠️ Architecture & Tech Stack

* **Language**: C++ (Object-Oriented Programming)
* **Design Pattern**: Layered UI/Logic architecture:
  * **Core Models**: `clsPerson`, `clsUser`, `clsClient`, `clsAuthor`, `clsBook`, `clsInvoice`, `clsItem`
  * **UI Screens**: Modular screen classes handling user inputs and displays (e.g., `clsAddNewUserScreen`, `clsUpdateUserScreen`, `clsLoginScreen`)
* **Data Persistence**: Text-file storage (`Users.txt`, `Items.txt`, `Authers.txt`, etc.) for lightweight data management.

---

## 🚀 How to Run

1. **Requirements**: Visual Studio 2019/2022 (C++ Desktop Development Workload) or any compatible C++ compiler.
2. **Open Project**: Open the solution file `Libray_Project.sln` in Visual Studio.
3. **Build & Run**: Compile and run the application (`Ctrl + F5`).
