#pragma once

#include <iostream>
#include <array>
#include <asio.hpp>

class TcpClient
{
public:
    TcpClient(asio::io_context& io_context)
        : m_io_context(io_context),
        m_resolver(asio::ip::tcp::resolver(io_context))
    {}

    void StartConnection();
private:
    asio::io_context& m_io_context;
    asio::ip::tcp::resolver m_resolver;
};
