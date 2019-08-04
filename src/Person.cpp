//
// Author by Ernesto
//

#ifndef LINKEDINBOT_PERSON_CPP
#define LINKEDINBOT_PERSON_CPP

#include "../include/Person.h"

Person::Person(const std::string &firstname, const std::string &lastname,
               const std::string &title, const std::string &company,
               const std::string &position)
    : firstname(firstname), lastname(lastname), title(title), company(company),
      position(position) {}

void Person::changefirstname(const std::string &newname) {
  if (firstname != newname) {
    firstname = newname;
  }
}

void Person::changelastname(const std::string &newname) {
  if (lastname != newname) {
    lastname = newname;
  }
}

void Person::changetitle(const std::string &newtitle) {
  if (title != newtitle) {
    title = newtitle;
  }
}

void Person::changecompany(const std::string &newcompany) {
  if (company != newcompany) {
    company = newcompany;
  }
}

void Person::changeposition(const std::string &newposition) {
  if (position != newposition) {
    position = newposition;
  }
}

std::string Person::getfirstname() const { return firstname; }

std::string Person::getlastname() const { return lastname; }

std::string Person::gettitle() const { return title; }

std::string Person::getcompany() const { return company; }

std::string Person::getposition() const { return position; }

void Person::print() const {
  std::cout << title << " " << firstname << " " << lastname << std::endl;
  std::cout << position << " at " << company << std::endl;
}

#endif // LINKEDINBOT_PERSON_CPP
