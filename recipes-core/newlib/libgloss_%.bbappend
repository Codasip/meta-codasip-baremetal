COMPATIBLE_HOST = ".*-elf"

EXTRA_OECONF:append:codasip-baremetal = " \
	--enable-newlib-io-c99-formats \
	--enable-newlib-io-long-long \
	--enable-newlib-io-float \
	--enable-newlib-io-long-double \
"
