/*
 * Copyleft (f) 2024 Sandroid75
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the MIT license. See `log.c` for details.
 *
 */

#ifndef LOG_H
#define LOG_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>

#define LOG_VERSION "0.3.0"

/* log level */
enum { LOG_NONE, LOG_TRACE, LOG_DEBUG, LOG_INFO, LOG_WARN, LOG_ERROR, LOG_FATAL };

/* Macro definitions */
#if defined(NODEBUG) || defined(RELEASE)
#define log_trace(...) 
#define log_debug(...) 
#else
#define log_trace(...) log_log(LOG_TRACE, 0, __FILE__, __func__, __LINE__, __VA_ARGS__)
#define log_debug(...) log_log(LOG_DEBUG, 0, __FILE__, __func__, __LINE__, __VA_ARGS__)
#endif
#define log_info(...)  log_log(LOG_INFO,  0, __FILE__, __func__, __LINE__, __VA_ARGS__)
#define log_warn(...)  log_log(LOG_WARN,  0, __FILE__, __func__, __LINE__, __VA_ARGS__)
#define log_error(...) log_log(LOG_ERROR, 0, __FILE__, __func__, __LINE__, __VA_ARGS__)
#define log_perror(...) log_log(LOG_ERROR, 1, __FILE__, __func__, __LINE__, __VA_ARGS__)
#define log_fatal(...) log_log(LOG_FATAL, 0, __FILE__, __func__, __LINE__, __VA_ARGS__)
/* Macro mnemonic definitions */
#define LOGT log_trace
#define LOGD log_debug
#define LOGI log_info
#define LOGW log_warn
#define LOGE log_error
#define LOGP log_perror
#define LOGF log_fatal

/* Function prototipes */
void log_set_filelog(char *filelog);
void log_set_fp(FILE *fp);
void log_set_level(int level);
void log_set_file_level(int level);
void log_log(int level, const int do_perror, const char *file, const char *function, int line, const char *fmt, ...);

#ifdef __cplusplus
}
#endif

#endif
