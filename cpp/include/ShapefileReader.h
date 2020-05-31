#ifndef SHAPEFILEREADER_H
#define SHAPEFILEREADER_H

#include "shapefile.h"

class ShapefileReader
{
    size_t m_n_record;

public:
    ShapefileReader() = delete;
    ShapefileReader(const uint8_t* buffer, size_t size);
    ~ShapefileReader() = default;

    size_t n_record() const { return m_n_record; }
};

#endif  // SHAPEFILEREADER_H
