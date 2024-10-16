rm -f /hda-contents/DajingApp.efi
cp /home/jing/Desktop/edk2/Build/Shell/DEBUG_GCC5/X64/ShellPkg/Application/MyEdk2/DajingApp/DajingApp/DEBUG/DajingApp.efi ./hda-contents
qemu-system-x86_64 -pflash ./hda-contents/OVMF.fd -hda fat:rw:hda-contents -net none
