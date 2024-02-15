LDGOLD:codasip-baremetal = ""
LDGOLD_ALTS:codasip-baremetal = ""

EXTRA_OECONF:append:codasip-baremetal = " \
	--disable-gprof \
	--disable-shared \
	--enable-lto \
	--enable-static \
"
