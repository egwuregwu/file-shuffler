# file-shuffler
Shuffles files in the binary's folder by adding 2 hex numbers and a space before file name.


For now, only works on Windows systems, using a helper file to write cmd command outputs to.
Don't recommend executing it several times, as it will lead to files having multiple prefixes, removing which is not yet implemented.

### Compiling
just compile the main code file with your compiler of choice, e.g.
```
gcc -o shuffler shuffler.c
```
