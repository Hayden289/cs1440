//
// Created by Hayden Nielsen on 1/28/17.
//

#ifndef ANALYSTCOMPARER_PURCHASESALE_H
#define ANALYSTCOMPARER_PURCHASESALE_H

#include <string>

class PurchaseSale {
private:
    std::string m_symbol;
    int m_quantity;
    int m_purchaseTime;
    int m_purchasePrice;
    int m_purchaseFee;
    int m_saleTime;
    int m_salePrice;
    int m_saleFee;

public:
    PurchaseSale(std::string symbol, int quantity, int purchaseTime, int purchasePrice, int purchaseFee, int saleTime, int salePrice, int saleFee);
    double computePL();
    int getPTime();
    int getSTime();
    std::string getSymbol();
};


#endif //ANALYSTCOMPARER_PURCHASESALE_H
