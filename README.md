# WoW Addon Manager

WAM (WoW Addon Manager) is a multiplatform peer-to-peer addon management solution for managing Addons for MMORPG World of Warcraft.

# Building

Requirements:
CMake 3.13
C++20 compatible compiler
Qt 5.14
Boost 1.71.0
[libtorrent 1.2.2](https://github.com/arvidn/libtorrent)
[cpp-httplib](https://github.com/yhirose/cpp-httplib)
## Windows
I used vcpkg to get libtorrent, but used the standard Qt installer and standard boost install instructions.
Dont forget to set `Qt5_DIR` and `Boost_ROOT` to the correct directories.
```sh
mkdir build
cd build
cmake ../ -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE="c:/tools/vcpkg/scripts/buildsystems/vcpkg.cmake"
C:\path\to\MSBuild.exe /t:Build /p:Configuration=Release ALL_BUILD.vxproj
cd Release
C:\path\to\Qt\5.14.0\msvc2017_64\bin\windeployqt.exe wam.exe
```
## Linux
### Packages
**Arch Linux**
`sudo pacman -S openssl libtorrent cmake gcc qt-base make boost`
Use your favorite AUR helper to get `libiconv` or install with makepkg

**Ubuntu**
`sudo apt-get install build-essential cmake`
Follow the standard Boost, QT, and libtorrent install instructions.
Ubuntu doesnt new enough versions available in `apt`

### Building
```sh
mkdir build
cd build
cmake ../ -DCMAKE_BUILD_TYPE=Release
make -j$(nproc)
```