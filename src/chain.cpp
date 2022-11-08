#include "vercontrol.h"
#include "terminal.h"
#include "memory.h"
#include "filecontrol.h"
#include "chainmacro.h"
#include "trex.h"
#include "stringstream.h"
#include "debug.h"
_ccmain_ { //execution starts here
    _maindeclare_;
    chain::terminal::setup();
    chain::version_control();
    if (_arguments_present){
        std::string read_file(argv[1]);
        file_line = chain::file::invoke_file(read_file); // returns the file in a string vector
        for (int i=0; i<file_line->size(); i++){
            chain::debug::print_vector<std::string>(*file_line);
            std::vector<string_construct> * parsed = chain::sstream::string_parser((*file_line)[i]); // returns a vector of string_construct with operator information
          //  chain::debug::print_parser(*parsed);
        }
        chain::terminal::compilation_success();
    } else {
        // chain::terminal::event_loop();
    }

    return 0;
}
