/**
 * @file clog.h
 * @brief Логирование поведения системы
 *
 * Ключ компиляции CLOG — включить логирование
 */
#ifndef CLOG_H_LOADED
#define CLOG_H_LOADED

#include <stdio.h>

#define LIM_MAX_STR 200

#ifdef LOG_ON
#define LOG_C_VERSION (__STDC_VERSION__ == 201112L) ? "C11" : "C??"

// Доп. инфо — целое — в лог
#define Li(x)                       \
  do {                              \
    char message[LIM_MAX_STR] = {}; \
    sprintf(message, "%d", (x));    \
    Ls(message)                     \
  } while (0);

// Доп. инфо — строка — в лог
#define Ls(x)                                                             \
  fprintf(stderr, "%s [%s] %s:%d\t%s()\t\t%s\n", LOG_C_VERSION, __TIME__, \
          __FILE__, __LINE__, __FUNCTION__, (x));

#define LN Ls("") /**< Запись без дополнительных параметров */

#else  // ключ CLOG_ON выключен
#define Li(x)
#define Ls(x)
#define LN
#endif

#define D Ls /**< Описание функции в начале блока реализации */

#endif
