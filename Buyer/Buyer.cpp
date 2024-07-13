#include "Buyer.h"

Buyer ::Buyer() : User()
{
}

Buyer ::Buyer(
    const std::string &first,
    const std::string &last,
    const std::string &user_name,
    const std::string &pass) : User(first, last, user_name, pass)
{
}

/// setters
void Buyer::setCategoty(const std::vector<Categories> &)
{
    this->categories = categories;
}
void Buyer::setPreferredCategory(std::string preferredCategory)
{
    this->preferredCategory.push_back(preferredCategory);
}
void Buyer::setPreferredSubCategory(std::string &preferredSubCategory)
{
    this->preferredSubCategory.push_back(preferredSubCategory);
}
// getters
std::vector<std::string> Buyer::getPreferredCategory()
{
    return this->preferredCategory;
}
std::vector<std::string> Buyer::getPreferredSubCategory()
{
    return this->preferredSubCategory;
}

Buyer *Buyer ::fromJson(json &j)
{
    return new Buyer(j["firstName"], j["lastName"], j["userName"], j["password"]);
}
// setter
void Buyer ::setCategoty(const std::vector<Categories> &categories)
{
    this->categories = categories;
}
// selecting the categories and subcategories
void Buyer::selectCategory()
{
    int count = 0, exit = 0, inputCheck = 0;
    std::vector<int> cat;
    do
    {
        //displaying only unselected categories 
        for (int i = 0; i < categories.size(); i++)
        {
            if (isCategoryPresent(categories[i].getCategory()))
            {
                continue;
            }
            inputCheck++;
            categories[i].displayCategories();
            cat.push_back(i);
        }
        //checking if all categories are selected or not

        if(inputCheck!=0){
        int choice;
        bool flag = false;
        do
        {
            //taking input of desired category
            std::cout << "Enter the category number you are interested in: ";
            std::cin >> choice;
            for (int h = 0; h < cat.size(); h++)
            {
                //checking if selected category is valid or not
                if (cat[h] == (choice - 1))
                {
                    flag = true;
                    setPreferredCategory(categories[choice - 1].getCategory());
                    cat.erase(cat.begin() + h);
                    break;
                }
            }
            if (!flag)
            {
                std::cout << "Invalid choice. Please try again!" << std::endl;
            }
        } while (!flag);
        std::cout << "Enter positive integer to continue selecting the categories and negative integer to stop : ";
        std::cin >> exit;
        count++;
        }
        else{
            std:: cout<<" You have already selected all of the categories.";
            break;
        }
    } while (count != 7 || exit > 0);
}

void Buyer::selectSubCategory()
{

    for (size_t i = 0; i < preferredCategory.size(); i++)
    {
        Categories category("");
        int count = 0, exit = 0;
        do
        {
            std ::cout << " Category : " << preferredCategory[i];
            std::cout << " Sub Categories :-\n";
            bool check;
            std::vector<int> subCat;
            int inputCheck=0;
            //displaying only unselected subcategories
            for (size_t j = 0; j < 4; j++)
            {
                for (int h = 0; i < subCat.size(); h++)
                {
                    if (j == subCat[h])
                    {
                        check = false;
                    }
                    check = true;

                    if (!check)
                    {
                        continue;
                    }
                    inputCheck++;
                    Categories category("");
                    category = findCategory(preferredCategory[i]);
                    std::cout << j + 1 << ". " << category.getSubCategory()[j] << std::endl;
                }
            }
            //checking if all subcategories are selected or not
            if(inputCheck!=0)
            {
            int choice;
            bool flag = false;
            do
            {
                //taking input of desired  sub category
                std::cout << "Enter the sub-category you want to select :";
                std::cin >> choice;
                for (int k = 0; k < subCat.size(); k++)
                {
                    //checking if selected sub category is valid or not
                    if ((choice - 1) == subCat[k])
                    {
                        flag = false;
                    }
                    else
                    {
                        subCat.push_back((choice - 1));
                        setPreferredSubCategory(category.getSubCategory()[(choice - 1)]);
                    }
                }
                if (!flag)
                {
                    std::cout << "Invalid choice. Please try again!" << std::endl;
                }

            } while (!flag);
            count++;
            std::cout << "Enter a positive integer to continue selecting subcategories of this category and negative integer to stop : ";
            std::cin >> exit;
            }
            else{
                std::cout <<"You have already selected all of the subcategories of this category.";
                break;
            }
        } while (count != 4 || exit > 0);
        std::cout<<"===============================================";
    }
}

Categories Buyer::findCategory(std::string category)
{
    for (size_t i = 0; i < categories.size(); i++)
    {
        if (categories[i].getCategory() == category)
        {
            return categories[i];
        }
    }
}

// checking if cattegory is already present
bool Buyer::isCategoryPresent(std::string category)
{
    for (int i = 0; i < categories.size(); i++)
    {
        if (preferredCategory[i] == category)
            return true;
    }
    return false;
}

json Buyer ::toJson()
{
    json j;
    j["firstName"] = this->firstName;
    j["lastName"] = this->lastName;
    j["userName"] = this->userName;
    j["password"] = this->password;
    return j;
}