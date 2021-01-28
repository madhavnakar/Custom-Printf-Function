# Custom Printf function

This was one of the projects I worked on while attending 42 Coding School. The purpose of this project was to create a function that exactly mimicked C's printf function.
The only allowed function was the system call "write()". I used my own library of C functions (in the Custom-C-Library repo).

This project turned out to be more difficult than I thought when I signed up to do it. There are some nuances to the printf function that are difficult to incorporate 
and need bit manipulation. For example, prinf("%s", "hello") will print "hello" but printf("%.3s", "hello") will print "hel" . Incoporating such nuances (and other
details that would take some explanation) made the project challenging.

By completing this project I learned about how to manage all of the helper functions in a large project. Rules such as having no more than 42 lines in a C file forced
me to be more efficient and readable.
