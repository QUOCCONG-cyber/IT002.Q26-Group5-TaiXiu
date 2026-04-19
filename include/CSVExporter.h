#pragma once
#include <string>
#include <vector>
#include "RoundRecord.h"
using namespace std;

class CSVExporter {
    string sFilename; 

public:
 
    CSVExporter(const string& filename);

    void exportToCSV(const string& strategyName,
                     const vector<RoundRecord>& records,
                     bool writeHeader = false);
};
