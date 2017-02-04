cmake_minimum_required(VERSION 3.6)
project(AnalystComparer)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Utils.cpp Utils.h Comparer.cpp Comparer.h Constants.h Analyst.cpp Analyst.h History.cpp History.h PurchaseSale.cpp PurchaseSale.h FormattedCell.cpp FormattedCell.h FormattedRow.cpp FormattedRow.h FormattedTable.cpp FormattedTable.h ColumnDefinition.cpp ColumnDefinition.h)
add_executable(AnalystComparer ${SOURCE_FILES})