#include "../../include/networking/TcpConnection.hpp"
#include <asio.hpp>

void TcpConnection::Start()
{
    m_Message = "This is test message, if you received it everything is working fine.";

    asio::async_write(m_Socket, asio::buffer(m_Message),
        std::bind(&TcpConnection::HandleWrite, shared_from_this(),
        std::placeholders::_1,
        std::placeholders::_2));
}
