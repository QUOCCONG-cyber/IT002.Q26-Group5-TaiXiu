#ifndef I_BETTING_STRATEGY_H
#define I_BETTING_STRATEGY_H

class IBettingStrategy
{
public:
    // Destructor ảo là bắt buộc trong C++ OOP để hệ thống dọn dẹp bộ nhớ an toàn (tránh memory leak)
    virtual ~IBettingStrategy() = default;

    // Các hàm thuần ảo (= 0) ép buộc các class chiến thuật con phải tự viết logic chi tiết

    // 1. Hàm tính toán số tiền cần cược cho ván tiếp theo
    // Biến lastBetWon (true = thắng, false = thua) giúp thuật toán biết nên nhân đôi hay giữ nguyên tiền
    virtual double calculateNextBetAmount(bool lastBetWon) = 0;

    // 2. Hàm quyết định đặt cửa nào (Ví dụ quy ước: 0 là Xỉu, 1 là Tài)
    virtual int determineBetSide() = 0;

    // 3. Hàm đưa chiến thuật về trạng thái xuất phát (reset mức cược về min bet)
    virtual void resetStrategy() = 0;
};

#endif // I_BETTING_STRATEGY_H