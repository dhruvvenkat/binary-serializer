// this is a class that writes binary based on an incoming struct
// i.e. this is a serializer
#include <vector>
#include <iostream>
#include <stdint.h>

#ifndef BINARY_WRITER
#define BINARY_WRITER

class BinaryWriter {
    private:
        std::vector<uint8_t> buffer; // glue bytes onto the back of this variable

    public:
        // UNSIGNED INT CONVERTERS
        void write_u8(uint8_t value);
        void write_u16(uint16_t value);
        void write_u32(uint32_t value);
        void write_u64(uint64_t value);

        // SIGNED INT CONVERTERS
        void write_i8(int8_t value);
        void write_i16(int16_t value);
        void write_i32(int32_t value);
        void write_i64(int64_t value);

        // FLOAT CONVERTERS
        void write_f32(float value);
        void write_f64(double value);

        // BOOL & STRING CONVERTERS
        void write_bool(bool value);
        void write_string(const std::string& value);

    
};

#endif