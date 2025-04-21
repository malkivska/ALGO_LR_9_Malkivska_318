#include "task1.h"  // Підключаємо заголовок task1.h для використання оголошених функцій
#include <cstring>  // Для роботи з рядками (strlen)

void customReplace(char* source, size_t pos, size_t len, const char* insert, size_t subpos, size_t sublen) {
    size_t sourceLen = 0, insertLen = 0;
    // Підраховуємо довжину джерела
    while (source[sourceLen] != '\0') ++sourceLen;
    // Підраховуємо довжину рядка, який вставляємо
    while (insert[insertLen] != '\0') ++insertLen;

    size_t newLen = sourceLen - len + sublen;  // Розраховуємо нову довжину рядка після заміни
    char* result = new char[newLen + 1];  // Виділяємо пам'ять для нового рядка

    // Копіюємо першу частину рядка до місця заміни
    for (size_t i = 0; i < pos; ++i)
        result[i] = source[i];

    // Копіюємо вставлений фрагмент з вхідного рядка
    for (size_t i = 0; i < sublen; ++i)
        result[pos + i] = insert[subpos + i];

    // Копіюємо залишок з джерела після місця заміни
    for (size_t i = pos + sublen; i < newLen; ++i)
        result[i] = source[i - sublen + len];

    result[newLen] = '\0';  // Завершуємо новий рядок символом '\0'

    // Переносимо результат назад в оригінальний рядок
    for (size_t i = 0; i <= newLen; ++i)
        source[i] = result[i];

    delete[] result;  // Очищаємо виділену пам'ять
}
