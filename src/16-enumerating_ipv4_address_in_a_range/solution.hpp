#pragma once

#include <string>
#include <vector>

class IPv4Address {
public:
    static const unsigned short length{4};

    IPv4Address(const std::string& address);
    ~IPv4Address() = default;

    bool operator==(const IPv4Address& address) const;
    bool operator<(const IPv4Address& address) const;
    bool operator>(const IPv4Address& address) const;

    friend std::ostream& operator<<(std::ostream& os, const IPv4Address& obj);
    friend std::istream& operator>>(std::istream& is, IPv4Address& obj);


    void from_str(const std::string& address);
    std::string to_str() const;

private:
    static const char m_delimiter = '.';

    std::vector<std::uint8_t> m_address;
};

std::vector<std::string> split(const std::string& s, char delimiter);
