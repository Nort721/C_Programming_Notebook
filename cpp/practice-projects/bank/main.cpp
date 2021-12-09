#include "iostream"
#include "account.cpp"

int main(int argc, char const *argv[])
{
    account *accs = new account[8];

    *(accs+0) = account("nort", 101);
    *(accs+1) = account("top", 82);

    for (int i = 0; i < sizeof(accs); i++)
    {
        account *acc_ptr = (accs+i);
        if (acc_ptr)
        {
            std::cout << "username[" << i << "]: " << acc_ptr->getUsername() << std::endl;
        }
    }

    return 0;
}