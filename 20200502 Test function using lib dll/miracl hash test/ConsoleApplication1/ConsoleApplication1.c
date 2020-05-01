#include <stdio.h>
#include "miracl.h"

char test[] = "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq";

int main()
{
    char hash[20];
    int i;
    sha sh;
    shs_init(&sh);
    for (i = 0; test[i] != 0; i++) shs_process(&sh, test[i]);
    shs_hash(&sh, hash);
    for (i = 0; i < 20; i++) printf("%02x", (unsigned char)hash[i]);
    printf("\n");
    return 0;
}



