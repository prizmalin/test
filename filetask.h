#ifndef FILETASK_H
#define FILETASK_H

#include <string>

// Поиск самого длинного слова в файле
std::string findLongestWord(const std::string &filename);

// Подсчёт количества повторений слова в файле
int countWordOccurrences(const std::string &filename, const std::string &word);

void runFileTask();

#endif // FILETASK_H
