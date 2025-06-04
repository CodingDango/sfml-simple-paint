#include <iostream>
#include <type_traits>
#include <sstream>

namespace
{
    namespace CharArrayHelpers
    {
         void appendCharPtrToString(std::string& output, const char* char_ptr)
         {  
            size_t index = 0; 
            while (char_ptr[index] != '\0')
            {
                output += char_ptr[index++];
            }
         }
    }

    namespace IntegralHelpers
    {
        template <typename T>
        void appendIntegralToString(std::string& output, T integral_val)
        {
            if constexpr (std::is_integral_v<integral_val>)
            {
                std::ostringstream os {};
                os << value_to_append;
                output += os.str();
            }
        }
    }
}

template <typename T>
void appendToString(std::string& output, T value_to_append)
{
    // Handle char*
    if constexpr (std::is_same_v<char*, T>)
    {
        CharArrayHelpers::appendCharPtrToString(output, value_to_append);
    }

    // Handle string and string_view
    else if constexpr (std::is_same_v<std::string, T> || std::is_same_v<std::string_view, T>)
    {
        output += value_to_append;
    }
    
    // Handle integral types
    else if constexpr (std::is_integral_v<T>)
    {
        IntegralHelpers::appendIntegralToString<T>(output, value_to_append);
    }
}

int main()
{

}