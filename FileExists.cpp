#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  struct stat sb;

  std::string fileName;

  std::cout << "File to check: \n";

  std::cin >> fileName;

  const char * c = fileName.c_str();


  if (stat(c, &sb) == -1) {
    std::cout << fileName << " does not exist.\n";
    return 0;
  }
  
  std::cout << fileName << ", " << sb.st_size << " bytes, last modified: " << ctime(&sb.st_mtime);

}