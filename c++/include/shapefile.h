#ifndef SHAPEFILE_H
#define SHAPEFILE_H

#include <cstdint>
#include <cstring>  // memcpy
#include <stdexcept>

namespace shapefile
{
/// メイン・ファイル・ヘッダ
struct FileHeader
{
    int32_t file_code;
    int32_t not_in_use_1;
    int32_t not_in_use_2;
    int32_t not_in_use_3;
    int32_t not_in_use_4;
    int32_t not_in_use_5;
    int32_t file_length;
    int32_t version;
    int32_t shape_type;
    double x_min;
    double y_min;
    double x_max;
    double y_max;
    double z_min;
    double z_max;
    double m_min;
    double m_max;
};

struct RecordHeader
{
    int32_t no;
    int32_t size;
};

struct Point
{
    int32_t shape_type;
    double x;
    double y;

    static Point build(const uint8_t* p)
    {
        if (p == nullptr)
        {
            throw std::runtime_error("nullptr");
        }

        Point result;

        memcpy(&result.shape_type, p, sizeof(result.shape_type));
        p += 4;
        memcpy(&result.x, p, sizeof(result.x));
        p += 8;
        memcpy(&result.y, p, sizeof(result.y));

        return result;
    }
};

}  // namespace shapefile

#endif  // SHAPEFILE_H
