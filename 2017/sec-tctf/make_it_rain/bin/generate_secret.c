#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv) {
    srand(atoi(argv[1]));
    char secret[0x30d40];
    int i;
    for(i = 0; i < 0x30d40; i++) {
//    d3f:	89 c2                	mov    edx,eax
//    d41:	89 d0                	mov    eax,edx
//    d43:	c1 f8 1f             	sar    eax,0x1f
//    d46:	c1 e8 18             	shr    eax,0x18
//    d49:	01 c2                	add    edx,eax
//    d4b:	0f b6 d2             	movzx  edx,dl
//    d4e:	29 c2                	sub    edx,eax
//    d50:	89 d0                	mov    eax,edx
//    d52:	88 03                	mov    BYTE PTR [rbx],al
        int random_num_0 = rand();
        int random_num_1 = random_num_0;
        random_num_0 >>= 0x1f;
        random_num_0 >>= 0x18;
        random_num_1 += random_num_0;
        random_num_1 &= 0xff;
        random_num_1 -= random_num_0;
        random_num_0 = random_num_1;
        random_num_0 &= 0xff;
        secret[i] = (char)random_num_0;
    }
    secret[i] = 0;
    write(1, secret, 0x30d40);
    fflush(stdin);
}
