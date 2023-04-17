#include <sys/syscall.h>
#include <stdlib.h>

#define STRING_SIZE 14
#define ERROR  (-1)
#define STDOUT  1

int main() {

    register int rdi          asm("rdi") = STDOUT;
    register char *rsi        asm("rsi") = "Hello, world!\n";
    register int rax          asm("rax") = SYS_write;
    register int rdx          asm("rdx") = STRING_SIZE;

    asm("syscall");                                                        
    
    register ssize_t ret_value   asm("rax");

    return (ret_value == ERROR) ? EXIT_FAILURE : EXIT_SUCCESS;

}
