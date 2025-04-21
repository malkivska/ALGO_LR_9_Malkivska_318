#include "task2.h"  // Підключаємо заголовок task2.h
#include <fstream>  // Для роботи з файлами (ifstream, ofstream)
#include <cctype>   // Для роботи з символами (isspace)
#include <iostream>  // Для виведення в консоль

// Функція для підрахунку кількості слів у рядку
int countWords(const std::string& line) {
    int count = 0;  // Лічильник слів
    bool inWord = false;  // Статус, чи знаходимося всередині слова

    // Перебираємо кожен символ рядка
    for (char ch : line) {
        if ((unsigned char)ch >= 128 && !isspace(ch)) {  // Якщо символ не пробіл і належить до символів
            if (!inWord) {  // Якщо ми ще не всередині слова
                inWord = true;  // Входимо в слово
                count++;  // Збільшуємо лічильник слів
            }
        } else if (isspace(ch)) {  // Якщо символ — пробіл
            inWord = false;  // Виходимо з слова
        }
    }

    return count;  // Повертаємо кількість слів
}

// Функція для перевірки, чи рядок містить хоча б одне слово
bool isValidLine(const std::string& line) {
    return countWords(line) > 0;  // Якщо є хоча б одне слово, рядок вважається валідним
}

// Функція для створення тестових файлів
void createFiles() {
    std::ofstream inFile("input.txt");  // Вхідний файл
    inFile << "Це перший рядок для перевірки.\n";  // Додаємо тестові рядки
    inFile << "Тестуємо кількість слів у рядках.\n";
    inFile << "Завдання з файлами та обробка.\n";
    inFile << "Кілька слів тут.\n";
    inFile << "Перевірка роботи програми.\n";
    inFile << "Останній рядок тесту.\n";
    inFile.close();  // Закриваємо файл

    std::ofstream outFile("output.txt");  // Вихідний файл
    outFile.close();  // Закриваємо вихідний файл
}

// Функція для обробки файлів (підрахунок слів у кожному рядку)
void runTask2() {
    std::string inputFileName = "input.txt";  // Вхідний файл
    std::string outputFileName = "output.txt";  // Вихідний файл

    std::ifstream inFile(inputFileName);  // Відкриваємо вхідний файл для читання
    std::ofstream outFile(outputFileName);  // Відкриваємо вихідний файл для запису

    if (!inFile.is_open()) {  // Перевіряємо, чи вдалося відкрити вхідний файл
        std::cout << "Помилка при відкритті вхідного файлу: " << inputFileName << std::endl;
        return;  // Якщо файл не відкрився — виводимо помилку і виходимо з функції
    }

    if (!outFile.is_open()) {  // Перевіряємо, чи вдалося відкрити вихідний файл
        std::cout << "Помилка при відкритті вихідного файлу: " << outputFileName << std::endl;
        return;  // Якщо файл не відкрився — виводимо помилку і виходимо з функції
    }

    std::string line;  // Змінна для зчитування рядків з файлу
    while (getline(inFile, line)) {  // Читаємо файл по рядках
        int wordCount = countWords(line);  // Підраховуємо кількість слів у рядку
        bool valid = isValidLine(line);  // Перевіряємо, чи є слова в рядку
        outFile << "Рядок: \"" << line << "\"\n";  // Записуємо рядок у вихідний файл
        outFile << "Кількість слів: " << wordCount << "\n";  // Записуємо кількість слів
        outFile << "Умова виконана: " << (valid ? "Так" : "Ні") << "\n\n";  // Записуємо результат перевірки валідності
    }

    inFile.close();  // Закриваємо вхідний файл
    outFile.close();  // Закриваємо вихідний файл
    std::cout << "Обробка завершена. Результати записано у " << outputFileName << std::endl;  // Виводимо повідомлення про завершення
}
