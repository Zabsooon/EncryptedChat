#pragma once

#include <asio.hpp>
#include "TcpConnection.hpp"

using asio::ip::tcp;

class TcpServer
{
public:
    TcpServer(asio::io_context& io_context)
        : m_io_context(io_context),
        m_acceptor(io_context, tcp::endpoint(tcp::v4(), 13))
    {
        StartAccept();
    }
private:
    void StartAccept();
    void HandleAccept(TcpConnection::pointer new_connection,
        const asio::error_code& error);

private:
    asio::io_context& m_io_context;
    tcp::acceptor m_acceptor;
};
