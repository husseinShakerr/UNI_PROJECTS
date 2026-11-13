//
// Created by zhass on 5/23/2025.
//

#include "reporter.h"

#include <cstring>
#include <iomanip>

reporter::reporter(const std::string &filename, const std::string &searching_method) {
    file.open(filename);
    if (!file.is_open()) {
        throw::std::runtime_error("Kunde inte öppna filen: " + filename);
    }
    //file << searching_method << std::endl;
    file << "N,Mean[ns],Stdv[ns],Samples\n";
}

void reporter::logger(size_t N, double mean, double stdv, int observations) {
    file << N << ","
    << mean << ","
    << stdv << ","
    << observations << std::endl;
}
