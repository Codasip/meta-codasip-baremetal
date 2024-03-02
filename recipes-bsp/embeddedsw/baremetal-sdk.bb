DESCRIPTION = "Codasip BareMetal SDK"

inherit deploy

COMPATIBLE_HOST = ".*-elf"

# Include the baremetal setting, if it's enabled
#BAREMETAL_INC = "${@bb.utils.contains('BBMULTICONFIG', 'baremetal', 'baremetal-cfg.inc', '', d)}"
#require ${BAREMETAL_INC}

PACKAGE_ARCH = "${MACHINE_ARCH}"

BRANCH="devel"
SRC_URI = " \
	git://git@gitlab.codasip.com/platform-sw/baremetal-sdk.git;protocol=ssh;branch=${BRANCH} \
	file://config.mk \
"

SRCREV = "${AUTOREV}"
BASE_VER ?= "${@bb.parse.vars_from_file("VERSION",d)[1] or 'master'}"
PV = "0.11.0+git${SRCPV}"
S = "${WORKDIR}/git"
B = "${S}"

LICENSE = "Codasip"
LIC_FILES_CHKSUM = "file://LICENSE;md5=2faad86a22b25ebf61a8d9b1ed916ada"
LICENSE_FLAGS = "commercial"

do_configure() {
    cp ${WORKDIR}/config.mk ${S}
}

COMPILER = "${CC}"
COMPILER_FLAGS = "-O2 -c"
EXTRA_COMPILER_FLAGS = "-g -Wall -Wextra -Os -flto -ffat-lto-objects"
ARCHIVER = "${AR}"

# common.mk tries to work out the compiler, override this
EXTRA_OEMAKE = "'CC=${CC}' 'OBJCOPY=${OBJCOPY}' DETECTED_PREFIX=something COMPILER_VERSION_STRING=gcc"

do_compile() {
    pwd
    oe_runmake
}

do_install() {
    :
}

PACKAGES = ""

do_deploy() {
    install -Dm 0644 ${B}/build/fsbl_rom.xexe ${DEPLOYDIR}/
}

addtask deploy before do_build after do_install

# Disable buildpaths QA check warnings.
INSANE_SKIP:${PN} += "buildpaths"
