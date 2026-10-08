#!/usr/bin/env bash
# Demo de la diapositiva 38: enviar SIGINT desde OTRA terminal.
# Uso: en la terminal A ejecuta ./ctrlc1 (o ./ctrlc2); en la terminal B:
#        ./enviar_sigint.sh            -> busca ctrlc1
#        ./enviar_sigint.sh ctrlc2     -> busca ctrlc2
cd "$(dirname "$0")" && . ./comun.sh
NOMBRE="${1:-ctrlc1}"
PID="$(pgrep -n -x "$NOMBRE")" || { echo "No hay ningun proceso llamado $NOMBRE"; exit 1; }

paso "Equivale a presionar Ctrl+C en la terminal de $NOMBRE (PID $PID)"
run kill -INT "$PID"
