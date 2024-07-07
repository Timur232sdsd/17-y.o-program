#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Task {
public:
    std::string title;
    std::string description;
    bool completed;

    Task(const std::string& _title, const std::string& _description) 
        : title(_title), description(_description), completed(false) {}
};

class TaskManager {
private:
    std::vector<Task> tasks;

public:
    void addTask(const Task& task) {
        tasks.push_back(task);
    }

    void displayTasks() {
        for (int i = 0; i < tasks.size(); ++i) {
            std::cout << "Task " << i + 1 << ": " << tasks[i].title << std::endl;
            std::cout << "Description: " << tasks[i].description << std::endl;
            std::cout << "Status: " << (tasks[i].completed ? "Completed" : "Incomplete") << std::endl;
            std::cout << "-------------------------------------" << std::endl;
        }
    }

    void markTaskAsCompleted(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].completed = true;
            std::cout << "Task marked as completed." << std::endl;
        }
        else {
            std::cout << "Invalid task index." << std::endl;
        }
    }

    void removeTask(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks.erase(tasks.begin() + index);
            std::cout << "Task removed." << std::endl;
        }
        else {
            std::cout << "Invalid task index." << std::endl;
        }
    }
};

int main() {
    TaskManager taskManager;
    
    while (true) {
        std::cout << "1. Add Task\n2. Display Tasks\n3. Mark Task as Completed\n4. Remove Task\n5. Exit" << std::endl;
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            std::string title, description;
            std::cout << "Enter task title: ";
            std::cin.ignore();
            std::getline(std::cin, title);
            std::cout << "Enter task description: ";
            std::getline(std::cin, description);
            Task newTask(title, description);
            taskManager.addTask(newTask);
        }
        else if (choice == 2) {
            taskManager.displayTasks();
        }
        else if (choice == 3) {
            int index;
            std::cout << "Enter the index of the task to mark as completed: ";
            std::cin >> index;
            taskManager.markTaskAsCompleted(index - 1);
        }
        else if (choice == 4) {
            int index;
            std::cout << "Enter the index of the task to remove: ";
            std::cin >> index;
            taskManager.removeTask(index - 1);
        }
        else if (choice == 5) {
            break;
        }
        else {
            std::cout << "Invalid choice. Try again." << std::endl;
        }
    }

    return 0;
}
