#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdint.h>

typedef enum Content_type{
    BINARY = 0,
    TEXT = 1
}Content_type;

typedef struct Read_Result{
    void *buffer;
    size_t length;
    Content_type type;
}Read_Result;

typedef enum pos_mode{
    START = 1,
    OFFSET = 2,
    END = 3
}pos_mode;

typedef struct Read_Options{
    pos_mode Position;
    off_t offset;
    size_t length;
}Read_Options;


ssize_t CTL_read(const char *path , const Read_Options *options , Read_Result *result);


