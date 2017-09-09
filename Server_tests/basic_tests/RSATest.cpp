//
// Created by rafal on 08.09.17.
//
#include "gtest/gtest.h"
#include "../../AlgAndDataStructures/RSA.h"
#include "../../AlgAndDataStructures/RSA.cpp"
namespace RSA {


    TEST(RSATest, GCDTest){
        RSA rsa;
        ASSERT_EQ(rsa.GCD(36, 31752),36);
        ASSERT_EQ(rsa.GCD(37, 31752),1);
    }

    TEST(RSATest, EuclideadAlgTest){
        RSA rsa;
        ASSERT_EQ(rsa.extendedEuclideanModulo(7, 5),3);
    }



    TEST(RSATest, decryptingCharTest) {
        RSA rsa;
        RSA rsa1(rsa.get_module(), rsa.get_publicKey());
        rsa.set_converserPublicKey(rsa1.get_publicKey());
        //rsa.set_converserPublicKey(rsa1.get_publicKey());//public key exchange
        //rsa1.set_converserPublicKey(rsa.get_publicKey());
       /* std::cerr << "rsa public = " << rsa.get_publicKey() << std::endl;
        std::cerr << "rsa private = " << rsa._privateKey << std::endl;
        std::cerr << "rsa modul = " << rsa._module << std::endl;
        std::cerr << "rsa1 public = " << rsa1.get_publicKey() << std::endl;
        std::cerr << "rsa1 private = " << rsa1._privateKey << std::endl;
        std::cerr << "rsa1 modul = " << rsa1._module << std::endl; */
        long cipher = rsa.encrypt(30);//216
        ASSERT_EQ(rsa1.decrypt(cipher),30);
    }

    TEST(RSATest, decryptingMessageTest){
        RSA rsa;
        RSA rsa1(rsa.get_module(), rsa.get_publicKey());
        rsa.set_converserPublicKey(rsa1.get_publicKey());

        //std::cerr << "message = " << codedMessage << std::endl;
        std::vector<long> text{};
        text.push_back('a');
        text.push_back('b');
        text.push_back('c');
        ASSERT_EQ(rsa1.decryptString(rsa.encryptString(text)).front(), 'a');
    }
}