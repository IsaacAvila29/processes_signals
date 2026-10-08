#!/usr/bin/env bash
# Demo de las diapositivas 8 y 10: ver la tabla de procesos con ps
cd "$(dirname "$0")" && . ./comun.sh

paso "Todos los procesos, formato completo: UID, PID, PPID, CMD"
runs "ps -ef | head -15"

paso "Formato BSD: la columna STAT muestra el estado de cada proceso"
runs "ps aux | head -12"

paso "Este mismo shell visto desde /proc"
runs "head -8 /proc/$$/status"
