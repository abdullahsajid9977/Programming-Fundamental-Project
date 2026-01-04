# Inventory Management System (C Language)

📌 Project Description
This project is a **console-based Inventory Management System** developed in **C language**.  
It helps manage **Suppliers, Purchases,Product and Sales** using structured programming concepts.

The system allows users to:
- Add new records
- Display records
- Search records
- Delete records

All data is stored **in memory using structures and arrays**.


 🛠 Features

1️⃣ Supplier Management
- Add supplier details
- Display all suppliers
- Search supplier by:
  - Supplier ID
  - Supplier Name
- Delete supplier records


2️⃣ Purchase Management
- Enter purchase details
- Display all purchases
- Search purchase by:
  - Purchase ID
  - Supplier ID
- Delete purchase records

 3️⃣ Sale Management
- Enter sale details
- Display all sales
- Search sales by:
  - Sale ID
  - Product ID
- Delete sale records

  2️⃣ Product Management
- Enter product details
- Display all products
- Search product
- Delete puroduct records


🧱 Data Structures Used
- `struct supplier`
- `struct purchase`
- `struct sale`
- Nested date structures for sales and purchases

Arrays are used to store records with a maximum capacity of **100 entries**.

---

 ▶️ How to Run the Program

1. Open terminal or command prompt
2. Compile the program:
   ```bash
   gcc inventory.c -o inventory
