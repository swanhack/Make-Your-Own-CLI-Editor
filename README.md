# Make-Your-Own-CLI-Editor

Yelo, this week we want you to try and make your own Command Line Editor.. that is, a command line application that allows you to both create and edit files.

The various examples attached to this repo are not fully fledged in anyway, they were all hacked together in around an hour, none the less they are all working examples.

## What is a file?

Abstracted somewhat, a basic file need be no more than a list of lines.

```
file = List(line)
```

Beyond this the main scope of a line editor might be a loop that continually waits for input:

```
while (Exit command not given) do {
    // Stuff
}
```

These code snippets are intentionally vague, there are no language restrictions.

For an extra challenge however, we would optionally like people to stick to a time limit of one hour.  Imagine it as a mini practice Hackathon if you will.

## Cool, but what do we do?

### Level 1

* You should be able to open the program (it should compile)
* You should be able to quit the program (sans interupt)
* You should be able to open a file using it's filename
* You should be able to list the contents of a file
* You should be able to append to the end of a file

Hint: Use a buffer!
* This will limit your interactions with the file to just two, opening and writing.

At this point a very simple version of the application may function like so:

```
> open thing.txt
File opened.

> list
1    Hello

> append
This works!
.

> list
1    Hello
2    This works!

> write
File written.

> quit
Bye!
```

### level 2

* You should be able to edit an existing line a file
* You should be able to delete lines from a file
* You should be able to add lines to the middle of a file
* You should be able to swap two or more line or blocks a file

At this point a very simple version of the application may function like so:

```
> open thing.txt
File opened.

> list
1    Hello
2    This works!

> edit 1
Hi

> list
1    Hi
2    This works!

> delete 2
Line 2 deleted.

> list
1   Hi

> quit
Bye!
```

### level 3

Why are you asking me? You clearly know what you want.

Oh go on then .. things you could add:

* Optional / Toggleable, User Defined / Default prompt
* Optional / Toggleable, User Defined / Default error messages
    * Possibly with varying levels of verbosity?
* Ability to search a file for occurences of a character / word / string

## The end

Nope, that really is it.. short and sweet, get designing!