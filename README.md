# Photo studio
## 1.1 Main Actors
- User
### The user interacts with the console application through a menu interface. The user can place orders, view existing orders, save orders to a file, and exit the system.
- System
### The system processes user input, manages order data, and handles menu navigation using a state-based structure.
- Photographer
### A domain entity representing photographers. In Release 1, the photographer functionality is planned but not fully implemented.

## 1.2 Business Process
    1. The user starts the application.
    2. The system displays the main menu.
    3. The user selects an option from the menu.
    4. The system processes the selected action:
    - place a new order
    - view existing orders
    - list photographers
    - save orders to a file
    - exit the application
    5. If a new order is placed, the system collects user input and validates it.
    6. The system creates an Order object and stores it using OrderManager.
    7. The system may save orders to a file using Logger.
    8. The system continues until the user chooses to exit.

## 1.3 Problem Areas
### Possible issues that may occur during system operation:
    - Invalid user input (incorrect menu option or invalid values)
    - Attempting to view orders when no orders exist
    - File writing errors when saving orders
    - Unimplemented functionality (for example photographer listing)
    - Incorrect file path provided by the user
### The system must validate user input and handle incorrect cases properly.

## 1.4 Conclusion (Three Axes)
- Right Product
### The system provides a console-based application for managing and storing customer orders.
- Done Right
### The program separates responsibilities between different components such as menu handling, input validation, order management, and logging.
- Managed Right
### The system follows a modular design and uses state-based program flow to manage application states.

## 1.5 Purpose
### The purpose of this project is to develop a console-based C++ application that demonstrates modular software architecture and object-oriented design.
### The application allows users to create and manage orders, interact with a menu-driven interface, and save order information to a file.

## 1.6 Scope
### The system provides basic functionality for managing orders through a console interface.
### Included features:
    - Console-based menu interface
    - User input validation
    - Creating new orders
    - Viewing current orders
    - Saving orders to a file
    - State-based application navigation
### Excluded features:
    - Graphical user interface
    - Network functionality
    - Database storage
    - Full photographer management system

## 1.7 Stakeholders
- User
### Uses the system to place and review orders.
- Developer
### Responsible for implementing and maintaining the system.
- Instructor
### Evaluates the project structure, code quality, and documentation.

## 2 SW Functional Requirements
1. FR-1
### The system shall display a main menu to the user.
2. FR-2
### The system shall allow the user to select menu options using numeric input.
3. FR-3
### The system shall validate user input before processing.
4. FR-4
## The system shall allow the user to place a new order.
5. FR-5
### The system shall store orders in memory using an order manager.
6. FR-6
### The system shall allow the user to view the current list of orders.
7. FR-7
### The system shall allow the user to save orders to a file.
8. FR-8
### The system shall control program flow using application states.
9. FR-9
### The system shall terminate when the user selects the quit option.

## 3 Acceptance Criteria
1. AC-1
### When the application starts, the main menu is displayed.
2. AC-2
### When the user selects a valid menu option, the corresponding action is executed.
3. AC-3
### When the user enters an invalid menu option, the system asks for input again.
4. AC-4
### When the user places an order, the order is added to the order collection.
5. AC-5
### When the user selects “See current orders”, the system displays the stored orders.
6. AC-6
### When the user selects “Save orders”, the system writes the orders to a file.
7. AC-7
### When the user selects “Quit”, the program exits successfully.

