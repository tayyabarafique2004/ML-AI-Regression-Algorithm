#include<iostream>
#include<string>
using namespace std;
int main()
{
    cout<<"hello\nhhhhh";
 system("pause");
    return 0;
}






// #include <iostream>
// #include <openssl/sha.h>
// #include <iomanip>
// #include <sstream>

// std::string sha256(const std::string& input) {
//     unsigned char hash[SHA256_DIGEST_LENGTH];
//     SHA256(reinterpret_cast<const unsigned char*>(input.c_str()), input.size(), hash);
    
//     std::stringstream ss;
//     for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
//         ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
//     }
//     return ss.str();
// }

// int main() {
//     std::string password = "MySecurePassword";
//     std::string hashedPassword = sha256(password);

//     std::cout << "Password: " << password << std::endl;
//     std::cout << "Hash: " << hashedPassword << std::endl;

//     return 0;
// }
