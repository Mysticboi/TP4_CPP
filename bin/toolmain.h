#if ! defined ( toolmain_H )
#define toolmain_H
#include <iostream>
using namespace std;
#include <string.h>
#include "toolmain1.h"
void onlyLogFile(const char * logFileNamec);
void logFile_e(const char * logFileNamec);
void logFile_g(const char * logFileNamec, const char * fileNameDotc);
void logFile_t(const char * logFileNamec, const char * Heurec);
void logFile_t_e(const char * logFileNamec, const char * Heurec);
void logFile_g_t(const char * logFileNamec,const char * fileNameDotc,const char * Heurec);
void logFile_g_e(const char * logFileNamec, const char * fileNameDotc);
void logFile_g_t_e(const char * logFileNamec,const char * fileNameDotc,const char * Heurec);
#endif
