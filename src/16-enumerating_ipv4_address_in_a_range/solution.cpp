#include "solution.hpp"
#include <algorithm>
#include <exception>
#include <sstream>

#include <iostream>

std::vector<std::string> split(const std::string& s, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream token_stream(s);
    while (std::getline(token_stream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

IPv4Address::IPv4Address(const std::string& address)
{
    from_str(address);
}

bool IPv4Address::operator==(const IPv4Address& address) const
{
    for (auto i = 0U; i < IPv4Address::length; ++i) {
        if (m_address[i] != address.m_address[i])
            return false;
    }
    return true;
}

bool IPv4Address::operator<(const IPv4Address& address) const
{
    for (auto i = IPv4Address::length - 1U; i != 0; --i) {
        if (m_address[i] < address.m_address[i])
            return true;
    }
    return false;
}

bool IPv4Address::operator>(const IPv4Address& address) const
{
    for (auto i = IPv4Address::length - 1U; i != 0; --i) {
        if (m_address[i] > address.m_address[i])
            return true;
    }
    return false;
}

std::ostream& operator<<(std::ostream& os, const IPv4Address& obj)
{
    os << obj.to_str();
    return os;
}

std::istream& operator>>(std::istream& is, IPv4Address& obj)
{
    std::string address;
    is >> address;
    obj.from_str(address);
    return is;
}

void IPv4Address::from_str(const std::string& address)
{
    auto string_tokens = split(address, m_delimiter);
    if (string_tokens.size() == IPv4Address::length) {
        m_address.clear();
        std::transform(string_tokens.begin(), string_tokens.end(),
            std::back_inserter(m_address),
            [](const std::string& str) { return std::stoul(str); });
    } else {
        throw std::invalid_argument("Invalid input address.");
    }
}

std::string IPv4Address::to_str() const
{
    std::stringstream output;
    output << static_cast<int>(m_address[0]) << m_delimiter
        << static_cast<int>(m_address[1]) << m_delimiter
        << static_cast<int>(m_address[2]) << m_delimiter
        << static_cast<int>(m_address[3]);

    return output.str();
}

