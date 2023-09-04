
.text
.global entry

entry:
  movl $666, %edx
  movl $1, %eax
  movl $0, %ebx
  int $0x80
