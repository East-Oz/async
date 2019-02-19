#include "async.h"
#include <vector>
#include "bulk.cpp"

namespace async 
{
	std::vector<ParserWrapper*> g_Parsers;

	handle_t connect(std::size_t bulk) 
	{
		ParserWrapper* wrp = new ParserWrapper( bulk );
		g_Parsers.push_back( wrp );
		return static_cast<handle_t>(wrp);
	}

	void receive(handle_t handle, const char *data, std::size_t size) 
	{
		auto it = std::find( g_Parsers.begin(), g_Parsers.end(), static_cast<ParserWrapper*>(handle) );
		if( it != g_Parsers.end() )
		{
			(*it)->ReceiveData( data, size );
		}
		else
		{
			std::cout << "Invalid handle, or handle not exist in collection";
		}
	}

	void disconnect(handle_t handle) 
	{
		auto it = std::find( g_Parsers.begin(), g_Parsers.end(), static_cast< ParserWrapper* >(handle) );
		if( it != g_Parsers.end() )
		{
			delete (*it);
			g_Parsers.erase( it );
		}
		else
		{
			std::cout << "Invalid handle, or handle not exist in collection";
		}
	}
}

