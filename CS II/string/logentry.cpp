//
//
// File:        logentry.cpp
//
// Version:     1.0
// Date:
// Author:
//
// Description: Class implementation for a log entry.
//
//

#include "logentry.hpp"
#include "string.hpp"
#include <iostream>
#include <map>
#include <vector>

LogEntry::LogEntry(const String &line) {
  std::vector<String> logEntryParts = line.split(' ');

  host = "";
  date.day = date.month = date.year = "";
  time.hour = time.minute = time.second = "";
  request = "";
  status = "";
  number_of_bytes = 0;

  if (logEntryParts.size() < 10) {
    return;
  }

  host = logEntryParts[0];

  String dateTime = logEntryParts[3];
  dateTime = dateTime.substr(1, dateTime.length() - 1);

  std::vector<String> dateTimeParts = dateTime.split(':');
  if (dateTimeParts.size() >= 4) {
    std::vector<String> dateParts = dateTimeParts[0].split('/');
    if (dateParts.size() == 3) {
      date.day = dateParts[0];
      date.month = dateParts[1];
      date.year = dateParts[2];
    }

    time.hour = dateTimeParts[1];
    time.minute = dateTimeParts[2];
    time.second = dateTimeParts[3];
  }

  request = logEntryParts[5] + " " + logEntryParts[6] + " " + logEntryParts[7];

  status = logEntryParts[8];

  if (logEntryParts[9] == "-") {
    number_of_bytes = 0;
  } else {
    int bytes = 0;
    for (int i = 0; i < logEntryParts[9].length(); ++i) {
      if (logEntryParts[9][i] >= '0' && logEntryParts[9][i] <= '9') {
        bytes = bytes * 10 + (logEntryParts[9][i] - '0');
      }
    }
    number_of_bytes = bytes;
  }
}

std::vector<LogEntry> parse(std::istream &in) {
  std::vector<LogEntry> result;
  char buffer[4096];

  while (in.getline(buffer, 4096)) {
    String line(buffer);
    result.push_back(LogEntry(line));
  }

  return result;
}
void output_all(std::ostream &out, const std::vector<LogEntry> &logs) {
  for (int i = 0; i < (int)logs.size(); i++) {
    out << logs[i] << std::endl;
  }
}

void by_host(std::ostream &out, const std::vector<LogEntry> &logs) {
  for (int i = 0; i < (int)logs.size(); i++) {
    out << logs[i].getHost() << std::endl;
  }
}


void unique_ips(std::ostream &out, const std::vector<LogEntry> &logs) {
  std::map<String, int> ip_counts;

  for (int i = 0; i < static_cast<int>(logs.size()); i++) {
    ip_counts[logs[i].getHost()]++;
  }

  for (std::map<String, int>::iterator it = ip_counts.begin(); it != ip_counts.end(); ++it) {
    out << it->first << std::endl;
  }

  out << "Total unique IPs: " << ip_counts.size() << std::endl;
}

int byte_count(const std::vector<LogEntry> &logs) {
  int total = 0;
  for (int i = 0; i < (int)logs.size(); i++) {
    total += logs[i].getBytes();
  }
  return total;
}



std::ostream &operator<<(std::ostream &out, const LogEntry &log) {
  out << log.host << " " << log.date.day << "/" << log.date.month << "/"
      << log.date.year << ":" << log.time.hour << ":" << log.time.minute << ":"
      << log.time.second << " " << log.request << " " << log.status << " "
      << log.number_of_bytes;
  return out;
}

