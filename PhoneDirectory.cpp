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
  std::string searchString;

  std::vector<std::string> phoneDirectory;

  std::cout << "Please enter a name or number to search: ";

  std::cin >> searchString;

  std::ifstream myfile ("PhoneDirectory.csv");
  if (myfile.is_open())
  {
    while ( getline (myfile, line) )
    {
      phoneDirectory.push_back(line);
    }
    myfile.close();
  }
  else std::cout << "Unable to open file"; 

  std::cout << "Searching " << size(phoneDirectory) << " records ..." << std::endl;

  

  std::string foundString = "";
  for(auto p : phoneDirectory) {
      if (p.find(searchString) != -1) {
        foundString = p;
        break;
      }
  }

  if (foundString == "") {
    std::cout << "Nothing found";
  } else {
    std::cout << "Contact details: " << foundString << std::endl;
  }

}