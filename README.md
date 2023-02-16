# Cub3D Parser
The parser section for the Cub3D project.

## Installation
```bash
  git clone git@github.com:lightiverson/cub3d-parser.git
  cd cub3d-parser
  make
```
    
## Usage/Examples
```bash
./cub3d /maps/map.cub
```
or
```bash
./open_all_maps.sh
```

## Running Docker container
Bouw image genaamd ubuntu-cub3d op basis van Dockerfile:
```bash
docker build -t ubuntu-cub3d-sanitize .
```

Draai container op basis van image genaamd  ubuntu-cub3d met mounted eigen folder:
```bash
docker run --cap-add=SYS_PTRACE --security-opt seccomp=unconfined -it --rm --init -v "$PWD:/pwd"  ubuntu-cub3d-sanitize sh -c "cd /pwd; bash"
```
--cap-add=SYS_PTRACE --security-opt seccomp=unconfined = nodig om lldb te kunnen runnen in container
-i = interactive so bash doesn’t immediately quit because there is no input\
-t = bash shows prompt\
--rm = delete container on exit to not waste space\
-v = mounts specific folder from host to Docker container\
--init = shiieet snap het nut niet, maar Noah gebruikt het\
-c = CPU shares (relative weight) ???\
sh = ?
