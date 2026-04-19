#pragma once
#include "Table.h"
#include "CSVExporter.h"
#include "ABettingStrategy.h"
#include <string>
#include <vector>
#include <memory>
#include <functional>

using StrategyFactory = std::function<std::unique_ptr<ABettingStrategy>()>;
struct SimulationEngine {

    SimulationEngine(int totalRounds, double initialBankroll,
                     double baseBet,  double maxBet);


    void addStrategy(std::string const& name, StrategyFactory factory);

    void run();

    bool exportCSV(std::string const& filename) const;

private:
    int    totalRounds;
    double initialBankroll;
    double baseBet;
    double maxBet;

    std::vector<std::pair<std::string, StrategyFactory>>       strategies;

    std::vector<std::pair<std::string, std::vector<RoundRecord>>> results;

    std::vector<RoundRecord> runOne(StrategyFactory& factory);
};
