#if !defined(_CATEGORIES_H_)
#define _CATEGORIES_H_
#include <iostream>
#include "vector"
class Categories
{

private:
    // categories and subcategories
    std::string category;
    std::vector<std::string> subCategory;

public:
    // constructor and destructor
    Categories(std::string category);
    ~Categories();

    // getters
    std::string getCategory();
    std::vector<std::string> getSubCategory();
    // display categories and subcategories
    void displayCategories();
    void displaySubCategories();
};

#endif // _CATEGORIES_H_
