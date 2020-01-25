# Make-Your-Own-CLI-Editor

Yelo, this week we want you to try and make your own Command Line Editor.. that is, a command line application that allows you to both create and edit files.

The example code attached to this repo is crap, an idiot (me) hacked it together in under 90 minutes, never the less it is a working example.

## What is a file?

Abstracted somewhat, a file need be no more than a list of lines.

```
file = List(line)
```

Beyond this the main scope of the program will be a loop that continually waits for for a user to type something:

```
while (Exit command not given) do {
    // Stuff
}
```

These code snippets are intentionally vague, there are no language restrictions.

## Cool, but what do we do?

### Level 1

* You should be able to open it, type stuff and then save it under a filename you choose
* You should be able to open a file using a filename as an argument and append to them

Notes: Some of these may need internal commands.

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

* Edit existing files, delete lines, add lines, change lines, swap lines, etc

At this point a very simple version of the application may function like so:

```
> open thing.txt
File opened.

> list
1    Hello
2    This works!

> edit 1
Hi
.

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

* Why are you asking me? You clearly know what you want.

## The end

Nope, that really is it.. short and sweet, get designing!