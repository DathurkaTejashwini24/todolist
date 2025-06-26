#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool isDone;
};

// Function declarations
void addTask(vector<Task>& tasks);
void viewTasks(const vector<Task>& tasks);
void markTaskAsDone(vector<Task>& tasks);
void deleteTask(vector<Task>& tasks);

int main() {
    vector<Task> tasks;
    int choice;

    do {
        cout << "\n--- To-Do List Menu ---\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Done\n";
        cout << "4. Delete Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice (1-5): ";
        cin >> choice;
        cin.ignore();  // Clear newline from input buffer

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskAsDone(tasks);
                break;
            case 4:
                deleteTask(tasks);
                break;
            case 5:
                cout << "Exiting... Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}

void addTask(vector<Task>& tasks) {
    Task newTask;
    cout << "Enter task description: ";
    getline(cin, newTask.description);
    newTask.isDone = false;
    tasks.push_back(newTask);
    cout << "Task added successfully!\n";
}

void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }

    cout << "\nYour Tasks:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". [" << (tasks[i].isDone ? "✔" : " ") << "] " << tasks[i].description << endl;
    }
}

void markTaskAsDone(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to mark as done.\n";
        return;
    }

    int index;
    viewTasks(tasks);
    cout << "Enter task number to mark as done: ";
    cin >> index;

    if (index < 1 || index > tasks.size()) {
        cout << "Invalid task number.\n";
    } else {
        tasks[index - 1].isDone = true;
        cout << "Task marked as done.\n";
    }
}

void deleteTask(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to delete.\n";
        return;
    }

    int index;
    viewTasks(tasks);
    cout << "Enter task number to delete: ";
    cin >> index;

    if (index < 1 || index > tasks.size()) {
        cout << "Invalid task number.\n";
    } else {
        tasks.erase(tasks.begin() + index - 1);
        cout << "Task deleted successfully.\n";
    }
}
