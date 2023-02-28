clang -O3 -shared pwvf.c -I./ -o PWVF.so
curl https://github.com/PicsumProjects/wclibc/releases/download/latest/wclibc-wasm32.wasm -o libc.wasm
clang -O3 -shared --target=wasm32 -nostdlib pwvf.c libc.wasm -I./ -o PWVF.so
