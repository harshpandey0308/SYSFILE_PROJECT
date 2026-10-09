#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdint.h>
#include<sys/types.h>

typedef enum Content_type{
    C_UNKNOWN = 0 ,                         // No valid content available right now
    C_BINARY = 1,                          // Read data is binary.
    C_TEXT = 2                             // Read data is normal text.
}Content_type;

typedef enum CTL_status{
    //============== SUCCESS =================

    C_SUCCESS ,                           // CTL_SUCCESS

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
    
}CTL_STATUS;

typedef struct Read_Result{
    void *buffer;                        // for storing read data 
    size_t length;                       // length of read data
    Content_type type;                   // whether read data is binary or normal text
}Read_Result;

typedef enum pos_mode{
    C_START = 1,                           // Start reading from beginning
    C_OFFSET = 2,                          // Start from any given offset
    C_END = 3                              // start from end
}pos_mode;

typedef struct Read_Options{
    pos_mode Position;
    off_t offset;
    size_t length;
}Read_Options;


CTL_STATUS CTL_read(const char *path , const Read_Options *options , Read_Result *result);

void CTL_FREE(void *ptr);

void CTL_RDR_CLEANUP(Read_Result *result);

