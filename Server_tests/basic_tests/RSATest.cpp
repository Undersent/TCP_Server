//
// Created by rafal on 08.09.17.
//
#include "gtest/gtest.h"
#include "../../AlgAndDataStructures/RSA.h"
#include "../../AlgAndDataStructures/RSA.cpp"

    class RSATest : public ::testing::Test {
    public:
        RSA rsa;
        RSATest() = default;
        virtual ~RSATest()  = default;

        void SetUp() override{
        }

        void TearDown() override{
        }
    };

    TEST_F(RSATest, GCDTest){
        long number36{36}, number31752{31752}, number37{37};
        ASSERT_EQ(rsa.GCD(number36, number31752),36);
        ASSERT_EQ(rsa.GCD(number37, number31752),1);
    }

    TEST_F(RSATest, EuclideadAlgTest){
        long number7{7}, number5{5};
        ASSERT_EQ(rsa.extendedEuclideanModulo(number7, number5),3);
    }



    TEST_F(RSATest, decryptingCharTest) {
        RSA rsa1(rsa.get_module(), rsa.get_publicKey());
        long number30{30}, number45{45};
        rsa.set_converserPublicKey(rsa1.get_publicKey());
        long cipher = rsa.encrypt(number30);//216
        ASSERT_EQ(rsa1.decrypt(cipher),30);
        cipher = rsa1.encrypt(number45);
        ASSERT_EQ(rsa.decrypt(cipher),45);
    }

    TEST_F(RSATest, decryptingMessageTest){
        RSA rsa1(rsa.get_module(), rsa.get_publicKey());
        rsa.set_converserPublicKey(rsa1.get_publicKey());
        std::vector<long> text{};
        text.push_back('a');
        text.push_back('b');
        text.push_back('c');
        ASSERT_EQ(rsa1.decryptString(rsa.encryptString(text)).front(), 'a');
    }

    TEST_F(RSATest, decryptingWholeMessage){
        RSA rsa1(rsa.get_module(), rsa.get_publicKey());
        rsa.set_converserPublicKey(rsa1.get_publicKey());
        ASSERT_EQ(rsa.decryptString(rsa.encryptString("b")),"b");
        ASSERT_EQ(rsa.decryptString(rsa.encryptString("bAcd.")),"bAcd.");
        ASSERT_EQ(rsa.decryptString(rsa.encryptString("b A cd.")),"b A cd.");
    }


