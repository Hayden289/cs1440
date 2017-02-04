//
// Created by Hayden Nielsen on 1/28/17.
//

#include <string>
#include <iostream>

#include "PurchaseSale.h"

PurchaseSale::PurchaseSale(std::string symbol, int quantity, int purchaseTime, int purchasePrice, int purchaseFee, int saleTime, int salePrice, int saleFee) :
    m_symbol(symbol),
    m_quantity(quantity),
    m_purchaseTime(purchaseTime),
    m_purchasePrice(purchasePrice),
    m_purchaseFee(purchaseFee),
    m_saleTime(saleTime),
    m_salePrice(salePrice),
    m_saleFee(saleFee)
{}

double PurchaseSale::computePL() {
    double inv = (m_quantity * m_purchasePrice) + m_purchaseFee + m_saleFee;

    return (m_quantity * m_salePrice) - inv;
}

std::string PurchaseSale::getSymbol() {
    return m_symbol;
}

int PurchaseSale::getPTime() {
    return m_purchaseTime;
}

int PurchaseSale::getSTime() {
    return m_saleTime;
}