1. Android build
  - Download original android source code (  android-9.0.0_r37 ) from http://source.android.com
  ( $repo init -u https://android.googlesource.com/platform/manifest -b android-9.0.0_r37
    $repo sync -cdq -j12 --no-tags
    $repo start  android-9.0.0_r37 --all
  )
	   
  - Then, merge the source into the android source code
  - Run following scripts to build android
    a) source build/envsetup.sh
    b) lunch 1
    c) make -j4
	
	
  - When you compile the android source code, you have to add google original prebuilt source(toolchain) into the android directory.
  - After build, you can find output at out/target/product/generic

2. Kernel Build  
  - Uncompress using following command at the android directory

    a) tar -xvzf *_Kernel_Pie.tar.gz

  - When you compile the kernel source code, you have to add google original "prebuilt" source(toolchain) into the android directory.
  - Run following scripts to build kernel
  
    a) cd kernel/msm-4.14
    b) mkdir -p out
    c) make ARCH=arm64 O=./out elsa_lgu_kr-perf_defconfig
    d) make ARCH=arm64 O=./out CROSS_COMPILE=$(pwd)/../../prebuilts/gcc/linux-x86/aarch64/aarch64-linux-android-4.9/bin/aarch64-linux-android- KERNEL_COMPRESSION_SUFFIX=gz -j4	

  * "-j4" : The number, 4, is the number of multiple jobs to be invoked simultaneously. 
  - After build, you can find the build image(zImage) at kernel/msm-4.14/out/arch/arm64/boot
 
