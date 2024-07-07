#include <iostream>
#include <vector>
#include <iomanip>

class Task {
public:
    std::string title;
    int start;
    int end;

    Task(const std::string& _title, int _start, int _end)
        : title(_title), start(_start), end(_end) {}
};


class Project {
public:
    std::string name;
    std::vector<Task> tasks;

    Project(const std::string& _name)
        : name(_name) {}

    void addTask(const Task& task) {
        tasks.push_back(task);
    }
};

void displayGantt(const Project& project) {
    
    const int maxDays = 30;

    char taskChar = '#'; 
    char emptyChar = ' '; // 

    // Создайте массив для временной шкалы и инициализируйте его пустыми символами.
    std::vector<char> gantt(maxDays + 1, emptyChar);

    // Заполните диаграмму Ганта символами задач для каждой задачи в проекте.
    for (const Task& task : project.tasks) {
        for (int day = task.start; day <= task.end && day <= maxDays; day++) {
            gantt[day] = taskChar;
        }
    }


    std::cout << "  |";
    for (int day = 0; day <= maxDays; day++) {
        std::cout << std::setw(2) << day << "|";
    }
    std::cout << std::endl;

    for (char symbol : gantt) {
        std::cout << "  |" << symbol << "|";
    }
    std::cout << std::endl;
}

int main() {
    setlocale(LC_ALL, "Rus");
    Project project("Пример проекта");
    int choice;

    do {
        std::cout << "\nВыберите действие:\n";
        std::cout << "1. Добавить задачу\n";
        std::cout << "2. Отобразить диаграмму Ганта\n";
        std::cout << "0. Выйти\n";
        std::cout << "Ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string title;
                int start, end;
                
                std::cout << "Введите название задачи: ";
                std::cin.ignore();
                std::getline(std::cin, title);

                std::cout << "Введите дату начала (день): ";
                std::cin >> start;

                std::cout << "Введите дату окончания (день): ";
                std::cin >> end;

                project.addTask(Task(title, start, end));
                break;
            }
            case 2:
                displayGantt(project);
                break;
            case 0:
                std::cout << "Программа завершена.\n";
                break;
            default:
                std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0);

    return 0;
}
