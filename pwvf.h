/* You Can Use This Code So Long As You Don't Plagiarize It And Don't Remove This Notice Public License, YCUTCSLAYDPIADRTNPL. Made By Picsum Authors*/
#ifndef PWVF
#define PWVF

static const unsigned char PWVFMagicBytes[4] = { 0x3f, 0x45, 0x33, 0x77 };

typedef struct {
    unsigned short width;
    unsigned short height;
    unsigned char stride;
    unsigned char type;
    unsigned int LZMA_dict_size;
    unsigned int LZMA_dict_count;
    unsigned int *LZMA_dict_data;
    unsigned int *LZMA_data;
    unsigned int LZMA_data_length;
    unsigned char *decodedData;
    unsigned int decodedDataLength;
} PWVF_context_t;

int pwvfIsMagicBytes(unsigned char *bytes);

int pwvfMakeContext(PWVF_context_t *ctx, unsigned char *data, unsigned long dataLength);

#endif
