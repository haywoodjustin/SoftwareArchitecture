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

/// <summary>
/// Test #1, tests if an order gets submitted correctly
/// </summary>
/// <param name=""></param>
/// <param name=""></param>
TEST(OrderManagerTest, TestOrderSubmition)
{
    MockOrder order;

    EXPECT_CALL(order, getItemNumber).Times(1);
    EXPECT_CALL(order, setStatus).Times(1);

    OrderManager om(&order);

    om.submitOrder();

}
/// <summary>
/// Test #2, tests if customers are created correctly
/// </summary>
/// <param name=""></param>
/// <param name=""></param>
TEST(OrderManagerTest, TestCustomerCreation)
{
    MockOrder order;

    EXPECT_CALL(order, setCustomerName).Times(1);
    EXPECT_CALL(order, setCustomerAddress).Times(1);

    OrderManager om(&order);

    om.createCustomer("John Doe", "123 Park Ave.");

}