
# 🎓 Student Record Management System (C Language)

A simple yet functional **Student Record Management System** built in **C**, designed for managing student data using `struct`, file handling, and a menu-driven interface.

## 🚀 Features

- Add new student records
- View all student records
- Search student by ID
- Update existing records
- Delete records
- Save and load data using `.txt` files
- Clean CLI-based menu system

## 🛠 Technologies Used

- Language: **C (ANSI C)**
- File I/O: `fopen()`, `fscanf()`, `fprintf()`
- Data Structures: `struct`, arrays
- Version Control: **Git + GitHub**

## 📸 Menu Preview

------ Student Record Management ------
1. Add Student
2. Display All Students
3. Search Student by ID
4. Delete Student by ID
5. Save to File
6. Save & Exit
---------------------------------------
Enter your choice:



## 💾 Data Storage

All student data is stored in a simple `.txt` file:</br>
***uid|Name|Grade|Avarage Marks|GPA***</br>
101|Rudro Bala|10|98.5|5.00 </br>
102|Arpita Biswas|09|93.2|5.00</br>

Each line represents one student record using `|` as a delimiter.

## 🧠 How It Works

- Data is loaded from `students.txt` into an array of `struct Student`
- You perform operations (add/update/delete) on the array
- On exit, the updated array is saved back to the file

## 📦 Getting Started

### 1. Compile the code:
```bash
gcc main.c -o student-manager
```

### 2. Run it:
```bash
./student-manager
```
> Make sure students.txt is in the same directory if you want to load existing data.



## 🤝 Contributing

Pull requests are welcome! For major changes, please open an issue first.


## 👨‍💻 Created By

Rudro Bala
📍 Sylhet, Bangladesh
🧠 16 | Dreaming Big | Exploring C