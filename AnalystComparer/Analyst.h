//
// Created by Hayden Nielsen on 1/28/17.
//

#ifndef ANALYSTCOMPARER_ANALYST_H
#define ANALYSTCOMPARER_ANALYST_H

#include <string>
#include <vector>

#include "History.h"

class Analyst {
private:
    std::string m_name;
    std::string m_initials;
    History m_history;

public:
    Analyst(std::string name, std::string initials, int days, int seedMoney);
    std::string getName();
    std::string getInitials();
    std::vector<std::string> getStocks();
    double computeTLPD();
    double computeSPLPD(std::string symbol);
    int getDays();
    double getTPL();
    int getSeedMoney();
    void addPurchaseSale(std::string symbol, int quantity, int purchaseTime, int purchasePrice, int purchaseFee, int saleTime, int salePrice, int saleFee);
};


#endif //ANALYSTCOMPARER_ANALYST_H
