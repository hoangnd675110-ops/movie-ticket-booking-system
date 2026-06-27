#include "BookingSystem.h"
#include "KonataArt.h"
#include "ConsoleUtils.h"
#include <iostream>
#include <limits>

static void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

static void waitForEnter() {
    std::cout << centered("Press Enter to continue...");
    std::cin.get();
}

static int getIntInput(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << centered(prompt);
        std::cin >> value;
        if (std::cin.fail()) {
            printCentered("Invalid input.");
            clearInput();
        } else {
            clearInput();
            return value;
        }
    }
}

static std::string getStringInput(const std::string& prompt) {
    std::cout << centered(prompt);
    std::string input;
    std::getline(std::cin, input);
    return input;
}

int main() {
    BookingSystem system;
    system.initializeDefaultData();

    auto konata = getKonataArt();

    clearScreen();
    printArtCentered(konata);
    printCentered("");
    printCentered("Welcome to the Movie Ticket Booking System");
    printCentered("");
    printCentered(std::to_string(system.getShowCount()) + " shows, "
                + std::to_string(system.getTheaterCount()) + " theaters loaded.");
    printCentered("");
    waitForEnter();

    int choice;
    do {
        clearScreen();
        printSeparator();
        printCenteredBanner("Movie Ticket Booking System");
        printCentered("");
        printCentered("1. View Shows");
        printCentered("2. View Theaters & Seats");
        printCentered("3. Book a Standard Ticket");
        printCentered("4. Book a Group Ticket (15% off)");
        printCentered("5. View All Tickets");
        printCentered("6. Cancel a Ticket");
        printCentered("7. Exit");
        printCentered("");
        printSeparator();
        choice = getIntInput("Choice: ");

        switch (choice) {
        case 1:
            clearScreen();
            printCentered("--- Shows ---");
            system.displayAllShows();
            waitForEnter();
            break;

        case 2: {
            clearScreen();
            system.displayAllTheaters();
            int tIdx = getIntInput("Select theater: ");
            printCentered("");
            system.displayTheaterSeats(tIdx);
            waitForEnter();
            break;
        }

        case 3: {
            clearScreen();
            if (system.getShowCount() == 0 || system.getTheaterCount() == 0)
                { printCentered("No shows or theaters available."); waitForEnter(); break; }

            printCentered("--- Select Show ---");
            system.displayAllShows();
            int sIdx = getIntInput("Show index: ");
            if (sIdx < 0 || sIdx >= system.getShowCount()) { waitForEnter(); break; }

            printCentered("--- Select Theater ---");
            system.displayAllTheaters();
            int tIdx = getIntInput("Theater index: ");
            if (tIdx < 0 || tIdx >= system.getTheaterCount()) { waitForEnter(); break; }

            system.displayTheaterSeats(tIdx);

            std::string rowStr = getStringInput("Row (A, B, ...): ");
            int row = static_cast<int>(std::toupper(rowStr[0]) - 'A');
            int col = getIntInput("Column number: ") - 1;
            std::string name = getStringInput("Customer name: ");
            if (name.empty()) { printCentered("Name required."); waitForEnter(); break; }

            if (system.bookTicket(sIdx, tIdx, row, col, name, "standard"))
                printCentered("Ticket booked.");
            else
                printCentered("Seat unavailable or invalid.");
            waitForEnter();
            break;
        }

        case 4: {
            clearScreen();
            if (system.getShowCount() == 0 || system.getTheaterCount() == 0)
                { printCentered("No shows or theaters available."); waitForEnter(); break; }

            printCentered("--- Select Show ---");
            system.displayAllShows();
            int sIdx = getIntInput("Show index: ");
            if (sIdx < 0 || sIdx >= system.getShowCount()) { waitForEnter(); break; }

            printCentered("--- Select Theater ---");
            system.displayAllTheaters();
            int tIdx = getIntInput("Theater index: ");
            if (tIdx < 0 || tIdx >= system.getTheaterCount()) { waitForEnter(); break; }

            system.displayTheaterSeats(tIdx);

            std::string rowStr = getStringInput("Row (A, B, ...): ");
            int row = static_cast<int>(std::toupper(rowStr[0]) - 'A');
            int col = getIntInput("Column number: ") - 1;
            std::string name = getStringInput("Customer name: ");
            int groupSize = getIntInput("Group size: ");
            if (name.empty() || groupSize < 2)
                { printCentered("Name required and group size >= 2."); waitForEnter(); break; }

            if (system.bookTicket(sIdx, tIdx, row, col, name, "group", groupSize))
                printCentered("Group ticket booked (15% discount applied).");
            else
                printCentered("Seat unavailable or invalid.");
            waitForEnter();
            break;
        }

        case 5:
            clearScreen();
            printCentered("--- All Tickets ---");
            system.displayAllTickets();
            waitForEnter();
            break;

        case 6: {
            clearScreen();
            if (system.getTicketCount() == 0)
                { printCentered("No tickets to cancel."); waitForEnter(); break; }
            system.displayAllTickets();
            int tId = getIntInput("Ticket ID to cancel: ");
            if (system.cancelTicket(tId))
                printCentered("Ticket cancelled.");
            else
                printCentered("Ticket not found.");
            waitForEnter();
            break;
        }

        case 7:
            clearScreen();
            printCentered("Thanks for stopping by! See you next time.");
            break;

        default:
            printCentered("Invalid choice (1-7).");
        }
    } while (choice != 7);

    return 0;
}
