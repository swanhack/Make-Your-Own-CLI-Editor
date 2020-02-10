#!/usr/bin/python3

import sys


prompt = ":"
buffer = ""
verbose = False
file = None
    

def main():
    if len(sys.argv) == 1:
        parse_commands()
    elif len(sys.argv) == 2:
        filename = sys.argv[1]
        open_file(filename)
        parse_commands()
    else:
        print("Error: Incorrect number of arguments.")
        sys.exit(2)


def parse_commands():
    while True:
        args = input(prompt).split()
        command = args[0]
        if len(args) == 2:
            param = args[1]
            get_function_for_command(command, param)
        else:
            get_function_for_command(command)


def get_function_for_command(cmd, arg=None):
    """Converts editor commands into function calls."""
    commands = {
        'e': lambda: open_file(arg),
        'a': append,
        'w': lambda: file.write(buffer),
        'p': lambda: print(buffer),
        'q': sys.exit
    }

    function = commands.get(cmd, lambda: print(f"Error: `{cmd}` is not a valid command."))
    return function()


def open_file(filename=None):
    """Open a file to edit it. Currently only supports appending new lines to a file."""
    if filename == None:
        print("Error: Missing filename")
        return
    else:
        # TODO Figure out how to edit existing file content, not just append to the end.
        global file
        file = open(filename, "a")
        print("Editing: " + filename)


def append():
    """Appends lines to the end of the buffer. Type `.` to exit."""
    end = False
    while not end:
        line = input()
        if line.startswith("."):
            end = True
        else:
            global buffer
            buffer += "\n" + line


main()
