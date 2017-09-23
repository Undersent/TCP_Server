//
// Created by rafal on 23.09.17.
//

#include <gmock/gmock.h>

#include "../../src/REST/RestApi_I.h"

namespace testing {
    class RestAPIMock : public RestApi_I {
    public:
        virtual ~RestAPIMock() = default;

        MOCK_METHOD0(post, void());

        MOCK_METHOD0(put, void());

        MOCK_METHOD0(deleteF, void());

        MOCK_METHOD0(get, std::string());

        MOCK_METHOD2(prepareSocketConnection, bool(
                const std::string &ipAdress,
                const int port));

        MOCK_METHOD1(setMsg, void(
                const std::string &msg));

    };

    using ::testing::AtLeast;

    TEST(MessageSameTest, canAnswerSameTextTest) {
        RestAPIMock restAPIMock;
      //  EXPECT_CALL(restAPIMock, get())
       //         .Times(AtLeast(1));
    }

}