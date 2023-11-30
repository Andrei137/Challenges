#include "MarkovGenerator.hpp"
#include <fstream>
#include <random>

MarkovGenerator::MarkovGenerator(const str& a_file_name)
{
    std::ifstream in{ a_file_name };
    if (!in)
    {
        throw std::runtime_error("File not found");
    }
    read_tokens(in);
}

// Remove quotes from the word
void MarkovGenerator::clean_word(str& a_word) const
{
    size_t quote_index = a_word.find('"');
    while (quote_index != std::string::npos)
    {
        a_word.erase(quote_index, 1);
        quote_index = a_word.find('"');
    }
}

// Make the word a combination of upper and lower case letters
str MarkovGenerator::shitpost(const str& a_word) const
{
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<int> distr(0, 1);

    str word{ a_word };
    for (size_t i = 0; i < word.length(); ++i)
    {
        if (distr(eng) % 2 == 0)
        {
            word[i] = toupper(word[i]);
        }
        else
        {
            word[i] = tolower(word[i]);
        }
    }
    return word;
}

//  Reads the file and returns a map of the tokens
//  tokens["the"] = { "file", "tokens" } for the sentence above
void MarkovGenerator::read_tokens(std::ifstream& a_in)
{
    str first_word{};
    a_in >> first_word;
    clean_word(first_word);

    str second_word{};
    while (a_in >> second_word)
    {
        clean_word(second_word);
        //  If the first word ends with a period, it is the end of a sentence
        //  So we don't want to add it to the map
        if (first_word[first_word.length() - 1] == '.')
        {
            first_word = second_word;
        }
        else
        {
            m_tokens[first_word].push_back(second_word);
            first_word = second_word;
        }
    }
}

// Generate a sentence using Markov chains
str MarkovGenerator::generate_sentence(bool a_shitpost)
{
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<int> distr(1, 15);

    // Select a random word to start with
    auto iter = std::next(m_tokens.begin(), distr(eng) % m_tokens.size());
    str curr_word = iter->first;

    str sentence{ a_shitpost ? shitpost(curr_word) : curr_word };
    sentence[0] = toupper(sentence[0]);
    while (!m_tokens[curr_word].empty())
    {
        // Select a random word from the list of words that follow the current word
        curr_word = m_tokens[curr_word][distr(eng) % m_tokens[curr_word].size()];
        sentence += ' ' + (a_shitpost ? shitpost(curr_word) : curr_word);
    }
    return sentence;
}