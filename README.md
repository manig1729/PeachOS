# PeachOS

A simple kernel (written in C and assembly) designed for the Intel x86 family of processors

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
