#ifndef FILE_READER_HPP_
#define FILE_READER_HPP_
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

// CSV reader to quickly read/write rows
class FileReader {
public:
	FileReader(const std::string& filepath, const std::vector<std::string>& first_row)
		: buffer{filepath} {
			if (!buffer.is_open()) { // If not exists, create it
				buffer.open(filepath, std::fstream::out);
				csv_write_row(first_row);
			}
		}
	~FileReader() {buffer.close();}

	bool empty() {
		buffer.seekg(0, buffer.end);
		return buffer.tellg() != 0;
	}

	std::vector<std::vector<std::string>> csv_get_rows() {
		std::stringstream contents{};
		// Read file into sstream
		contents << buffer.rdbuf();
		std::vector<std::vector<std::string>> rows{};
		std::string row;
		while (std::getline(contents, row, '\n')) { // Split by newline
			std::vector<std::string> row_split{};
			std::stringstream sstr{row};
			std::string val{};
			while (std::getline(sstr, val, ',')) { // Split by comma
				row_split.push_back(val);
			}
			rows.push_back(row_split);
		}
		return rows;
	}

	void csv_write_row(const std::vector<std::string>& row) {
		for (int i = 0; i < row.size(); i++) {
			buffer << row[i];
			if (i != row.size() - 1) { // If not last
				buffer << ',';
			}
		}
		buffer << '\n';
	}
private:
	std::fstream buffer{""};
};

#endif // FILE_READER_HPP_
