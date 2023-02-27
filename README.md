# PWVF
Picsum’s Weird Video Format

Spec:
Magic bytes are 4 bytes (0x3f, 0x45, 0x33, 0x77)
Width (2 bytes, unsigned, LE)
Height (2 bytes, unsigned, LE)
Stride (in bytes, 1 byte, unsigned, LE), can be 1, 2, 3, 4, 5)
Type (1 byte, either 0 for RGBA (isnt float), 1 for RGB (isn't float), 2 for YCbCr (isn't float), 3 for YCbCrA (isn't float), anything above 9 is custom.)
Data (size is width * height * stride, first compressed with RLE8, then LZMA)
