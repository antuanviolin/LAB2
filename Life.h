#include <fstream>
#include <cstring>
#include <vector>

#ifndef LAB_2_LIFE_H
#define LAB_2_LIFE_H

class lifeException: public std::exception
{
public:
    explicit lifeException(std::string error): error_(std::move(error))
    {}
    const char* what() const noexcept override { return error_.c_str(); }
private:
    std::string error_;
};

namespace life {
    class Life {
    public:
        explicit Life(std::ifstream &input);

        ~Life();

        void runLife(int iterations);

        void printLife();

        void printLife(std::ofstream &output);

        std::vector<bool> getSpace();

        void checkNeighbours();

        void checkLife();

        std::vector<unsigned char> getNeighbours();

    private:
        int height;
        int width;
        std::vector<bool> space;
        std::vector<unsigned char> neighbours;
        std::string name;
        bool birth[9];
        bool survival[9];
    };
}

#endif //LAB_2_LIFE_H
