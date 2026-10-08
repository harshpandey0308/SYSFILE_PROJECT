#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdint.h>

typedef enum Content_type{
    BINARY = 0,                          // 0 represents that the file is binary file
    TEXT = 1                             // 1 indicates that file is text file / regular file
}Content_type;

typedef enum CTL_status{
    //============== API ERRORS================
     C_EIA ,                              // CTL_ERRORINVALIDARGUMENT - Given argument is invalid
     C_ENA ,                              // CTL_ERRORNULLARGUMENT- Required pointer is NULL
     C_EIMODE ,                           // CTL_ERRORINVALIDMODE - Unknown position mode
     C_ECOMB ,                            // CTL_ERRORCOMBINATION - Option conflict with each other 
     C_EIOFF ,                            // CTL_ERRORINVALIDOFFSET - Offset is invalid
     C_EIL ,                              // CTL_ERRORINVALIDLENGTH - Given length is invalid
     C_EIRANGE ,                          // CTL_ERRORINVALIDRANGE - Given range is invalid

    //================FILE ERRORS ====================

    C_EFNE ,                              // CTL_ERRORFILENOTEXIST - File/Path does not exist
    C_ENF  ,                              // CTL_ERRORNOTFILE - Path/File exist but it's not a regular file
    C_EPERM  ,                            // CTL_ERRORPERMISSIONDENIED - Insufficient Permission
    C_EFOPEN  ,                           // CTL_ERRORFILEOPEN - File could not be opened
    C_ESTAT,                              // CTL_ERRORSTAT - Metadata cannot be available

    //================ RUNTIME/RESOURCE ERROR =============

    C_EMEM ,                              // CTL_ERRORMEMORY - Memory allocation failed
    C_EIO  ,                              // CTL_ERRORIO - General I/O failure
    C_ERD  ,                              // CTL_ERRORREAD - Underlying read operation failed
    C_EOVERFLOW ,                         // CTL_ERROROVERFLOW - Size/offset calculation would overflow
    C_EINT                                // CTL_ERRORINTERNAL - Unexpected Internal library failure
    
}STATUS;

typedef struct Read_Result{
    void *buffer;                        // for storing read data 
    size_t length;                       // length of read data
    Content_type type;                   // whether read data is binary or normal text
}Read_Result;

typedef enum pos_mode{
    START = 1,                           // Start reading from beginning
    OFFSET = 2,                          // Start from any given offset
    END = 3                              // start from end
}pos_mode;

typedef struct Read_Options{
    pos_mode Position;
    off_t offset;
    size_t length;
}Read_Options;


ssize_t CTL_read(const char *path , const Read_Options *options , Read_Result *result);


