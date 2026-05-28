# dhruv's binary serializer

I wanted to learn about byte streams in C++ as I get deeper into performance programming, so I'm making this as a way of understanding how seralization works

Serialization is an important part of performance programming because it turns proprietary data (e.g. structs) into a portable format (binary or text) so that it can be easily moved around + displayed on different machines

Building both a serializer and a deserializer for a basic struct - student