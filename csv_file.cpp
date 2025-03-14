#include "csv_file.h"
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<std::string> splitString(const std::string& s, char c, size_t sizeHint = 0) {
    std::vector<std::string> tokens(sizeHint);

    size_t i = 0;
    std::string token;
    std::istringstream stream(s);
    while (std::getline(stream, token, c)) {
        if (sizeHint > 0) { [[likely]]
            tokens[i] = token;
            i++;
            if (sizeHint != 0 && i >= sizeHint) {
                break;
            }
        } else { [[unlikely]]
            tokens.push_back(token);
        }
    }
    
    return tokens;
}

CsvEntry::CsvEntry(std::vector<std::string>&& tokens, CsvIndexMap& indexMap) : tokens(tokens), indexMap(indexMap) {
}

bool CsvEntry::hasColumn(const std::string& column) const {
    if (!this->indexMap.contains(column)) {
        return false;
    }

    size_t index = this->indexMap[column];
    return this->tokens.size() > index;
}

const std::string& CsvEntry::getValueAtColumn(const std::string& column) const {
    if (!this->indexMap.contains(column)) {
        throw std::runtime_error("CsvEntry::getValueAtColumn column doesn't exist");
    }

    size_t index = this->indexMap[column];

    if (this->tokens.size() <= index) {
        throw std::runtime_error("CsvEntry::getValueAtColumn column doesn't exist");
    }

    return this->tokens[index];
}

uint32_t CsvEntry::getU32(const std::string& column) const {
    const std::string& value = this->getValueAtColumn(column);
    // not _exactly_ safe, but it should be fine
    return std::stoul(value);
}

int CsvEntry::getI32(const std::string& column) const {
    const std::string& value = this->getValueAtColumn(column);
    return std::stoi(value);
}

float CsvEntry::getF32(const std::string& column) const {
    const std::string& value = this->getValueAtColumn(column);
    return std::stof(value);
}

CsvFile::CsvFile(const std::string& fileName) {
    std::ifstream in(fileName);
    if (!in.is_open()) {
        this->parseError = true;
        return;
    }

    size_t startingPos = in.tellg();
    size_t lf_cnt = std::count(std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>(), '\n');
    in.seekg(startingPos);

    this->lines = (CsvEntry*) malloc(sizeof(CsvEntry) * lf_cnt);

    size_t i = 0;
    std::string line;
    bool isFirstLine = true;
    while (std::getline(in, line)) {
        if (isFirstLine) {
            // Build the indexMap
            isFirstLine = false;
            
            std::vector<std::string> schema = splitString(line, ',');
            for (size_t i = 0; i < schema.size(); i++) {
                this->indexMap[schema[i]] = i;
            }

            continue;
        }

        // Skip empty lines and comments
        if (line.length() == 0 || line.starts_with("#")) {
            continue;
        }

        new (&this->lines[i]) CsvEntry(splitString(line, ',', indexMap.size()), this->indexMap);
        i++;
    }

    // Set the line count to the number of lines that we have read.
    //  This can be lower than lf_cnt above, essentially wasting space,
    //  but eh
    this->lineCount = i;
}
