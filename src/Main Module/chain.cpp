#include "../ChainDevKit/Virtual Machine/vercontrol.h"
#include "../ChainDevKit/Compiler/loggers/terminal.h"
#include "../ChainDevKit/Virtual Machine/memory.h"
#include "chainmacro.h"
#include "../TRex Encryption/trex.h"
#include "../deprecated/deprecated_stringstream.h"
#include "../ChainDevKit/Compiler/loggers/debug.h"
#include "../ChainDevKit/Compiler/compiler.h"
#include "../Abstract Syntax Tree/lexer_module.h"

_ccmain_ {
    _maindeclare_
    auto result = chain::syntax_tree::extract_complex("Hello!!\\n\\n");
    for (auto &i : *result){
        std::cout << i << std::endl;
    }
    if (_arguments_present){
        if (_direct_call_){ // checks if command was not run via the terminal
            _set_file_direct_call_;
            file_line = chain::file::invoke_file(read_file); // returns the file in a string vector
            std::cout.flush();
            /*for (auto && i : *file_line){
                chain::line++;
                std::vector<chain::string_construct> * parsed = chain::sstream::string_parser(i); // returns a vector of string_construct with operator information
                chain::debug::print_parser(*parsed);
            }*/
            for (auto &i : *file_line){
                std::cout << i << std::endl;
                std::cout.flush();
            }
            chain::terminal::compilation_success();
            return 0;
        }

        if (!(_direct_call_)){
            _configure_arguments_;
            std::cout << "COMMAND IS " << argv[1];
        }
        if (!strcmp(_argument_, "-chainc")){
            chain::terminal::setup();
            chain::version_control();
            std::cout << "We invoke the Chain Compiler\n";
            _set_file_;
            file_line = chain::file::invoke_file(read_file); // returns the file in a string vector
            for (int i=0; i<file_line->size(); i++){
                std::vector<chain::string_construct> * parsed = chain::sstream::string_parser((*file_line)[i]); // returns a vector of string_construct with operator information
            }
            chain::terminal::compilation_success();

        }

        if (_argument_ == "-chainvm"){
            chain::install::install_update();
        }


    } else {
        // chain::terminal::event_loop();
        chain::terminal::compilation_success();
    }

    return 0;
}
