## **log**

**Library to manage the output messages of the own programs**

How to use:

First of all include "**log.h**" header than if you want to see colored messages on the screen define **LOG_USE_COLOR** macro to enable Escape sequence colors on ANSI screen.
Now is time to set up the log enviroment with following functions:

 - log_set_level(); *Used to set the minimum level of log to shown on the screen. See log.h for levels*
 - log_set_filelog(); *If no NULL set the file log name*
 - log_set_fp(); *If filelog is NULL, set the stream: stdout or stderr*
 - log_set_file_level(); *Used to set the minimum level of log to write in the stream file. See log.h for levels*

After setup the enviroment you can use the macros to print the messages
| mnemonic | extended | description
| -- | -- | -- |
| LOGT(); | log_trace(); | *print trace level message* |
| LOGD(); | log_debug(); | *print debug level message* |
| LOGI(); | log_info(); | *print info level message* |
| LOGW(); | log_warn(); | *print warning level message* |
| LOGE(); | log_error(); | *print error level message* |
| LOGP(); | log_perror(); | *print perror level message* |
| LOGF(); | log_fatal(); | *print fatal level message* |

The function parameters and all other details are commented in the source files.
