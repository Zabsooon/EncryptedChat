#include "../../include/networking/TcpClient.hpp"

void TcpClient::StartConnection()
{
    try
    {
        asio::ip::tcp::socket socket(m_io_context);
    
        asio::ip::tcp::resolver::results_type endpoints =
            m_resolver.resolve("127.0.0.1", "chat");

        asio::connect(socket, endpoints);

        for(;;)
        {
            std::array<char, 128> buf;
            asio::error_code error;

            size_t len = socket.read_some(asio::buffer(buf), error);

            if(error == asio::error::eof)
                break; // Connection closed cleanly by peer.
            else if(error)
                throw asio::system_error(error); //Some other error.

            std::cout.write(buf.data(), len);
        }
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}
