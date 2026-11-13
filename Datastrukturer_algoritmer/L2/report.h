//
// Created by zhass on 5/14/2025.
//

#ifndef REPORT_H
#define REPORT_H
#include <iosfwd>
#include <fstream>
#include <iomanip>


class report {

public:
    report(const std::string& filename, const std::string&);
    void log_result(size_t, double mean, double stdv, int samples, const std::string& dataType);
private:
    std::ofstream file;
    std::string method;
};



#endif //REPORT_H
