# ☕ Coffee Shop Management System (C++)

## 🚀 Overview

This project is a **Coffee Shop Management System** built in **C++**. It simulates real-world shop operations including:

* Order management
* Billing system
* Stock control
* Employee management
* Admin controls

The system uses **file handling** to store accounts, sales, and inventory data.

---

## ⚙️ Features

### 👨‍💼 Admin Panel

* Register Admin & Employee Accounts
* Delete Accounts
* View Sales Records
* Manage Employee Information
* Restock Items (Coffee, Tea, Snacks)
* Check Available Stock
* Update Item Prices

### 👨‍🍳 Employee Panel

* Login System
* Take Customer Orders
* Generate Bill
* Apply Discount
* Print Receipt
* Track Sales Automatically

---

## 🧠 Concepts Used

* Object-Oriented Programming (Struct-based design)
* File Handling (Persistent Storage)
* Arrays and Data Management
* Menu-driven Programming
* Billing Logic
* Inventory Management

---

## 💻 Requirements

* C++ Compiler (CodeBlocks / Dev C++ / Visual Studio)
* Windows OS (`conio.h` used)

---

## 📂 File Structure

```id="coffee01"
<username>.txt              → Employee account
<username>admin.txt         → Admin account
<employee>_sales.txt        → Sales records
<employee>_totalsales.txt   → Total sales summary
<employee>data.txt          → Employee personal info
stock.txt                   → Inventory and prices
```

---

## 🧾 System Workflow

### 🛒 Order Process

1. Employee logs in
2. Select category (Coffee / Tea / Snacks)
3. Choose item and quantity
4. System checks stock availability
5. Item added to bill

---

### 💵 Billing System

* Calculates total bill
* Applies discount (%)
* Accepts customer payment
* Calculates return amount
* Option to print receipt

---

### 📦 Inventory System

* Auto-updates stock after each order
* Admin can:

  * Restock items
  * Update prices
  * View stock status

---

### 📊 Sales Tracking

* Each employee has:

  * Individual sales file
  * Total sales record
* Admin can view complete sales history

---

## 🛠️ How to Run

1. Open project in C++ compiler
2. Compile and run
3. Choose mode:

   * Employee
   * Admin

---

## ⚠️ Limitations

* No database (file-based system)
* No password encryption
* CLI-based (no GUI)
* Uses basic struct instead of full OOP classes

---

## 🔥 Future Improvements

* Convert to full OOP (classes instead of structs)
* Add GUI (Qt / Web App)
* Use database (MySQL / SQLite)
* Add authentication security (hashing)
* Add analytics dashboard

---

## 👤 Author

**Abdullah Aziz**
