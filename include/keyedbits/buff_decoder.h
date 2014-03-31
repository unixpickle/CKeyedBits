#include "types.h"

/**
 * Configure a kb_buff_t for decoding from a fixed-size buffer.
 */
void kb_buff_initialize_decode(kb_buff_t * kb, void * buff, uint64_t len);

/**
 * Read a single byte from a KeyedBits buffer and return it as a header
 * struct.
 * @return false if no bytes are left, true otherwise.
 */
bool kb_buff_read_header(kb_buff_t * kb, kb_header_t * header);

/**
 * Reads a NULL-terminated string from the KeyedBits buffer and copies it out
 * to a specified buffer.
 * @param out The output buffer
 * @param max The length of the output buffer. This includes the byte used for
 * NULL termination.
 * @return false if the buffer ended before a NULL byte; false if more than
 * max characters are utilized by the string; true otherwise.
 */
bool kb_buff_read_string(kb_buff_t * kb, char * out, uint64_t max);

/**
 * Reads a double value as a UTF-8 string and parses it.
 * @return false on general buffer underflow; false if the input is not a
 * valid double value; false if the string exceeds 64 bytes in storage; true
 * otherwise.
 */
bool kb_buff_read_double(kb_buff_t * kb, double * out);

/**
 * Reads an integer from the stream. You must provide the lenLen field from
 * the header so that the decoder knows how many bytes to use.
 * @param lenLen The lenLen field from the integer's header.
 * @param out The output value
 * @return false on buffer underflow or invalid lenLen field; true otherwise.
 */
bool kb_buff_read_int(kb_buff_t * kb, uint8_t lenLen, uint64_t * out);

/**
 * Reads a data object from the buffer.
 * @param lenLen The lenLen field of the object's header.
 * @param out The output buffer
 * @param max The maximum length the buffer may have.
 * @return false on buffer underflow OR overflow; true otherwise.
 */
bool kb_buff_read_data(kb_buff_t * kb,
                       uint8_t lenLen,
                       void * out,
                       uint64_t max);

/**
 * Reads an ASCII dictionary key from the buffer.
 * @param out An output NULL-terminated ASCII buffer. If this is a dictionary
 * terminator, the output string will be 0 characters (i.e. out[0] == 0).
 * @param max The number of bytes allocated for `out` including the NULL
 * terminator.
 * @return true if a key or dictionary terminator is read; false otherwise.
 */
bool kb_buff_read_key(kb_buff_t * kb, char * out, uint64_t max);
