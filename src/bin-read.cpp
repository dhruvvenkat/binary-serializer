#include "bin-read.hpp"
#include <vector>
#include <stdint.h>
#include <iostream>

using namespace std;

BinaryReader::BinaryReader(const vector<uint8_t> &rawBytes)
    : buffer(rawBytes), offset(0) {}

uint8_t BinaryReader::read_u8() {
    if (offset >= buffer.size()) {
        throw std::runtime_error("offset greater than # of bytes, aborting");
    }
    return (uint8_t)(buffer[offset++]);
}

uint16_t BinaryReader::read_u16() {
    uint16_t b0 = read_u8();
    uint16_t b1 = read_u8();

    return ((b0 << 8) | (b1 << 0));
}

uint32_t BinaryReader::read_u32() {
    uint32_t b0 = read_u8();
    uint32_t b1 = read_u8();
    uint32_t b2 = read_u8();
    uint32_t b3 = read_u8();

    return ((b0 << 24) | (b1 << 16) | (b2 << 8) | (b3 << 0));
}

uint64_t BinaryReader::read_u64() {
    uint64_t combined = 0;

    for (int i = 7; i > -1; i++) {
        uint64_t byteToAdd = read_u8();
        combined |= (byteToAdd << (i*8));
    }
}

int8_t BinaryReader::read_i8() {
    return static_cast<int8_t>(read_u8());
}

int16_t BinaryReader::read_i16() {
    return static_cast<int16_t>(read_u16());
}

int32_t BinaryReader::read_i32() {
    return static_cast<int32_t>(read_u32());
}

int64_t BinaryReader::read_i64() {
    return static_cast<int64_t>(read_u64());
}

float BinaryReader::read_f32() {
    return bit_cast<float>(read_u32());
}


double BinaryReader::read_f64() {
    return bit_cast<double>(read_u64());
}

bool BinaryReader::read_bool() {
    return static_cast<bool>(read_u8());
}

string BinaryReader::read_string() {
    uint32_t stringSize = read_u32();
    string outputString = "";

    for (int i = 0; i < stringSize; i++) {
        outputString += static_cast<char>(read_u8());
    }
}