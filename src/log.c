/*
 Copyleft 1991-2024 by Sandroid75

 Plese read log.h
*/

#ifdef __linux__
#define _GNU_SOURCE 1 // strerror_r()
#else
#undef _GNU_SOURCE
#endif

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>

#include "log.h"

/* Struct declaration */
static struct {
    char *filelog;
    FILE *fp;
    int level;
    int filelevel;
} L = {NULL, NULL, LOG_NONE, LOG_NONE};

/* Level string array */
static const char *level_names[] = {
    "NONE",
    "TRACE",
    "DEBUG",
    "INFO",
    "WARN",
    "ERROR",
    "PERR",
    "FATAL"};

/* Escape color sequences for ANSI screen */
#ifdef LOG_USE_COLOR
static const char *level_colors[] = {
    "\x1b[30m",
    "\x1b[94m",
    "\x1b[36m",
    "\x1b[32m",
    "\x1b[33m",
    "\x1b[31m",
    "\x1b[34m",
    "\x1b[35m"};
#endif

/* Function to set the log file of NULL to set a standard stream */
void log_set_filelog(char *filelog)
{
    L.filelog = filelog;
}

/* Function to set standard stream (filelog must be NULL), can be stdout or stderr */
void log_set_fp(FILE *fp)
{
    L.fp = fp;
}

/* Set the log level, can be LOG_NONE, LOG_TRACE, LOG_DEBUG, LOG_INFO, LOG_WARN, LOG_ERROR, LOG_PERROR, LOG_FATAL */
void log_set_level(int level)
{
    L.level = level;
}

/* Set the log file level, can be LOG_NONE, LOG_TRACE, LOG_DEBUG, LOG_INFO, LOG_WARN, LOG_ERROR, LOG_PERROR, LOG_FATAL */
void log_set_file_level(int level)
{
    L.filelevel = level;
}

/* Main log function */
void log_log(int level, const char *file, const char *function, int line, const char *fmt, ...)
{
    char err_msg[1024];

    /* Check if perror must be print */
    if (level == LOG_PERROR) {
        strerror_r(errno, err_msg, sizeof(err_msg));
    }

    /* Get current time */
    time_t t      = time(NULL);
    struct tm *lt = localtime(&t);

    /* Log to stderr */
    if (L.level != LOG_NONE && level >= L.level) {
        va_list args;
        char buf[16];

        /* Build the time stamp string */
        buf[strftime(buf, sizeof(buf), "%H:%M:%S", lt)] = '\0';

#ifdef LOG_USE_COLOR
        fprintf(stderr, "%s %s%-5s\x1b[0m \x1b[90m%s:%d:\x1b[0m ", buf, level_colors[level], level_names[level], file, line);
#else
        fprintf(stderr, "%s %-5s %s@%d: ", buf, level_names[level], file, line);
#endif
        va_start(args, fmt);
        vfprintf(stderr, fmt, args);
        va_end(args);

        if (level == LOG_PERROR) {
            fprintf(stderr, ": %s", err_msg);
        }
        fprintf(stderr, "\n");
        fflush(stderr);
    }

    /* Log to file */
    if (L.filelevel != LOG_NONE && level >= L.filelevel) {
        /* Open the file pointer or set the stream */
        if (L.filelog) { // check if filelog is set
            L.fp = fopen(L.filelog, "a+");
            if (L.fp == NULL) { // if fopen() fail
                fprintf(stderr, "Unable to open '%s' the log will print on stderr\n", L.filelog);
                L.fp = stderr;
            }
        } else if (L.fp && L.fp != stdout && L.fp != stderr) { // if file pointer is not standard output
            L.fp = stderr;                                     // than set it to stderr
        } else if (L.fp == NULL) {
            return;
        }

        va_list args;
        char buf[32];

        /* Build the time stamp string */
        buf[strftime(buf, sizeof(buf), "%Y%m%d %H:%M:%S", lt)] = '\0';

        fprintf(L.fp, "%s %-5s %s:%s(%d): ", buf, level_names[level], file, function, line);
        va_start(args, fmt);
        vfprintf(L.fp, fmt, args);
        va_end(args);

        /* Check if perror must be print */
        if (level == LOG_PERROR) {
            fprintf(L.fp, ": %s", err_msg);
        }
        fprintf(L.fp, "\n");
        fflush(L.fp);
        /* close the file */
        if (L.fp != stdout && L.fp != stderr) {
            fclose(L.fp);
        }
    }

    return;
}
