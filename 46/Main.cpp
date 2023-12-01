#include <codecvt>
#include <fstream>
#include <iostream>
#include <locale>
#include <unordered_map>

int main() 
{
    // Open the input file stream with wide characters
    std::wifstream in("String.txt", std::ios::binary);

    // Set it to support UTF-8 encoding
    in.imbue(std::locale(in.getloc(), new std::codecvt_utf8<wchar_t>));

    // Check if the file is successfully opened
    if (in.is_open()) 
    {
        // Read the Unicode string from the file
        std::wstring unicode_string{};
        std::getline(in, unicode_string);

        // Open a file stream with UTF-8 encoding
        std::wofstream out("Occurrences.txt", std::ios::out | std::ios::binary);

        // Set it to support UTF-8 encoding
        out.imbue(std::locale(std::locale(), new std::codecvt_utf8<wchar_t>));

        // Check if the output file is successfully opened
        if (out.is_open()) 
        {
            // Write the original Unicode string to the file
            out << L"Original Unicode String: " << unicode_string << L"\n\n";

            // Count the frequency of each character
            std::unordered_map<wchar_t, int> char_frequency{};
            for (wchar_t ch : unicode_string) 
            {
                ++char_frequency[ch];
            }

            std::unordered_map<wchar_t, bool> char_written{};

            // Write the character frequencies to the file
            for (const auto& ch : unicode_string) 
            {
                if (!char_written[ch]) 
                {
                    char_written[ch] = true;
                    out << L"The character " << ch << L" appears " << char_frequency[ch];
                    if (char_frequency[ch] == 1)
                    {
                        out << L" time\n";
                    }
                    else
                    {
                        out << L" times\n";
                    }
                }
            }

            // Close the output file stream
            out.close();

            // Success message
            std::wcout << L"File saved successfully with UTF-8 encoding and character frequencies.\n";
        } 
        else 
        {
            std::wcerr << L"Failed to open the output file.\n";
        }

        // Close the input file stream
        in.close();
    } 
    else 
    {
        std::wcerr << L"Failed to open the input file." << std::endl;
    }

    return 0;
}