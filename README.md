# meta-codasip-baremetal

This layer is meant to augment Yocto/OE functionality to provide a
Baremetal/Standalone distribution. It can also be used to build
FSBL from the baremetal-sdk package require to boot on the Hobgoblin
FPGA platform.

This layer is derived from the meta-xilinx-standalone layer,
provided by Xilinx for the same purpose: building a set of tools
suitable for standalone development or building a FSBL.

## Building

The software in this layer may be used in either a standard single
configuration build, or a multiconfig build.  A multiconfig build is
needed to build the FSBL firmware automatically.

## Dependencies

This layer depends on:

	URI: https://git.yoctoproject.org/poky
	layers: meta, meta-poky
	branch: nanbield

	URI: https://git.openembedded.org/meta-openembedded
	layers: meta-oe
	branch: nanbield

	URI: https://github.com/kraj/meta-clang
	layers: meta-clang
