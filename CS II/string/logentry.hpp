//
// File:        logentry.hpp
//
// Version:     1.0
// Date:
// Author:
//
// Description: Class definition for a log entry.
//
//
//

#ifndef CS_LOGENTRY_H_
#define CS_LOGENTRY_H_

#include "string.hpp"
#include <iostream>
#include <vector>

class LogEntry;

class Date {
public:
  Date() {};
  friend class LogEntry;
  friend std::ostream &operator<<(std::ostream &, const LogEntry &);

private:
  String day, month, year;
};

class Time {
public:
  Time() {};
  friend class LogEntry;
  friend std::ostream &operator<<(std::ostream &, const LogEntry &);

private:
  String hour, minute, second;
};

class LogEntry {
public:
  LogEntry() {};
  LogEntry(const String &);
  friend std::ostream &operator<<(std::ostream &, const LogEntry &);

  String getHost() const { return host; }
  int getBytes() const { return number_of_bytes; }

private:
  String host;
  Date date;
  Time time;
  String request;
  String status;
  int number_of_bytes;
};


std::vector<LogEntry> parse(std::istream &);
void output_all(std::ostream &, const std::vector<LogEntry> &);
void by_host(std::ostream &, const std::vector<LogEntry> &);
int byte_count(const std::vector<LogEntry> &);
void unique_ips(std::ostream&, const std::vector<LogEntry>&);

#endif

