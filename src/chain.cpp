#include "vercontrol.h"
#include "terminal.h"
#include "memory.h"
#include "filecontrol.h"
#include "chainmacro.h"
#include "trex.h"
#include "stringstream.h"

_ccmain_ { //execution starts here
    _maindeclare_;
    chain::terminal::setup();
    chain::version_control();
    if (_arguments_present){
        std::string read_file(argv[1]);
        file_line = chain::file::invoke_file(read_file);
        chain::sstream::file_encryptor(file_line);
        _debug_;
        chain::sstream::file_printer(*file_line);

    } else {
        // chain::terminal::event_loop();
    }
    chain::terminal::end_process();
    return 0;
}
