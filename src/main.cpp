#include "bin-read.hpp"
#include "bin-write.hpp"
#include "test-struct.hpp"

int main() {
    Student dhruv =  {
        "Dhruv",
        20,
        4.0
    };

    BinaryWriter binWrite = BinaryWriter();
    binWrite.write_string(dhruv.name);
    binWrite.write_u16(dhruv.age);
    binWrite.write_f32(dhruv.gpa);

    binWrite.print_bytes();
}