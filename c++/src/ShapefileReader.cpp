#include "ShapefileReader.h"

#include "ByteOrderConverter.h"

#include <cstring>  // memcpy

ShapefileReader::ShapefileReader(const uint8_t* buffer, size_t buffer_size)
    : m_n_record(0)
{
    if (buffer == nullptr)
    {
        return;
    }

    shapefile::FileHeader file_header;

    // メイン・ファイル・ヘッダの内容をコピー
    memcpy(&file_header, &buffer[0], 36);

    // ビッグ→リトル変換
    swapEndian(file_header.file_code);
    swapEndian(file_header.file_length);

    if (file_header.file_code != 0x270A)
    {
        throw std::runtime_error("Shapefileではない");
    }

    if (file_header.file_length * 2 != buffer_size)
    {
        throw std::runtime_error("ファイルサイズ不正");
    }

    const int32_t shape_type = file_header.shape_type;

    // 以下、レコード群

    size_t offset = 100;

    while (offset < buffer_size)
    {
        const auto p = &buffer[offset];
        const auto* header = reinterpret_cast<const shapefile::RecordHeader*>(p);

        int no = header->no;
        swapEndian(no);

        int size = header->size;
        swapEndian(size);

        const int32_t record_shape_type = *(int32_t*)(buffer + offset + sizeof(shapefile::RecordHeader));
        if (record_shape_type != shape_type)
        {
            throw std::runtime_error("shape_typeが想定外");
        }

        ++m_n_record;

        offset += sizeof(shapefile::RecordHeader) + size * 2;
    }
}
