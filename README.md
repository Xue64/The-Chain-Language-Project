# CubeClub's Chain Programming Language
© CubeClub (Rufelle Emmanuel Pactol), 2022

## DevLog as of 27/11/2022
We have now made significant progress as we decouple the old chain::string_construct token handler and deprecated the chain::stringstream header. We have now introduced the new chain::syntax-tree which uses the chain::lexer and the all-new chain::Token for managing tokens, allowing for better modularity going forward. We also shifted the software engineering focus to avoid possible memory leaks. From hereon out, unless absolutely necessary, all pointers will be handled by std::unique_ptr and std::shared_ptr. All NULL handling will also be handled by std::string::npos for strings and special ENUM values for tokens. We also shifted from C-style arrays to std::array<>. 

## ReadMe

The official documentation is available (incomplete) at: https://bit.ly/chaindocx

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
