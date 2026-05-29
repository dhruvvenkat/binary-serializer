#include "bin-read.hpp"
#include "bin-write.hpp"
#include "test-struct.hpp"
#include <cassert>
#include <cmath>

using namespace std;

void testPrimitives(BinaryWriter &writer) {
    writer.write_u8(0x12);
    writer.write_u16(0x1234);
    writer.write_u32(0x12345678);
    writer.write_u64(0x1122334455667788ULL);
    writer.write_i32(-123);
    writer.write_f32(1.5f);
    writer.write_f64(3.25);
    writer.write_bool(true);
    writer.write_string("Dhruv");
    //writer.print_bytes();

    BinaryReader reader(writer.returnBuffer());

    assert(reader.read_u8() == 0x12);
    assert(reader.read_u16() == 0x1234);
    assert(reader.read_u32() == 0x12345678);
    assert(reader.read_u64() == 0x1122334455667788ULL);
    assert(reader.read_i32() == -123);
    assert(std::fabs(reader.read_f32() - 1.5f) < 0.0001f);
    assert(std::fabs(reader.read_f64() - 3.25) < 0.0001);
    assert(reader.read_bool() == true);
    assert(reader.read_string() == "Dhruv");
}

void serializeStudent(BinaryWriter &writer, Student toSerialize) {
    writer.write_string(toSerialize.name);
    writer.write_u8(toSerialize.age);
    writer.write_f32(toSerialize.gpa);
}

void deserializeStudent(BinaryReader &reader) {
    cout << "deserialized data: " << endl;;
    cout << " - name: " << reader.read_string() << endl;
    cout << " - age: " << static_cast<int>(reader.read_u8()) << endl;
    cout << " - gpa: " << reader.read_f32() << endl;;
}

int main() {
    Student dhruv =  {
        "Dhruv",
        20,
        4.0
    };

    cout << "original data: " << endl;
    cout << " - name: " << dhruv.name << endl;
    cout << " - age: " << dhruv.age << endl;
    cout << " - gpa: " << dhruv.gpa << endl;
    cout << endl;

    BinaryWriter writer;
    // testPrimitives(writer);
    // writer.clear();

    serializeStudent(writer, dhruv);
    cout << "serialized data: ";
    writer.print_bytes();
    cout << endl;

    BinaryReader reader = BinaryReader(writer.returnBuffer());
    deserializeStudent(reader);


}