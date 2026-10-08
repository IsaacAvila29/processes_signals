#!/usr/bin/env bash
# Código 4.1 - kill y killall (shell)
# kill identifica al destino por PID; killall, por nombre del programa.
cd "$(dirname "$0")" && . ./comun.sh

paso "Un proceso de prueba en segundo plano"
bg sleep 300
sleep 300 &
PID=$!
run ps -o pid,stat,cmd -p "$PID"

paso "kill envia la senal que se le indique: aqui SIGHUP, por PID"
run kill -HUP "$PID"
wait "$PID" 2>/dev/null
echo "sleep termino con estado $? (128 + 1, el numero de SIGHUP)"

paso "Dos procesos con el mismo nombre"
bg "sleep 300 & sleep 300"
sleep 300 & A=$!
sleep 300 & B=$!
run ps -o pid,stat,cmd -p "$A,$B"

paso "killall los identifica por nombre; sin opciones manda SIGTERM"
run killall sleep
wait "$A" 2>/dev/null; echo "primer sleep: estado $? (128 + 15, SIGTERM)"
wait "$B" 2>/dev/null; echo "segundo sleep: estado $? (128 + 15, SIGTERM)"
