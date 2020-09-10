#ifndef TST_TESTIROVANIE_H
#define TST_TESTIROVANIE_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <IKeypad.h>
#include <ILatch.h>
#include <lockcontroller.h>

using namespace testing;

struct MockKeypad : IKeypad
{
    MOCK_METHOD
    (
        bool,
        isActive,
        (),
        (override)
    );

    MOCK_METHOD
    (
        void,
        wait,
        (),
        (override)
    );

    MOCK_METHOD
    (
        PasswordResponse,
        requestPassword,
        (),
        (override)
    );

};


struct MockLatch : ILatch
{
    MOCK_METHOD
    (
        bool,
        isActive,
        (),
        (override)
    );

    MOCK_METHOD
    (
        DoorStatus,
        open,
        (),
        (override)
    );

    MOCK_METHOD
    (
        DoorStatus,
        close,
        (),
        (override)
    );

    MOCK_METHOD
    (
        DoorStatus,
        getDoorStatus,
        (),
        (override)
    );

};


TEST(Testing, test1)
{
    // Arrange
    const short expected_calls_number = 1;
    MockKeypad keypad;
    MockLatch latch;
    LockController controller(&keypad, &latch);

    // Prepare mocks
    EXPECT_CALL(keypad, wait())
            .Times(expected_calls_number)  // ����� wait() ������ IKeypad ����� ������ ���� ���;
            .WillOnce(Return());

    // Act
    controller.wait();

    // Assert

}


TEST(Testing, test2)
{
    // Arrange
    const short expected_calls_number = 1;
    MockKeypad keypad;
    MockLatch latch;
    LockController controller(&keypad, &latch);

    // Prepare mocks
    EXPECT_CALL(latch, getDoorStatus())
            .Times(expected_calls_number) // ����� getDoorStatus() ������ ILatch ����� ������ ���� ���;
            .WillOnce(Return(DoorStatus::CLOSE));

    // Act
    bool is_open = controller.isDoorOpen();

    // Assert
    ASSERT_FALSE(is_open); //����� isDoorOpen() ������ LockController ����� false;
}


TEST(Testing, test3)
{
    // Arrange
    const short expected_calls_number = 1;
    MockKeypad keypad;
    MockLatch latch;
    LockController controller(&keypad, &latch);

    // Prepare mocks
    EXPECT_CALL(latch, getDoorStatus())
            .Times(expected_calls_number) // ����� getDoorStatus() ������ ILatch ����� ������ ���� ���;
            .WillOnce(Return(DoorStatus::OPEN));

    // Act
    bool is_open = controller.isDoorOpen();

    // Assert
    ASSERT_TRUE(is_open); //����� isDoorOpen() ������ LockController ����� true;
    //ASSERT_EQ(calls_number, expected_calls_number); //����� getDoorStatus() ������ ILatch ����� ������ ���� ���;
}


TEST(Testing, test4)
{
    // Arrange
    const short expected_calls_number = 1;
    MockKeypad keypad;
    MockLatch latch;
    LockController controller(&keypad, &latch);

    // Prepare mocks
    EXPECT_CALL(latch, open())
            .Times(expected_calls_number) // ����� open() ������ ILatch ����� ������ ���� ���;
            .WillOnce(Return(DoorStatus::OPEN));

    // Act
    DoorStatus door_status_test = controller.unlockDoor();

    // Assert
    ASSERT_EQ(DoorStatus::OPEN, door_status_test); //����� unlockDoor() ������ LockController ����� DoorStatus::OPEN;
}


TEST(Testing, test5)
{
    // Arrange
    const short expected_calls_number = 1;
    MockKeypad keypad;
    MockLatch latch;
    LockController controller(&keypad, &latch);

    // Prepare mocks
    EXPECT_CALL(latch, close())
            .Times(expected_calls_number) // ����� open() ������ ILatch ����� ������ ���� ���;
            .WillOnce(Return(DoorStatus::CLOSE));

    // Act
    DoorStatus door_status_test = controller.unlockDoor();

    // Assert
    ASSERT_EQ(DoorStatus::CLOSE, door_status_test); //����� unlockDoor() ������ LockController ����� DoorStatus::OPEN;
}


TEST(Testing, test6)
{
    // Arrange
    const short expected_calls_number = 1;
    MockKeypad keypad;
    MockLatch latch;
    LockController controller(&keypad, &latch);

    // Prepare mocks
    EXPECT_CALL(keypad, isActive())
            .Times(expected_calls_number) //  ����� isActive() ������ IKeypad ����� ������ ���� ���;
            .WillOnce(Return(true));

    EXPECT_CALL(latch, isActive())
            .Times(expected_calls_number) //  ����� isActive() ������ ILatch ����� ������ ���� ���;
            .WillOnce(Return(true));

    // Act
    HardWareStatus hard_ware_status = controller.hardWareCheck();

    // Assert
    ASSERT_EQ(HardWareStatus::OK, hard_ware_status); //����� hardWareCheck() ������ LockController ����� HardWareStatus::OK;
}

TEST(Testing, test7)
{
    // Arrange
    MockKeypad keypad;
    MockLatch latch;
    LockController controller(nullptr, &latch);

    // Prepare mocks
    EXPECT_CALL(keypad, isActive())
            .Times(AtLeast(0)) //  ����� isActive() ������ IKeypad ����� ������ ���� ��� ����� ���;
            .WillOnce(Return(true));

    EXPECT_CALL(latch, isActive())
            .Times(AtLeast(0)) //  ����� isActive() ������ ILatch ����� ������ ���� ��� ����� ���;
            .WillOnce(Return(true));

    // Act
    HardWareStatus hard_ware_status = controller.hardWareCheck();

    // Assert
    ASSERT_EQ(HardWareStatus::ERROR, hard_ware_status); //����� hardWareCheck() ������ LockController ����� HardWareStatus::ERROR;

}


TEST(Testing, test8)
{
    // Arrange
    MockKeypad keypad;
    MockLatch latch;
    LockController controller(&keypad, &latch);

    // Prepare mocks
    EXPECT_CALL(keypad, isActive())
            .Times(AtLeast(0)) //  ����� isActive() ������ IKeypad ����� ������ ���� ��� ����� ���;
            .WillOnce(Return(true));

    EXPECT_CALL(latch, isActive())
            .Times(AtLeast(0)) //  ����� isActive() ������ ILatch ����� ������ ���� ��� ����� ���;
            .WillOnce(Return(false));

    // Act
    HardWareStatus hard_ware_status = controller.hardWareCheck();

    // Assert
    ASSERT_EQ(HardWareStatus::ERROR, hard_ware_status); //����� hardWareCheck() ������ LockController ����� HardWareStatus::ERROR;
}


TEST(Testing, test9)
{
    // Arrange
    const short expected_calls_number = 1;
    MockKeypad keypad;
    MockLatch latch;
    LockController controller(&keypad, &latch);

    PasswordResponse user_input;
    user_input.status = PasswordResponse::Status::OK;
    user_input.password = "0000";  //������������ ������ ���������� ������


    // Prepare mocks
    EXPECT_CALL(keypad, requestPassword())
            .Times(expected_calls_number) //����� requestPassword() ������ IKeypad ����� ������ ���� ���;
            .WillOnce(Return(user_input));

    // Act
    bool correct_password = controller.isCorrectPassword();

    // Assert
    ASSERT_TRUE(correct_password); //����� isCorrectPassword() ������ LockController ����� true;
}

TEST(Testing, test10)
{
    // Arrange
    const short expected_calls_number = 1;
    MockKeypad keypad;
    MockLatch latch;
    LockController controller(&keypad, &latch);

    PasswordResponse user_input;
    user_input.status = PasswordResponse::Status::OK;
    user_input.password = "1111"; // ������������ ������ �� ���������� ������


    // Prepare mocks
    EXPECT_CALL(keypad, requestPassword())
            .Times(expected_calls_number) // ����� requestPassword() ������ IKeypad ����� ������ ���� ���;
            .WillOnce(Return(user_input));

    // Act
    bool correct_password = controller.isCorrectPassword();

    // Assert
    ASSERT_FALSE(correct_password); // ����� requestPassword() ������ IKeypad ����� ������ ���� ���;
}


TEST(Testing, test11)
{
    // Arrange
    MockKeypad keypad;
    MockLatch latch;
    LockController controller(&keypad, &latch);

    PasswordResponse user_input_old;
    user_input_old.status = PasswordResponse::Status::OK;
    user_input_old.password = "0000";  //������������ ������ ���������� ������ ������

    PasswordResponse user_input_new;
    user_input_new.status = PasswordResponse::Status::OK;
    user_input_new.password = "1111";  // ������������ ������ ����� ������


    // Prepare mocks
    EXPECT_CALL(keypad, requestPassword())
            .Times(3)                            // ���������, ��� � ������������ ������� ������ ������ ���-�� ���
            .WillOnce(Return(user_input_old))   // ������������ ������ ���������� ������ ������
            .WillOnce(Return(user_input_new))   // ������������ ������ ����� ������
            .WillOnce(Return(user_input_new)); // ���� ��� �������� ������ ������

    // Act
    controller.resetPassword();
    bool correct_password = controller.isCorrectPassword(); // ��������� �� ������������ ����� ������

    // Assert
    ASSERT_TRUE(correct_password); // ��������� �� ������������ ����� ������
}

TEST(Testing, test12)
{
    // Arrange
    MockKeypad keypad;
    MockLatch latch;
    LockController controller(&keypad, &latch);

    PasswordResponse user_input_old;
    user_input_old.status = PasswordResponse::Status::OK;
    user_input_old.password = "0000";  //������������ ������ ���������� ������ ������

    PasswordResponse user_input_new;
    user_input_new.status = PasswordResponse::Status::OK;
    user_input_new.password = "9876";  // ������������ ������ ����� ������


    // Prepare mocks
    EXPECT_CALL(keypad, requestPassword())
            .Times(4)                            // ���������, ��� � ������������ ������� ������ ������ ���-�� ���
            .WillOnce(Return(user_input_old))
            .WillOnce(Return(user_input_new))    //������ ������ �� 9876
            .WillOnce(Return(user_input_old))
            .WillOnce(Return(user_input_new)) ;   // ����� ������ ������ � ��������� ��� �� ������������


    // Act
    controller.resetPassword();
    user_input_old.password = user_input_new.password;
    user_input_new.password = "1111";
    controller.resetPassword();

     // ��������� �� ������������ ����� ������
    bool correct_password = controller.isCorrectPassword();

    // Assert
    ASSERT_TRUE(correct_password); // ��������� �� ������������ ����� ������
}


#endif // TST_TESTIROVANIE_H
