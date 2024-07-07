#include <iostream>
#include <string>
#include <vector>

class Task {
public:
    std::string title;
    std::string description;
    int start_date;
    int end_date;

    Task(const std::string& _title, const std::string& _description, int _start_date, int _end_date)
        : title(_title), description(_description), start_date(_start_date), end_date(_end_date) {}
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

void displayGanttChart(const Project& project) {
    // Определение максимального количество дней для временной шкалы
    const int maxDays = 30;

    // Выведите заголовок временной шкалы.
    std::cout << "  |";
    for (int day = 0; day <= maxDays; day++) {
        std::cout << day << "|";
    }
    std::cout << std::endl;

    // Определение символы для отображения задачи и пустого места в диаграмме Ганта.
    char taskChar = '#'; // Используйте любой символ, который представляет задачу.
    char emptyChar = ' '; // Пробел для пустого места.

    // Создайте массив для временной шкалы и инициализируйте его пустыми символами.
    std::vector<char> ganttChart(maxDays + 1, emptyChar);

    // Заполните диаграмму Ганта символами задач для каждой задачи в проекте.
    for (const Task& task : project.tasks) {
        for (int day = task.start_date; day <= task.end_date && day <= maxDays; day++) {
            ganttChart[day] = taskChar;
        }
    }

    // Выведите диаграмму Ганта на консоль.
    for (int day = 0; day <= maxDays; day++) {
        std::cout << day << "|";
        std::cout << ganttChart[day] << "|";
    }
    std::cout << std::endl;
}



int main() {
    Project project("Пример проекта");

    Task task1("Задача 1", "Описание задачи 1", 0, 5);
    Task task2("Задача 2", "Описание задачи 2", 2, 7);
    Task task3("Задача 3", "Описание задачи 3", 6, 10);

    project.addTask(task1);
    project.addTask(task2);
    project.addTask(task3);

    displayGanttChart(project);

    return 0;
}
