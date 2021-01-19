#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <vector>

struct Record {
  char initial;
  std::string last;
  int salary;

  Record(char i, std::string l, int s) {
    initial = i;
    last = l;
    salary = s;
  }
};

std::vector<std::string> split(const std::string& str, const std::string& delim)
{
    std::vector<std::string> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == std::string::npos) pos = str.length();
        std::string token = str.substr(prev, pos-prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    }
    while (pos < str.length() && prev < str.length());
    return tokens;
}

int main() {
  std::string line;

  std::vector<Record> records;

  std::ifstream myfile ("records.csv");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      std::vector<std::string> parts = split(line, ", ");
      Record record = Record(
        parts[0][0], 
        parts[1], 
        stoi(parts[2])
      );
      records.push_back(record);
    }
    myfile.close();
  }
  else std::cout << "Unable to open file"; 

  int longestLast = 0;
  int longestSalary = 0;

  for (auto r : records) {
    int lastNameSize = size(r.last);
    if (lastNameSize > longestLast) {
      longestLast = lastNameSize;
    }

    int salarySize = size(std::to_string(r.salary));
    if (salarySize > longestSalary) {
      longestSalary = salarySize;
    }
  }

  std::cout << "Initial   Last        Salary\n--------  ----------  -------\n";

  for (auto r : records) {
    std::string spacesAfterInitial(8, ' ');
    std::string spacesAfterName(longestLast + 3 - size(r.last), ' ');
    std::cout << r.initial << "." << spacesAfterInitial << r.last << spacesAfterName << "£" << r.salary << " \n";
  }

}

