#pragma once
#include <string>
#include <iomanip>
#include <sstream>

class Transcript {
    static std::string letter(double s) {
        return s >= 8.5 ? "A" : s >= 7.0 ? "B" : s >= 5.5 ? "C" : "F";
    }
public:
    static std::string line(const std::string& course, int credits, double score) {
        std::ostringstream oss;
        oss << std::left << std::setw(12) << course 
            << " " << credits << " credits  score " << letter(score);
        return oss.str();
    }
};