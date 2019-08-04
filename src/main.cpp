#include "../include/MessageCreator.h"

#include <memory>
#include <windows.h>

DWORD WINAPI CheckEscape(LPVOID lpParam) {
  while (GetAsyncKeyState(VK_ESCAPE) == 0) {
    // sleep
    Sleep(10);
  }
  exit(0);
}

int main() {

  std::cout << "Press \"esc\" to exit" << std::endl;

  HANDLE hThread = CreateThread(nullptr, 0, CheckEscape, nullptr, 0, nullptr);

  while (true){
      std::string firstname, lastname, title, company, position;

      std::cout << "Enter title:";
      std::getline(std::cin, title);

      std::cout << "Enter last name:";
      std::getline(std::cin, lastname);

      std::cout << "Enter position:";
      std::getline(std::cin, position);

      std::cout << "Enter company:";
      std::getline(std::cin, company);

      Person recruiter(firstname, lastname, title, company, position);

      std::string ifile = "../msgs/templatemsg.txt";
      std::string ofile = "../msgs/finalmsg.txt";

      iMessage templatemsg(ifile);
      oMessage finalmsg(ofile);

      if (templatemsg.isOpened() && finalmsg.isOpened()) {

          std::unique_ptr<MessageCreator> u(
                  MessageCreator::instance(&templatemsg, &finalmsg, &recruiter));
          u->replaceWords();
          u->copy2clip();
          std::cout << "Done." << std::endl;

      } else {
          std::string exitPress;
          std::cout << "Unable to open files. Press enter to exit program."
                    << std::endl;
          getline(std::cin, exitPress); // consume existing line
          std::cin.get();               // get the key press
          CloseHandle(hThread);
          exit(1);
      }
  }

  CloseHandle(hThread);
  return 0;
}