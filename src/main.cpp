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
    binWrite.write_u16(dhruv.age);

    std::cout << dhruv.name << std::endl;
}