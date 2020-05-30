#include "interface.h"

#include "ShapefileReader.h"

#include <sstream>

int add(int a, int b)
{
    return a + b;
}

const char* sum(int a, int b, int c, const char* text)
{
    std::ostringstream oss;
    oss << a + b + c << " " << text;

    return oss.str().c_str();
}

const char* sumFromText(const char* text)
{
    std::istringstream iss(text);

    int a, b, c;
    std::string s;

    iss >> a >> b >> c >> s;

    return sum(a, b, c, s.c_str());
}

size_t getShapefileNRecord(const uint8_t* buffer, size_t buffer_size)
{
    ShapefileReader reader(buffer, buffer_size);
    return reader.n_record();
}
