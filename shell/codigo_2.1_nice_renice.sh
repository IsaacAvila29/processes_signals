#!/usr/bin/env bash
# Código 2.1 - nice y renice (shell)
# Arranca un proceso con prioridad baja y luego se la cambia.
cd "$(dirname "$0")" && . ./comun.sh

paso "Arranca sleep con nice: su valor NI sera 10"
bg nice sleep 300
nice sleep 300 &
PID=$!
sleep 0.3

paso "La columna NI muestra el valor nice (PID $PID)"
run ps -o pid,ppid,ni,stat,cmd -p "$PID"

paso "renice cambia la prioridad de un proceso que ya corre"
run renice 15 -p "$PID"
run ps -o pid,ppid,ni,stat,cmd -p "$PID"

paso "Limpieza"
run kill "$PID"
