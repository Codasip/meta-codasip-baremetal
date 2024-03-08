COMPATIBLE_HOST = "${HOST_SYS}"

FILESEXTRAPATHS:prepend :=  "${FILE_DIRNAME}/clang:"
SRC_URI += "\
    file://0100-Remove-nostdsysteminc-for-baremetal.patch \
    file://0101-Switch-baremetal-to-libgcc.patch \
"
