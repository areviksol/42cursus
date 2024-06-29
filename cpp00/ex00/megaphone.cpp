#include <iostream>
#include <cctype> // for std::toupper

int main(int argc, char* argv[]) {
    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return 0;
    }

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        for (std::string::iterator it = arg.begin(); it != arg.end(); ++it) {
            if (std::islower(*it)) {
                *it = std::toupper(*it);
            }
        }
        std::cout << arg << " ";
    }
    std::cout << std::endl;
    return 0;
}
