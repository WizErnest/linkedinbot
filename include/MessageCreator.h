//
// Author: wizernest
//

#ifndef LINKEDINBOT_MESSAGECREATOR_H
#define LINKEDINBOT_MESSAGECREATOR_H

#include "Message.h"
#include "Person.h"

#include <regex>
#include <sstream>
#include <windows.h>

// class iMessage;
// class oMessage;
// class Person;

class MessageCreator {
public:
  MessageCreator() = delete;
  ~MessageCreator();
  static MessageCreator *instance(iMessage *input, oMessage *output,
                                  Person *rando);

  void replaceWords();
  void copy2clip() const;

private:
  explicit MessageCreator(iMessage *input, oMessage *output, Person *rando);
  iMessage *templatemsg;
  oMessage *finalmsg;
  Person *recruiter;
  std::stringstream ss;
  static MessageCreator *inst;
};

#endif // LINKEDINBOT_MESSAGECREATOR_H
