# Quine-clock
A [Quine](https://en.wikipedia.org/wiki/Quine_(computing)) in C that live-overlays the current UTC time while printing its own source code.


## Demo
https://github.com/arscisca/quine-clock/assets/39992784/97c57a09-efe8-4710-9f81-90735d139e7e


## Usage
Compile and run the program:

    $ make
    $ ./quine-clock
You can then copy-paste the output into a new file and check that there is no `diff` from `main.c`, meaning you can also compile and run the copied file and observe the same result.

> ⚠️ The usage of [ANSI escape codes](https://en.wikipedia.org/wiki/ANSI_escape_code) prevents a basic output
redirection since, if not filtered away, they will pollute the output file.

Note that:
1. An ANSI-compatible terminal is required.
2. Time is displayed in UTC+0.
3. This is not guaranteed to work in all systems because of some tricks and assumptions used to simplify the code. For instance, it is assumed that `time_t` is an integer which, despite being the most common implementation, is not a requirement of the C standard.


## Code
The code has been made unreadable in order to minify it and shape it into a rectangle. The underlying idea is:
1. The string `i` that contains a copy of the entire source code.
2. An `@` character inside `i` breaks the recursion where `i` should contain its own string literal inside itself.
3. Iterate over the characters of `i`:
   * If the character isn't an `@`, print it.
   * If the character is an `@`, it's the moment to print the string literal of `i` inside itself. Do an inner iteration over `i` to print its characters while escaping newlines, backslashes and quotes.

Printing the time:
1. Get the current time and store the hours, minutes and seconds in `h`, `m`, `s`.
2. An array `d` contains the to-be-displayed digits of the clock.
3. An array `f` contains a font encoding (taken from [Martin Kleppe's JS implementation](https://aem1k.com/qlock/)) where `f[k]`'s bits represents a 3x5 matrix of the pixels of number `k`. `f[10]` represents the `:` separator. 
4. When printing, keep track of the current `x` and `y`. Use them to determine which digit from `d` is being printed, and take its pixel color from `f` at that position.
5. Print the character with the determined pixel color as the background using ANSI escape codes.


## Credit
This project was inspired by [Tsoding's stream](https://www.youtube.com/watch?v=plFwBqBYpcY), which prompted me to try my own implementation.
