#include <string>
#include <iostream>
#include <cstring>
#include "interface.h"
#include "Life.h"

namespace interface{
    const size_t ZERO = 0;
    const size_t ONE = 1;
    const size_t TWO = 2;
    const size_t THREE = 3;
    const size_t FOUR = 4;
    const size_t FIVE = 5;
    const size_t NINE = 9;
    const size_t SIX = 6;
    const size_t THIRTEEN = 13;
    bool onlineInterface::toHhandle(int argc) {
        return argc == TWO;

    }

    void onlineInterface::handel(char **argv) {
        std::string inpath = argv[ONE];
        std::ifstream finput;
        finput.open(inpath);
        if (!finput.is_open()) {
            throw interfaceException("Input file not found");
        }
        life::Life life(finput);
        system("CLS");
        life.printLife();
        while (true) {
            std::string string;
            std::cout << "Enter the command: ";
            std::getline(std::cin, string);
            if (string == "exit") {
                break;
            } else if (string.substr(ZERO, FOUR) == "tick") {
                if (string.size() == FOUR) {
                    life.runLife(ONE);
                } else {
                    life.runLife(std::stoi(string.substr(FIVE)));
                }
                system("CLS");
                life.printLife();
            } else if (string.substr(ZERO, ONE) == "t") {
                if (string.size() == ONE) {
                    life.runLife(ONE);
                } else {
                    life.runLife(std::stoi(string.substr(TWO)));
                }
                system("CLS");
                life.printLife();
            } else if (string.substr(ZERO, FOUR) == "dump") {
                std::ofstream foutput;
                foutput.open(string.substr(FIVE));
                if (!foutput.is_open()) {
                    std::cout << "Output file not found.\n" << std::endl;
                } else {
                    std::cout << "The information was successfully recorded.\n" << std::endl;
                    life.printLife(foutput);
                }
            } else if (string == "help") {
                std::cout
                        << "This program has 3 command: \n 1)tick - does a given number of iterations\n 2)dump - writes the universe to the specified file\n 4)exit - terminates the program\n"
                        << std::endl;
            } else {
                std::cout << "This command is not supported, enter \"help\" to find out the list of commands\n"
                          << std::endl;
            }
        }
    }

    bool onlineInterfaceWithoutInputFile::toHhandle(int argc) {
        return argc == ONE;
    }

    void onlineInterfaceWithoutInputFile::handel(char **argv) {
        std::string inpath = "input1.txt";
        std::ifstream finput;
        finput.open(inpath);
        if (!finput.is_open()) {
            throw interfaceException("Input file not found, check the integrity of the program folder.\n");
        }
        life::Life life(finput);
        system("CLS");
        life.printLife();
        while (true) {
            std::string string;
            std::cout << "Enter the command:";
            std::getline(std::cin, string);
            if (string == "exit") {
                break;
            } else if (string.substr(ZERO, FOUR) == "tick") {
                if (string.size() == FOUR) {
                    life.runLife(ONE);
                } else {
                    life.runLife(std::stoi(string.substr(5)));
                }
                system("CLS");
                life.printLife();
            } else if (string.substr(ZERO, ONE) == "t") {
                if (string.size() == ONE) {
                    life.runLife(ONE);
                } else {
                    life.runLife(std::stoi(string.substr(2)));
                }
                system("CLS");
                life.printLife();
            } else if (string.substr(ZERO, FOUR) == "dump") {
                std::ofstream foutput;
                foutput.open(string.substr(FIVE));
                if (!foutput.is_open()) {
                    std::cout << "Output file not found.\n" << std::endl;
                } else {
                    std::cout << "The information was successfully recorded.\n" << std::endl;
                    life.printLife(foutput);
                }
            } else if (string == "help") {
                std::cout
                        << "This program has 3 command:\n 1)tick - does a given number of iterations\n 2)dump - writes the universe to the specified file\n 4)exit - terminates the program\n"
                        << std::endl;
            } else {
                std::cout << "This command is not supported, enter \"help\" to find out the list of commands."
                          << std::endl;
            }
        }
    }

    bool offlineInterfaceV1::toHhandle(int argc) {
        return argc == FOUR;
    }

    void offlineInterfaceV1::handel(char **argv) {
        int iteration;
        std::string inpath = argv[ONE];
        std::string outpath;
        std::ifstream finput;
        std::ofstream foutput;
        std::string str = argv[TWO];
        if (!(str.substr(ZERO, THIRTEEN).compare("--iterations="))) {
            iteration = std::stoi(str.substr(THIRTEEN));
        } else if (!str.substr(ZERO, NINE).compare("--output=")) {
            outpath = str.substr(NINE);
        } else {
            throw interfaceException("Wrong literal");
        }
        str = argv[3];
        if (!(str.substr(ZERO, THIRTEEN).compare("--iterations="))) {
            iteration = std::stoi(str.substr(THIRTEEN));
        } else if (!str.substr(ZERO, NINE).compare("--output=")) {
            outpath = str.substr(NINE);
        } else {
            throw interfaceException("Wrong literal");
        }
        finput.open(inpath);
        if (!finput.is_open()) {
            throw interfaceException("Input file not found");
        }
        foutput.open(outpath);
        if (!foutput.is_open()) {
            throw interfaceException("Output file not found");
        }
        life::Life life(finput);
        life.runLife(iteration);
        life.printLife(foutput);
        finput.close();
        foutput.close();
    }

    bool offlineInterfaceV2::toHhandle(int argc) {
        return argc == SIX;
    }

    void offlineInterfaceV2::handel(char **argv) {
        int iteration;
        std::string inpath = argv[ONE];
        std::string outpath;
        std::ifstream finput;
        std::ofstream foutput;
        if (!strcmp(argv[TWO], "-i")) {
            iteration = std::stoi(argv[THREE]);
        } else if (!strcmp(argv[TWO], "-o")) {
            outpath = argv[THREE];
        } else {
            throw interfaceException("Wrong literal");
        }
        if (!strcmp(argv[FOUR], "-i")) {
            iteration = std::stoi(argv[FIVE]);
        } else if (!strcmp(argv[FOUR], "-o")) {
            outpath = argv[FIVE];
        } else {
            throw interfaceException("Wrong literal");
        }
        finput.open(inpath);
        if (!finput.is_open()) {
            throw interfaceException("Input file not found");
        }
        foutput.open(outpath);
        if (!foutput.is_open()) {
            throw interfaceException("Output file not found");
        }
        life::Life life(finput);
        life.runLife(iteration);
        life.printLife(foutput);
        finput.close();
        foutput.close();
    }
}
