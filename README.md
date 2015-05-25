#Arcadia 0.0.5#

Hello there!
Have fun with my chess engine "Arcadia"!

Why is it called Arcadia? It's a port to C++ of my Java engine "Eden", which is a tribute to a program called PARADISE. For simplicity's sake I just googled for a synonym of "Eden".

##How to use it:##
Use a program like "Arena" (www.playwitharena.com) to play against it, or let other engines play against it, even have tournaments, or let it solve problem test suites (usually contained in ".epd" files.


You can freely use it.

This is version 0.0.5, released 2015-05-25.

##Features##
- supports the very basics of the UCI protocol (for chess engines)

- knows all rules of chess, including castling and en passant
- can sub-promote if necessary, i. e. take a knight instead of a queen on promotion
- knows about stalemate

##Some implementation notes##
* straightforward alpha-beta
* Iterative Deepening
* Simple time control: When the time limit is reached (hardcoded 20 seconds for now), it returns the best-so-far move.
* naive Quiescence Search using only captures
* Basic Shannon-type (one-dimensional array) 10 x 8 board

##Playing strength##
* Version 0.0.5 is a significant improvement over version 0.0.4.
* It is very weak, maybe around 1000 Elo on the usual chess engines Elo lists
* roughly the same strength as Eden 0.0.8, definitely better than Eden 0.0.7

##Test suites I ran##
###WAC 300(Intel i7 3930k, 20 seconds per move)###
* 0.0.5: 92,

##UCI protocol features##
* go, will always stop after 20 seconds
* stop
* only "id", "uciok", "readyok" and "bestmove" (without "ponder") is sent back

##TODO LIST = Limitations/Known Bugs/Future Features (in no particular order)##
Get all the features of Eden 0.0.13 in.
###Known issues###
* UCI score gets reported as the minimum value whenever we switch to the next iteration depth
###Probable focus for the next version###
* more raw speed
* UCI protocol compliance: use the "go" time parameters properly
* UCI protocol compliance: show "nodes" and "nps"

* whatever else it takes to beat this version!

If you test this, please let me know your results.
I love feedback (criticism, questions, tournament reports, games played by Eden, ...)! 
*myfirstname*.*mylastname*@gmail.com, replace *myfirstname* and *mylastname* by, well, ...)
* Google Plus
* Twitter
* GitHub
* BitBucket
 

#Changes from 0.0.4->0.0.5#
* optimizations and bugfixes
* accepts commands asynchronously (yay, C++11!)

Nicolai Czempin

P. S. This chess engine is dedicated to Pavel and Janik.