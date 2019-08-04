//
// Author: wizernest
//

#ifndef LINKEDINBOT_MESSAGE_H
#define LINKEDINBOT_MESSAGE_H

#include <fstream>
#include <iostream>

class Message {

public:
  Message() = delete;
  explicit Message(const std::string &fname) : filename(fname), opened(false){};
  virtual ~Message() = default;
  virtual bool isOpened() const = 0;

protected:
  std::string filename;
  bool opened;
};

class iMessage : public Message {
public:
  explicit iMessage(const std::string &fname) : ::Message(fname) {

    file.open(filename.c_str());

    if (file.fail()) {
      std::cout << "Unable to open input file" << std::endl;
    } else {
      opened = true;
    }
  };

  ~iMessage() final {
    if (opened) {
      file.close();
    }
  };

  bool isOpened() const override { return opened; };

  std::ifstream *getFile() { return &file; };

private:
  std::ifstream file;
};

class oMessage : public Message {
public:
  explicit oMessage(const std::string &fname) : ::Message(fname) {

    file.open(filename.c_str());

    if (file.fail()) {
      std::cout << "Unable to open output file." << std::endl;
    } else {
      opened = true;
    }
  };

  ~oMessage() final {
    if (opened) {
      file.close();
    }
  };

  bool isOpened() const override { return opened; };

  std::ofstream *getFile() { return &file; };

private:
  std::ofstream file;
};

#endif // LINKEDINBOT_MESSAGE_H
