# Arcadia Chess Engine 0.0.9 (Historical Archive)

**⚠️ This is a historical/archived project. Active chess engine development has moved to [Zathras](https://github.com/nczempin/zathras).**

Have fun with my chess engine "Arcadia"!

Why is it called Arcadia? It's a port to C++ of my Java engine "Eden", which is a tribute to a program called PARADISE. For simplicity's sake I just googled for a synonym of "Eden".

## Build Instructions ##

```bash
# For Linux/macOS with g++
make

# For Windows, open arcadia.sln in Visual Studio
```

## How to use it ##
Use a UCI-compatible program like "Arena" (www.playwitharena.com) to play against it, or let other engines play against it, even have tournaments.
You can also let it solve problem test suites (usually contained in ".epd" files).

The binary will be created as `arcadia` (Linux/macOS) or `arcadia.exe` (Windows).

This is version 0.0.9, released 2015-06-06. You can freely use it.

## Features ##
- supports the very basics of the UCI protocol (for chess engines)
- knows all rules of chess, including castling and en passant
- can sub-promote if necessary, i. e. take a knight instead of a queen on promotion
- knows about stalemate

## Some implementation notes  ##
* straightforward alpha-beta
* Iterative Deepening
* naive Quiescence Search using only captures
* Basic Shannon-type (one-dimensional array) 10 x 9 board
* Pseudolegal move generation
* Copy/Make rather than make/unmake

## Playing strength ##
* Approximately 1100 Elo on standard chess engine rating lists
* Version 0.0.9 showed significant improvement over 0.0.8 in tournaments
* Roughly equivalent strength to Eden 0.0.9 (the Java predecessor)

## Engine Lineage ##
This is part of a chess engine evolution:
1. **Eden** (Java) - Original implementation
2. **Arcadia** (C++) - This project, port of Eden to C++
3. **Zathras** (Modern C++) - Current active development with advanced techniques

## Test suites I ran ##
### WAC 300 (Intel i7 3930k, 20 seconds per move) ###
* 0.0.5: 92
* 0.0.6: 97
* 0.0.7: 123
* 0.0.8: 102
* 0.0.9: 135 (130 @ 10 seconds, 153 @ 1 min, 164 @ 2 min)

## UCI protocol features ##
* go, defaults to "infinite", but will use wtime, winc, btime, binc, movestogo
* stop
* only "id", "uciok", "readyok" and "bestmove" (without "ponder") is sent back

## Perft ##
* embarrassingly slow "perft" command (e. g. "perft 7")
* "divide" command

## TODO LIST = Limitations/Known Bugs/Future Features (in no particular order) ##
* Speeding up pawn structure evaluation (by dynamic programming / a pawn structure hashtable)
* Get all the features of Eden 0.0.13 in.

## Probable focus for the next version ##
* more raw speed
* whatever else it takes to beat this version!

If you test this, please let me know your results.
I love feedback (criticism, questions, tournament reports, games played by Eden, ...)! 
*myfirstname*.*mylastname*@gmail.com, replace *myfirstname* and *mylastname* by, well, ...)

* Google Plus: https://plus.google.com/u/0/+NicolaiCzempin/posts
* Twitter: https://twitter.com/nczempin
* GitHub: https://github.com/nczempin
* BitBucket: https://bitbucket.org/nczempin
 
# Changes from 0.0.8->0.0.9 #
* basic endgame detection and evaluation

# Changes from 0.0.7->0.0.8 #
* Re-enabled quiescence search

# Changes from 0.0.6->0.0.7 #
* Fixed mate and stalemate detection bug
* Introduced some significant new bugs, probably with quiescence search
 
# Changes from 0.0.5->0.0.6 #
* switched from fully legal to pseudo-legal
* various "comfort" features such as displaying nodes and nps properly
* migrated more parts of Eden's evaluation function
* gave the move generator vector<Move> an initial size
* more optimizations and bugfixes

# Changes from 0.0.4->0.0.5 #
* optimizations and bugfixes
* accepts commands asynchronously (yay, C++11!)

Nicolai Czempin

P. S. This chess engine is dedicated to Pavel and Janik.
