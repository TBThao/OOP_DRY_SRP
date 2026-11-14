#pragma once
#include <string>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <cctype>
#include <algorithm>

class LineFormatter {
    static std::string letter(double s) {
        return s >= 8.5 ? "A" : s >= 7.0 ? "B" : s >= 5.5 ? "C" : "F";
    }
public:
    enum class Mode { INVOICE, GRADE };

    static std::string format(Mode mode, std::string label, double v1, double v2,
                              bool uppercaseLabel, bool showCurrency,
                              bool showLetterGrade, bool roundV1, int labelWidth) {
        std::string l = label;
        if (uppercaseLabel) {
            std::transform(l.begin(), l.end(), l.begin(), ::toupper);
        }
        std::ostringstream leftStream;
        leftStream << std::left << std::setw(labelWidth) << l;
        std::string left = leftStream.str();

        if (mode == Mode::INVOICE) {
            std::string qty = roundV1 ? std::to_string(static_cast<long>(v1)) : std::to_string(v1);
            std::ostringstream moneyStream;
            moneyStream << std::fixed << std::setprecision(0) << (v1 * v2);
            std::string money = moneyStream.str() + (showCurrency ? " VND" : "");
            return left + " x" + qty + "  " + money;
        } else {
            std::string credits = roundV1 ? std::to_string(static_cast<long>(v1)) : std::to_string(v1);
            std::string score = showLetterGrade ? letter(v2) : std::to_string(v2);
            
            if (!showLetterGrade) {
                score.erase(score.find_last_not_of('0') + 1, std::string::npos);
                if (score.back() == '.') score.pop_back();
            }

            return left + " " + credits + " credits  score " + score;
        }
    }
};