#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#ifdef _WIN32
#include <windows.h>
#endif

inline int getConsoleWidth() {
#ifdef _WIN32
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
        return csbi.srWindow.Right - csbi.srWindow.Left + 1;
#endif
    return 80;
}

inline std::string centered(const std::string& text, int width = -1) {
    if (width < 0) width = getConsoleWidth();
    int len = static_cast<int>(text.length());
    if (len >= width) return text;
    int padding = (width - len) / 2;
    return std::string(padding, ' ') + text;
}

inline void printCentered(const std::string& text, int width = -1) {
    std::cout << centered(text, width) << "\n";
}

inline void printArtCentered(const std::vector<std::string>& art, int width = -1) {
    if (width < 0) width = getConsoleWidth();
    for (const auto& line : art)
        printCentered(line, width);
}

inline void printSeparator(int width = -1) {
    if (width < 0) width = getConsoleWidth();
    std::cout << std::string(width, '=') << "\n";
}

inline void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    std::cout << "\033[2J\033[1;1H";
#endif
}

inline void printCenteredBanner(const std::string& text, char fill = '=', int width = -1) {
    if (width < 0) width = getConsoleWidth();
    int textLen = static_cast<int>(text.length());
    if (textLen >= width - 2) {
        std::cout << text << "\n";
        return;
    }
    int padding = (width - textLen - 2) / 2;
    std::cout << std::string(padding, fill) << " " << text << " "
              << std::string(width - padding - textLen - 2, fill) << "\n";
}
