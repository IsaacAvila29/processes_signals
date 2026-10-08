#!/usr/bin/env bash
# Demo de la diapositiva 24 (Código 3.6): un proceso zombi en la tabla
cd "$(dirname "$0")" && . ./comun.sh
BIN=../05_zombies

paso "fork2: el hijo termina a los 3 s, el padre sigue hasta los 5 s"
bg "$BIN/fork2"
"$BIN/fork2" > /dev/null &
PADRE=$!

paso "A los 4 s el hijo ya termino, pero el padre no ha llamado a wait"
run sleep 4
runs "ps -el | grep -E 'PID|fork2'"
echo "El renglon con S es el padre; el renglon con Z (<defunct>) es el hijo zombi."
wait "$PADRE"
