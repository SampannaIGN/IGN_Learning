#include <iostream>
#include <dirent.h>
#include <sys/types.h>
#include <string>

int main() {
  DIR *dir;
  struct dirent *ent;
  std::string path_to_folder = "SectionChallenge";

  if ((dir = opendir (path_to_folder.c_str())) != NULL) {
    while ((ent = readdir (dir)) != NULL) {
      std::cout << ent->d_name << " => "<<ent->d_type<<std::endl;
    }
    closedir (dir);
  } else {
    perror ("");
    return EXIT_FAILURE;
  }
  return 0;
}
