//
// Created by Hayden Nielsen on 1/28/17.
//

#ifndef ANALYSTCOMPARER_HISTORY_H
#define ANALYSTCOMPARER_HISTORY_H

#include <vector>

#include "PurchaseSale.h"

class History {
private:
    int m_numDays;
    int m_seedMoney;
    std::vector<PurchaseSale*> m_history;

public:
    History(int days, int seedMoney);
    int getNumDays();
    int getSeedMoney();
    std::vector<PurchaseSale*> getHistory();
    double computeTPL();
    void addPurchaseSale(std::string symbol, int quantity, int purchaseTime, int purchasePrice, int purchaseFee, int saleTime, int salePrice, int saleFee);
};


#endif //ANALYSTCOMPARER_HISTORY_H
