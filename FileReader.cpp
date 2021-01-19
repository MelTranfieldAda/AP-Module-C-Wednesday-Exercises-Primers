#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <vector>

int main() {
  std::string line;

  std::vector<std::string> names;

  std::ifstream myfile ("names.csv");
  if (myfile.is_open())
  {
    while ( getline (myfile, line) )
    {
      names.push_back(line);
    }
    myfile.close();
  }
  else std::cout << "Unable to open file"; 

  for (int i = 0; i < size(names); i++) {
    std::cout << i + 1 << ": " << names[i] << std::endl;
  }

  std::cout << "Total number of lines read: " << size(names);

}

