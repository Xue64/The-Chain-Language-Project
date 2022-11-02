#include "vercontrol.h"
#include "terminal.h"
#include "memory.h"
#include "filecontrol.h"
#include "chainmacro.h"

_ccmain_ { //execution starts here
    chain::terminal::setup();
    chain::version_control();
    chain::Memory * memory = new chain::Memory();
    if (_no_arguements){
        std::string read_file(argv[1]);
        chain::file::invoke_file(read_file);
    } else {
        chain::terminal::event_loop();
    }
    chain::terminal::end_process();
    return 0;
}
