=================== Student Management System ===================

This project is a console-based Student Management System written in C.
It provides a secure and interactive way to manage student records with password-protected access, file storage, and a menu-driven interface.

✨ Features

🔑 Login System with Password File
- On first run, prompts the user to create a password (saved in password.txt).
- On subsequent runs, requires login authentication with masked password input (* for characters).

📝 Student Records Management
- Create a new student list and save it into a CSV file (student_information.csv).
- Add new student(s) to the list.
- View all stored students with formatted output.
- Edit/update student information by searching via Student ID.
- Delete student records by Student ID.

🎨 Console UI Enhancements
- Colored text for better readability (using ANSI escape codes and Windows API).
- Custom functions for cursor movement (gotoxy) and styled text (textcolor).
- Animated login and loading screens for a better user experience.

📂 File Handling
- Student information is stored in CSV format for persistence.
- Each record includes: Name, Age, Department, ID, Point, Result (PASSED/FAILED).
- Auto-generates random unique student IDs.

⚙️ Program Workflow
=================== Student Management System ===================

1: Create a student list.
2: View students.
3: Add students.
4: Change student information.
5: Delete student.
6: Exit the menu.

Please enter your choice:

Data Storage
- All data is written into student_information.csv for persistence.

🛠️ Technologies Used
- C Standard Library: stdio.h, stdlib.h, string.h, time.h
- Windows-Specific Libraries: windows.h, conio.h
    - Cursor movement
    - Colored console text
    - Real-time input handling
- File Handling for CSV data persistence

📌 Example Output
=================== Student Management System ===================

1: Create a student list.
2: View students.
3: Add students.
4: Change student information.
5: Delete student.
6: Exit the menu.

Please enter your choice:

🚀 Future Improvements
- Cross-platform support (remove Windows-specific dependencies)
- Search by name/department
- GPA calculation and ranking
- Export/Import options (Excel/JSON)
- GUI version
