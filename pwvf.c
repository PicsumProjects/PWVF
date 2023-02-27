#include <pwvf.h>

int pwvfIsMagicBytes(unsigned char bytes[4])
{
    unsigned char i = 0;
    return (bytes[i++] == PWVFMagicBytes[i++]) && (bytes[i++] == PWVFMagicBytes[i++]) && (bytes[i++] == PWVFMagicBytes[i++]) && (bytes[i++] == PWVFMagicBytes[i++]);
};
