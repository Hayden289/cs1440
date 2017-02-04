//
// Created by Hayden Nielsen on 1/28/17.
//

#include <string>
#include <vector>

#include "Analyst.h"
#include "History.h"
#include "PurchaseSale.h"

Analyst::Analyst(std::string name, std::string initials, int days, int seedMoney) :
    m_name(name),
    m_initials(initials),
    m_history(days, seedMoney)
{}

std::string Analyst::getName() {
    return m_name;
}

std::string Analyst::getInitials() {
    return m_initials;
}

std::vector<std::string> Analyst::getStocks() {
    std::vector<PurchaseSale*> history = m_history.getHistory();
    std::vector<std::string> stocks;

    for (PurchaseSale* i : history) stocks.push_back(i->getSymbol());

    return stocks;
}

int Analyst::getDays() {
    return m_history.getNumDays();
}

double Analyst::getTPL() {
    return m_history.computeTPL() / 100.00;
}

int Analyst::getSeedMoney() {
    return m_history.getSeedMoney();
}

double Analyst::computeTLPD() {
    double tpl = m_history.computeTPL();
    if (m_history.getNumDays() != 0) return (tpl / m_history.getNumDays()) / 100.00;
    else return 0.0;
}

void Analyst::addPurchaseSale(std::string symbol, int quantity, int purchaseTime, int purchasePrice, int purchaseFee, int saleTime, int salePrice, int saleFee) {
    m_history.addPurchaseSale(symbol, quantity, purchaseTime, purchasePrice, purchaseFee, saleTime, salePrice, saleFee);
}

double Analyst::computeSPLPD(std::string symbol) {
    double tpl = 0;
    double firstBuy = 0;
    double lastSale = 0;
    double sid;

    for (PurchaseSale* i : m_history.getHistory()) {
        if (symbol == i->getSymbol()) {
            tpl += i->computePL();
            if (firstBuy == 0 || i->getPTime() < firstBuy) firstBuy = i->getPTime();
            if (lastSale == 0 || i->getSTime() > lastSale) lastSale = i->getSTime();
        }
    }

    sid = (lastSale - firstBuy) / 1440;

    return (tpl / sid) / 100.00;
}
