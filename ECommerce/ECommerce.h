#ifndef _ECOMMERCE_H_
#define _ECOMMERCE_H_

#include "./../Database/Database.h"

class ECommerce
{
public:
    static ECommerce* getInstance ();
    static void releaseInstance ();

    template <typename type> 
    bool isUserNameTaken (const std::string&, const std::vector<type*>&);

    // Add/SignUp functions
    template <typename type>
    void addUser (const std::string&, type*, std::vector<type*>&); // template function to add a new user
    void addBuyer (Buyer* b);
    void addSeller (Seller* p);
    void addAdmin (Admin* a);

    // Remove 
    template <typename type>
    bool removeUser (const std::string&, const std::string&, std::vector<type*>&); // template function to remove a user
    bool removeSeller (const std::string& userName);
    bool removeBuyer (const std::string& userName);
    bool removeAdmin (const std::string& userName);

    // Login functions
    template <typename type>
    type* isLoggedIn (const std::string&, const std::string&, std::vector<type*>); // template function to login
    Buyer* isBuyerLoggedIn (const std::string&, const std::string&);
    Seller* isSellerLoggedIn (const std::string&, const std::string&);
    Admin* isAdminLoggedIn (const std::string&, const std::string&);

    
    void signUp();
    Admin* adminSignUp (const std::string&, const std::string&, const std::string&, const std::string&);
    Buyer* buyerSignUp (const std::string&, const std::string&, const std::string&, const std::string&);
    Seller* sellerSignUp (const std::string&, const std::string&, const std::string&, const std::string&);

    template <typename T>
    void inputCredentials ( std::string&, std::string&, std::string&, std::string&, const std::vector<T*>&);

    void loadData () { 
        Database :: getInstance()->loadAdmins(admins);
        Database :: getInstance()->loadBuyers(buyers);
        Database :: getInstance()->loadSellers(sellers);
    }

private:

    ECommerce() = default;
    ~ECommerce ();

    ECommerce(const ECommerce &) = delete;
    std::vector<Buyer *> buyers;
    std::vector<Seller *> sellers;
    std::vector<Admin *> admins;
};

// Global functions
void inputCredentials (std::string&, std::string&);
void login (); 

#endif // _ECOMMERCE_H_ Singleton class