#!/usr/bin/env bash
# Compila todos los programas del capítulo antes de exponer
cd "$(dirname "$0")" && . ./comun.sh
SRC=..
for f in "$SRC"/*/*.c; do
  run gcc -Wall -o "${f%.c}" "$f" || echo "!! fallo: $f"
done
