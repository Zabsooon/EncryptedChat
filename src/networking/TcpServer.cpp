#include "../../include/networking/TcpServer.hpp"

void TcpServer::StartAccept()
{
    TcpConnection::pointer new_connection =
        TcpConnection::Create(m_io_context);

    m_acceptor.async_accept(new_connection->Socket(),
        std::bind(&TcpServer::HandleAccept, this, new_connection,
        std::placeholders::_1));
}

void TcpServer::HandleAccept(TcpConnection::pointer new_connection,
    const asio::error_code& error)
{
    if(!error)
    {
        new_connection->Start();
    }

    StartAccept();
}
