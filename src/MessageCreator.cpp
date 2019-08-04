//
// Author by Ernesto
//

#ifndef LINKEDINBOT_MESSAGECREATOR_CPP
#define LINKEDINBOT_MESSAGECREATOR_CPP

#include "MessageCreator.h"

MessageCreator *MessageCreator::inst = nullptr;

MessageCreator::~MessageCreator() { inst = nullptr; }

MessageCreator *MessageCreator::instance(iMessage *input, oMessage *output,
                                         Person *rando) {
  inst = (inst == nullptr) ? new MessageCreator(input, output, rando) : inst;
  return inst;
}

MessageCreator::MessageCreator(iMessage *input, oMessage *output, Person *rando)
    : templatemsg(input), finalmsg(output), recruiter(rando),
      ss(std::stringstream()){};

void MessageCreator::replaceWords() {
  std::string newWord;
  while (std::getline(*(templatemsg->getFile()), newWord)) {

    newWord = std::regex_replace(newWord, std::regex("\\[title\\]"),
                                 recruiter->gettitle());
    newWord = std::regex_replace(newWord, std::regex("\\[lastname\\]"),
                                 recruiter->getlastname());
    newWord = std::regex_replace(newWord, std::regex("\\[position\\]"),
                                 recruiter->getposition());
    newWord = std::regex_replace(newWord, std::regex("\\[company\\]"),
                                 recruiter->getcompany());
    *(finalmsg->getFile()) << newWord << std::endl;
    ss << newWord << std::endl;
  }
}

void MessageCreator::copy2clip() const {
  std::string msg = ss.str();
  const char *output = msg.c_str();
  const size_t len = msg.size() + 1;

  HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, len);
  memcpy(GlobalLock(hMem), output, len);
  GlobalUnlock(hMem);

  OpenClipboard(nullptr);
  EmptyClipboard();
  SetClipboardData(CF_TEXT, hMem);
  CloseClipboard();
  GlobalFree(hMem);
}

#endif // LINKEDINBOT_MESSAGECREATOR_CPP
