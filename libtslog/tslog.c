#include "libtslog.h"
#include <pthread.h>
#include <stdarg.h>
#include <time.h>
#include <stdlib.h>

static FILE *log_file = NULL;
static pthread_mutex_t log_mutex = PTHREAD_MUTEX_INITIALIZER;

int tslog_init(const char *path) {
    log_file = fopen(path, "a");
    if (!log_file) return -1;
    setvbuf(log_file, NULL, _IOLBF, 0); // flush a cada linha
    return 0;
}

void tslog_close(void) {
    if (log_file) {
        fclose(log_file);
        log_file = NULL;
    }
}

void tslog_write(const char *level, const char *fmt, ...) {
    if (!log_file) return;

    pthread_mutex_lock(&log_mutex);

    // timestamp
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    char buf[20];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", tm_info);

    fprintf(log_file, "[%s] [%s] ", buf, level);

    va_list args;
    va_start(args, fmt);
    vfprintf(log_file, fmt, args);
    va_end(args);

    fprintf(log_file, "\n");
    fflush(log_file);

    pthread_mutex_unlock(&log_mutex);
}
