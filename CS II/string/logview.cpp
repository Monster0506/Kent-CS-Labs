#include "logentry.hpp"
#include "string.hpp"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
  std::vector<String> option(4);
  option[0] = "all";
  option[1] = "bytes";
  option[2] = "host";
  option[3] = "ip";
  if (argc != 3) {
    std::cerr << "Error" << std::endl;
    std::cerr << "Usage: " << argv[0] << " [ " << option[0] << " | "
              << option[1] << " | " << option[2] << " | "<<option[3]<<" ] log_file" << std::endl;
    exit(1);
  }

  std::ifstream in(argv[2]);
  if (!in) {
    std::cerr << "Error: Can not open file: " << argv[2] << std::endl;
    exit(2);
  }
  std::vector<LogEntry> log_entries = parse(in);
  in.close();

  String arg(argv[1]);
  if (arg == option[0]) {
    output_all(std::cout, log_entries);
  } else if (arg == option[1]) {
    std::cout << "Total number of bytes sent: " << byte_count(log_entries)
              << std::endl;
  } else if (arg == option[2]) {
    by_host(std::cout, log_entries);
  } else if (arg == option[3]) {
    // created a map of each ip, which automatically makes them unique as it is a set, then print the size of that map
    unique_ips(std::cout, log_entries);
  } else {
    std::cerr << "Invalid option: " << argv[1] << std::endl;
    std::cerr << "Valid options: " << option[0] << " " << option[1] << " "
              << option[2] << " " << option[3] << std::endl;
    exit(3);
  }
  return 0;
}
