clang -O3 -shared pwvf.c -I./ -o PWVF.so
clang -O3 -shared --target=wasm32 pwvf.c -I./ -o PWVF.so
