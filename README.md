# cub3d

Bouw image genaamd ubuntu-cub3d op basis van Dockerfile:
```bash
docker build -t ubuntu-cub3d-valgrind .
```

Draai container op basis van image genaamd  ubuntu-cub3d met mounted eigen folder:
```bash
docker run --cap-add=SYS_PTRACE --security-opt seccomp=unconfined -it --rm --init -v "$PWD:/pwd"  ubuntu-cub3d-valgrind sh -c "cd /pwd; bash"
```
--cap-add=SYS_PTRACE --security-opt seccomp=unconfined = nodig om lldb te kunnen runnen in container
-i = interactive so bash doesn’t immediately quit because there is no input\
-t = bash shows prompt\
--rm = delete container on exit to not waste space\
-v = mounts specific folder from host to Docker container\
--init = shiieet snap het nut niet, maar Noah gebruikt het\
-c = CPU shares (relative weight) ???\
sh = ?