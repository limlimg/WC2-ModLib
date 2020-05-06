# WC2-ModLib
No more assemby! Create a new .so to modify World Conqueror 2 game code with ease!

Open Android Studio, create a sample native c/c++ project, put code from this repo in the project, build APK with GCC toolchain from NDK version r16b, extract libmodlibeasytech.so from built APK and put them in game apk.

Folders:

easytech/includes: header files defining types from libeasytech.so

easytech/src: linkage code, DO NOT modify

code: feature code, modify them to add/change features of the game
