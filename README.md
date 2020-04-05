# WoW Addon Manager
| Platform | Master | Dev |
| -------- | ------ | --- |
| Windows  | [![Build status](https://ci.appveyor.com/api/projects/status/eat30wg7qk4nnqd5/branch/dev?svg=true)](https://ci.appveyor.com/project/jorbo/wam-client-windows/branch/master) | [![Build status](https://ci.appveyor.com/api/projects/status/eat30wg7qk4nnqd5/branch/dev?svg=true)](https://ci.appveyor.com/project/jorbo/wam-client-windows/branch/dev) |
| Linux | [![Build status](https://ci.appveyor.com/api/projects/status/xsq7i86cqwmbb768/branch/dev?svg=true)](https://ci.appveyor.com/project/jorbo/wam-client-linux/branch/master) | [![Build status](https://ci.appveyor.com/api/projects/status/xsq7i86cqwmbb768/branch/dev?svg=true)](https://ci.appveyor.com/project/jorbo/wam-client-linux/branch/dev) |
| Mac | N/A | N/A

WAM (WoW Addon Manager) is a multiplatform peer-to-peer addon management solution for managing Addons for MMORPG World of Warcraft.

# Building

Requirements:
CMake 3.13  
C++20 compatible compiler  
Qt 5.14  
Boost 1.70.0  
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
  #### Setup
  ```sh
  sudo add-apt-repository ppa:mhier/libboost-latest
  sudo apt-get update
  sudo apt-get upgrade
  sudo apt-get install libboost1.70-dev build-essential qt5-default
  ```
  #### Install newer CMake
  ```sh

  wget https://github.com/Kitware/CMake/releases/download/v3.17.0-rc3/cmake-3.17.0-rc3-Linux-x86_64.sh
  chmod +x cmake-3.17.0-rc3-Linux-x86_64.sh
  sudo ./cmake-3.17.0-rc3-Linux-x86_64.sh --skip-license
  ```

  #### Build and install newer libtorrent
  ```sh

  git clone https://github.com/arvidn/libtorrent.git
  cd libtorrent
  mkdir -p build
  cd build
  cmake ../ -DCMAKE_BUILD_TYPE=Release
  make -j$(nproc)
  sudo make install
  cd ../../
  ```

  #### Building
  ```sh
  mkdir build
  cd build
  cmake ../ -DCMAKE_BUILD_TYPE=Release
  make -j$(nproc)
  ```
