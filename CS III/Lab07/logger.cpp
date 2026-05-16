#include <fstream>
#include <iostream>
#include <string>

class Logger {
   public:
    static Logger& instance() {
        static Logger instance;
        return instance;
    }

    void report(const std::string& message) {
        fout << message << std::endl;
    }

    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

   private:
    std::ofstream fout;

    Logger() {
        fout.open("log.txt", std::fstream::out | std::fstream::app);
    }

    ~Logger() {
        fout.close();
    }
};

void run1() {
    Logger::instance().report("11");
    Logger::instance().report("12");
}

void run2() {
    Logger::instance().report("21");
    Logger::instance().report("22");
    Logger::instance().report("23");
}

int main() {
    Logger::instance().report("begin");

    run1();
    run2();
    run1();
    run2();
    run1();
    run2();
    run1();
    run2();
    run1();
    run2();

    
    Logger::instance().report("end");

    return 0;
}
