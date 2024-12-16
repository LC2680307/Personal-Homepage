#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <stdlib.h>

// width of normal column and the row index column
const int DEFAULT_COLUMN_WIDTH = 7;
const int DEFAULT_ROW_IDX_WIDTH = 4;

// forward declaration of derived classes
class NumberSpreadSheetCell;
class StringSpreadSheetCell;

// types of spreadsheet cells
enum CellType { Number, String };

// The base SpreadSheetCell class 
class SpreadSheetCell
{
public:
    // constructors and destructors.
    SpreadSheetCell();
    ~SpreadSheetCell();

    // output the content of cell
    friend std::ostream& operator<<(std::ostream& os, const SpreadSheetCell& cell);

    // comparsion between two cells
    virtual bool operator<(const SpreadSheetCell& that) const;

    // get the type of this cell, returns either CellType::Number or CellType::String
    CellType GetType() const;

protected:
    CellType m_type; // stores the type of the cell (either CellType::Number or CellType::String)
};


// The `NumberSpreadSheetCell` class, which content is a double
class NumberSpreadSheetCell : public SpreadSheetCell
{
    // Your own implementation here
    
};


// The `StringSpreadSheetCell` class, which content is a string
class StringSpreadSheetCell : public SpreadSheetCell
{
    // Your own implementation here

};



class SpreadSheet 
{
public:
    // constructors and destructors
    SpreadSheet(int rows, int cols);
    ~SpreadSheet();

    // "hide" a row or column in this sheet, hidden row or column 
    // will not be shown in "ExportSheet" function
    void HideRow(int row);
    void HideColumn(int col);

    // re-show a hidden row or column in this sheet.
    // If the given row is not hidden, this does nothing.
    void ShowRow(int row);
    void ShowColumn(int col);

    // set a the pointer at (row, col) to `cell`, 
    // if there is already be a cell, delete it and reset it to `cell`
    void UpdateCell(int row, int col, SpreadSheetCell* cell);

    /* print the sheet to the ostream `os`. You may assume that `os' is std::cout.
     * Each column has width = DEFAULT_COLUMN_WIDTH
     * It's guaranteed that length of all cell contents are less than DEFAULT_COLUMN_WIDTH
     * The width of the column of ROW INDEX has width = DEFAULT_ROW_IDX_WIDTH
     * row index and column index are all ints which starts from 1.
     * If your implementation is correct, the output of given "main" function will be similar to:
     *     |      1      2      3      4
     * ---------------------------------
     *    1|  0.658   qufk    vry   3.43
     *    2|     ld   fdkr    omx  0.892
     *    3|    mlg   uqpb   4.91      r
     *    4|   wneo   4.49   atdh   itbf
     */
    void ExportSheet(std::ostream& os);

    // PROBLEM 3: Sort all rows by the value in `col`, in accending order, and number < string < nullptr.
    void SortByColumn(int col);

private:
    std::vector<std::vector<SpreadSheetCell*>> m_cells;
    // Add your own private variables and functions here
};

// PROBLEM 3: A functor class for sorting. It should have an operator() that takes 2 parameters.
class ColumnComparator 
{

};

SpreadSheet::SpreadSheet(int rows, int cols)
{

}

SpreadSheet::~SpreadSheet()
{

}

void SpreadSheet::HideRow(int row)
{

}

void SpreadSheet::HideColumn(int col)
{

}

void SpreadSheet::ShowRow(int row)
{

}

void SpreadSheet::ShowColumn(int col)
{

}

void SpreadSheet::UpdateCell(int row, int col, SpreadSheetCell* cell)
{

}

void SpreadSheet::ExportSheet(std::ostream& os)
{

}

void SpreadSheet::SortByColumn(int col)
{

}

int main()
{
    srand(0);
    SpreadSheet sheet(4, 4);
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            if (rand() < 0.5f * RAND_MAX)
                sheet.UpdateCell(i, j, new NumberSpreadSheetCell((double)rand() / double(RAND_MAX) * 5.0f));
            else 
            {
                std::string s;
                for(int k = 0; k < 1 + rand()%5; k++)
                    s += ('a' + rand() % 26);
                sheet.UpdateCell(i, j, new StringSpreadSheetCell(s));
            }
        }
    }
    sheet.ExportSheet(std::cout);
}
