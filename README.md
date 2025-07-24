# file-shuffler
Shuffles files in the binary's folder by adding 2 hex numbers and a space before file name.  

for example:  
file  
\\/  
D3 file  
  
For now, only works on Windows systems, using a helper file to write cmd command outputs to.  
Don't recommend executing it several times, as it will lead to files having multiple prefixes, removing which is not yet implemented.

## Compiling
just compile the main code file with your compiler of choice, e.g.
```
gcc -o shuffler shuffler.c
```

### TODO
!!! Removing prefixes  
! Customizible prefix length  
? custom prefix style (make it more distinct)  
