//
// Created by Stephen Clyde on 1/16/17.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <sstream>
#include "Comparer.h"
#include "FormattedTable.h"

int Comparer::load(int argv, char* argc[])
{
    if (argv<3)
    {
        std::cout << "Invalid parameters" << std::endl;
        std::cout << "usage: AnalystComparer <output file> <input file 1> <input file 2> ..." << std::endl;
        return -1;
    }

    m_outputFilename = argc[1];
    m_analystCount = argv - 2;
    // TODO: Allocate a container, like an array of pointers, to hold the analysts
    //
    // Example Code:
    // m_analysts = new Analyst*[m_analystCount];
    m_analysts = std::vector<Analyst*>();

    int analystIndex = 0;
    for (int i = 0; i < m_analystCount; i++)
    {
        std::ifstream inputStream(argc[2 + analystIndex]);

        // TODO: Create a new analyst, load it from the input stream, and put it into the container if that load succeeded
        //
        // Example code:
        // m_analysts[analystIndex] = new Analyst();
        // if (m_analysts[analystIndex]->load(inputStream) < 0)
        // {
        //     std::cout << "Failed to load " << argc[analystIndex] << std::endl;
        // }
        // else
        //      analystIndex++;
        if (!inputStream) std::cout << "Failed to load " << argc[analystIndex] << std::endl;

        std::string name;
        std::string initials;
        int days;
        int seedMoney;
        std::string symbol;
        int quantity;
        int purchaseTime;
        int purchasePrice;
        int purchaseFee;
        int saleTime;
        int salePrice;
        int saleFee;


        std::getline(inputStream, name);
        std::getline(inputStream, initials);
        inputStream >> days;
        inputStream >> seedMoney;

        Analyst* next = new Analyst(name, initials, days, seedMoney);

        m_analysts.push_back(next);

        int numRecords;
        inputStream >> numRecords;

        std::string temp;

        while (numRecords) {
            inputStream >> temp;

            std::stringstream ss(temp);

            std::getline(ss, temp, ',');
            symbol = temp;

            std::getline(ss, temp, ',');
            quantity = std::stoi(temp);

            std::getline(ss, temp, ',');
            purchaseTime = std::stoi(temp);

            std::getline(ss, temp, ',');
            purchasePrice = std::stoi(temp);

            std::getline(ss, temp, ',');
            purchaseFee = std::stoi(temp);

            std::getline(ss, temp, ',');
            saleTime = std::stoi(temp);

            std::getline(ss, temp, ',');
            salePrice = std::stoi(temp);

            ss >> temp;
            saleFee = std::stoi(temp);

            next->addPurchaseSale(symbol, quantity, purchaseTime, purchasePrice, purchaseFee, saleTime, salePrice, saleFee);
            --numRecords;
        }

        analystIndex++;
    }

    loadSymbols();

    int result = 0;
    if (analystIndex < m_analystCount)
        result = -1;

    return result;
}

int Comparer::compare() const
{
    if (m_analystCount < 2)
    {
        std::cout << "Cannot do comparison with " << m_analystCount << " analysts" << std::endl;
        return -1;
    }

    if (m_outputFilename == "")
    {
        std::cout << "Cannot do comparison because no output file is specified" << std::endl;
        return -1;
    }

    std::ofstream outputStream(m_outputFilename);
    outputInvestorNames(outputStream);
    outputOverallPerformance(outputStream);
    outputStockPerformance(outputStream);

    return 0;
}

void Comparer::loadSymbols()
{
    m_symbolsCount = 0;
    // TODO: Go through all analysts' histories and build a list of symbols used in any Purchase-Sale.
    // According to the design, every analyst has a design and a history contains purchase-sale objects.
    // Each purchase-sale object is for a symbol.
    //
    // The m_symbols array contains the list of references symbols.  The std::find methods checks to see
    // if a symbol is already in that array.  If it is not, then the result result is the std::end of the
    // the array and the symbol is array to the array.
    //
    // Example code:
    // for (int i = 0; i < m_analystCount; i++)
    // {
    //    History& history = m_analysts[i]->getHistory();
    //    history.resetIterator();
    //    const PurchaseSale* purchaseSale;
    //    while ((purchaseSale = history.nextPurchaseSale()) != nullptr)
    //    {
    //        std::string symbol = purchaseSale->getSymbol();
    //        std::string *existingSymbol = std::find(std::begin(m_symbols), std::end(m_symbols), symbol);
    //        if (existingSymbol == std::end(m_symbols)) {
    //            m_symbols[m_symbolsCount++] = symbol;
    //        }
    //    }
    // }

    for (Analyst* i : m_analysts) {
        std::vector<std::string> symbols = i->getStocks();

        for (std::string j : symbols) {
            std::string *existingSymbol = std::find(std::begin(m_symbols), std::end(m_symbols), j);
            if (*existingSymbol != j) {
                m_symbols[m_symbolsCount] = j;
                ++m_symbolsCount;
            }
        }
    }
}


void Comparer::outputInvestorNames(std::ofstream& outputStream) const
{
    // TODO: Write out investor names
    outputStream << "Investors:\n";
    for (Analyst* i : m_analysts) {
        outputStream << std::left << std::setw(10) << i->getInitials() << std::right << i->getName() << std::endl;
    }
    outputStream << std::endl;
}

void Comparer::outputOverallPerformance(std::ofstream& outputStream) const
{
    // TODO: Write out Overall Performance table.  The classes from the FormattedTable example might be helpful.
    FormattedTable performanceTable(m_analystCount, 5);

    performanceTable.addColumn(new ColumnDefinition("Analyst", 20, ColumnDefinition::String, ColumnDefinition::Center));
    performanceTable.addColumn(new ColumnDefinition("Days", 20, ColumnDefinition::Integer));
    performanceTable.addColumn(new ColumnDefinition("Seed Amount", 20, ColumnDefinition::Integer));
    performanceTable.addColumn(new ColumnDefinition("TPL", 20, ColumnDefinition::FixedPrecision, ColumnDefinition::Right, 2));
    performanceTable.addColumn(new ColumnDefinition("PLPD", 20, ColumnDefinition::FixedPrecision, ColumnDefinition::Right, 2));

    for (Analyst* i : m_analysts) {
        FormattedRow* row = new FormattedRow(&performanceTable);
        row->addCell(new FormattedCell(i->getInitials()));
        row->addCell(new FormattedCell(i->getDays()));
        row->addCell(new FormattedCell(i->getSeedMoney()));
        row->addCell(new FormattedCell((float) i->getTPL()));
        row->addCell(new FormattedCell((float) i->computeTLPD()));
        performanceTable.addRow(row);
    }

    outputStream << "Overall Performance:\n";
    performanceTable.write(outputStream);
    outputStream << std::endl;
};

void Comparer::outputStockPerformance(std::ofstream& outputStream) const
{
    // TODO: Write out Stock Performance table.  The classes from the FormattedTable example might be helpful.
    FormattedTable stocksTable(m_symbolsCount, m_analystCount + 2);

    stocksTable.addColumn(new ColumnDefinition("Symbol", 20, ColumnDefinition::String));

    for (Analyst* i : m_analysts) {
        stocksTable.addColumn(new ColumnDefinition(i->getInitials(), 20, ColumnDefinition::FixedPrecision, ColumnDefinition::Left, 2));
    }

    for (int i = 0; i < m_symbolsCount; ++i) {
        std::string symbol = m_symbols[i];
        FormattedRow* row = new FormattedRow(&stocksTable);
        row->addCell(new FormattedCell(symbol));
        for (Analyst* analyst : m_analysts) {
            row->addCell(new FormattedCell((float) analyst->computeSPLPD(symbol)));
        }
        stocksTable.addRow(row);
    }

    outputStream << "Stock Performance:\n";
    stocksTable.write(outputStream);
}
