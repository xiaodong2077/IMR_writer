# IMR_writer

A small tool for writing [IMR](https://docs.novatel.com/Waypoint/Content/Data_Formats/IMR_File.htm) file.

## Build and Install

```bash
mkdir build
cd build
cmake .. -G Ninja
cmake --build .
cmake --install .
```

Currently it will install the headers/lib to the build folder. Feel free to change the `CMAKE_INSTALL_PREFIX` or use `stow` to manage the lib.

## Write vs WriteDirectly

The compiler will automatically align the memory of the struct. So the size of a struct will not equal the sum of each field. It's often bigger than the sum. Here, I use `#pragma pack(push, 1)` and `#pragma pack(pop)` to avoid memory alignment. But I don't know whether it will affect efficiency. You can comment out these lines and use the function Write. If you keep these lines, you can use WriteDirectly.

## Example

Here, I offer an example of the usage of this library. I read a file with a custom format of IMU data and write an IMR file.

## License

[MIT](LICENSE)

## Thanks

[inertial-navigation](https://github.com/ethanjinhuang/inertial-navigation) provides a nice struct of IMR.
