#include "bin-write.hpp"
#include <vector>
#include <stdint.h>
#include <iostream>
#include <bit>
#include <cstdint>
#include <iomanip>

using namespace std;

BinaryWriter::BinaryWriter() {
    buffer = {0};
}

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

// we can just use a loop to iterate thru intead of writin 8 lines lol
void BinaryWriter::write_u64(uint64_t value) {
    for (int i = 7; i > -1; i--) {
        buffer.push_back((value >> i*8) & 0xFF);
    }
}

// can't bit shift on signed integers, so we can just static cast
// might use two's complement to do this later(?)
void BinaryWriter::write_i8(int8_t value) {
    write_u8(static_cast<uint8_t>(value));
}

void BinaryWriter::write_i16(int16_t value) {
    write_u16(static_cast<uint16_t>(value));
}

void BinaryWriter::write_i32(int32_t value) {
    write_u32(static_cast<uint32_t>(value));
}

void BinaryWriter::write_i64(int64_t value) {
    write_u64(static_cast<uint64_t>(value));
}

void BinaryWriter::write_f32(float value) {
    uint32_t floatBits = std::bit_cast<uint32_t>(value);
    write_u32(floatBits);
}

void BinaryWriter::write_f64(double value) {
    uint64_t doubleBits = std::bit_cast<uint64_t>(value);
    write_u64(doubleBits);
}

void BinaryWriter::write_bool(bool value) {
    buffer.push_back(static_cast<uint8_t>(value));
}

void BinaryWriter::write_string(const string &value) {
    write_u32(static_cast<uint32_t>(value.size())); // need to save the # of characters in the string

    for (char c : value) {
        write_u8(static_cast<uint8_t>(c));
    }
}

void BinaryWriter::print_bytes() {
    for (uint8_t byte : buffer) {
        cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(byte) << ' ';
    }

    cout << dec << '\n';
}

std::vector<uint8_t> BinaryWriter::returnBuffer() {
    return buffer;
}

void BinaryWriter::clear() {
    buffer.clear();
}