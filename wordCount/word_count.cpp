#include <iostream>
#include <fstream>
#include "boost/program_options.hpp"
#include "utils.hpp"

namespace po = boost::program_options;

// Linux Shell usage:
// g++ word_count.cpp utils.cpp -lboost_program_options
// ./a.out <OPTIONS> [file1 file2 ..]

int main(int argc, char** argv) {
    // Boost program options definition
    po::options_description generic("Options");
    generic.add_options()
            ("help,h", "Show help")
            ("lines,l", "Show number of count_lines")
            ("bytes,c", "Show file size in bytes")
            ("words,w", "Show number of words")
            ("chars,m", "Show number of letters")

            ("input-files", po::value<std::vector<std::string>>(), "Input files")
    ;

    bool l_flag, c_flag, w_flag, m_flag = false;
    std::vector<std::string> files;

    po::positional_options_description p;
    p.add("input-files", -1);

    po::variables_map vm;
    po::store(po::command_line_parser(argc, argv)
                    .options(generic)
                    .positional(p)
                    .run(),
              vm);
    po::notify(vm);


    if (vm.count("help") || argc == 1) {
        std::cout << generic << "\n";
        return 0;
    }
    if (vm.count("input-files")) {
        files = vm["input-files"].as<std::vector<std::string>>();
    }

    // I couldn't come up with anything better :(
    if (vm.count("lines"))
        l_flag=true;
    if (vm.count("bytes"))
        c_flag=true;
    if (vm.count("words"))
        w_flag=true;
    if (vm.count("chars"))
        m_flag=true;

    for(auto & file : files) {
        std::cout << "For file " << file << ":\n";
        if (l_flag)
            std::cout << "Total lines: " << count_lines(file) << "\n";
        if (c_flag)
            std::cout << "File size: " << count_bytes(file) << " bytes\n";
        if (w_flag)
            std::cout << "Total words: " << count_words(file) << "\n";
        if (m_flag)
            std::cout << "Total chars: " << count_chars(file) << "\n";
    }

    return 0;
}