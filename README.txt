Matthew Groholski's CSE240 Honors Project 13 for CSE240

Within the singleThread folder, there is a program that sorts through texts and stores each of word into a map data structure,
while also counting the total words. This version is ran on a single thread.

Within the muliThread folder, there is a program that divides a text into four sections and stores each word into a 
map while counting total words. 

Within text folder, there is various texts that you are able to use with the programs. Each text is of different lengths, and can be used
to test the programs run times and optimizations. greatGatsby.txt will provide the most comprehensive test of the program, since it is
2308 lines.



IMPORTANT NOTE: Each of the files was compiled using clang++ -std=c++11 FILENAME.cpp (where filename is replaced).

NOTE: The singleThread file will support any of the texts files, with accurate word counts. 
However, the multiThread file will only support the.txt with a somewhat accurate count.
The multiThread file is buggy, but since it is in a preliminary phase works well. I plan 
on adding/fixing the following features: 

Both single thread and multi-thread:
- Create own string header file.
- Create own map header file (If data structure is not changed).
- Consider different data types (Find an optimal strcuture).
- Make a stricter definition of what consitutes a word
- Determine and fix why files will not compile without different c++ version.
- Implement statistics feature
- Create a makefile (could potentially help if no work around for note is found)

Multi-thread: 
- Formulate dynamic approach to finding file splits
- Tidy up code

Single Thread:
- Tidy up code
