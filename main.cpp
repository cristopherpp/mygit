#include <cstdlib>
#include <iostream>
#include <string>

int run(const std::string& cmd) {
    std::cout << ">> " << cmd << '\n';

    int result = std::system(cmd.c_str());

    if (result != 0) {
        std::cerr << "Command failed\n";
        std::exit(result);
    }

    return result;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr
            << "Usage: mygit \"commit message\" branch-name\n";
        return 1;
    }

    std::string message = argv[1];
    std::string branch = argv[2];

    run("git add .");

    run("git commit -m \"" + message + "\"");

    run("git push -u origin " + branch);

    std::cout << "Done\n";

    return 0;
}
