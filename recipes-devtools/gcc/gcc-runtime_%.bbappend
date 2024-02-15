require gcc-configure-codasip-baremetal.inc

COMPATIBLE_HOST = "${HOST_SYS}"

EXTRA_OECONF:append:codasip-baremetal:class-target = " \
	--disable-libstdcxx-pch \
	--with-newlib \
	--disable-threads \
	--enable-plugins \
	--with-gnu-as \
	--disable-libitm \
"

# Changes local to gcc-runtime...

# Dont build libitm, etc.
RUNTIMETARGET:codasip-baremetal:class-target = "libstdc++-v3"

do_install:append:codasip-baremetal:class-target() {
	# Fixup what gcc-runtime normally would do, we don't want linux directories!
	rm -rf ${D}${includedir}/c++/${BINV}/${TARGET_ARCH}${TARGET_VENDOR}-linux
}

FILES:${PN}-dbg:append:codasip-baremetal:class-target = "\
    ${libdir}/libstdc++.a-gdb.py \
"
