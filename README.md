A small graphical program that closes any program on the GNU Linux system, by writing the name of the program, and it can also be used through the terminal.

First, make sure that the installed distribution on your device contains the GTK version 2.24, or 3, or 4 libraries.

Second, go to the source folder and type the following commands:

```
gcc -c dialog.c `pkg-config --libs --cflags gtk+-3.0`

gcc -shared dialog.o -o libpkillx.so `pkg-config --libs --cflags gtk+-3.0`

sudo cp -av libpkillx.so /usr/lib/

gcc pkillx.c /usr/lib/libpkillx.so -o pkillx `pkg-config --libs --cflags gtk+-3.0`

```

![](https://i39.servimg.com/u/f39/19/27/76/07/110.png)

Example: We want to close one program, or several programs at the same time

![](https://i39.servimg.com/u/f39/19/27/76/07/210.png)

![](https://i39.servimg.com/u/f39/19/27/76/07/310.png)

Or from terminal example:

```
pkillx java firefox virtualbox
```

You can choose the number of programs that you want to kill at the same time, it does not have to be one program.

[releases](https://github.com/mrx01x/PkillX/releases)
