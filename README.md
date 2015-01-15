# StickFace
An awesome desktop sticky widget which follows you everywhere. Written in C and built with GTK for GNOME and Unity desktop environments. Well tested under Ubuntu.

# Requirements
1. Linux
2. GCC
3. Gtk-Bundle

# Install dependencies
## Ubuntu
```shell
sudo apt-get install gcc libgtk-3-dev
```

# Compiling from source
```shell
mkdir -p bin/; gcc src.c $(pkg-config --cflags --libs gtk+-3.0) -o bin/sticky
```
# Features
1. StickFace's special feature is to follow you around your workspace until you give it the command "Go To Desktop"

![Go To Desktop](https://www.anonimg.com/img/910bd31e0b3fd9e75cf5b8c9ce7eef65.png "Go to Desktop")

2. Click on "Follow Me" again toggles StickFace to follow you around the screen 

![Follow Me](https://www.anonimg.com/img/198aa7304b87c25d5318c55fcb145ae7.png "Follow Me")

3. Click on "Add New" creates a New Stick Screen for a second note

![New](https://www.anonimg.com/img/a604405c31d8b68c327b06633e6e498b.png "New Note")

# Usage
1. data_file_1.stick (is the database file and is responsible for holding the database for StickFace)
2. Run the executable: `bin/sticky`

# Contributing
I'll try to merge every pull request that I receive.

# Bugs and Errors
**There are a few bugs in StickFace. It is not stable for daily use yet. Help me fix them!**

1. Every time StickFace loads data from the data file, four extra StickFace interfaces comes into the run-time stack
2. Database update module not ready
3. Glitches not fixed
4. Some times it becomes annoying (UX problem)

