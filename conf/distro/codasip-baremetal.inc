DISTRO = "codasip-baremetal"
DISTRO_NAME = "Codasip Bare Metal Distro"
DISTRO_VERSION = "1.5"
TARGET_VENDOR = "-codasip"
SDK_VENDOR = "-baremetalsdk"
SDK_VERSION = "R1.5"

TCLIBC = "newlib"
TCLIBCAPPEND =""

PACKAGE_CLASSES ?= "package_rpm"

SDK_NAME = "${DISTRO}-${TCLIBC}-${SDKMACHINE}-${IMAGE_BASENAME}-${TUNE_PKGARCH}-${MACHINE}"
SDKPATHINSTALL = "/opt/${DISTRO}/${SDK_VERSION}"

# Build with clang where possible
TOOLCHAIN = "clang"

# Use meta-clang to provide llvm rather than core
PREFERRED_PROVIDER_llvm = "clang"
PREFERRED_PROVIDER_llvm-native = "clang-native"
PREFERRED_PROVIDER_nativesdk-llvm = "nativesdk-clang"
PROVIDES:pn-clang = "llvm"
PROVIDES:pn-clang-native = "llvm-native"
PROVIDES:pn-nativesdk-clang = "nativesdk-llvm"

# Include clang in SDK
CLANGSDK = "1"

# Mark newlib as only buildable with gcc
TOOLCHAIN:pn-newlib = "gcc"
TOOLCHAIN:pn-libgloss = "gcc"
TOOLCHAIN:pn-baremetal-sdk = "gcc"

# Hold this until it gets merged in core, we need libc.a and libgloss.a for cross-canadian
LIBC_DEPENDENCIES:append:codasip-baremetal = " newlib-staticdev libgloss-staticdev"

ESW_CFLAGS ?= ""

# Make sure all regular recipes are excluded from compatibility
# Avoid using this for native, nativesdk or cross recipes
COMPATOS = ""
# Set the regex for target recipes only, follow TARGET_OS default
COMPATOS:class-target = ".*-linux${LIBCEXTENSION}${ABIEXTENSION}"
COMPATIBLE_HOST ?= "${COMPATOS}"

# Clear defaults
PREFERRED_PROVIDER_virtual/kernel = "linux-dummy"

# Workaround for pulling in nativesdk-mingw-w64-winpthreads
TOOLCHAIN_HOST_TASK:append:sdkmingw32 = " nativesdk-mingw-w64-winpthreads"

# Disable static for all classes, except for target.  This will ensure we can
# share more recipe hashes with other distros, while still building
# static binaries for baremetal targets (by default).  The user can of course
# still override this, but will need to specifically select class-target to
# do so.
DISABLE_STATIC:class-target ?= ""

require conf/distro/include/no-static-libs.inc
require conf/distro/include/yocto-uninative.inc
INHERIT += "uninative"

BB_SIGNATURE_HANDLER ?= "OEEquivHash"
BB_HASHSERVE ??= "auto"

MACHINE_FEATURES_BACKFILL_CONSIDERED += "rtc qemu-usermode"

# We only care about RISC-V targets, but we need x86_64 for building
QEMU_TARGETS ?= "riscv32 riscv64 x86_64"
