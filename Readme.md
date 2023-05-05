# Mario runs in your terminal.
This is a tiny C program which allows you to let Mario run in your terminal.

![running](./screen/run.gif)

It is inspired by SL command.

> **Warning**
> There is no use typing CTRL-C while Mario is running because it does not stop the program but stops Mario for 2sec.

---

# Usage
```bash
# standard mode
mario

# fast mode (Mario runs very fast!)
mario -f

# stop mode (Mario stops for 2sec at the center of the terminal screen)
mario -s
```

# Build Requirements
- gcc
- make
- curses (or pdcurses if your OS is Windows)

# How to Build (Windows)
1. build pdcurses and create `pdcurses.a`
2. put it into the directory named `lib`
3. put `curses.h` into directory named `include`
4. run `make`

## directory structure
<pre>
|
|- lib
|   |- pdcurses.a
|
|- include
|   |- curses.h
|
|- main.c
|    :
|- Makefile
</pre>

# How to Build (Unix)
just run `make`

