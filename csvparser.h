#ifndef CSVPARSER_H
#define CSVPARSER_H

#include <fstream>
#include <sstream>
#include <vector>

/**
 * Stores the csv into an easier-to-process format
 * 
 * note: currently restricted to specific format:
 *       > item1, item2, item3
 *       > there must be a space after each comma
 *       > there CANNOT be spaces between words  (e.g. item1, item2 item 2.5, item 3)
 *
 * @param filename  Name of the file you want to parse
 * @return vector of vectors where each sub-vector is a row on the csv
 */

std::vector<std::vector<std::string>> parse_csv(const std::string &filename) {
  std::ifstream fin(filename);
  std::string line;
  std::vector<std::vector<std::string>> document;
  while (getline(fin, line)) {
    if (line.empty()) continue;
    std::istringstream input(line);
    std::string word;
    std::vector<std::string> words;
    while (input >> word) {
        if (word.back() == ',') word.pop_back();
        words.push_back(word);
    }
    document.push_back(words);
  }
  return document;
}

#endif