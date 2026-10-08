# Funciones comunes: muestran cada comando antes de ejecutarlo
paso() { printf '\n\033[1;36m# %s\033[0m\n' "$*"; }
run()  { printf '\033[1;32m$ %s\033[0m\n' "$*"; "$@"; }
runs() { printf '\033[1;32m$ %s\033[0m\n' "$1"; eval "$1"; }   # para tuberías
bg()   { printf '\033[1;32m$ %s &\033[0m\n' "$*"; }
