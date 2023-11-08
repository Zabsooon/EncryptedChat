# EncryptedChat based on P2P connection.
---

# Building

To build the EncryptedChat we are using Conan and cmake:

If you don't have conan installed you can do it by using pip:
```
$ pip install conan
```

You can check what packages we use in file CMakeLists.txt and also what Conan installs in conanfile.py.

To build the project you need to execute this commands:

```
$ conan install conanfile.py --build=missing
$ cd build
```

If you want to build release version execute:
```
$ cmake .. -DCMAKE_TOOLCHAIN_FILE=./Release/generators/conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release
```

By now you should have generated Makefile, now you just need to execute:
```
$ cmake --build .
```
OR
```
$ make
```
