#include <iostream>
#include <fstream>

int main() {
  std::string name;
  std::string proceed = "Y";
  std::ofstream myfile;
  myfile.open ("list.csv", std::ios::out | std::ios::app);

  while (proceed == "Y") {
    std::cout << "Enter name: \n";
    std::cin >> name;
    myfile << name << "\n";
    std::cout << "Updating file \n";
    std::cout << "Add another? Y/N \n";
    std::cin >> proceed;
  } 
  std::cout << "Goodbye";
  
}