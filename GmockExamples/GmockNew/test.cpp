#include "MockOrder.h"
#include "OrderManager.h"

using ::testing::InSequence;
using ::testing::Return;
using ::testing::AtLeast;
using ::testing::_;
using ::testing::Ge;
using ::testing::StrictMock;
using ::testing::NiceMock;

class MockTest {
public:
    MOCK_METHOD(void, SomeMethod, ());
};

TEST(OrderManagerTest, TestItemOutOfStock)
{
    MockOrder order;

    EXPECT_CALL(order, getItemNumber).Times(1).WillOnce(Return(3000));
    EXPECT_CALL(order, setStatus).Times(1);

    OrderManager om(&order);

    om.submitOrder();

}

TEST(OrderManagerTest, TestOrderCreation)
{
    MockOrder order;

    EXPECT_CALL(order, setCustomerName).Times(1);
    EXPECT_CALL(order, setCustomerAddress).Times(1);

    OrderManager om(&order);

    om.createCustomer("John Doe", "123 Park Ave.");

}