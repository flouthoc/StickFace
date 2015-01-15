# StickFace
An Awesome DeskTop Sticky Widget which Follows you Everywhere .Written in C language.Built With Gtk For Gnome and Unity Environment.Well Tested Under Ubuntu

#Requirements
1. Linux
2. GCC
3. Gtk-Bundle

#Compiling The src.c
```shell
gcc src.c $(pkg-config --cflags --libs gtk+-3.0) -o sticky
```
#Features
1. StickFace's special feature is to follow you around your WorkSpace Until You Give it Command "Go To DeskTop"
![Go To DeskTop](https://www.anonimg.com/img/910bd31e0b3fd9e75cf5b8c9ce7eef65.png "Go To DeskTop")
2. Click on "Follow Me" Again Toggles StickFace To Follow You Around The Screen 
![Follow Me](https://www.anonimg.com/img/198aa7304b87c25d5318c55fcb145ae7.png "Follow Me")
3. Click on "Add New" Creates a New Stick Screen For Second Note
![New](https://www.anonimg.com/img/a604405c31d8b68c327b06633e6e498b.png "New Note")

#Usage
> 1. data_file_1.stick (is the Database File it is resonsible for holding databse for StickFace)
> 2. Run the Executable 

#Bugs and Errors
#####There are Lot Of Bugs in StickFace It is Not Stable For Use ,Help Me Fix Them
1. Every Time StickFace Loads Data From Datafile 4 Extra StickFace Comes into Runtime Stack
2. DataBase Update Module Not Ready
3. Glitches Not Fixed
4. Some Times Become Annoying ( UX problem)

