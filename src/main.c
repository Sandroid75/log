#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LOG_USE_COLOR   // show Escape colors on ANSI screen
#include "log.h"

int main ()
{
    char *filename = "message.log";
    
    log_set_level(LOG_TRACE);       // set the minimum level of log to shown on the screen. See log.h
    log_set_filelog(NULL);        // if no NULL set the file log name
    log_set_fp(stderr);             // if filelog is NULL, set the file log pointer, can be stdout, stderr, if not set or NULL stderr is default stream
    log_set_file_level(LOG_TRACE);  // set the minimum level of log to write in the stream. See log.h

    log_trace("trace");
    log_debug("debug");
    log_info("info");
    log_warn("warn");
    log_error("error");
    log_perror("perror");
    log_fatal("fatal");
    
    return EXIT_SUCCESS;
}