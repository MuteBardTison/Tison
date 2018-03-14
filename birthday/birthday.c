void main() {
    __asm__ (
        "movl $1, %eax;\n"
        "movl $1, %ebx;\n"
        "movl $message, %esi;\n"
        "movl $26, %edx;\n"
        "syscall;\n"
        "movl $60,%eax;\n"
        "xorl %ebx,%ebx; \n"
        "syscall;\n"
        "message: .ascii \"Happy Birthday to Myself!\\n\";"
    );
}
