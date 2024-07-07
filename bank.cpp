#include <iostream>
#include <string>
#include <vector>
#include <clocale> 

struct Task {
    std::string description;
    bool completed;
};

int main() {
    setlocale(LC_ALL, "Russian"); 

    std::vector<Task> tasks;
    char choice;
    std::string description; 

    while (true) {
        std::cout << "Управление задачами\n";
        std::cout << "1. Добавить задачу\n";
        std::cout << "2. Показать задачи\n";
        std::cout << "3. Отметить задачу как выполненную\n";
        std::cout << "4. Выйти\n";
        std::cout << "Выберите действие: ";

        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case '1':
                std::cout << "Введите описание задачи: ";
                std::getline(std::cin, description);
                tasks.push_back({description, false});
                break;
            case '2':
                std::cout << "Список задач:\n";
                for (size_t i = 0; i < tasks.size(); ++i) {
                    std::cout << (i + 1) << ". " << tasks[i].description;
                    if (tasks[i].completed) {
                        std::cout << " (Завершено)";
                    }
                    std::cout << "\n";
                }
                break;
            case '3':
                std::cout << "Введите номер задачи, которую вы хотите отметить как выполненную: ";
                size_t taskNumber;
                std::cin >> taskNumber;
                if (taskNumber > 0 && taskNumber <= tasks.size()) {
                    tasks[taskNumber - 1].completed = true;
                    std::cout << "Задача отмечена как выполненная.\n";
                } else {
                    std::cout << "Некорректный номер задачи.\n";
                }
                break;
            case '4':
                std::cout << "Выход из программы.\n";
                return 0;
            default:
                std::cout << "Некорректный выбор. Пожалуйста, выберите корректное действие.\n";
        }
    }

    return 0;
}
