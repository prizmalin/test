#include <iostream>
#include <fstream>
#include <sstream>
#include "filetask.h"
#include "utils.h"

// Очистка слова от пунктуации по краям
static std::string normalizeWord(const std::string &w)
{
    int left = 0;
    int right = (int)w.size() - 1;

    while (left <= right && std::ispunct((unsigned char)w[left]))
        left++;
    while (right >= left && std::ispunct((unsigned char)w[right]))
        right--;

    if (left > right)
        return "";

    return w.substr(left, right - left + 1);
}

// Поиск самого длинного слова в файле
std::string findLongestWord(const std::string &filename)
{
    std::ifstream fin(filename);
    if (!fin)
        throw std::runtime_error("Cannot open file: " + filename);

    std::string line, word, longest;

    while (std::getline(fin, line))
    {
        std::istringstream iss(line);
        while (iss >> word)
        {
            word = normalizeWord(word);
            if (!word.empty() && word.size() > longest.size())
                longest = word;
        }
    }

    return longest;
}

// Подсчёт количества повторений слова в файле
int countWordOccurrences(const std::string &filename, const std::string &wordInput)
{
    std::ifstream fin(filename);
    if (!fin)
        throw std::runtime_error("Cannot open file: " + filename);

    std::string line, wNorm;
    int count = 0;

    std::string word = toLower(wordInput);

    while (std::getline(fin, line))
    {
        std::istringstream iss(line);
        while (iss >> wNorm)
        {
            wNorm = toLower(normalizeWord(wNorm));
            if (wNorm == word)
                count++;
        }
    }

    return count;
}

void runFileTask()
{
    std::string filename;
    std::cout << "Enter file name to process: ";
    std::getline(std::cin, filename);

    try
    {
        std::string longest = findLongestWord(filename);

        if (longest.empty())
        {
            std::cout << "File contains no valid words.\n";
            return;
        }

        int freq = countWordOccurrences(filename, longest);

        std::cout << "\nLongest word: " << longest << '\n';
        std::cout << "Occurrences: " << freq << "\n\n";
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << "\n";
    }
}
