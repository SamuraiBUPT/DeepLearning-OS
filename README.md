# DeepLearning-OS

Hello, here is the code structure description.

We use `Makefile` to compile and link `.o` files.

To compile again, normally I will `make clean` first, and `make mykernel.iso` to compile the project again.

# Project Quick-View

We are now building an Operating System, now it's at starting stage because we haven't accomplish the **Interrupt**, and we are working on it.

`loader.s`, `Makefile`, `linker.ld` are used to connect.

## Interrupt
`interrupts.h`, `interrupts.cpp`, `interruptstubs.s` are now the files we are working on.

