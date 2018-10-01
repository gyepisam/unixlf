# What is this?

unixlf is a unix command line tool that filters input lines with any
line end convention and outputs lines with unix line end conventions.

It is useful for converting files from DOS or Mac (OSX) systems into
unix format without knowing the source input line conventions in advance.

Use this program to ensure that a given input data conforms to the desired
line end convention.

# How do I install it?

Install to the default destination directory of '/usr/local/bin' with the command

    `make install`

Provide an alternate destination directory if desired:

    `make DESTDIR=~/bin install`

If you just want to build but not install, use the command 

    `make`

Build the program and run tests with the command

    `make tests`

# How do I use it? 

As a filter program, unixlf reads from stdin and prints to stdout.

The command 

    `unixlf < inputfile`
        
filters the content of inputfile to stdout, while the command

    `unixlf < inputfile > outputfile`

puts the output in outputfile.

unixlf can also be combined with other tools in a standard pipeline
such as in this example.

    `unixlf < inputfile | awk '$1 ~ /Chapter/ {print $2}`
    
# Tell me more 

Text lines in unix end with the new line character (LF, \012).
Text lines on other common platforms end with carriage return (CR, \015) or
CRLF (\015\012). The program changes either kind to new lines.
However, carriage returns that are preceded with a backslashed escape
character are not modified.

The test files in the 't' directory provide good examples if various inputs
and their corresponding expected outputs.

# Where do I send praise or blame? 

unixlf is written by Gyepi Sam <self-unixlf@gyepi.com>

