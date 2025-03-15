#include "read_num.h"
#include <cstdio>
#include <cstdlib>
#include <arpa/inet.h> 

uint32_t read_num(const char *filename, int *success) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: %s\n", filename);
        *success = 0;
	return 0;
    }
    
    uint32_t num;
    if (fread(&num, sizeof(uint32_t), 1, file) != 1) {
        fprintf(stderr, "Error: %s\n", filename);
        fclose(file);
	*success = 0;
        return 0;
    }
    
    fclose(file);
    *success = 1;
    return ntohl(num); 
}

