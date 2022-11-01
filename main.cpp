#include <iostream>
#include <fstream>
#include <cstring>
#include <windows.h>
#include "vercontrol.h"
#include "terminal.h"
#include "memory.h"
int main() {
    rsasm::terminal::setup();
    rsasm::version_control();
    rsasm::Memory * memory = new rsasm::Memory();
    rsasm::terminal::end_process();
    return 0;
}
