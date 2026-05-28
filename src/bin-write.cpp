#include "bin-write.hpp"
#include <vector>
#include <stdint.h>
#include <iostream>

using namespace std;

void BinaryWriter::write_u8(uint8_t value) {
    buffer.push_back(value);
}

void BinaryWriter::write_u16(uint16_t value) {
    buffer.push_back((value >> 8) & 0xFF);
    buffer.push_back((value >> 0) & 0xFF);
}

void BinaryWriter::write_u32(uint32_t value) {
    buffer.push_back((value >> 24) & 0xFF);
    buffer.push_back((value >> 16) & 0xFF);
    buffer.push_back((value >> 8) & 0xFF);
    buffer.push_back((value >> 0) & 0xFF);
}

void BinaryWriter::write_u64(uint64_t value) {
    for (int i = 7; i > -1; i--) {
        buffer.push_back((value >> i*8) & 0xFF);
    }
}