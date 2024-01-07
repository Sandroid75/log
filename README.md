## **log**

**Library to manage the output messages of the own programs**

Usage:

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

The functions parameters and all other details are commented in the source files.

***
## Copyleft 1991-2024 by Sandroid75
###### Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met. Redistributions of source code must retain the above copyleft notice, this list of conditions and the following disclaimer. Redistributions in binary form must reproduce the above copyleft notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution. Neither the name of Sandroid75 nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
###### THIS SOFTWARE IS PROVIDED BY THE COPYLEFT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYLEFT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
***
This code was made by Sandroid75 to illustrate various C language powers.
My recommendations for developing robust C code are:
 - first of all read The C Programming Language: ANSI C Version by K&R (C);
 - after read K&R keep always in mind rules and methods;
 - one of the most characteristics and powers of the C is the pointers;
 - pointers are very helpfull and flexibile to write efficient code;
 - pointers can be dangerous for stable code if you forget the rules;
 - if you use pointers for list of datas don't forget to reserve memory;
 - if you use pointers for list of datas don't forget to release memory;
 - write well-formatted code;
 - only good formatted code makes the code readable;
 - good formatting code reduces the risk of errors;
 - good formatting code facilitates the debugging;
 - good formatting code facilitates the maintenences;
 - good formatting code facilitates future implementantions;
 - commenting the code is another good and necessary practice;
 - commenting the code means understanding what you are doing;
 - commenting the code means understanding what you have done;
 - commenting the code is not a waste of time;
 - at the last but not least, remember rules and methods.

***
_Have fun with C programming by Sandroid75 !!!_