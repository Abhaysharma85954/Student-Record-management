#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <limits>

using namespace std;

struct Student {
    string roll_no, name, Class, course, mobile_no, admission_year;
};

vector<Student> students;

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void enter() {
    int count;
    cout << "How many students do you want to enter? ";
    cin >> count;
    clearInputBuffer();

    for (int i = 0; i < count; ++i) {
        Student s;
        cout << "\nEnter the Data for Student " << i + 1 << ":\n";
        cout << "Roll No: ";
        getline(cin, s.roll_no);
        cout << "Name: ";
        getline(cin, s.name);
        cout << "Class: ";
        getline(cin, s.Class);
        cout << "Course: ";
        getline(cin, s.course);
        cout << "Mobile No: ";
        getline(cin, s.mobile_no);
        cout << "Admission Year: ";
        getline(cin, s.admission_year);
        students.push_back(s);
    }
}

void displayTableHeader() {
    cout << setfill('-') << setw(85) << "-" << setfill(' ') << endl;
    cout << setw(10) << left << "| Roll No"
         << setw(20) << "| Name"
         << setw(10) << "| Class"
         << setw(15) << "| Course"
         << setw(15) << "| Mobile No"
         << setw(10) << "| Adm Year |" << endl;
    cout << setfill('-') << setw(85) << "-" << setfill(' ') << endl;
}

void displayStudentRow(const Student& s) {
    cout << "| " << setw(8) << left << s.roll_no
         << "| " << setw(18) << s.name
         << "| " << setw(8) << s.Class
         << "| " << setw(13) << s.course
         << "| " << setw(13) << s.mobile_no
         << "| " << setw(8) << s.admission_year << " |" << endl;
}

void show() {
    if (students.empty()) {
        cout << "No Data is Entered" << endl;
        return;
    }

    displayTableHeader();
    for (const auto& student : students) {
        displayStudentRow(student);
    }
    cout << setfill('-') << setw(85) << "-" << setfill(' ') << endl;
}

void search() {
    if (students.empty()) {
        cout << "No data is entered" << endl;
        return;
    }

    string searchTerm;
    cout << "Enter Roll No, Name, or Mobile No to search: ";
    clearInputBuffer();
    getline(cin, searchTerm);

    vector<Student> results;
    for (const auto& student : students) {
        if (student.roll_no == searchTerm ||
            student.name == searchTerm ||
            student.mobile_no == searchTerm) {
            results.push_back(student);
        }
    }

    if (results.empty()) {
        cout << "No matching students found." << endl;
    } else {
        cout << results.size() << " matching student(s) found:\n" << endl;
        displayTableHeader();
        for (const auto& student : results) {
            displayStudentRow(student);
        }
        cout << setfill('-') << setw(85) << "-" << setfill(' ') << endl;
    }
}

void update() {
    if (students.empty()) {
        cout << "No data is entered" << endl;
        return;
    }

    string rollno;
    cout << "Enter the roll no of student to update: ";
    clearInputBuffer();
    getline(cin, rollno);

    auto it = find_if(students.begin(), students.end(),
                      [&rollno](const Student& s) { return s.roll_no == rollno; });

    if (it != students.end()) {
        cout << "\nCurrent data:" << endl;
        displayTableHeader();
        displayStudentRow(*it);
        cout << setfill('-') << setw(85) << "-" << setfill(' ') << endl;

        cout << "\nEnter new data (press Enter to keep current value):" << endl;
        string input;

        cout << "Name (" << it->name << "): ";
        getline(cin, input);
        if (!input.empty()) it->name = input;

        cout << "Class (" << it->Class << "): ";
        getline(cin, input);
        if (!input.empty()) it->Class = input;

        cout << "Course (" << it->course << "): ";
        getline(cin, input);
        if (!input.empty()) it->course = input;

        cout << "Mobile No (" << it->mobile_no << "): ";
        getline(cin, input);
        if (!input.empty()) it->mobile_no = input;

        cout << "Admission Year (" << it->admission_year << "): ";
        getline(cin, input);
        if (!input.empty()) it->admission_year = input;

        cout << "Record updated successfully." << endl;
    } else {
        cout << "No student found with Roll No: " << rollno << endl;
    }
}

void deleteRecord() {
    if (students.empty()) {
        cout << "No data is entered yet" << endl;
        return;
    }

    string rollno;
    cout << "Enter the roll no of student to delete (or 'ALL' to delete all records): ";
    clearInputBuffer();
    getline(cin, rollno);

    if (rollno == "ALL") {
        char confirm;
        cout << "Are you sure you want to delete all records? (y/n): ";
        cin >> confirm;
        if (tolower(confirm) == 'y') {
            students.clear();
            cout << "All records have been deleted." << endl;
        } else {
            cout << "Operation cancelled." << endl;
        }
    } else {
        auto it = remove_if(students.begin(), students.end(),
                            [&rollno](const Student& s) { return s.roll_no == rollno; });

        if (it != students.end()) {
            students.erase(it, students.end());
            cout << "Student record deleted successfully." << endl;
        } else {
            cout << "No student found with Roll No: " << rollno << endl;
        }
    }
}

void saveToFile() {
    ofstream outFile("students.txt");
    if (!outFile) {
        cerr << "Error opening file for writing." << endl;
        return;
    }

    for (const auto& student : students) {
        outFile << student.roll_no << "|"
                << student.name << "|"
                << student.Class << "|"
                << student.course << "|"
                << student.mobile_no << "|"
                << student.admission_year << endl;
    }
    outFile.close();
    cout << "Data saved to file successfully." << endl;
}

void loadFromFile() {
    ifstream inFile("students.txt");
    if (!inFile) {
        cerr << "Error opening file for reading." << endl;
        return;
    }

    students.clear();
    string line;
    while (getline(inFile, line)) {
        Student s;
        size_t pos = 0;
        string token;
        int i = 0;
        while ((pos = line.find("|")) != string::npos) {
            token = line.substr(0, pos);
            switch(i) {
                case 0: s.roll_no = token; break;
                case 1: s.name = token; break;
                case 2: s.Class = token; break;
                case 3: s.course = token; break;
                case 4: s.mobile_no = token; break;
            }
            line.erase(0, pos + 1);
            i++;
        }
        s.admission_year = line;
        students.push_back(s);
    }
    inFile.close();
    cout << "Data loaded from file successfully." << endl;
}

void sortRecords() {
    if (students.empty()) {
        cout << "No data is entered yet" << endl;
        return;
    }

    int choice;
    cout << "Sort by:\n1. Roll No\n2. Name\n3. Admission Year\nEnter your choice: ";
    cin >> choice;

    switch(choice) {
        case 1:
            sort(students.begin(), students.end(),
                 [](const Student& a, const Student& b) { return a.roll_no < b.roll_no; });
            break;
        case 2:
            sort(students.begin(), students.end(),
                 [](const Student& a, const Student& b) { return a.name < b.name; });
            break;
        case 3:
            sort(students.begin(), students.end(),
                 [](const Student& a, const Student& b) { return a.admission_year < b.admission_year; });
            break;
        default:
            cout << "Invalid choice. No sorting performed." << endl;
            return;
    }

    cout << "Records sorted successfully." << endl;
    show();
}

int main() {
    loadFromFile();
    int choice;
    while (true) {
        cout << "\n----- Student Record Management System -----" << endl;
        cout << "1. Enter new student record" << endl;
        cout << "2. Display all records" << endl;
        cout << "3. Search records" << endl;
        cout << "4. Update record" << endl;
        cout << "5. Delete record" << endl;
        cout << "6. Sort records" << endl;
        cout << "7. Save data to file" << endl;
        cout << "8. Load data from file" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: enter(); break;
            case 2: show(); break;
            case 3: search(); break;
            case 4: update(); break;
            case 5: deleteRecord(); break;
            case 6: sortRecords(); break;
            case 7: saveToFile(); break;
            case 8: loadFromFile(); break;
            case 9:
                saveToFile();
                cout << "Exiting program. Data saved." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
