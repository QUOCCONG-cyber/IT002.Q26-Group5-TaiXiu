/* SCOPED enum */
enum class BetType { Tai, Xiu };
enum class BetResult { Win, Lose };

/**/
struct Bet {
  private:
    BetType type;
    double dAmount;
};

/**/
struct ABettingStrategy {
    virtual Bet calNextBet(BetResult const &) = 0;
    void reset();

  protected:
    double dBaseBet, dCurrentBet;
};
