Student Record Management System
Description
The Student Record Management System is a console-based application written in C++. It allows users to manage student records, including adding, displaying, searching, updating, deleting, sorting, saving to a file, and loading from a file. The data is stored in a text file, ensuring persistence between program executions.

Features
Add New Student Record: Enter details for new students and add them to the record.
Display All Records: Show a tabular view of all student records.
Search Records: Search for students by roll number, name, or mobile number.
Update Record: Modify existing student details.
Delete Record: Remove a student's record by roll number or delete all records.
Sort Records: Sort records by roll number, name, or admission year.
Save Data to File: Save all student records to a text file.
Load Data from File: Load student records from a text file.
Getting Started
Prerequisites
A C++ compiler (e.g., GCC, MSVC)
Basic knowledge of C++ and command line operations
Installing
Clone the repository or download the source code.
Compile the code using your preferred C++ compiler.
Example compilation command using g++:

bash
Copy code
g++ -o student_management main.cpp
Running the Program
Run the compiled executable:

bash
Copy code
./student_management
Usage
On running the program, you will be presented with a menu:
markdown
Copy code
----- Student Record Management System -----
1. Enter new student record
2. Display all records
3. Search records
4. Update record
5. Delete record
6. Sort records
7. Save data to file
8. Load data from file
9. Exit
Enter your choice:
Choose an option by entering the corresponding number.
Follow the prompts to perform the desired action.
Functions
enter()
Prompts the user to enter the number of students and their details, and adds them to the records.

show()
Displays all student records in a tabular format.

search()
Searches for students by roll number, name, or mobile number and displays matching records.

update()
Updates the details of a student by roll number.

deleteRecord()
Deletes a student record by roll number or deletes all records.

sortRecords()
Sorts the student records by roll number, name, or admission year.

saveToFile()
Saves all student records to a text file (students.txt).

loadFromFile()
Loads student records from a text file (students.txt).

File Format
The student records are saved in students.txt in the following format:

vbnet
Copy code
roll_no|name|Class|course|mobile_no|admission_year
Each record is on a new line, and fields are separated by the | character.

Example
yaml
Copy code
----- Student Record Management System -----
1. Enter new student record
2. Display all records
3. Search records
4. Update record
5. Delete record
6. Sort records
7. Save data to file
8. Load data from file
9. Exit
Enter your choice: 1
How many students do you want to enter? 2

Enter the Data for Student 1:
Roll No: 101
Name: John Doe
Class: 12A
Course: Science
Mobile No: 1234567890
Admission Year: 2020

Enter the Data for Student 2:
Roll No: 102
Name: Jane Smith
Class: 12B
Course: Commerce
Mobile No: 0987654321
Admission Year: 2021

Enter your choice: 2

-------------------------------------------
| Roll No  | Name               | Class    | Course      | Mobile No    | Adm Year  |
-------------------------------------------
| 101      | John Doe           | 12A      | Science     | 1234567890   | 2020      |
| 102      | Jane Smith         | 12B      | Commerce    | 0987654321   | 2021      |
-------------------------------------------
