#Arcadia 0.0.6#

Hello there!
Have fun with my chess engine "Arcadia"!

Why is it called Arcadia? It's a port to C++ of my Java engine "Eden", which is a tribute to a program called PARADISE. For simplicity's sake I just googled for a synonym of "Eden".

##How to use it:##
Use a program like "Arena" (www.playwitharena.com) to play against it, or let other engines play against it, even have tournaments, or let it solve problem test suites (usually contained in ".epd" files.


You can freely use it.

This is version 0.0.6, released 2015-05-29.

##Features##
- supports the very basics of the UCI protocol (for chess engines)

- knows all rules of chess, including castling and en passant
- can sub-promote if necessary, i. e. take a knight instead of a queen on promotion
- knows about stalemate [does it, though? 0.0.6 seems to have problems]

##Some implementation notes##
* straightforward alpha-beta
* Iterative Deepening
* time control using UCI "go" command
* naive Quiescence Search using only captures
* Basic Shannon-type (one-dimensional array) 10 x 8 board

##Playing strength##
* Version 0.0.6 is a mild improvement over version 0.0.5.
* It is very weak, maybe around 1000 Elo on the usual chess engines Elo lists
* roughly the sightly stronger than Eden 0.0.8, definitely weaker than Eden 0.0.9

##Test suites I ran##
###WAC 300(Intel i7 3930k, 20 seconds per move)###
* 0.0.5: 92,
* 0.0.6: 97

##UCI protocol features##
* go, defaults to "infinite", but will use winc etc.
* stop
* only "id", "uciok", "readyok" and "bestmove" (without "ponder") is sent back

##Perft##
* embarrassingly slow "perft" command (e. g. "perft 7")
* "divide" command

##TODO LIST = Limitations/Known Bugs/Future Features (in no particular order)##
Seems to have problems with stalemate/mate detection
endgame evaluation
Get all the features of Eden 0.0.13 in.

##Probable focus for the next version##
* more raw speed
* find out why it is only minimally stronger than 0.0.5, despite the massive nps increase
* whatever else it takes to beat this version!

If you test this, please let me know your results.
I love feedback (criticism, questions, tournament reports, games played by Eden, ...)! 
*myfirstname*.*mylastname*@gmail.com, replace *myfirstname* and *mylastname* by, well, ...)
* Google Plus
* Twitter
* GitHub
* BitBucket
 

#Changes from 0.0.5->0.0.6#
* switched from fully legal to pseudo-legal
* various "comfort" features such as displaying nodes and nps properly
* migrated more parts of Eden's evaluation function
* gave the move generator vector<Move> an initial size
* more optimizations and bugfixes

#Changes from 0.0.4->0.0.5#
* optimizations and bugfixes
* accepts commands asynchronously (yay, C++11!)

Nicolai Czempin

P. S. This chess engine is dedicated to Pavel and Janik.