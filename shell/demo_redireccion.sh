#!/usr/bin/env bash
# Demo de la diapositiva 26 (Códigos 3.8 y 3.9): redirigir la entrada estándar
cd "$(dirname "$0")" && . ./comun.sh
BIN=../06_redireccion

paso "Un archivo de prueba en minusculas"
runs "echo 'hola, esto es una prueba' > file.txt"
run cat file.txt

paso "El shell redirige la entrada de upper"
runs "$BIN/upper < file.txt"

paso "useupper hace lo mismo desde C, con freopen y execl"
( cd "$BIN" && run ./useupper "$OLDPWD/file.txt" )
