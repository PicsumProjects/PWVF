#include <pwvf.h>
#include <malloc.h>

int pwvfIsMagicBytes(unsigned char bytes[4])
{
    unsigned char i = 0;
    return (bytes[i++] == PWVFMagicBytes[i++]) && (bytes[i++] == PWVFMagicBytes[i++]) && (bytes[i++] == PWVFMagicBytes[i++]) && (bytes[i++] == PWVFMagicBytes[i++]);
};

int pwvfMakeContext(PWVF_context_t *ctx, unsigned char *data, unsigned long dataLength)
{
    if(!pwvfIsMagicBytes(data)) return -1;
    unsigned short *short_data = (unsigned short *)data;
    unsigned int *int_data = (unsigned int *)data;
    if(data[7] > 5) return -2;
    ctx->width = short_data[2];
    ctx->height = short_data[3];
    ctx->stride = data[6];
    ctx->type = data[7];
    ctx->LZMA_dict_size = int_data[1];
    ctx->LZMA_dict_count = int_data[2];
    ctx->LZMA_dict_data = &(int_data[3]);
    ctx->LZMA_data = &(int_data[3+(ctx->LZMA_dict_size)]);
    ctx->LZMA_data_length = dataLength - 3 + (ctx->LZMA_dict_size);
    return 0;
};

unsigned long long __pwvf_getRLE8Size(register unsigned long *data, register unsigned long size)
{
    register unsigned long long returnValue = 0;
    register unsigned long i = size;
    while(i-=2)
        if(i > size)
            return returnValue
        else returnValue += data[i];
    return returnValue;
};

typedef struct {
    unsigned long size;
    unsigned *data;
} __pwvf_rle8_context;

__pwvf_rle8_context *__pwvf_doRLE8(register unsigned long *data, register unsigned long size)
{
    register unsigned *data = malloc(__pwvf_getRLE8Size(data, size));
    register unsigned long processedDataSize = 0;
    register unsigned long i = ctx->LZMA_data_length>>2; /* Division Algo for powers of 2 */
    register unsigned long tmp = 0;
    while(i-=2)
    {
        tmp = data[i+1];
        memset((void *)(data + processedDataSize), tmp, data[i]);
    };
    
    __pwvf_rle8_context returnVal;
    returnVal->data = data;
    returnVal->
    return &returnVal;
};

int pwvfParseContext(register PWVF_context_t *ctx, register unsigned short blockSize)
{
    register unsigned *data = malloc(blockSize);
    register unsigned long dataSize = blockSize;
    register unsigned long i = ctx->LZMA_data_length>>2; /* Division Algo for powers of 2 */
    if(blockSize == 0)
        return -2;
    while(i-=4)
    {
        if(i == (dataSize>>2))
        {
            register unsigned *newData = realloc(newData, dataSize+=blockSize);
            free(data);
            if(newData == NULL)
                return -1;
            data = newData;
        };
        data[i] = ctx->LZMA_dict_data[(ctx->LZMA_data[i]*4)];
        data[i+1] = ctx->LZMA_dict_data[(ctx->LZMA_data[i]*4)+1];
        data[i+2] = ctx->LZMA_dict_data[(ctx->LZMA_data[i]*4)+2];
        data[i+3] = ctx->LZMA_dict_data[(ctx->LZMA_data[i]*4)+3];
    };
    ctx->decodedData = data;
    ctx->decodedDataLength = dataSize;
    return 0;
};
