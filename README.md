# PeachOS

A bootloader and kernel (written in C and assembly) designed for the intel x86 family of processors

I am maintaining this repository as I follow Daniel McCarthy's Udemy Course - "Developing a Multithreaded Kernel From Scratch!"

## Instructions for running on the qemu simulator

First go to the PeachOS directory and run the following

```
make clean
./build.sh
```

Then go to the bin directory to check the simulation
```
cd bin
qemu-system-x86_64 -hda ./os.bin
```
## Instructions for debugging

After building the project 
```
cd bin
gdb
```
And in gdb, attach the kernelfull.o symbol file and start debugging
```
add-symbol-file ../build/kernelfull.o 0x100000
```
```y``` for yes
```
target remote | qemu-system-i386 -hda ./os.bin -S -gdb stdio
```
Add break point if any  
```c``` to continue, ```next``` for stepping instructions, ```print <var>``` for printing variables
