//
// Created by zhass on 5/14/2025.
//

#include "report.h"
report::report(const std::string& filename, const std::string& method): file(filename), method(method) {
    if (!file.is_open())
        throw::std::runtime_error("Kunde inte öppna filen: " + filename);
    file << "N,Mean[ms],Stdv[ms],Samples,Data type\n";
}

void report::log_result(size_t N, double mean, double stdv, int samples, const std::string& dataType) {
    file << N <<","
         << mean <<","
         << stdv <<","
         << samples <<","
         << dataType
         << "\n";
}