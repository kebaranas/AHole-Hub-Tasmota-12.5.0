/////////////////////////////////////////////////////////////////////
// compressed by tools/unishox/compress-html-uncompressed.py
/////////////////////////////////////////////////////////////////////

const size_t HTTP_HEADER_MONITOR_SIZE = 32;
const char HTTP_HEADER_MONITOR_COMPRESSED[] PROGMEM = "\x3D\x3C\x1F\xF4\x65\x2F\x7C\x33\xE1\xEC\x20\xC5\x5F\xE8\xE8\x6B\xF1\xEC\x3F\x0F"
                             "\x43\xB0\x10\x6A\x1F\x86";

#define  HTTP_HEADER_MONITOR       Decompress(HTTP_HEADER_MONITOR_COMPRESSED,HTTP_HEADER_MONITOR_SIZE).c_str()