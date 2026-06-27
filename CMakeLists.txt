cmake_minimum_required(VERSION 3.10)
project(MovieTicketBookingSystem CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADERS
    include/Person.h
    include/Customer.h
    include/Admin.h
    include/Show.h
    include/Movie.h
    include/Concert.h
    include/Seat.h
    include/RegularSeat.h
    include/VIPSeat.h
    include/Ticket.h
    include/StandardTicket.h
    include/GroupTicket.h
    include/Payment.h
    include/CashPayment.h
    include/CardPayment.h
    include/NotificationService.h
    include/ConsoleNotification.h
    include/Theater.h
    include/BookingSystem.h
)

set(SOURCES
    src/Person.cpp
    src/Customer.cpp
    src/Admin.cpp
    src/Show.cpp
    src/Movie.cpp
    src/Concert.cpp
    src/Seat.cpp
    src/RegularSeat.cpp
    src/VIPSeat.cpp
    src/Ticket.cpp
    src/StandardTicket.cpp
    src/GroupTicket.cpp
    src/Payment.cpp
    src/CashPayment.cpp
    src/CardPayment.cpp
    src/NotificationService.cpp
    src/ConsoleNotification.cpp
    src/Theater.cpp
    src/BookingSystem.cpp
    src/main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
