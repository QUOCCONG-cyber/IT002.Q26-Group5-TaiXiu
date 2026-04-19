#include "../include/CSVExporter.h"
#include <fstream>

using namespace std;

/*
 * @brief Constructor — lưu tên file để dùng khi ghi CSV
 *
 * Ví dụ: CSVExporter exporter("results.csv")
 * → sFilename = "results.csv", dùng cho tất cả lần ghi sau đó
 */
CSVExporter::CSVExporter(const string& filename) : sFilename(filename) {}

/*
 * @brief Ghi danh sách kết quả 1 chiến thuật vào file CSV
 *
 * Dùng ios::app để append — nhiều chiến thuật ghi nối tiếp vào cùng 1 file
 * mà không ghi đè nhau. writeHeader chỉ true cho chiến thuật đầu tiên.
 *
 * @param strategyName Tên chiến thuật — xuất hiện ở cột Strategy trong CSV
 * @param records      Danh sách RoundRecord chứa kết quả từng ván
 * @param writeHeader  true → ghi dòng header (chỉ dùng cho chiến thuật đầu tiên)
 */
void CSVExporter::exportToCSV(const string& strategyName,
                               const vector<RoundRecord>& records,
                               bool writeHeader) { // default = false đã khai báo trong .h
    // writeHeader=true → tạo file mới (ios::out), false → ghi nối tiếp (ios::app)
    ofstream file(sFilename, writeHeader ? ios::out : ios::app);
    if (!file.is_open()) return;

    // Chỉ ghi header 1 lần duy nhất cho toàn bộ file
    if (writeHeader)
        file << "Strategy,Round,BetSide,BetAmount,Result,Bankroll\n";

    // Ghi từng ván — round đếm từ 1
    int round = 1;
    for (const auto& r : records) {
        file << strategyName                                       << ","
             << round++                                           << ","
             << (r.bet.type == BetType::Xiu ? "Xiu" : "Tai")     << ","
             << r.bet.dAmount                                     << ","
             << (r.result == BetResult::Win ? "Win" : "Lose")    << ","
             << r.dCurrentBankroll                                << "\n";
    }
}
