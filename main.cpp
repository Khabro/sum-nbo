#include "read_num.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr,"Erorr", argv[0]);
        return EXIT_FAILURE;
    }
    
    uint32_t total_sum = 0;
    
    for (int i = 1; i < argc; i++) {
	int success;
        uint32_t num = read_num(argv[i], &success);
	if(!success){
		return EXIT_FAILURE;
	}
        if (i > 1) {
		printf("+ ");
	}
        printf("%u(0x%04x) ", num, num);
        total_sum += num;
    }
    
    printf("= %u(0x%04x)\n", total_sum, total_sum);
    
    return EXIT_SUCCESS;
}

