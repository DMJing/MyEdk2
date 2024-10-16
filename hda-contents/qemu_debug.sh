qemu-system-x86_64 -drive if=pflash,format=raw,readonly=on,file=OVMF.fd -m 2048M -serial file:debug.log -nographic
