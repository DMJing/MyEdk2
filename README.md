# MyEdk2
qemu + edk2 Env

    VMware linux 20.04
    gcc 8.4
    python3.8
    nasm 2.15.05

## Step1 get codebase
git clone https://github.com/tianocore/edk2.git

git submodule update --init

[If update submodule fail, try maunal update]

### submoudles:

[submodule "CryptoPkg/Library/OpensslLib/openssl"]

	path = CryptoPkg/Library/OpensslLib/openssl
	url = https://github.com/openssl/openssl

[submodule "SoftFloat"]

	path = ArmPkg/Library/ArmSoftFloatLib/berkeley-softfloat-3
	url = https://github.com/ucb-bar/berkeley-softfloat-3.git

[submodule "UnitTestFrameworkPkg/Library/CmockaLib/cmocka"]

	path = UnitTestFrameworkPkg/Library/CmockaLib/cmocka
	url = https://github.com/tianocore/edk2-cmocka.git

[submodule "MdeModulePkg/Universal/RegularExpressionDxe/oniguruma"]

	path = MdeModulePkg/Universal/RegularExpressionDxe/oniguruma
	url = https://github.com/kkos/oniguruma

[submodule "MdeModulePkg/Library/BrotliCustomDecompressLib/brotli"]

	path = MdeModulePkg/Library/BrotliCustomDecompressLib/brotli
	url = https://github.com/google/brotli

[submodule "BaseTools/Source/C/BrotliCompress/brotli"]

	path = BaseTools/Source/C/BrotliCompress/brotli
	url = https://github.com/google/brotli
	ignore = untracked

[submodule "RedfishPkg/Library/JsonLib/jansson"]

	path = RedfishPkg/Library/JsonLib/jansson
	url = https://github.com/akheron/jansson 

## Step2 get basetool
    sudo apt install git
    sudo apt install build-essential
    sudo apt install make
    sudo apt install gcc
    sudo apt install python
    sudo apt install iasl
    sudo apt install nasm
    sudo apt install uuid-dev

## Step3 make Env

    cd BaseTools
    make clean
    make

## Step4 Configration
generate target env configration

    source .edksetup.sh

modify ./Conf/target.txt

    TOOL_CHAIN_TAG = GCC5
    TARGET_ARCH = X64
    ACTIVE_PLATFORM       = OvmfPkg/OvmfPkgX64.dsc

## Step5 build

    cd edk2
    build


# Fail issue list
## [1]
build error

    /root/kernels/ovmf-build-X64/Build/OvmfX64/DEBUG_GCC5/X64/MdePkg/Library/BaseLib/BaseLib/OUTPUT/X64/LongJump.iii:44: error: parser: instruction expected
    /root/kernels/ovmf-build-X64/Build/OvmfX64/DEBUG_GCC5/X64/MdePkg/Library/BaseLib/BaseLib/OUTPUT/X64/LongJump.iii:49: error: parser: instruction expected
    make: *** [GNUmakefile:742: /root/kernels/ovmf-build-X64/Build/OvmfX64/DEBUG_GCC5/X64/MdePkg/Library/BaseLib/BaseLib/OUTPUT/X64/LongJump.obj] Error 1
    
Root cause: https://edk2.groups.io/g/devel/topic/89637409

## [2]
build error

    x11/xlib.h no such file or directory

Root cause: sudo apt-get install libx11-dev

## [3]
git push error

    $ git push
    remote: Permission to DMJing/MyEdk2.git denied to DMJing.
    fatal: unable to access 'https://github.com/DMJing/MyEdk2.git/': The requested URL returned error: 403

Root cause:https://blog.csdn.net/qq_41485414/article/details/80817709?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522165011199716782092949686%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=165011199716782092949686&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_ecpm_v1~rank_v31_ecpm-1-80817709.142^v9^pc_search_result_cache,157^v4^control&utm_term=%3A+The+requested+URL+returned+error%3A+403&spm=1018.2226.3001.4187

    vim .git/config
    url = git@github.com:DMJing/MyEdk2.git

## [4] ...



---
If you have other questions, pls comment a code issue,I will try to solve it 

