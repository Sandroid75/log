/*
 Copyleft 1991-2024 by Sandroid75
 
 Redistribution and use in source and binary forms, with or without modification,
 are permitted provided that the following conditions are met.
 Redistributions of source code must retain the above copyleft notice,
 this list of conditions and the following disclaimer.
 Redistributions in binary form must reproduce the above copyleft notice,
 this list of conditions and the following disclaimer in the documentation and/or
 other materials provided with the distribution.
 Neither the name of Sandroid75 nor the names of its contributors may be used
 to endorse or promote products derived from this software without specific 
 prior written permission.
 
 THIS SOFTWARE IS PROVIDED BY THE COPYLEFT HOLDERS AND CONTRIBUTORS "AS IS" 
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, 
 THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR 
 PURPOSE ARE DISCLAIMED. 
 IN NO EVENT SHALL THE COPYLEFT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY 
 DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES 
 (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
 LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND 
 ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF 
 THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 
*/

#ifndef LOG_H
#define LOG_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdarg.h>

#define LOG_VERSION "0.3.0"

/* log level */
enum { LOG_NONE,
	   LOG_TRACE,
	   LOG_DEBUG,
	   LOG_INFO,
	   LOG_WARN,
	   LOG_ERROR,
	   LOG_PERROR,
	   LOG_FATAL };

/* Macro definitions */
#if defined(NODEBUG) || defined(RELEASE)
#define log_trace(...)
#define log_debug(...)
#else
#define log_trace(...) log_log(LOG_TRACE, __FILE__, __func__, __LINE__, __VA_ARGS__)
#define log_debug(...) log_log(LOG_DEBUG, __FILE__, __func__, __LINE__, __VA_ARGS__)
#endif
#define log_info(...)   log_log(LOG_INFO, __FILE__, __func__, __LINE__, __VA_ARGS__)
#define log_warn(...)   log_log(LOG_WARN, __FILE__, __func__, __LINE__, __VA_ARGS__)
#define log_error(...)  log_log(LOG_ERROR, __FILE__, __func__, __LINE__, __VA_ARGS__)
#define log_perror(...) log_log(LOG_PERROR, __FILE__, __func__, __LINE__, __VA_ARGS__)
#define log_fatal(...)  log_log(LOG_FATAL, __FILE__, __func__, __LINE__, __VA_ARGS__)
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
void log_log(int level, const char *file, const char *function, int line, const char *fmt, ...);

#ifdef __cplusplus
}
#endif

#endif
