// this is a class that reads binary and turns it into the original struct that it was
// i.e. this is a deserializer
#include "test-struct.hpp"
#include <vector>
#include <stdint.h>
#include <iostream>


#ifndef BINARY_READER
#define BINARY_READER


class BinaryReader {
    private:
    const std::vector<uint8_t> &buffer;
    size_t offset = 0;

    public:
    explicit BinaryReader(const std::vector<uint8_t> &rawBytes);

    uint8_t read_u8();
    uint16_t read_u16();
    uint32_t read_u32();
    uint64_t read_u64();

    int8_t read_i8();
    int16_t read_i16();
    int32_t read_i32();
    int64_t read_i64();

    float read_f32();
    double read_f64();

    bool read_bool();
    std::string read_string();
};

#endif