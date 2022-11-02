# CubeClub_RS_ASM
© CubeClub (Rufelle Emmanuel Pactol), 2022

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

## What is RS-ASM?
The Relatively Simpler Assembly (chain) is an virtual machine for the chain programming language built for educational purposes-- to help educate new programmers towards ASM. 

## RS-ASM vs RelativelySimpler CPU, which should I install?
The RelativelySimpler CPU (RSCPU) is a small project meant for basic ASM commands. However, it has some integaral design flaws that makes it hard to use. These points are only a part of our rationale as to why the change was done:
  - The base RSCPU cannot support in-line version control and update
  - The base RSCPU cannot check for updates
  - The source code of the original RSCPU is cluttered, with multiple layers of unecessary abstraction
  - The 256 byte memory limit
  - The original source code was hard to maintain
  - Because of the memory limit, strings and labels are hard to support
  - Copy pasting code was unreliable
  - Does not support file output
  - Naming clash with Windows API, making the Windows API incompatible
  
 ## Integral changes from RS-ASM to RelativelySimpler CPU
  - Introducing, the argument operator (','), which can be used to specify that the command has an operand. 

  #### From the RSCPU syntax of:
        LOAD 5
        SAVE 3
        ORG 12
 
  #### To the RS-ASM syntax of:
        LOAD, 5
        SAVE, 3
        ORG, 12
        
  - We are also introducing the label operator (':') which indicates that the following string is a label. Labels are case-sensetive.
  
        sampleLABEL:
        LOAD, 10
        SAVE, 3
        ORG, 12
        
   - The RS ASM also installs directly to your PC and is run directly in the command line using the Windows Shell or the Command Prompt, just enter chain in the command line to run.
   - Now as 64kb of memory!
   - Now runs as an virtual machine
