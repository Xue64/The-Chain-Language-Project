#include <iostream>
#include <fstream>
#include <cstring>
#include <windows.h>
#include "vercontrol.h"
#include "terminal.h"
#include "memory.h"
#include "filecontrol.h"
int main() {
    rsasm::terminal::setup();
    rsasm::version_control();
    rsasm::Memory * memory = new rsasm::Memory();
    std::cout << std::endl;
    std::string read_file;
    std::cin >> read_file;
    rsasm::file::invoke_file(read_file);
    rsasm::terminal::end_process();
    return 0;
}
