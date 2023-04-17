#include <sys/syscall.h>
#include <stdlib.h>

#define ERROR  (-1)
#define STDOUT  1



ssize_t my_write(int fileDescriptor, const void* buffer, size_t countOfBytes) {
    
    register int rdi          asm("rdi") = STDOUT;
    register char *rsi        asm("rsi") = "Hello, world!\n";
    register int rax          asm("rax") = SYS_write;
    register int rdx          asm("rdx") = STRING_SIZE;

    asm("syscall");                                                        
    
    register ssize_t ret_value   asm("rax");
    
    return ret_value;
}

int main() {

    size_t length = 14;
    char* message = "Hello, world!\n";

    ssize_t ret = my_write(STDOUT, message, length);
    
    return (ret == ERROR) ? EXIT_FAILURE : EXIT_SUCCESS;

}
