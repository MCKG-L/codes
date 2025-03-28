#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <iomanip>
#include <filesystem>  // 引入 filesystem 库
using namespace std;

// 计算校验和
uint16_t calculateChecksum(const vector<uint8_t>& data) {
    uint32_t checksum = 0;
    // 遍历数据，每次取两个字节
    for (size_t i = 0; i < data.size(); i += 2) {
        uint16_t word = data[i] << 8; // 高 8 位
        if (i + 1 < data.size()) {
            word |= data[i + 1]; // 低 8 位
        }
        checksum += word;
        // 处理溢出
        if (checksum > 0xFFFF) {
            checksum = (checksum & 0xFFFF) + 1;
        }
    }

    // 取反返回
    return ~checksum & 0xFFFF;
}

// 校验报文是否有效
bool verifyChecksum(const vector<uint8_t>& data, uint16_t checksum) {
    uint32_t total = calculateChecksum(data) + checksum;
    return (total & 0xFFFF) == 0xFFFF;
}

// 从文件读取报文
vector<uint8_t> readPacket(const string& filename) {
    ifstream file(filename, ios::binary);
    if (!file) {
        throw runtime_error("无法打开文件: " + filename);
    }
    return vector<uint8_t>((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
}

// 将报文写入文件
void writePacket(const string& filename, const vector<uint8_t>& data) {
    ofstream file(filename, ios::binary);
    if (!file) {
        throw runtime_error("无法创建文件: " + filename);
    }
    file.write(reinterpret_cast<const char*>(data.data()), data.size());  
    
}

// 打印字节流（用于调试）
void printPacket(const vector<uint8_t>& data) {
    for (size_t i = 0; i < data.size(); ++i) {
        cout << hex << setw(2) << setfill('0') << static_cast<int>(data[i]) << " ";
        if ((i + 1) % 16 == 0) {
            cout << endl;
        }
    }
    cout << endl;
}

// 主函数
int main() {
    // 示例报文（IP 头部，无校验和）
    vector<uint8_t> packet = {
        0x45, 0x00, 0x00, 0x3c, 0x1c, 0x46, 0x40, 0x00, 0x40, 0x06,
        0x00, 0x00, // 校验和占位符
        0xc0, 0xa8, 0x01, 0x68, 0xc0, 0xa8, 0x01, 0x01
    };
    // 计算校验和
    uint16_t checksum = calculateChecksum(packet);
    cout << "计算出的校验和: 0x" << hex << checksum << endl;

    // 插入校验和
    packet[10] = checksum >> 8;       // 高字节
    packet[11] = checksum & 0xFF;    // 低字节

    cout << "插入校验和后的报文: " << endl;
    printPacket(packet);

    // 校验报文
    bool isValid = verifyChecksum(packet, 0);
    cout << "校验结果: " << (isValid ? "成功" : "失败") << endl;

    // 写入文件
    writePacket("test_packet.bin", packet);
    cout << "报文已写入 test_packet.bin" << endl;

    // 从文件读取
    auto readData = readPacket("test_packet.bin");
    cout << "从文件读取的报文: " << endl;
    printPacket(readData);
    return 0;
}
