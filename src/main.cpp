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
    binWrite.clear();

    binWrite.write_u8(0x12);        
    binWrite.write_u16(0x1234);     
    binWrite.write_u32(0x12345678); 
    binWrite.write_u64(0x1122334455667788ULL);

    binWrite.print_bytes();
}