# Índice de códigos

Numeración de los programas del capítulo 11 ("Procesos y Señales") de
_Beginning Linux Programming_, 4.ª ed., tal como aparecen en la presentación.
Formato: "Código <sección>.<n>" (2 = Estructura de un proceso,
3 = Inicio de nuevos procesos, 4 = Señales).

| Código | Archivo | Sección | Descripción |
|--------|---------|---------|-------------|
| 2.1 | `shell/codigo_2.1_nice_renice.sh` | 2. Estructura de un proceso | Comandos de shell `nice` y `renice` para cambiar la prioridad de un proceso |
| 3.1 | `01_system/system1.c` | 3. Inicio de nuevos procesos | Ejecuta `ps ax` con `system()` y espera a que termine |
| 3.2 | `02_exec/exec_ejemplos.c` | 3. Inicio de nuevos procesos | Las seis variantes de la familia `exec` para lanzar `ps` |
| 3.3 | `02_exec/pexec.c` | 3. Inicio de nuevos procesos | Reemplaza el proceso actual por `ps ax` con `execlp()` |
| 3.4 | `03_fork/fork1.c` | 3. Inicio de nuevos procesos | Duplica el proceso con `fork()`: padre e hijo corren a la vez |
| 3.5 | `04_wait/wait.c` | 3. Inicio de nuevos procesos | El padre espera al hijo con `wait()` y lee su código de salida |
| 3.6 | `05_zombies/fork2.c` | 3. Inicio de nuevos procesos | El hijo termina primero y queda como zombie porque el padre no llama a `wait()` |
| 3.7 | solo en la presentación | 3. Inicio de nuevos procesos | `waitpid()` con `WNOHANG` para revisar a un hijo sin bloquearse (fragmento) |
| 3.8 | `06_redireccion/upper.c` | 3. Inicio de nuevos procesos | Filtro que convierte la entrada estándar a mayúsculas |
| 3.9 | `06_redireccion/useupper.c` | 3. Inicio de nuevos procesos | Redirige stdin a un archivo y ejecuta `upper` con `execl()` |
| 4.1 | `shell/codigo_4.1_kill_killall.sh` | 4. Señales | Comandos de shell `kill` y `killall` |
| 4.2 | solo en la presentación | 4. Señales | Prototipo de `signal()` |
| 4.3 | `07_signal/ctrlc1.c` | 4. Señales | Captura Ctrl+C (`SIGINT`) con `signal()` y restaura la acción por defecto |
| 4.4 | solo en la presentación | 4. Señales | Prototipo de `kill()` |
| 4.5 | solo en la presentación | 4. Señales | `kill()` con manejo de errores (fragmento) |
| 4.6 | solo en la presentación | 4. Señales | Prototipos de `alarm()` y `pause()` |
| 4.7 | `08_enviar_senales/alarm.c` | 4. Señales | alarm.c, parte 1: manejador `ding()` que pone una bandera |
| 4.8 | `08_enviar_senales/alarm.c` | 4. Señales | alarm.c, parte 2: `main()`; el hijo envía `SIGALRM` al padre, que espera con `pause()` |
| 4.9 | solo en la presentación | 4. Señales | `sigaction()` y su estructura `struct sigaction` |
| 4.10 | `09_sigaction/ctrlc2.c` | 4. Señales | Captura Ctrl+C con `sigaction()`; el manejador no se reinicia |
| 4.11 | solo en la presentación | 4. Señales | Funciones de conjuntos de señales (`sigemptyset`, `sigaddset`, …) |
| 4.12 | solo en la presentación | 4. Señales | Prototipos de `sigprocmask`, `sigpending` y `sigsuspend` |
| 4.13 | no está en el repositorio | 4. Señales | bloqueo.c: bloqueo de señales (ejemplo propio, no viene en el libro) |

## Demos de shell

Scripts de apoyo en `shell/` (bash, Linux). Cada uno muestra el comando antes de ejecutarlo.

| Script | Diapositiva | Descripción |
|--------|-------------|-------------|
| `shell/demo_ps.sh` | 8 y 10 | Tabla de procesos con `ps -ef`, `ps aux` y `/proc/<pid>/status` |
| `shell/demo_zombi.sh` | 24 (Código 3.6) | Ejecuta `fork2` y muestra al hijo zombi (`Z`, `<defunct>`) con `ps -el` |
| `shell/demo_redireccion.sh` | 26 (Códigos 3.8 y 3.9) | Redirige stdin de `upper` desde el shell y desde C con `useupper` |
| `shell/enviar_sigint.sh` | 38 | Envía `SIGINT` a `ctrlc1` o `ctrlc2` desde otra terminal |
| `shell/compilar.sh` | — | Compila todos los `.c` del capítulo con `gcc -Wall` |
| `shell/comun.sh` | — | Funciones comunes (`paso`, `run`, `runs`, `bg`); lo cargan los demás scripts |

## Sin numerar

Archivos fuente del repositorio que no aparecen en la presentación:

| Archivo | Descripción |
|---------|-------------|
| `01_system/system2.c` | Igual que system1.c, pero lanza `ps` en segundo plano (`&`), así que `system()` regresa de inmediato |
| `03_fork/fork_fragmento.c` | Estructura típica de un `switch` después de `fork()` (-1 error, 0 hijo, PID en el padre) |
