#pragma once

#include <functional>
#include <memory>
#include <asio.hpp>

class TcpConnection
    : public std::enable_shared_from_this<TcpConnection>
{
public:
    typedef std::shared_ptr<TcpConnection> pointer;

    static pointer Create(asio::io_context& io_context)
    {
        return pointer(new TcpConnection(io_context));
    }

    asio::ip::tcp::socket& Socket() { return m_Socket; }

    void Start();

private:
    TcpConnection(asio::io_context& io_context)
        : m_Socket(io_context)
    {}

    void HandleWrite(const asio::error_code& /*error*/,
        size_t /*bytes_transferred*/)
    {}

private:
    asio::ip::tcp::socket m_Socket;
    std::string m_Message;
};
