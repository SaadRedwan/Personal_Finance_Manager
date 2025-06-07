# Personal Finance Manager (Console Application)

A command-line application built with C++ for tracking personal income and expenses. This project is a comprehensive exercise designed to apply and reinforce core software engineering principles and modern C++ features in a console environment.

## Core Features

The application currently supports the following features through a text-based menu interface:

-   **Add Transactions:** Record both income and expense transactions with details for the date, amount, and description.
-   **View Transaction History:** Display a complete, formatted list of all past transactions.
-   **Live Balance Tracking:** Automatically calculate and display the current balance based on the transaction history.
-   **Data Persistence:** All financial data is automatically saved to a local `transactions.csv` file upon exiting and loaded back when the application starts.

## Tech Stack & Key Concepts Practiced

This project was built from the ground up to practice essential C++ concepts.

-   **Language:** C++ (utilizing the C++17 standard)
-   **Build System:** CMake
-   **Core Principles:** Object-Oriented Programming (OOP) is at the heart of the project, using:
    -   **Inheritance and Polymorphism:** A base `Transaction` class with derived `Income` and `Expense` classes.
    -   **Encapsulation:** Data is protected within classes and accessed via public methods.
-   **Memory Management:** Modern C++ practices are used, specifically **smart pointers** (`std::unique_ptr`) to manage the lifetime of transaction objects, preventing memory leaks.
-   **Data Structures:** `std::vector` is used to hold the collection of all transactions.
-   **File I/O:** `fstream` is used for all file operations, saving to and loading from a human-readable CSV format. `sstream` is used for parsing data from the file.
-   **Console I/O:** The user interface is built using `iostream`, with robust input handling.

## Build and Run Instructions

1.  **Prerequisites:** Ensure you have a C++17 compliant compiler (e.g., MinGW g++, MSVC) and CMake installed and available in your PATH.
2.  Clone the repository.
3.  From the project's root directory, create and navigate to a build folder:
    ```bash
    mkdir build
    cd build
    ```
4.  Run CMake to configure the project:
    ```bash
    cmake ..
    ```
5.  Run the build command to compile the source code:
    ```bash
    cmake --build .
    ```
6.  The executable, `personal_finance_manager.exe`, will be located in the `build` directory. Run it from the terminal to start the application.

## Known Limitations

-   **Unicode Display:** The current console implementation on Windows has known limitations in reliably displaying non-ASCII characters (e.g., Arabic). This is a primary motivator for the future migration to a GUI-based frontend.