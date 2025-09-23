#ifndef LIBTSLOG_H
#define LIBTSLOG_H

#include <stdio.h>

/* Inicializa a biblioteca de log.
 * path: caminho do arquivo de log (ex.: "app.log").
 * Retorna 0 se ok, -1 se erro. */
int tslog_init(const char *path);

/* Encerra a biblioteca e fecha arquivo. */
void tslog_close(void);

/* Escreve uma mensagem de log com timestamp.
 * level: ex.: "INFO", "WARN", "ERROR". */
void tslog_write(const char *level, const char *fmt, ...);

#endif