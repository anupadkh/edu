from ctypes import (
        Union, Array,
        c_uint8, c_uint32,
        cdll, CDLL
)

class uint8_array(Array):
    _type_ = c_uint8
    _length_ = 4

class u_type(Union):
    _fields_ = ("data", c_uint32), ("chunk", uint8_array)

# load printf function from Dynamic Linked Libary libc.so.6 (I'm use linux)
libc = CDLL(cdll.LoadLibrary('libc.so.6')._name)
printf = libc.printf

if __name__ == "__main__":
    # initialize union
    _32bitsdata = u_type()
    # set values to chunk
    _32bitsdata.chunk[:] = (1, 2, 3, 4)
    # and print it
    printf(b"Data in 32 bits: %d\n", _32bitsdata.data)
