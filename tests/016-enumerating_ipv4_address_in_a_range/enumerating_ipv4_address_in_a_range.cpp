#include "enumerating_ipv4_address_in_a_range/IPv4Address.hpp"

#include <gmock/gmock.h>

using namespace testing;

TEST(IPv4Address, GetsAddressWithDots)
{
    IPv4Address ipv4_address("192.168.9.21");
    ASSERT_STREQ(ipv4_address.to_str().c_str(), "192.168.9.21");
}

TEST(IPv4Address, GetsAddressAsStream)
{
    IPv4Address ipv4_address("0.0.0.0");
    std::stringstream address;
    address << "127.0.0.1";
    address >> ipv4_address;
    ASSERT_STREQ(ipv4_address.to_str().c_str(), "127.0.0.1");
}

TEST(IPv4Address, 0_0_1_0IsNotLessThan0_0_1_0)
{
    IPv4Address address_1("0.0.1.0");
    IPv4Address address_2("0.0.1.0");
    ASSERT_FALSE(address_1 < address_2);
}

TEST(IPv4Address, 0_0_0_0IsLessThan0_0_0_1)
{
    IPv4Address address_1("0.0.0.0");
    IPv4Address address_2("0.0.0.1");
    ASSERT_TRUE(address_1 < address_2);
}

TEST(IPv4Address, 0_0_0_1IsLessThan0_0_1_0)
{
    IPv4Address address_1("0.0.0.1");
    IPv4Address address_2("0.0.1.0");
    ASSERT_TRUE(address_1 < address_2);
}

TEST(IPv4Address, 0_0_1_0IsLessThan0_1_0_0)
{
    IPv4Address address_1("0.0.1.0");
    IPv4Address address_2("0.1.0.0");
    ASSERT_TRUE(address_1 < address_2);
}

TEST(IPv4Address, 0_255_0_0IsLessThan1_0_0_127)
{
    IPv4Address address_1("0.255.0.0");
    IPv4Address address_2("1.0.0.127");
    ASSERT_TRUE(address_1 < address_2);
}

TEST(IPv4Address, 0_0_255_0IsEqualTo0_0_255_0)
{
    IPv4Address address_1("0.0.255.0");
    IPv4Address address_2("0.0.255.0");
    ASSERT_TRUE(address_1 == address_2);
}

TEST(IPv4Address, 0_0_0_1IsGreaterThan0_0_0_0)
{
    IPv4Address address_1("0.0.0.1");
    IPv4Address address_2("0.0.0.0");
    ASSERT_TRUE(address_1 > address_2);
}

TEST(IPv4Address, 0_0_1_0IsGreaterThan0_0_0_1)
{
    IPv4Address address_1("0.0.1.0");
    IPv4Address address_2("0.0.0.1");
    ASSERT_TRUE(address_1 > address_2);
}

TEST(IPv4Address, 0_1_0_0IsGreaterThan0_0_1_0)
{
    IPv4Address address_1("0.1.0.0");
    IPv4Address address_2("0.0.1.0");
    ASSERT_TRUE(address_1 > address_2);
}

TEST(IPv4Address, 1_0_0_127IsGreaterThan0_255_0_0)
{
    IPv4Address address_1("1.0.0.127");
    IPv4Address address_2("0.255.0.0");
    ASSERT_TRUE(address_1 > address_2);
}

TEST(IPv4Address, DISABLED_ReturnsAddressesBetween0_0_0_0And0_0_0_1) {}
