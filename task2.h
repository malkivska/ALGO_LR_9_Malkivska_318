#ifndef TASK2_H  // Перевірка, чи не була вже включена ця бібліотека
#define TASK2_H  // Якщо не була, визначаємо її

#include <string>  // Для роботи зі стандартними рядками

// Оголошення функцій для підрахунку слів та перевірки валідності рядка
int countWords(const std::string& line);
bool isValidLine(const std::string& line);

// Оголошення функцій для створення файлів та обробки тексту
void createFiles();
void runTask2();

#endif // TASK2_H
