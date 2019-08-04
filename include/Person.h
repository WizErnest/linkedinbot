//
// Author: wizernest
//

#ifndef LINKEDINBOT_PERSON_H
#define LINKEDINBOT_PERSON_H

#include <iostream>

class Person {
public:
  Person() = delete;

  explicit Person(const std::string &firstname, const std::string &lastname,
                  const std::string &title, const std::string &company,
                  const std::string &position);

  void changefirstname(const std::string &firstname);
  void changelastname(const std::string &lastname);
  void changetitle(const std::string &title);
  void changecompany(const std::string &company);
  void changeposition(const std::string &position);

  std::string getfirstname() const;
  std::string getlastname() const;
  std::string gettitle() const;
  std::string getcompany() const;
  std::string getposition() const;

  void print() const;

private:
  std::string firstname;
  std::string lastname;
  std::string title;
  std::string company;
  std::string position;
};

#endif // LINKEDINBOT_PERSON_H
