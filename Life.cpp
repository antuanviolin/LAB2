#include "Life.h"
#include <iostream>

int mod(int x, int y);

namespace life {
    const size_t ZERO = 0;
    const size_t NEG_ONE = -1;
    const size_t ONE = 1;
    const size_t TWO = 2;
    const size_t THREE = 3;
    const size_t SHIFT = 1;
    const size_t NINE = 9;

    Life::Life(std::ifstream &input) {
        std::string buff;
        std::getline(input, buff);
        int position_space = ZERO;
        for (int i = ZERO; i < buff.size(); ++i) {
            if (buff[i] == ' ') {
                position_space = i;
            }
        }
        width = std::stoi(buff.substr(ZERO, position_space));
        height = std::stoi(buff.substr(position_space + 1));
        std::getline(input, buff);
        if (buff.substr(ZERO, TWO) == "#N") {
            name = buff.substr(THREE);
        } else {
            throw lifeException("Your universe has no name");
        }
        for (int i = ZERO; i < NINE; ++i) {
            birth[i] = false;
            survival[i] = false;
        }
        std::getline(input, buff);
        if (buff.substr(ZERO, TWO) == "#R") {
            char whatRules = 'b';
            buff = buff.substr(THREE);
            for (int i = ZERO; i < buff.length(); ++i) {
                if (buff[i] != '/') {
                    if (buff[i] == 'B') {
                        whatRules = 'b';
                    } else if (buff[i] == 'S') {
                        whatRules = 's';
                    } else {
                        if (whatRules == 'b') {
                            birth[buff[i] - '0'] = true;
                        } else {
                            survival[buff[i] - '0'] = true;
                        }
                    }
                }
            }
        } else {
            throw lifeException("Your universe has no life parameters");
        }
        space.resize(height * width);
        std::fill(space.begin(), space.end(), false);
        neighbours.resize(height * width);
        std::fill(neighbours.begin(), neighbours.end(), 0);
        int x, y;
        while (!input.eof()) {
            input >> buff;
            x = stoi(buff) - SHIFT;
            input >> buff;
            y = stoi(buff) - SHIFT;
            if (ZERO < x < width && ZERO < y < height) {
                space[y * width + x] = true;
            } else {
                throw lifeException("Incorrect coordinates");
            }
        }
    }

    void Life::runLife(int iterations) {
        for (int i = ZERO; i < iterations; ++i) {
            this->checkNeighbours();

            this->checkLife();
        }
    }

    void Life::checkNeighbours() {
        for (int i = ZERO; i < height * width; ++i) {
            int row = i / width;
            int column = i % width;
            neighbours[i] = space[(mod(row - SHIFT, height)) * width + mod(column - SHIFT, width)] +
                            space[(mod(row - SHIFT, height)) * width + column] +
                            space[(mod(row - SHIFT, height)) * width + mod(column + SHIFT, width)] +
                            space[(mod(row, height)) * width + mod(column - SHIFT, width)] +
                            space[(mod(row, height)) * width + mod(column + SHIFT, width)] +
                            space[(mod(row + SHIFT, height)) * width + mod(column - SHIFT, width)] +
                            space[(mod(row + SHIFT, height)) * width + column] +
                            space[(mod(row + SHIFT, height)) * width + mod(column + SHIFT, width)];
        }
    }

    void Life::checkLife() {
        for (int i = ZERO; i < height * width; ++i) {
            if (birth[neighbours[i]] || (survival[neighbours[i]] && space[i])) {
                space[i] = true;
            } else {
                space[i] = false;
            }
        }
    }

    int mod(int x, int y) {
        return (x == NEG_ONE ? y - ONE : x % y);
    }

    void Life::printLife() {
        for (int i = ZERO; i < height * width; ++i) {
            if (i % width == ZERO && i != ZERO)
                std::cout << std::endl;
            std::cout << space[i];
        }
        std::cout << std::endl;
    }

    void Life::printLife(std::ofstream &output) {
        output << name << std::endl;
        for (int i = ZERO; i < width * height; ++i) {
            if (i % width == ZERO && i != ZERO)
                output << std::endl;
            output << space[i];
        }
    }

    std::vector<bool> Life::getSpace() {
        return space;
    }

    std::vector<unsigned char> Life::getNeighbours() {
        return neighbours;
    }
}