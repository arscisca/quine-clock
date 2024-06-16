# Quine-clock
A C-[Quine](https://en.wikipedia.org/wiki/Quine_(computing)) that prints the current time on itself.


## Demo
https://github.com/arscisca/quine-clock/assets/39992784/97c57a09-efe8-4710-9f81-90735d139e7e


## Usage
Compile and run the program:

    $ make
    $ ./quine-clock
You can then copy-paste the output into a new file and check that there is no `diff` from `main.c`, implying you can
compile and run the copied file and obtain the same result.

An ANSI-compatible terminal is required.

> ⚠️ The usage of [ANSI escape codes](https://en.wikipedia.org/wiki/ANSI_escape_code) prevents a basic output
redirection since, if not filtered away, they will pollute the output file.

Note that there is some trickery happening which may cause issues on certain systems. For instance, it is assumed that
`time_t` is implemented with an integer, which albeit being the most common implementation, is not a requirement of
the C standard.

## Code
The code is unreadable because it has to be minified and formatted into a rectangular shape. The idea is:
1. The source code contains a string `i` that contains a copy of the source code itself.
2. A `@` character inside `i` breaks the recursion when `i` reaches the point where it should contain itself.
3. The program scans `i` character by character.
   * If the character isn't an `@`, print it.
   * Otherwise, we reached the point where `i` should contain itself: print its characters start to end while escaping
     newlines quotes and backslashes.

Printing the time:
1. Get the current time and store the hours, minutes and seconds in `h`, `m`, `s`.
2. An array `d` contains the digits of the clock.
3. An array `f` contains a *font-encoding* of digits 0-9 and the separator, taken from
[Martin Kleppe's JS implementation](https://aem1k.com/qlock/).
4. When printing, keep track of the current `x` and `y`. Use them to determine which digit from `d` and which *pixel*
from `f` is being printed.
5. Print the character with the determined background color.


## Credit
This project was inspired by [Tsoding's implementation](https://www.youtube.com/watch?v=plFwBqBYpcY).
