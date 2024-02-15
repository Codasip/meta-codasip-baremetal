require gcc-configure-codasip-baremetal.inc

COMPATIBLE_HOST = "${HOST_SYS}"

python do_multilib_install:codasip-baremetal:class-target () {
    pass
}

baremetal_fixup () {
	(
		cd ${D}${libdir}
		for each in ${TARGET_SYS}/*/* ; do
			ln -s $each $(basename $each)
		done
	)

	# Apparently we can end up with an empty /lib occasionally
        find ${D}/lib -type d | sort -r | xargs rmdir || :
}

FIXUP_FUNCTION = ""
FIXUP_FUNCTION:codasip-baremetal:class-target = " baremetal_fixup"

do_install[postfuncs] .= "${FIXUP_FUNCTION}"

FILES:${PN}-dev:append:codasip-baremetal:class-target = " \
	${libdir}/*.a \
	${libdir}/*.o \
"
