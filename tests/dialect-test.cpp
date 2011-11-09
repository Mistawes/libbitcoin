#include <bitcoin/dialect.hpp>
#include <bitcoin/types.hpp>
#include <bitcoin/util/assert.hpp>
#include <bitcoin/util/logger.hpp>

using namespace libbitcoin;

int main()
{
    data_chunk raw_tx = {
                                                    0x01, 0x00, 0x00, 0x00, 0x01, 0x6D, 0xBD, 0xDB,
    0x08, 0x5B, 0x1D, 0x8A, 0xF7, 0x51, 0x84, 0xF0, 0xBC, 0x01, 0xFA, 0xD5, 0x8D, 0x12, 0x66, 0xE9,
    0xB6, 0x3B, 0x50, 0x88, 0x19, 0x90, 0xE4, 0xB4, 0x0D, 0x6A, 0xEE, 0x36, 0x29, 0x00, 0x00, 0x00,
    0x00, 0x8B, 0x48, 0x30, 0x45, 0x02, 0x21, 0x00, 0xF3, 0x58, 0x1E, 0x19, 0x72, 0xAE, 0x8A, 0xC7,
    0xC7, 0x36, 0x7A, 0x7A, 0x25, 0x3B, 0xC1, 0x13, 0x52, 0x23, 0xAD, 0xB9, 0xA4, 0x68, 0xBB, 0x3A,
    0x59, 0x23, 0x3F, 0x45, 0xBC, 0x57, 0x83, 0x80, 0x02, 0x20, 0x59, 0xAF, 0x01, 0xCA, 0x17, 0xD0,
    0x0E, 0x41, 0x83, 0x7A, 0x1D, 0x58, 0xE9, 0x7A, 0xA3, 0x1B, 0xAE, 0x58, 0x4E, 0xDE, 0xC2, 0x8D,
    0x35, 0xBD, 0x96, 0x92, 0x36, 0x90, 0x91, 0x3B, 0xAE, 0x9A, 0x01, 0x41, 0x04, 0x9C, 0x02, 0xBF,
    0xC9, 0x7E, 0xF2, 0x36, 0xCE, 0x6D, 0x8F, 0xE5, 0xD9, 0x40, 0x13, 0xC7, 0x21, 0xE9, 0x15, 0x98,
    0x2A, 0xCD, 0x2B, 0x12, 0xB6, 0x5D, 0x9B, 0x7D, 0x59, 0xE2, 0x0A, 0x84, 0x20, 0x05, 0xF8, 0xFC,
    0x4E, 0x02, 0x53, 0x2E, 0x87, 0x3D, 0x37, 0xB9, 0x6F, 0x09, 0xD6, 0xD4, 0x51, 0x1A, 0xDA, 0x8F,
    0x14, 0x04, 0x2F, 0x46, 0x61, 0x4A, 0x4C, 0x70, 0xC0, 0xF1, 0x4B, 0xEF, 0xF5, 0xFF, 0xFF, 0xFF,
    0xFF, 0x02, 0x40, 0x4B, 0x4C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x19, 0x76, 0xA9, 0x14, 0x1A, 0xA0,
    0xCD, 0x1C, 0xBE, 0xA6, 0xE7, 0x45, 0x8A, 0x7A, 0xBA, 0xD5, 0x12, 0xA9, 0xD9, 0xEA, 0x1A, 0xFB,
    0x22, 0x5E, 0x88, 0xAC, 0x80, 0xFA, 0xE9, 0xC7, 0x00, 0x00, 0x00, 0x00, 0x19, 0x76, 0xA9, 0x14,
    0x0E, 0xAB, 0x5B, 0xEA, 0x43, 0x6A, 0x04, 0x84, 0xCF, 0xAB, 0x12, 0x48, 0x5E, 0xFD, 0xA0, 0xB7,
    0x8B, 0x4E, 0xCC, 0x52, 0x88, 0xAC, 0x00, 0x00, 0x00, 0x00};

    dialect_ptr translator(new original_dialect);
    const message::transaction& tx = translator->transaction_from_network(raw_tx);
    BITCOIN_ASSERT(raw_tx == translator->to_network(tx));
    return 0;
}

